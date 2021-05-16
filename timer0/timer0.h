/**
 * @file timer0.h
 * @brief Deklaracija vremenskih funkcija
 * @date 16.05.2021.
 * @version 1.0
 */

#ifndef TIMER0_H_
#define TIMER0_H_

/**
 * Funkcija za inicijalizaciju prekida
 * @return nema povratnu vrednost
 */
void timer0InteruptInit();

/**
 * Funkcija za proteklo vreme
 * @return uint32_t vreme_proteklo
 */
uint32_t timer0millis();

/**
 * Funkcija za generisanje prekida
 * @param uint32_t delay_length
 * @return nema povratnu vrednost
 */
void timer0DelayMs(uint32_t delay_length);

#endif /* TIMER0_H_ */
