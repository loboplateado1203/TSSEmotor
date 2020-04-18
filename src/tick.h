# ifndef TICK_H
# define TICK_H

# include <stdint.h>

	void tick( uint8_t, uint8_t );    

	void digitalWrite( uint8_t, uint8_t );

	void digitalSet( uint8_t, uint8_t );

	void myStepper_setSpeed( uint8_t );

	void delay( uint8_t );

	void Paso_1E(long);

	void Paso_2E(long);

	void Paso_3E(long);

	void Paso_4E(long);

# endif // TICK_H