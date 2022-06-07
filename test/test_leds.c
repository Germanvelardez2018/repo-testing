
/* Lista de elementos a probar:
    Despues de inicializar, verificar que todos los leds estes apagados
    Se puede prender un LED individual.
    Se puede apagar un LED individual.
    Se pueden prender y apagar múltiples LED’s.
    Se pueden prender todos los LEDs de una vez.
    Se pueden apagar todos los LEDs de una vez.
    Se puede consultar el estado de un LED.
    Revisar limites de los parametros.
    Revisar parámetros fuera de los limites.

*/




#include "unity.h"

#include "leds.h"

void test_LedsOffAfterCreate(void){
 
    uint16_t leds_port  = 1;
    Leds_init(&leds_port);

    TEST_ASSERT_EQUAL_HEX16(0x0000,leds_port);
}


void test_TurnOnLed(void){
    uint16_t leds_port;
    Leds_init(&leds_port);
    Led_turn_on(5);

    TEST_ASSERT_EQUAL_HEX16((1 << 5), leds_port);
}


void test_TurnOffLed(void){

    uint16_t leds_port;
    Leds_init(&leds_port);
    Led_turn_on(5);
    Led_turn_off(5);

    TEST_ASSERT_EQUAL_HEX16((0), leds_port);

}


