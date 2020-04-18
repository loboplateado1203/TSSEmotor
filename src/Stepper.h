/*
 * Stepper.h - Biblioteca Stepper para Wiring / Arduino - Versión 1.1.0
 * *
 * Biblioteca original (0.1) de Tom Igoe.
 * Modificaciones a dos hilos (0.2) por Sebastian Gassner
 * Versión combinada (0.3) de Tom Igoe y David Mellis
 * Corrección de errores para cuatro hilos (0.4) por Tom Igoe, corrección de errores de Noah Shibley
 * Mod de pasos de alta velocidad por Eugene Kozlenko
 * Corrección de reinicio del temporizador por Eugene Kozlenko
 * Cinco fases cinco hilos (1.1.0) por Ryan Orendorff
 * *
 * Esta biblioteca es software libre; puedes redistribuirlo y / o
 * Modifíquelo bajo los términos del Público General Menor de GNU
 * Licencia publicada por la Free Software Foundation; ya sea
 * versión 2.1 de la Licencia, o (a su elección) cualquier versión posterior.
 * *
 * Esta biblioteca se distribuye con la esperanza de que sea útil,
 * pero SIN NINGUNA GARANTÍA; sin siquiera la garantía implícita de
 * COMERCIABILIDAD o APTITUD PARA UN PROPÓSITO EN PARTICULAR. Ver la GNU
 * Licencia pública general menor para más detalles.
 * *
 * Debería haber recibido una copia del Público general menor de GNU
 * Licencia junto con esta biblioteca; si no, escriba al Software Libre
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 EE. UU.
 * *
 * *
 * Acciona un motor paso a paso unipolar, bipolar o de cinco fases.
 * *
 * Al conectar múltiples motores paso a paso a un microcontrolador, se ejecuta rápidamente
 * sin pines de salida, con cada motor que requiere 4 conexiones.
 * *
 * Al hacer uso del hecho de que en cualquier momento dos de las cuatro bobinas del motor están
 * el inverso de los otros dos, el número de conexiones de control puede ser
 * reducido de 4 a 2 para los motores unipolares y bipolares.
 * *
 * Un circuito ligeramente modificado alrededor de un conjunto de transistores Darlington o un
 * El puente H L293 se conecta a solo 2 pines del microcontrolador, invierte las señales
 * recibido, y entrega las 4 señales de salida (2 más 2 invertidas)
 * requerido para conducir un motor paso a paso. Del mismo modo, los escudos del motor Arduino
 * Se pueden usar 2 pines de dirección.
 * *
 * La secuencia de señales de control para 5 fases, 5 cables de control es la siguiente:
 * *
 * Paso C0 C1 C2 C3 C4
 *    1  0  1  1  0  1
 *    2  0  1  0  0  1
 * 3 0 1 0 1 1
 * 4 0 1 0 1 0
 * 5 1 1 0 1 0
 * 6 1 0 0 1 0
 * 7 1 0 1 1 0
 * 8 1 0 1 0 0
 * 9 1 0 1 0 1
 * 10 0 0 1 0 1
 * *
 * La secuencia de señales de control para 4 cables de control es la siguiente:
 * *
 * Paso C0 C1 C2 C3
 * 1 1 0 1 0
 * 2 0 1 1 0
 * 3 0 1 0 1
 * 4 1 0 0 1
 * *
 * La secuencia de señales de control para 2 cables de control es la siguiente
 * (columnas C1 y C2 de arriba):
 * *
 * Paso C0 C1
 * 1 0 1
 * 2 1 1
 * 3 1 0
 * 4 0 0
 * *
 * Los circuitos se pueden encontrar en
 * *
 * http://www.arduino.cc/en/Tutorial/Stepper
 */

// asegúrese de que esta descripción de la biblioteca solo se incluya una vez
# ifndef Stepper_h
# define  Stepper_h

// descripción de la interfaz de la biblioteca

   
    // constructores:
  /*  int Paso_apaso ( int numero_de_pasos, int motor_pin_1, int motor_pin_2);
    int Pasoa_paso ( int numero_de_pasos, int motor_pin_1, int motor_pin_2,
                                 int motor_pin_3, int motor_pin_4);*/
     int  paso_a_paso ( int numero_de_pasos, int motor_pin_1, int motor_pin_2,
                                 int motor_pin_3, int motor_pin_4,
                                 int motor_pin_5);

    // método de establecimiento de velocidad:
    void  setSpeed ( long whatSpeed);

    // método de movimiento:
    int vacio( int numero_de_pasos);



  //privado:
    int stepMotor ( int this_step);

    int sentido;            // Dirección de rotación
    unsigned  long step_delay; // retraso entre pasos, en ms, según la velocidad
    int numero_de_pasos;      // número total de pasos que este motor puede tomar
    int pin_count;            // cuántos pines están en uso.
    int step_number;          // en qué paso está el motor

    // números de pin del motor:
    int motor_pin_1;
    int motor_pin_2;
    int motor_pin_3;
    int motor_pin_4;
    int motor_pin_5;          // Solo motor de 5 fases

    unsigned  long last_step_time; // marca de tiempo en nosotros de cuándo se dio el último paso


# endif
