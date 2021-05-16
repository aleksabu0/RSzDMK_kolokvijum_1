/**
 * @file arrays.h
 * @brief Deklaracija array funkcija
 * @author Aleksa Bu
 * @date 16.05.2021.
 * @version 1.0
 */
#ifndef ARRAYS_H_
#define ARRAYS_H_
#include<stdint.h>
#define ITERATIVE 1
#define FORMULA 2


int16_t Element(int16_t first_element, int16_t difference, int16_t n);

int16_t Sum(int16_t first_element, int16_t difference, int16_t n, int8_t mode);


#endif /* ARRAYS_H_ */
