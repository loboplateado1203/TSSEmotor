/*
• >> 1 verificacion de  los terminales a usar para la conexion del motor.
• >> 2 verificacion del funcionamiento del control manual de los botones.
• >> 3 verificacion de la aceleracion.
• >> 4 verificacion abance por paso de los motores, para no redefinir las funciones del Mock.
*/
//********************************************************************
#include "unity.h"
#include "motor.h"
#include "mock_tick.h"
//#include "mock_Stepper.h"

void setUp(void){//Funcion que se ejecuta al inicio de todos los test
	    IN1 = 1;
        IN2 = 2;
        IN3 = 3;
        IN4 = 4;
		motorSpeed = 90;
}

void tearDown(void){
}

//************ terminales a usar para la conexion del motor ****************

void test_Motor_setup(void){

		digitalSet_Expect(IN1, OUTPUT);
        digitalSet_Expect(IN2, OUTPUT);
        digitalSet_Expect(IN3, OUTPUT);
        digitalSet_Expect(IN4, OUTPUT);

	float degXStep = 1024;

    Motor_setup(degXStep);
}
//*************funcionamiento del control manual de los botones*****************

void test_ejecutarBotones1(void)
{
        digitalWrite_Expect(ledPin, HIGH);

	        bBotonGiroDerecha   = false;
	        bBotonGiroIzquierda = false;
	        bBotonContinue      = true;
	        bToggleDeContinue   = false;

    ejecutarBotones();
}
//************ funcionamiento del boton Continue ****************
void test_ejecutarBotones2(void)
{
        digitalWrite_Expect(ledPin, LOW);
        digitalWrite_Expect(IN1, LOW);
        digitalWrite_Expect(IN2, LOW);
        digitalWrite_Expect(IN3, LOW);
        digitalWrite_Expect(IN4, LOW);        

	        bBotonGiroDerecha   = false;
	        bBotonGiroIzquierda = false;
	        bBotonContinue      = true;
	        bToggleDeContinue   = true;

	ejecutarBotones();
}
//************ funcionamiento del boton Izquierda ****************

void test_ejecutarBotones3(void)
{
        digitalWrite_Expect(ledPin2, LOW);

	        bBotonGiroDerecha   = false;
 	        bBotonGiroIzquierda = true;
 	        bToggleDeContinue   = true;

	ejecutarBotones();
}
//************ funcionamiento del boton Derecha ****************

void test_ejecutarBotones4(void)
{
        digitalWrite_Expect(ledPin2, HIGH);

	        bBotonGiroDerecha    = true;
 	        bBotonGiroIzquierda  = false;
 	        bToggleDeContinue    = true;

	 ejecutarBotones();	
}	 	
//******************** verificacion de la aceleracion.*************************

void test_acelerar(void)
{
	        //motorSpeed = 90;
	        int  nuevaVelocidad = 100;

			int abs;
            abs = motorSpeed + 1;
	        myStepper_setSpeed_Expect(abs);//(motorSpeed + 1)

	acelerar( nuevaVelocidad );
}
//*******************************************************************
void test_Motor_step1(void)
{
			Paso_1E;
			Paso_2E; 
			Paso_3E;
      		Paso_4E;

		long  nDeSteps = 1;

	Motor_step(nDeSteps);
}
//***************************************************************************
void test_Motor_step2(void)
{
     	 	Paso_4E;
  			Paso_3E;
     		Paso_2E;
	 		Paso_1E; 

		long  nDeSteps = -1;

	Motor_step(nDeSteps);
}	
