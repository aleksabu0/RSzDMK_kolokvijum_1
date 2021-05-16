#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include<stdint.h>
#include "arrays.h"

/**
 * Funkcija vraca trazeni element niza
 * @param first_element prvi clan niza
 * @param difference razlika niza
 * @param n pozicija trazenog clana u nizu
 * @return element niza
 */
int16_t Element(int16_t first_element, int16_t difference, int16_t n)
{
	return (first_element + (n - 1) * difference);
}

//zadatak kaze void sum, ali ima povratnu vrednost ?
/**
 * Funkcija vraca sumu do trazenog elementa niza
 * @param first_element prvi clan niza
 * @param difference razlika niza
 * @param n pozicija trazenog clana u nizu
 * @param mode nacin racunanja sume
 * @return suma niza
 */
int16_t Sum(int16_t first_element, int16_t difference, int16_t n, int8_t mode)
{
	int16_t suma = 0;
	int16_t clan = first_element;
	if (mode == ITERATIVE)
	{
		for(uint8_t i = 0; i < n; i++)
		{
			suma += clan;
			clan += difference;
		}
	}
	else if (mode == FORMULA)
	{
		suma = (n * (2 * first_element + (n - 1) * difference))/2;
	}
	return suma;
}
