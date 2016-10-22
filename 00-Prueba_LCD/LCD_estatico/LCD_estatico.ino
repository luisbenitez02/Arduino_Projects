/*
  LCD con texto estatico
*/

/*( Librerias )*/
#include <Wire.h>  // Libreria de comunicacion I2C/TWI de Arduino IDE
#include <LiquidCrystal_I2C.h>  // Libreria LCD-I2C de fmalpartida

/*( Constantes )*/
#define dir 0x3F  //Es la direccion de tu LCD

/*( Objetos )*/
LiquidCrystal_I2C lcd(dir, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  /* Funcion de configuracion
de pines del modulo LCD/I2C (Direccion,en,rw,rs,d4,d5,d6,d7,backlight,polaridad)*/



void setup(){   //Las instrucciones solo se ejecutan una vez, despues del arranque
  lcd.begin(16,2);  //Inicializacion de LCD de 16 caracteres y 2 lineas
  lcd.backlight(); // Dejamos encendido el backlight
}

void loop(){  //Las instrucciones se ejecutan una y otra vez, hasta un reset o apagado
  /*( Escribir en el LCD )*/ 
  lcd.setCursor(0,0); //Apuntamos a la direccion LCD(caracter,linea)
  lcd.print("Hola Mundo!");  //Escribimos texto
  delay(1000);  //Tiempo de espera
 
  lcd.setCursor(0,1); //Apuntamos a la direccion LCD(caracter,linea)
  lcd.print("Luis Benitez");  //Escribimos texto
  delay(500);  //Tiempo de espera
 
  for(int i = 12; i< 12; i++)  //Bucle Procesando...
  {  //Inicio del bucle procesando...
    lcd.setCursor(i,1);  //Apuntamos a la direccion LCD(caracter,linea)
    lcd.print(".");  //Escribimos texto
    delay(500);  //Tiempo de espera
  }  //fin del bucle procesando..
 
  lcd.setCursor(12,1); //Apuntamos a la direccion LCD(caracter,linea)
  lcd.print(":)");  //Escribimos texto
  delay(2000);  //Tiempo de espera
 
  /*( Desplazamiento )*/
  lcd.clear();  //Borrado del LCD
  lcd.setCursor(20,0); //Apuntamos a la direccion LCD(caracter,linea)
  lcd.print("Me muevo...");  //Escribimos texto
  lcd.setCursor(16,1); //Apuntamos a la direccion LCD(caracter,linea)
  lcd.print("....Me voy :D");  //Escribimos texto
  for (int i = 0; i < 20; i++) //Bucle desplazamiento
  {  //Inicio del bucle desplazamiento
    lcd.scrollDisplayLeft();  //Desplazamiento a la izquierda
    delay(150);  //Tiempo de espera
  }  //Fin del bucle desplazamiento
  delay(6000);  //Tiempo de espera
  lcd.clear();  //Borrado del LCD
  delay(1000);  //Tiempo de espera
 
}  //Fin del Loop

/*******************************************************/

//Fin del programa
