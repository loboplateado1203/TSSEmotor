#include "motor.h"
#include "mock_tick.h"

//********************** Motor_setup ******************************

void Motor_setup( float degXStep )
{
    gradosPorPaso = degXStep;

        IN1 = 1;
        IN2 = 2;
        IN3 = 3;
        IN4 = 4;

            digitalSet(IN1, OUTPUT);
            digitalSet(IN2, OUTPUT);
            digitalSet(IN3, OUTPUT);
            digitalSet(IN4, OUTPUT);
}
//*********************************************************************

void ejecutarBotones(void)
{
        if (bBotonGiroDerecha) 
        {
            bBotonGiroDerecha = false;
            iUltimoBotonActivado = 1;
            digitalWrite (ledPin2 , HIGH );

            if(bToggleDeContinue) 
            return; 
        }
        if (bBotonGiroIzquierda) 
        {
            bBotonGiroIzquierda = false;
            iUltimoBotonActivado = -1;
            digitalWrite (ledPin2 , LOW );

            if(bToggleDeContinue) 
            return; 
        }
        if (bBotonContinue) 
        {
            bBotonContinue = false;
            if (bToggleDeContinue)  
            {
                bToggleDeContinue = false;
                iUltimoBotonActivado = 0;
                digitalWrite(ledPin , LOW );

            motorSpeed = 0;
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, LOW);
                digitalWrite(IN3, LOW);
                digitalWrite(IN4, LOW);        
            } else {
            
                    bToggleDeContinue=true;
                    digitalWrite(ledPin, HIGH);
                    }
         }
}
//************************Motor acelerar *****************************

void acelerar(int nuevaVelocidad)
{
        if (nuevaVelocidad != motorSpeed) 
        {
            if(nuevaVelocidad > motorSpeed)
            {
                motorSpeed++;
                //para evitar que se clave en 0 
                if (motorSpeed == 0 && nuevaVelocidad != 0) motorSpeed = 1; 
            }
        else if (nuevaVelocidad < motorSpeed)
            {
                    motorSpeed--;
                    //para evitar que se clave en 0        
                    if (motorSpeed == 0 && nuevaVelocidad != 0)  motorSpeed = -1; 
            }int abs;
            abs =motorSpeed;
                 myStepper_setSpeed(abs);//(motorSpeed)
        }
}
//*************************Motor_step***********************

void Motor_step(long nDeSteps)
{
    if (nDeSteps > 0)
    {
         for (long i = 0; i < nDeSteps; i++)
        {   
            Paso_1;
            Paso_2;
            Paso_3;
            Paso_4;
        }
     }
    if (nDeSteps < 0)
    {
        for (long i = 0; i > nDeSteps; i--)
        {
            Paso_4;
            Paso_3;  
            Paso_2;
            Paso_1;
        }
    }
 }