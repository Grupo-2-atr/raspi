#include <stdio.h>
#include <stdlib.h>
#include "port.h"
#include "hardware.h"

//Esta función se encarga de imprimir el puerto
void print_port(void);

int main(void) {
    //Zona de variables
    char c;
    int bit, n;

	for (n = 7; n >= 0; --n)
	{
		export_p(leds(n));
	}
	
    //Esto se repetira siempre que no se ingrese una 'q', en ese caso terminara el programa
    do {
        c = getchar();
        switch (c) {
                //Si se recibe una 't', se debe cambiar de estado todas las LED
            case 't':
            {
                maskToggle('a', 0xFF);
                print_port();
                break;
            }

                //Si se recibe una 'c', se debe apagar todas las LED
            case 'c':
            {
                maskOff('a', 0xFF);
                print_port();
                break;
            }

                //Si se recibe una 's', se debe encender todas las LED	
            case 's':
            {
                maskOn('a', 0xFF);
                print_port();
                break;
            }

                //Si se recibe un numero (del 0 al 7) se debe encender esa LED
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            {
                bit=((int)c)-48;
                bitSet('a', bit);
                print_port();
                break;
            }

                //Mientras haya espacios o enter o en el caso de la 'q' el programa no hace nada
            case '\n':
            case ' ':
            case 'q':
            {
                break;
            }

                //Si se recibe cualquier cosa distinta a los casos anteriores, es un caracter invalido	
            default:
            {
                printf("Caracter inválido.\n");
                break;
            }
        }
    } while (c != 'q');

	for (n = 7; n >= 0; --n)
	{
		unexport_p(leds(n));
	}
    return 0;
}

//Esta función se encarga de imprimir el puerto	
void print_port(void) {
    //Zona de variables
    int n;

    //Imprime desde el b7 hasta el b0
    for (n = 7; n >= 0; --n) 
    {
        if(bitGet('a',n)==1)
        {
        	led_on_off(leds(n), "1");
       	}
       	else
       	{
       		led_on_off(leds(n),"0");
       	}
        printf("%d ", bitGet('a', n));
    }
    printf("\n");
}


