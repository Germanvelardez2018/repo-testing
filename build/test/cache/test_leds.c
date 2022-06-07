#include "src/include/leds.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




void test_LedsOffAfterCreate(void){



    uint16_t leds_port = 1;

    Leds_init(&leds_port);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((leds_port)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnLed(void){

    uint16_t leds_port;

    Leds_init(&leds_port);

    Led_turn_on(5);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((1 << 5))), (UNITY_INT)(UNITY_INT16)((leds_port)), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOffLed(void){



    uint16_t leds_port;

    Leds_init(&leds_port);

    Led_turn_on(5);

    Led_turn_off(5);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((0))), (UNITY_INT)(UNITY_INT16)((leds_port)), (

   ((void *)0)

   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_HEX16);



}
