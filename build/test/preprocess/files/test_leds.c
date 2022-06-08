#include "build/test/mocks/mock_errors.h"
#include "src/include/leds.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






static uint16_t leds_port;

static gravedad_t status;



void log_errors(gravedad_t gravedad, const char * funcion, int linea, const char * mensaje, ...){

    status = gravedad;

}



void setUp(void){



    Leds_init(&leds_port,log_errors);



}





void tearDown(void){

  status == 0xFF;

}





void test_LedsOffAfterCreate(void){



    leds_port = 1;

    Leds_init(&leds_port,log_errors);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((leds_port)), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnLed(void){



    Led_turn_on(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((1 << (5 -1)))), (UNITY_INT)(UNITY_INT16)((leds_port)), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOffLed(void){



    Led_turn_on(5);

    Led_turn_off(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((0))), (UNITY_INT)(UNITY_INT16)((leds_port)), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnManyLeds(void){

    Led_turn_on(5);

    Led_turn_on(7);

    Led_turn_off(7);

    Led_turn_on(11);



    void Leds_turn_on(uint16_t mask);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((1<<(5 -1))|(1<<(11 -1)))), (UNITY_INT)(UNITY_INT16)((leds_port)), (

   ((void *)0)

   ), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnLedOutRange(void){









     Led_turn_on(17);

     UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((ALERTA)), (UNITY_INT)(UNITY_INT16)((status)), (

    ((void *)0)

    ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_HEX16);

}
