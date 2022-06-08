#include "leds.h"




#define BIT(x)                               (1<<(x))
#define BIT_GET(x,b)                        ((x) & BIT(b))
#define CLR_BIT(p,n)                        ((p) &= ~(BIT(n)))
#define SET_BIT(p,n)                        ((p) |= (BIT(n)))
#define LED_ALL_OFF                         (0x00)
#define LED_ALL_ON                          (0xFFFF)


uint16_t*          __port_address;
registro_errores_t __log_error;

void Leds_init(uint16_t* port, registro_errores_t log_error){
    
    __port_address = port;
    __log_error = log_error;

    *__port_address = 0;
}

void    Led_turn_on(int led_position){

    if(led_position > 16 || led_position < 1){
        __log_error(ALERTA,__FUNCTION__,__LINE__,ALERT_MSG_INVALID_PARAM);
    }
    else{
        (*__port_address) |= SET_BIT((*__port_address),LED_OFFSET(led_position));

    }
};


void Led_turn_off(int led_position){

    (*__port_address) |= CLR_BIT((*__port_address),LED_OFFSET(led_position));
}


void Leds_turn_on(uint16_t mask){

    (*__port_address) |= mask;
}



int Led_check_state(int led_position){

    return  (BIT_GET((*__port_address),LED_OFFSET(led_position)))?1:0;
}


void Led_turn_on_all(void ){

    (*__port_address) |= LED_ALL_ON;
}



void Led_turn_off_all(void ){

    (*__port_address) &= LED_ALL_OFF;
}
