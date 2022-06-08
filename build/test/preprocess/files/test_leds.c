#include "src/include/leds.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








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

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_HEX16);

}







void test_TurnOnLed(void){



    Led_turn_on(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((1 << (5 -1)))), (UNITY_INT)(UNITY_INT16)((leds_port)), (

   ((void *)0)

   ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_HEX16);

}







void test_TurnOffLed(void){



    Led_turn_on(5);

    Led_turn_off(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((0))), (UNITY_INT)(UNITY_INT16)((leds_port)), (

   ((void *)0)

   ), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_HEX16);

}







void test_TurnOnManyLeds(void){



    Led_turn_on(5);

    Led_turn_on(7);

    Led_turn_off(7);

    Led_turn_on(11);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((1<<(5 -1))|(1<<(11 -1)))), (UNITY_INT)(UNITY_INT16)((leds_port)), (

   ((void *)0)

   ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_HEX16);

}









void test_TurnOnLedOutRange(void){









     Led_turn_on(17);

     UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((ALERTA)), (UNITY_INT)(UNITY_INT16)((status)), (

    ((void *)0)

    ), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_HEX16);



}







void test_CheckLedStatusOn(void){



    Led_turn_on(5);

    int state = 0;

    state = Led_check_state(5);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((state)), (

   ((void *)0)

   ), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_INT);

}







void test_CheckLedStatusOff(void){



    Led_turn_on(9);

    Led_turn_off(9);

    int state = 1;

    state = Led_check_state(9);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((state)), (

   ((void *)0)

   ), (UNITY_UINT)(113), UNITY_DISPLAY_STYLE_INT);

}





void test_TurnOnAllLeds(void){



    Led_turn_on_all();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((0xFFFF))), (UNITY_INT)(UNITY_INT16)((leds_port)), (

   ((void *)0)

   ), (UNITY_UINT)(120), UNITY_DISPLAY_STYLE_HEX16);



}



void test_TurnOffAllLeds(void){



    leds_port = (0xFFFF);

    Led_turn_off_all();



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((0x00))), (UNITY_INT)(UNITY_INT16)((leds_port)), (

   ((void *)0)

   ), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_HEX16);





}
