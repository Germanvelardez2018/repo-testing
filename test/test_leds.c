
/* Lista de elementos a probar:
    Despues de inicializar, verificar que todos los leds estes apagados
    Se puede prender un LED individual.
    Se puede apagar un LED individual.
    Se pueden prender y apagar múltiples LED’s.
    Se pueden prender todos los LEDs de una vez.
    Se pueden apagar todos los LEDs de una vez.
    Se puede consultar el estado de un LED apagado.
    Se puede consultar el estado de un LED prendido.
    Revisar parámetros fuera de los limites.

*/




#include "unity.h"
#include "leds.h"

//#include "mock_errors.h" No necesito el mock porque uso inyeccion de dependencias


static  uint16_t leds_port;
static gravedad_t status;



void  log_errors(gravedad_t gravedad, const char * funcion, int linea, const char * mensaje, ...){
    
    status = gravedad;
}

void  setUp(void){
    
    Leds_init(&leds_port,log_errors);
}


void tearDown(void){ 
   status == 0xFF;
}



//Despues de inicializar, verificar que todos los leds estes apagados
void test_LedsOffAfterCreate(void){
 
    leds_port  = 1;
    Leds_init(&leds_port,log_errors);
    TEST_ASSERT_EQUAL_HEX16(0x0000,leds_port);
}


//Se puede prender un LED individual.
void test_TurnOnLed(void){
   
    Led_turn_on(5);
    TEST_ASSERT_EQUAL_HEX16((1 << LED_OFFSET(5)), leds_port);
}


//Se puede apagar un LED individual.
void test_TurnOffLed(void){

    Led_turn_on(5);
    Led_turn_off(5);
    TEST_ASSERT_EQUAL_HEX16((0), leds_port);
}


//Se pueden prender y apagar múltiples LED’s.
void test_TurnOnManyLeds(void){
    
    Led_turn_on(5);
    Led_turn_on(7);
    Led_turn_off(7);
    Led_turn_on(11);
    TEST_ASSERT_EQUAL_HEX16((1<<LED_OFFSET(5))|(1<<LED_OFFSET(11)), leds_port);
}



//Revisar parámetros fuera de los limites.
void test_TurnOnLedOutRange(void){
   // RegistrarMensaje_Expect(ALERTA,"Led_turn_on",0,ALERT_MSG_INVALID_PARAM);
    //ignora el tercer parametro (linea)
   // RegistrarMensaje_IgnoreArg_linea();

     Led_turn_on(17); 
     TEST_ASSERT_EQUAL_HEX16(ALERTA,status);   //Alerta tiene valor 1 y status que es nivel de alerta del sistema se 
                                               //carga con valor Alerta cuando sucede error en funcion led
}


// Se puede consultar el estado de un LED prendido.
void test_CheckLedStatusOn(void){

    Led_turn_on(5);
    int state = LED_OFF;
    state = Led_check_state(5);
    TEST_ASSERT_EQUAL(LED_ON,state);
}


// Se puede consultar el estado de un LED apagado.
void test_CheckLedStatusOff(void){
    
    Led_turn_on(9);
    Led_turn_off(9);
    int state = LED_ON;
    state = Led_check_state(9);
    TEST_ASSERT_EQUAL(LED_OFF,state);
}


void test_TurnOnAllLeds(void){

    Led_turn_on_all();
    TEST_ASSERT_EQUAL_HEX16(LED_ALL_ON,leds_port);

}

void test_TurnOffAllLeds(void){
    
    leds_port = LED_ALL_ON;
    Led_turn_off_all();
    
    TEST_ASSERT_EQUAL_HEX16(LED_ALL_OFF,leds_port);


}

