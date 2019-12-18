/**************************************************************************/
/*!
    @file     Adafruit_MMA8451.h
    @author   K. Townsend (Adafruit Industries)
    @license  BSD (see license.txt)

    This is an example for the Adafruit MMA8451 Accel breakout board
    ----> https://www.adafruit.com/products/2019

    Adafruit invests time and resources providing this open source code,
    please support Adafruit and open-source hardware by purchasing
    products from Adafruit!

    @section  HISTORY

    v1.0  - First release
*/
/**************************************************************************/

#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();

int outpin = 3;
int outpin2 = 5;

void setup(void) {
  Serial.begin(9600);
  pinMode(outpin, OUTPUT);
  pinMode(outpin2, OUTPUT);
  
  Serial.println("Adafruit MMA8451 test!");
  

  if (! mma.begin()) {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_2_G);
  
  Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  Serial.println("G");
  
}

void loop() {
  // Read the 'raw' data in 14-bit counts
  mma.read();
  
  
  Serial.print("X:\t"); Serial.print(mma.x); 
  Serial.print("\tY:\t"); Serial.print(mma.y); 
  Serial.print("\tZ:\t"); Serial.print(mma.z); 
  Serial.println();

  /* Get a new sensor event */ 
  sensors_event_t event; 
  mma.getEvent(&event);

  /* Display the results (acceleration is measured in m/s^2) */
  //Serial.print("X: \t"); Serial.print(event.acceleration.x); Serial.print("\t");
  //Serial.print("Y: \t"); Serial.print(event.acceleration.y); Serial.print("\t");
 // Serial.print("Z: \t"); Serial.print(event.acceleration.z); Serial.print("\t");
  //Serial.println("m/s^2 ");
  
  /* Get the orientation of the sensor */
  uint8_t o = mma.getOrientation();

  if(mma.x > 1000){
      analogWrite(5, 0);
      analogWrite(3, 0);
  }
  else if(mma.x < -1000){
      analogWrite(5, 0);
      analogWrite(3, 255);
  }
  else{
      analogWrite(5, 255);
  }
//  
//  switch (o) {
//    case MMA8451_PL_PUF: 
//      //Serial.println("Portrait Up Front");
//      analogWrite(5, 255);
//      break;
//    case MMA8451_PL_PUB: 
//      //Serial.println("Portrait Up Back");
//      analogWrite(5, 255);
//      break;    
//    case MMA8451_PL_PDF: 
//      //Serial.println("Portrait Down Front");
//      
//      break;
//    case MMA8451_PL_PDB: 
//      //Serial.println("Portrait Down Back");
//      
//      break;
//    case MMA8451_PL_LRF: 
//      //Serial.println("Landscape Right Front");
//      analogWrite(5, 0);
//      analogWrite(3, 0);
//      break;
//    case MMA8451_PL_LRB: 
//      //Serial.println("Landscape Right Back");
//      analogWrite(5, 0);
//      analogWrite(3, 0);
//      break;
//    case MMA8451_PL_LLF: 
//      //Serial.println("Landscape Left Front");
//      analogWrite(5, 0);
//      analogWrite(3, 255);
//      break;
//    case MMA8451_PL_LLB: 
//      //Serial.println("Landscape Left Back");
//      analogWrite(5, 0);
//      analogWrite(3, 255);
//      break;
//    }

    
  Serial.println();
  delay(100);
  
}
