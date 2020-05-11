#include "mbed.h"
static AnalogIn range_sensor(A1); //ULTRASONIC SENSOR
Serial pc(USBTX,USBRX);

int main (){
    
    while(1){
        uint16_t height;
        height = range_sensor. read_u16();
        float height_cm=(height*0.0198442452); 
/*CALIBRATION
A=(VCC/512)volts/inch
3.3/512= 6.4453*10^-3 volts/inch
an inch = 2.54 cm
hence volts/cm= (6.4453*10^-3v/inch)/2.54cm= 2.5375*10^-3V/cm

DECIMAL VALUE TO VOLTAGE CONVERSION
D=(DECIMAL_VALUE)/(2^16-1)*3.3V
D=DECIMAL_VALUE*0.0000503547 VOLTS

HEIGHT_IN_CM = (DECIMAL_VALUE*0.0000503547 VOLTS)/2.5375*10^-3V/cm = DECIMAL_VALUE*0.0198442452
    */
        pc.printf("\rDEPTH:%f CM\n",height_cm);
        wait(3.0);
        }
    }