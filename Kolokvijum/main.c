/**
 * @file main.c
 * @brief Glavni fajl
 * @author Aleksa Bu
 * @date 16.05.2021.
 * @version 1.0
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include"../usart/usart.h"
#include"../timer0/timer0.h"
#include"../arrays/arrays.h"
#include"../pin/pin.h"
#include <stdint.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#define ITERATIVE 1
#define FORMULA 2

/**
 * Funkcija ispisuje broj
 * @param broj_sam broj koji se ispisuje
 * @return nista
 */
void put_broj(int16_t broj_sam);

/**
 * Funkcija pretvara string u broj
 * @param broj_sam[] string koji je unesen
 * @param broj_cif broj cifara
 * @return konvertovan broj
 */
uint16_t get_broj(uint8_t broj_sam[],uint8_t broj_cif);

int main()
{
	//inicijalizacija
	int16_t str[64];
	usartInit(9600);
	pinInit(PORT_B, 5, OUTPUT);
	timer0InteruptInit();
	uint8_t size=0;
	int16_t prvi_element;
	int16_t razlika;
	int16_t n;
	int16_t vreme1;
	while(1)
	{
		//unos prvog elementa
		pinSetValue(PORT_B, 5, HIGH);
		usartPutString("Unesite prvi element");
		usartPutString("\r\n");
		while(!usartAvailable());
		_delay_ms(100);
		size=usartAvailable();
		_delay_ms(100);
		usartGetString(str);
		prvi_element=get_broj(str,size);

		//unos razlike niza
		pinSetValue(PORT_B, 5, LOW);
		usartPutString("Unesite razliku niza");
		usartPutString("\r\n");
		while(!usartAvailable());
		_delay_ms(100);
		size=usartAvailable();
		_delay_ms(100);
		usartGetString(str);
		razlika=get_broj(str,size);

		//unos broja clanan niza
		usartPutString("Unesite trazeni clan niza");
		usartPutString("\r\n");
		while(!usartAvailable());
		_delay_ms(100);
		size=usartAvailable();
		_delay_ms(100);
		usartGetString(str);
		n=get_broj(str,size);

		//ispis niza - prvo osnovni podaci
		usartPutString("Prvi element niza: ");
		put_broj(prvi_element);
		usartPutString(", razlika: ");
		put_broj(razlika);
		usartPutString(", n: ");
		put_broj(n);
		usartPutString("\r\n");

		//ispis niza - n-ti element
		vreme1=timer0millis();
		usartPutString("n-ti element: ");
		put_broj(Element(prvi_element,razlika,n));
		usartPutString(", proteklo vreme: ");
		put_broj(timer0millis()-vreme1);
		usartPutString("ms\r\n");

		//ispis niza - iterativna suma
		vreme1=timer0millis();
		usartPutString("suma_iter: ");
		put_broj(Sum(prvi_element,razlika,n,ITERATIVE));
		usartPutString(", proteklo vreme: ");
		put_broj(timer0millis()-vreme1);
		usartPutString("ms\r\n");

		//ispis niza - suma po formuli
		vreme1=timer0millis();
		usartPutString("suma_form: ");
		put_broj(Sum(prvi_element,razlika,n,FORMULA));
		usartPutString(", proteklo vreme: ");
		put_broj(timer0millis()-vreme1);
		usartPutString("ms\r\n");
	}
	return 0;
}

/****************************************************************************************************************/

void put_broj(int16_t broj_sam)
{
	uint16_t tens=1;
	uint8_t broj_sam_konv[64];
	uint8_t broj_cif=0;
	uint8_t i=0;
	if(broj_sam<0)
	{
		broj_sam_konv[0]='-';
		i++;
		broj_cif++;
		broj_sam = broj_sam * (-1);
	}

	int16_t temp=broj_sam;
	while(temp>0)
	{
		temp=temp/10;
		broj_cif++;
	}

	while(i<broj_cif)
	{
		for(uint8_t k=0;k<(broj_cif-i-1);k++)
		{
			tens=tens*10;
		}
		broj_sam_konv[i]=broj_sam/tens;
		broj_sam=broj_sam-broj_sam_konv[i]*tens;
		broj_sam_konv[i]=broj_sam_konv[i]+48;
		tens=1;
		i++;
	}
	broj_sam_konv[broj_cif]='\0';
	usartPutString(broj_sam_konv);
}

/****************************************************************************************************************/

uint16_t get_broj(uint8_t broj_sam[],uint8_t broj_cif)
{
	uint16_t tens=1;
	uint16_t broj_sam_konv=0;

	for(uint8_t i = 0; i < broj_cif; i++)
	{
		for(uint8_t k = 0; k < (broj_cif-i-1); k++)
		{
			tens=tens*10;
		}
		broj_sam_konv+=(broj_sam[i]-48)*tens;
		//broj_sam[i]=broj_sam[i]-broj_sam_konv*tens;
		//broj_sam_konv[i]=broj_sam_konv[i]+48;
		tens=1;
	}
	return broj_sam_konv;
}





