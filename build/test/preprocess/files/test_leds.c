#include "src/include/leds.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




void test_LedsOffAfterCreate(void){



    uint16_t leds_port ;

    Leds_init(&leds_port);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x000)), (UNITY_INT)(UNITY_INT16)((leds_port)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_HEX16);

    UnityFail( (("comenzamos")), (UNITY_UINT)(28));

}
