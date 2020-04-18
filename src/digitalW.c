#include "motor.h"
#include "mock_tick.h"
//#include <Stepper.h>


void Paso_1(long nDeSteps){
            digitalWrite(IN1, 1);
            digitalWrite(IN2, 0);
            digitalWrite(IN3, 0);
            digitalWrite(IN4, 1);
            delay(delayStep); 
}

void Paso_2(long nDeSteps){
 // Paso 2
            digitalWrite(IN1, 0);
            digitalWrite(IN2, 1);
            digitalWrite(IN3, 1);
            digitalWrite(IN4, 0);
        delay(delayStep)

}
void Paso_3(long nDeSteps){
// Paso 3
            digitalWrite(IN1, 0);
            digitalWrite(IN2, 1);
            digitalWrite(IN3, 0);
            digitalWrite(IN4, 1);
        delay(delayStep);

}
       
void Paso_4(long nDeSteps){
// Paso 4
            digitalWrite(IN1, 1);
            digitalWrite(IN2, 0);
            digitalWrite(IN3, 0);
            digitalWrite(IN4, 1);
        delay(delayStep);
} 

//***************************************************************

void Paso_1E(long){
// Paso 1    
            digitalWrite_Expect(IN1, 1);
            digitalWrite_Expect(IN2, 0);
            digitalWrite_Expect(IN3, 1);
            digitalWrite_Expect(IN4, 0);
        delay_Expect(delayStep);

}

void Paso_2E(long){
// Paso 2
            digitalWrite_Expect(IN1, 0);
            digitalWrite_Expect(IN2, 1);
            digitalWrite_Expect(IN3, 1);
            digitalWrite_Expect(IN4, 0);
       delay_Expect(delayStep);

}

void Paso_3E(long){
// Paso 3
            digitalWrite_Expect(IN1, 0);
            digitalWrite_Expect(IN2, 1);
            digitalWrite_Expect(IN3, 0);
            digitalWrite_Expect(IN4, 1);
    delay_Expect(delayStep);
    
}

void Paso_4E(long){
// Paso 4
            digitalWrite_Expect(IN1, 1);
            digitalWrite_Expect(IN2, 0);
            digitalWrite_Expect(IN3, 0);
            digitalWrite_Expect(IN4, 1);
	delay_Expect(delayStep);

}
       
