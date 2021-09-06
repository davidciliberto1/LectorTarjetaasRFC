#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define rele 8
#define RST_PIN         9          // Configurable
#define SS_PIN          10         // Configurable

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
byte LecturaUID[4];
byte Usuario1[4] = {0x37, 0xE9, 0x8E, 0x4A};    // codigo serial HEX
byte Usuario2[4] = {0xDA, 0xC4, 0xEB, 0x80};
int buzz = 7;
LiquidCrystal_I2C lcd(0x3f,16,4);
void setup() {

  Serial.begin(9600);    // Initialize serial communications 
  lcd.init();
  lcd.backlight();
  lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("==> VIDEOS <=="); 
  lcd.setCursor (0,1);
  lcd.print("==> ELECTROALL <");
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  pinMode (buzz, OUTPUT);   //init buzzer
  pinMode(rele, OUTPUT);   // set  rele output
  digitalWrite(rele, LOW); // Apaga rele 
  Serial.print("Listo ");
}

void loop() {
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
    return;
   // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
    return;
    Serial.print("UID:");
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      if (mfrc522.uid.uidByte[i] < 0x10) {
        Serial.print(" 0");
      }
      else {
        Serial.print(" ");
      }
      Serial.print(mfrc522.uid.uidByte[i], HEX);        //Asigna valor de lectura UID
      LecturaUID[i]=mfrc522.uid.uidByte[i];        
    }
    Serial.println("\t");
    if(comparaUID(LecturaUID, Usuario1)){         //compara usuario y tarjeta
    digitalWrite(rele, HIGH);                 // enciende relay
    digitalWrite(buzz, HIGH);                   // suena buzzer
  delay(1000);
  digitalWrite(rele, LOW);                    // apaga relay
  digitalWrite(buzz, LOW);                      //apaga zumbador
    Serial.println("Bienvenido Usuario 1");
    }
    
    else if(comparaUID(LecturaUID, Usuario2)){                // compara
   digitalWrite(rele, HIGH);                      //enciende relay
  delay(1000);                                      //delay
  digitalWrite(rele, LOW);                              // apaga relay  
    Serial.println("Bienvenido Usuario 2");             
    }
    else 
    Serial.println("Acceso Denegado!");
    mfrc522.PICC_HaltA();
  }
  boolean comparaUID(byte Lectura[], byte Usuario[])
  {
    for (byte i=0; i <mfrc522.uid.size; i++){
      if(Lectura[i] != Usuario[i])
      return(false);
    }
    return(true);
  }
