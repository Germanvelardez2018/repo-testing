#include "leds.h"


#define CLR_BIT(p,n) ((p) &= ~((1) << (n)))
#define SET_BIT(p,n) ((p) |= ((1) << (n)))


uint16_t* port_address;


void Leds_init(uint16_t* port){
    port_address = port;
    *port_address = 0;
}

void    Led_turn_on(int led_position){
    (*port_address) |= SET_BIT((*port_address),led_position);
};


void Led_turn_off(int led_position){
        (*port_address) |= CLR_BIT((*port_address),led_position);


}

 