#include <stdio.h>
#include <stdlib.h>

//Denfinimos a las LED con los puertos asociados.
char D0[] = "17";
char D1[] = "4";
char D2[] = "18";
char D3[] = "23";
char D4[] = "24";
char D5[] = "25";
char D6[] = "22";
char D7[] = "27";

//Esta función es la encargada de asociar un bit con un pin. Devuelve el pin.
char* leds(int bit)
{
    char * pin;
    switch(bit)
    {
        case 0:
        {
            pin=D0;
            break;
        }
        case 1:
        {
            pin=D1;
            break;
        }
        case 2:
        {
            pin=D2;
            break;
        }
        case 3:
        {
            pin=D3;
            break;
        }
        case 4:
        {
            pin=D4;
            break;
        }
        case 5:
        {
            pin=D5;
            break;
        }
        case 6:
        {
            pin=D6;
            break;
        }
        case 7:
        {
            pin=D7;
            break;
        }
    }
    return pin;
}

//Esta función se encarga de exportar un pin.
void export_p(char * a) {
    FILE * handle_pins;
    int pin;
    
    //Abrimos el archivo EXPORT.
    if ((handle_pins = fopen("/sys/class/gpio/export", "w")) == NULL) {
        printf("Cannot open EXPORT File. Try again later.\n");
        exit(1);
    }
    
    //Establecemos que pin deseamos exportar
    pin = fputs(a, handle_pins);

    if (pin == -1) {
        printf("Cannot EXPORT PIN . Try again later.\n");
        exit(1);
    } else
        printf("EXPORT File opened succesfully\n");
    fclose(handle_pins);
}

//Esta función se encarga de desexportar un pin. 
void unexport_p(char * a) {
    FILE * handle_pins;
    int pin;
    
    //Abrimos el archivo UNEXPORT.
    if ((handle_pins = fopen("/sys/class/gpio/unexport", "w")) == NULL) {
        printf("Cannot open UNEXPORT File. Try again later.\n");
        exit(1);
    }

	//Establecemos que pin deseamos exportar.
    pin = fputs(a, handle_pins);

    if (pin == -1) {
        printf("Cannot UNEXPORT PIN . Try again later.\n");
        exit(1);
    } else
        printf("UNEXPORT File opened succesfully\n");
    fclose(handle_pins);
}

//Esta función se encarga de poner un pin en "out", después lo pone en 
//active-high y por último le asigna el valor que se desea.
void led_on_off(char * a, char * on) {
    FILE * handle_value;
    FILE * handle_direction;
    FILE * handle_low;

    int direction, low, value;
    
    //Establecemos handle_direction dependiendo del pin que se este utilizando
   	if(a==D0)
	{
		handle_direction = fopen("/sys/class/gpio/gpio17/direction", "w");
	}
    else if(a==D1)
	{
		handle_direction = fopen("/sys/class/gpio/gpio4/direction", "w");
	}
	else if(a==D2)
	{
		handle_direction = fopen("/sys/class/gpio/gpio18/direction", "w");
	}    
	else if(a==D3)
	{
		handle_direction = fopen("/sys/class/gpio/gpio23/direction", "w");
	}
	else if(a==D4)
	{
		handle_direction = fopen("/sys/class/gpio/gpio24/direction", "w");
	}
	else if(a==D5)
	{
		handle_direction = fopen("/sys/class/gpio/gpio25/direction", "w");
	}
	else if(a==D6)
	{
		handle_direction = fopen("/sys/class/gpio/gpio22/direction", "w");
	}
	else if(a==D7)
	{
		handle_direction = fopen("/sys/class/gpio/gpio27/direction", "w");
	}    

    if (handle_direction == NULL) {
        printf("Cannot open DIRECTION File. Try again later.\n");
        exit(1);
    }
    if ((direction = fputs("out", handle_direction)) == -1) {
        printf("Cannot open DIRECTION pin. Try again later.\n");
        exit(1);
    }

	fclose(handle_direction);
	
	//Establecemos handle_low dependiendo del pin que se este utilizando
	if(a==D0)
	{
		handle_low = fopen("/sys/class/gpio/gpio17/active_low", "w");
	}
    else if(a==D1)
	{
		handle_low = fopen("/sys/class/gpio/gpio4/active_low", "w");
	}
	else if(a==D2)
	{
		handle_low = fopen("/sys/class/gpio/gpio18/active_low", "w");
	}    
	else if(a==D3)
	{
		handle_low = fopen("/sys/class/gpio/gpio23/active_low", "w");
	}
	else if(a==D4)
	{
		handle_low = fopen("/sys/class/gpio/gpio24/active_low", "w");
	}
	else if(a==D5)
	{
		handle_low = fopen("/sys/class/gpio/gpio25/active_low", "w");
	}
	else if(a==D6)
	{
		handle_low = fopen("/sys/class/gpio/gpio22/active_low", "w");
	}
	else if(a==D7)
	{
		handle_low = fopen("/sys/class/gpio/gpio27/active_low", "w");
	}
	
    if (handle_low == NULL) {
        printf("Cannot open ACTIVE_LOW File. Try again later.\n");
        exit(1);
    }
    if ((low = fputs("0", handle_low)) == -1) {
        printf("Cannot open ACTIVE_LOW pin. Try again later.\n");
        exit(1);
    }
	
	fclose(handle_low);
	
	//Establecemos handle_value dependiendo del pin que se este utilizando
	if(a==D0)
	{
		handle_value = fopen("/sys/class/gpio/gpio17/value", "w");
	}
    else if(a==D1)
	{
		handle_value = fopen("/sys/class/gpio/gpio4/value", "w");
	}
	else if(a==D2)
	{
		handle_value = fopen("/sys/class/gpio/gpio18/value", "w");
	}    
	else if(a==D3)
	{
		handle_value = fopen("/sys/class/gpio/gpio23/value", "w");
	}
	else if(a==D4)
	{
		handle_value = fopen("/sys/class/gpio/gpio24/value", "w");
	}
	else if(a==D5)
	{
		handle_value = fopen("/sys/class/gpio/gpio25/value", "w");
	}
	else if(a==D6)
	{
		handle_value = fopen("/sys/class/gpio/gpio22/value", "w");
	}
	else if(a==D7)
	{
		handle_value = fopen("/sys/class/gpio/gpio27/value", "w");
	}
	
    if (handle_value == NULL) {
        printf("Cannot open VALUE File. Try again later.\n");
        exit(1);
    }
    if ((value = fputs(on, handle_value)) == -1) {
        printf("Cannot open VALUE pin. Try again later.\n");
        exit(1);
    }

    fclose(handle_value);
}
