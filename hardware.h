/*******************************************************************************
File: hardware.h
Brief: Este archivo contiene todo lo necesario para poder utilizar la Raspberry
Pi, prender y apagar leds conectados a pines.
Autor: Grupo2
*******************************************************************************/

#ifndef HARDWARE_T_
#define HARDWARE_T_

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/* 	Función leds: 
Se encarga de asociar un bit con su pin correspondiente.
Recibe como argumento el número de bit.
Devuelve un puntero con el pin.*/
char* leds(int bit);

/*	Función export_p:
Se encarga de exportar los pines que se pidan.
Recibe el pin que se desea exportar.*/
void export_p(char * a);

/*	Función unexport_p:
Se encarga de desexportar los pines que se pidan.
Recibe el pin que se desea desexportar.*/
void unexport_p(char * a);

/*	Función led_on_off:
Se encarga de encender o apagar un led.
Recibe el pin que se desea poner en 1 o en 0, y el valor que se le debe 
asignar.*/
void led_on_off(char * a, char * on);

/*******************************************************************************
 ******************************************************************************/
#endif //HARDWARE_T_
