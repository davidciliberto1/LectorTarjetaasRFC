### Lector de tarjetas RFC con relay y zumbador
Descripcion: Lector de tarjetas / llaveros RFC programable para apertura de puertas, manejo de seguridad.
Revisa identidad de tarjeta / llavero, compara dentro del array de ID seguros y permite apertura del rele conectado al mecanismo de seguridad, dependiendo de la respuesta, emite luz y sonido de acuerdo al resultado. (display lcd opcional)

Description: RFC Card an Keychain reader programmable for door opening, security devices, and more.
It verifies the ID of the card/keychain, checks the ID with the security array and allows the opening off a 10A relay connected to the security mechanism or gates, pending verification of ID it emits visual display of lights and sounds for approved or denied access. (optional lcd display)

### "inserte diseño de conexion de componentes y modulos"

Lista de libreria
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

## Lector de Tarjetas RFC 

<img src="https://raw.githubusercontent.com/davidciliberto1/LectorTarjetaasRFC/main/images/WhatsApp%20Image%202021-08-20%20at%2010.01.18.jpeg" width="200"  style="text-align: right;"> 
