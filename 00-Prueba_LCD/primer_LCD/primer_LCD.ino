/*( Librerias )*/
#include <Wire.h>  // Libreria de comunicacion I2C/TWI de Arduino IDE
#include <LiquidCrystal_I2C.h>  // Libreria LCD-I2C de fmalpartida
/*( Constantes )*/
/*( Objetos )*/
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  /* Funcion de configuracion
de pines del modulo LCD/I2C (Direccion,en,rw,rs,d4,d5,d6,d7,backlight,polaridad)*/
/*( Variables Globales )*/

/*******************************************************/

/*******************( SETUP )***************************/

void setup()   //Las instrucciones solo se ejecutan una vez, despues del arranque
{  //Inicio del Setup
  lcd.begin(16,2);  //Inicializacion de LCD de 16 caracteres y 2 lineas
 
  /*( Parpadeo backlight )*/
  for(int i = 0; i< 3; i++)  //Bucle encendido/apagado del backlight
  {  //Inicio del bucle encendido/apagado del backlight
    lcd.backlight();  //Encendido
    delay(250);  //Tiempo de espera
    lcd.noBacklight();  //Apagado
    delay(250);  //Tiempo de espera
  }  //fin del bucle encendido/apagado del backlight
 
  lcd.backlight(); // Dejamos encendido el backlight
}  //Fin del Setup

/*******************************************************/

/*******************( LOOP )****************************/

void loop()  //Las instrucciones se ejecutan una y otra vez, hasta un reset o apagado
{  //Inicio del Loop
 
  /*( Escribir en el LCD )*/ 
  lcd.setCursor(0,0); //Apuntamos a la direccion LCD(caracter,linea)
  lcd.print("ElectroHobby.es");  //Escribimos texto
  delay(1000);  //Tiempo de espera
 
  lcd.setCursor(1,1); //Apuntamos a la direccion LCD(caracter,linea)
  lcd.print("Test");  //Escribimos texto
  delay(500);  //Tiempo de espera
 
  for(int i = 5; i< 12; i++)  //Bucle Procesando...
  {  //Inicio del bucle procesando...
    lcd.setCursor(i,1);  //Apuntamos a la direccion LCD(caracter,linea)
    lcd.print(".");  //Escribimos texto
    delay(500);  //Tiempo de espera
  }  //fin del bucle procesando..
 
  lcd.setCursor(12,1); //Apuntamos a la direccion LCD(caracter,linea)
  lcd.print("ok");  //Escribimos texto
  delay(2000);  //Tiempo de espera
 
  /*( Desplazamiento )*/
  lcd.clear();  //Borrado del LCD
  lcd.setCursor(20,0); //Apuntamos a la direccion LCD(caracter,linea)
  lcd.print("Te espero en");  //Escribimos texto
  lcd.setCursor(16,1); //Apuntamos a la direccion LCD(caracter,linea)
  lcd.print("WWW.ElectroHobby.es");  //Escribimos texto
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
