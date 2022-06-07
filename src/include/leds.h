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

/**
 * @brief Encender un led
 * 
 * @param led_position posicion del led a encender
 * @return ** void 
 */
void Led_turn_on(int led_position);


/**
 * @brief Apagar un led
 * 
 * @param led_position posicion del led que quiero apagar
 * @return ** void 
 */
void Led_turn_off(int led_position);


#endif