#include "RASDemo.h"
#
#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/adc.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/linesensor.h>

tBoolean led_on;

void blink(void) {
    SetPin(PIN_F1, led_on);
    SetPin(PIN_F3, !led_on);

    led_on = !led_on;
}

int main(void) {  
    char ch;
  //  tLineSensor *line = InitializeGPIOLineSensor(PIN_xx, PIN_xx, PIN_xx, PIN_xx, PIN_xx, PIN_xx, PIN_xx, PIN_xx); 
 //These are the eight pins you chose in the proper order
//    float linevals[8];
    //tADC *dist = InitializeADC(PIN_B4);
    //float distval;
    tMotor *left = InitializeServoMotor(PIN_B0, true);
    tMotor *right = InitializeServoMotor(PIN_B1, false);

    CallEvery(blink, 0, 0.25f);

    while (1) {
        Printf("\nRAS Demo for Robotathon 2013\n"
               "  0=UART Demo\n"
	       "  1=Motor Demo\n"
               "  2=Servo Demo\n"
	       "  3=I2C Line Sensor Demo\n"
               "  4=IR Sensor Demo\n"
	       "  5=Encoders Demo\n"
               "  6=GPIO Demo\n"
	       "  7=GPIO Line Sensor Demo\n"
               "  8=Sonar Demo\n"
               ">> ");
        
        // Read input from user
        ch = Getc();
        Printf("\n");
	
	//distval = ADCRead(dist);
        //Printf("IR sensor value is %f\n", distval); //%f is the escape character for floats
	SetMotor(left, 1.0);  
	SetMotor(right, -1.0);
//       LineSensorReadArray(line, linevals);
   //    Printf(“%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t”, value[0], value[1], value[2], 
 //      value[3], value[4], value[5], value[6], value[7]); 
  // \t is the escape character for tabs
        switch(ch) {
            case '0':
                Printf("\nUART Demo\n");
                uartDemo();                 
                break;
            case '1':
                Printf("\nMotor Demo\n");
                initMotors();
                motorDemo(); 
                break;
            case '2':
                Printf("\nServo Demo\n");
                initServo();
                servoDemo();     
                break;
            case '3':
                Printf("\nLine Sensor Demo\n");
                initI2CLineSensor();          
                i2cLineSensorDemo();    
                break;
            case '4':                            
                Printf("\nIR Sensor Demo\n");
                initIRSensor();
                IRSensorDemo();     
                break;
            case '5':
                Printf("\nEncoders Demo\n");
                initEncoders();
                encoderDemo();
                break;
            case '6':
                Printf("\nGPIO Demo\n");
                gpioDemo();
                break;
            case '7':
                Printf("\nGPIO Line Sensor Demo\n");
                initGPIOLineSensor();
                gpioLineSensorDemo();
                break;
            case '8':
                Printf("\nSonar Demo\n");
                initSonar();
                sonarDemo();
                break;
        }
    }
}
