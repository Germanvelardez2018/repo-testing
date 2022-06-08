
/* Lista de elementos a probar:
    Despues de inicializar, verificar que todos los leds estes apagados
    Se puede prender un LED individual.
    Se puede apagar un LED individual.
    Se pueden prender y apagar múltiples LED’s.
    Se pueden prender todos los LEDs de una vez.
    Se pueden apagar todos los LEDs de una vez.
    Se puede consultar el estado de un LED apagado.
    Se puede consultar el estado de un LED prendido.
    Revisar limites de los parametros.
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


void test_LedsOffAfterCreate(void){
 
    leds_port  = 1;
    Leds_init(&leds_port,log_errors);
    TEST_ASSERT_EQUAL_HEX16(0x0000,leds_port);
}


void test_TurnOnLed(void){
   
    Led_turn_on(5);
    TEST_ASSERT_EQUAL_HEX16((1 << LED_OFFSET(5)), leds_port);
}


void test_TurnOffLed(void){

    Led_turn_on(5);
    Led_turn_off(5);
    TEST_ASSERT_EQUAL_HEX16((0), leds_port);
}


void test_TurnOnManyLeds(void){
    
    Led_turn_on(5);
    Led_turn_on(7);
    Led_turn_off(7);
    Led_turn_on(11);

    void Leds_turn_on(uint16_t mask);

    TEST_ASSERT_EQUAL_HEX16((1<<LED_OFFSET(5))|(1<<LED_OFFSET(11)), leds_port);
}


void test_TurnOnLedOutRange(void){
   // RegistrarMensaje_Expect(ALERTA,"Led_turn_on",0,ALERT_MSG_INVALID_PARAM);
    //ignora el tercer parametro (linea)
   // RegistrarMensaje_IgnoreArg_linea();

     Led_turn_on(17); 
     TEST_ASSERT_EQUAL_HEX16(ALERTA,status);   //Alerta tiene valor 1 y status que es nivel de alerta del sistema se 
                                               //carga con valor Alerta cuando sucede error en funcion led
}


void test_CheckLedOn(void){
    Led_turn_on(5);
    int check = LED_OFF;
    check = Led_check_on(5);
    TEST_ASSERT_EQUAL(LED_ON,check);
}