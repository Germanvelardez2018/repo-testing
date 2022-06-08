
/**************************************************************************************************
 ** (c) Copyright 2012: GERMAN VELARDEZ <germanvelardez16@gmail.com>
 ** ALL RIGHTS RESERVED, DON'T USE OR PUBLISH THIS FILE WITHOUT AUTORIZATION
 *************************************************************************************************/

#ifndef LEDS_H   /*! @cond    */
#define LEDS_H   /*! @endcond */



/** @file leds.h
 ** @brief Declaraciones de la libreria para el manejo de un puerto de leds
 **
 ** Libreria para el registro del los errores del sistema.
 **
 **| REV | YYYY.MM.DD | Autor           | Descripción de los cambios                              |
 **|-----|------------|-----------------|---------------------------------------------------------|
 **|   1 | 2022.06.07 | German Velardez | Version inicial del driver para manejo de leds      |
 **
 ** @addtogroup plataforma
 ** @{ */

/* === Inclusiones de archivos externos ======================================================== */



#include <stdint.h>
#include "errors.h"      // En codigo de produccion no van llamadas a mocks




/* === Cabecera C++ ============================================================================ */
#ifdef __cplusplus
extern "C" {
#endif

/* === Definicion y Macros ===================================================================== */

// MACROS DE CONFIGURACION DEL OFFSET
#define OFFSET                  1
#define LED_OFFSET(POS)     (POS -OFFSET)
#define ALERT_MSG_INVALID_PARAM             "Parametro invalido"
#define LED_ON                          1
#define LED_OFF                         0


/**
 * @brief Inicia un puerto con 16 leds
 * 
 * @param port puntero a la memoria que mapea el puerto de leds
 * @return ** void 
 */
void Leds_init(uint16_t* port,registro_errores_t log_error);

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


/**
 * @brief Prendo mas de un led a la vez
 * 
 * @param mask  mascara de leds que quiero prender
 * @return ** void 
 */
void Leds_turn_on(uint16_t mask);


/**
 * @brief Checkeo si el led indicado esta prendido. Retorno 1 Si es Verdadero y 0 si es Falso.
 * 
 * @param led_position 
 * @return ** int 
 */
int Led_check_on(int led_position);



/* === Ciere de documentacion ================================================================== */
#ifdef __cplusplus
}
#endif

/** @} Final de la definición del modulo para doxygen */






#endif