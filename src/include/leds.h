/**
 * @file leds.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */




#ifndef  __LEDS_H__
#define __LEDS_H__

#include <stdint.h>



/**
 * @brief Inicia un puerto con 16 leds
 * 
 * @param port puntero a la memoria que mapea el puerto de leds
 * @return ** void 
 */
void Leds_init(uint16_t* port);


#endif