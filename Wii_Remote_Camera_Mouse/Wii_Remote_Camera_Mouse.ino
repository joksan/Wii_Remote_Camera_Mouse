#include <Wire.h>
#include <PVision.h>

//Objeto de tipo PVision con la camara
PVision camara;

//Ubicacion de los perifericos
const int pinBoton = 9;
const int pinLed = 10;

//Variables de estado global
boolean boton = false;        //Estado actual del boton
boolean botonAnt = false;     //Estado anterior del boton
boolean mouseActivo = false;  //Estado de activacion del mouse

void setup() {
  //Establece la direccion de los pines
  pinMode(pinBoton, INPUT);
  pinMode(pinLed, OUTPUT);

  //Inicializa la camara
  camara.init();
}

void loop() {
  //Valor de retorno para la funcion de lectura de la camara
  byte ValorRetorno;

  //Actualiza el estado del boton
  botonAnt = boton;
  boton = digitalRead(pinBoton);

  //Si el boton fue presionado recientemente, determina una accion
  //en base al estado del mouse
  if (boton && !botonAnt) {
    if (!mouseActivo) {
      //Si el mouse esta inactivo, lo activa y enciende el LED
      Mouse.begin();
      digitalWrite(pinLed, HIGH);
      mouseActivo = true;
    }
    else {
      //Si el mouse esta activo, lo desactiva y apaga el LED
      Mouse.end();
      digitalWrite(pinLed, LOW);
      mouseActivo = false;
    }
  }

  //Actualiza las coordenadas del mouse siempre que este activo
  if (mouseActivo) {
    //Lee la camara para ver si se detectan bultos
    ValorRetorno = camara.read();

    //En caso que se detecte un bulto, toma las coordenadas
    //del primero que encuentre y las envia a la PC
    if (ValorRetorno & BLOB1) {
      Mouse.move(
        map(camara.Blob1.X, 0, 1023, -127, 127),
        map(camara.Blob1.Y, 0, 768, 127, -127),
        0);
    }
  }

  //Realiza el proceso cada 10ms
  delay(10);
}
