#include "build/temp/_test_motor.c"
#include "build/test/mocks/mock_tick.h"
#include "src/motor.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"




void setUp(void){

     IN1 = 1;

        IN2 = 2;

        IN3 = 3;

        IN4 = 4;

  motorSpeed = 90;

}



void tearDown(void){

}







void test_Motor_setup(void){



  digitalSet_CMockExpect(29, IN1, 1);

        digitalSet_CMockExpect(30, IN2, 1);

        digitalSet_CMockExpect(31, IN3, 1);

        digitalSet_CMockExpect(32, IN4, 1);



 float degXStep = 1024;



    Motor_setup(degXStep);

}





void test_ejecutarBotones1(void)

{

        digitalWrite_CMockExpect(42, 3, 1);



         bBotonGiroDerecha = 0;

         bBotonGiroIzquierda = 0;

         bBotonContinue = 1;

         bToggleDeContinue = 0;



    ejecutarBotones();

}



void test_ejecutarBotones2(void)

{

        digitalWrite_CMockExpect(54, 3, 0);

        digitalWrite_CMockExpect(55, IN1, 0);

        digitalWrite_CMockExpect(56, IN2, 0);

        digitalWrite_CMockExpect(57, IN3, 0);

        digitalWrite_CMockExpect(58, IN4, 0);



         bBotonGiroDerecha = 0;

         bBotonGiroIzquierda = 0;

         bBotonContinue = 1;

         bToggleDeContinue = 1;



 ejecutarBotones();

}





void test_ejecutarBotones3(void)

{

        digitalWrite_CMockExpect(71, 4, 0);



         bBotonGiroDerecha = 0;

          bBotonGiroIzquierda = 1;

          bToggleDeContinue = 1;



 ejecutarBotones();

}





void test_ejecutarBotones4(void)

{

        digitalWrite_CMockExpect(83, 4, 1);



         bBotonGiroDerecha = 1;

          bBotonGiroIzquierda = 0;

          bToggleDeContinue = 1;



  ejecutarBotones();

}





void test_acelerar(void)

{



         int nuevaVelocidad = 100;



   int abs;

            abs = motorSpeed + 1;

         myStepper_setSpeed_CMockExpect(100, abs);



 acelerar( nuevaVelocidad );

}



void test_Motor_step1(void)

{

   Paso_1E;

   Paso_2E;

   Paso_3E;

        Paso_4E;



  long nDeSteps = 1;



 Motor_step(nDeSteps);

}



void test_Motor_step2(void)

{

        Paso_4E;

     Paso_3E;

       Paso_2E;

    Paso_1E;



  long nDeSteps = -1;



 Motor_step(nDeSteps);

}
