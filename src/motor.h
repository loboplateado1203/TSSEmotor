#include <stdio.h>
#include <stdint.h>
//#include <Stepper.h>
//***********************************************
#define true    1
#define false   0
#define LOW     0
#define HIGH    1
#define ledPin  3
#define ledPin2 4
#define OUTPUT  1

//***********************************************
    float gradosPorPaso;

    uint8_t IN1 ;
    uint8_t IN2 ;
    uint8_t IN3;
    uint8_t IN4;
    
    uint8_t iUltimoBotonActivado;
    uint8_t motorSpeed;
    uint8_t delayStep;

    
//***********************************************
    typedef uint8_t bool_t;

            bool_t bBotonGiroDerecha;
            bool_t bToggleDeContinue;
            bool_t bBotonGiroIzquierda;
            bool_t bBotonContinue;

//***********************************************
void Motor_setup( float );

void ejecutarBotones( void );

void acelerar( int );

void Motor_step(long);
//***********************************************

void Paso_1(long);
void Paso_2(long);
void Paso_3(long);
void Paso_4(long);