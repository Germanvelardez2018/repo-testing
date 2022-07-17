#include "leds.h"




// MACROS DE MANEJO DE BITS
#define BIT(x)                              (1<<(x))
#define BIT_GET(x,b)                        ((x) & BIT(b))
#define CLR_BIT(p,n)                        ((p) &= ~(BIT(n)))
#define SET_BIT(p,n)                        ((p) |= (BIT(n)))


// MACROS DE CONFIGURACION DEL OFFSET
#define OFFSET                               1
#define LED_OFFSET(POS)                     (POS -OFFSET)
#define ALERT_MSG_INVALID_PARAM             "Parametro invalido"
#define LED_ON                               1
#define LED_OFF                              0
#define LED_ALL_OFF                         (0x00)
#define LED_ALL_ON                          (0xFFFF)


// MACROS DE CONSTANTES UTILIZADAS
#define MAX_LED_INDEX                       (16)
#define MIN_LED_INDEX                       (1)


// MACROS PARA CHECK
#define CHECK_OK                            (1)
#define CHECK_ERROR                         (0)



uint16_t*          port_address;
registro_errores_t log_error;




static int Param_check(int index){
    int ret = CHECK_OK;
    if(index > MAX_LED_INDEX || index < MIN_LED_INDEX)
    {
        ret = CHECK_ERROR;
        log_error(ALERTA,__FUNCTION__,__LINE__,ALERT_MSG_INVALID_PARAM);
    } 
    return ret;
}




void Leds_init(uint16_t* port, registro_errores_t reg_error){
    
    port_address = port;
    log_error = reg_error;
    Led_turn_off_all(); 
}


void Led_turn_on(int led_position){

    if(Param_check(led_position))    (*port_address) |= SET_BIT((*port_address),LED_OFFSET(led_position));    
}


void Led_turn_off(int led_position){

    if(Param_check(led_position)) (*port_address) |= CLR_BIT((*port_address),LED_OFFSET(led_position));
}


int Led_check_state(int led_position){
    
    int ret = LED_OFF;
     if(Param_check(led_position)) 
     {
        if(BIT_GET((*port_address),LED_OFFSET(led_position))) ret = LED_ON;
     }
     return ret;
}


void Led_turn_on_all(void ){

    (*port_address) |= LED_ALL_ON;
}


void Led_turn_off_all(void ){

    (*port_address) &= LED_ALL_OFF;
}
