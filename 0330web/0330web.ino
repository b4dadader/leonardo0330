#include <CapacitiveSensor.h>
#include <Keyboard.h>

// Set the Send Pin & Receive Pin.   
CapacitiveSensor   cs_13_4 = CapacitiveSensor(13,4); 
CapacitiveSensor   cs_13_5 = CapacitiveSensor(13,5); 
CapacitiveSensor   cs_13_6 = CapacitiveSensor(13,6); 
CapacitiveSensor   cs_13_7 = CapacitiveSensor(13,7);     
CapacitiveSensor   cs_13_8 = CapacitiveSensor(13,8);        
CapacitiveSensor   cs_13_9 = CapacitiveSensor(13,9); 
CapacitiveSensor   cs_13_10 = CapacitiveSensor(13,10); 
CapacitiveSensor   cs_13_11 = CapacitiveSensor(13,11); 

//哪組感應點被觸發
bool touch_q=false;
bool touch_a=false;
bool touch_z=false;
bool touch_w=false;
bool touch_s=false;
bool touch_x=false;
bool touch_e=false;
bool touch_d=false;
bool touch_c=false;

int trigger=4000;

void setup()     
{

  Keyboard.begin();
  // turn off autocalibrate on channel 1 - just as an example
  cs_13_4.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_13_5.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_13_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_13_7.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_13_8.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_13_9.set_CS_AutocaL_Millis(0xFFFFFFFF);   
  cs_13_10.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_13_11.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
  delay(10);//Wait chip initialization is complete
    
}
void loop()                   
{
  
  // Set the sensitivity of the sensors.
  long touch4 = cs_13_4.capacitiveSensor(100);
  long touch5 = cs_13_5.capacitiveSensor(100);
  long touch6 = cs_13_6.capacitiveSensor(100);
  long touch7 = cs_13_7.capacitiveSensor(100);
  long touch8 = cs_13_8.capacitiveSensor(100);
  long touch9 = cs_13_9.capacitiveSensor(100);
  long touch10 = cs_13_10.capacitiveSensor(100);
  long touch11 = cs_13_11.capacitiveSensor(100);
  Serial.print(touch4);
  Serial.print(" ");
  Serial.print(touch5);
  Serial.print(" ");
  Serial.print(touch6);
  Serial.print(" ");
  Serial.print(touch7);
  Serial.print(" ");
  Serial.print(touch8);
  Serial.print(" ");
  Serial.print(touch9);
  Serial.print(" ");
  Serial.print(touch10);
  Serial.print(" ");
  Serial.print(touch11);
  Serial.println(" ");
  //摸著才會持續播放，一直摸著聲音會loop，放開再摸才會跑新的
  /*pin4*/
  if (touch4 > trigger&&touch_q==false) //觸碰到感應點 
  {
    touch_q=true;
    Keyboard.press('q');
    delay(10);      
  }
  else if(touch4 < trigger) //偵測手離開感應點
  {
    touch_q=false; 
    Keyboard.release('q');
    delay(10);
  }

  
  
  /*pin5*/
  if (touch5 > trigger&&touch_a==false) //觸碰到感應點 
  {
    touch_a=true;
    Keyboard.press('a');
    delay(10);      
  }
  else if(touch5 < trigger) //偵測手離開感應點
  {
    touch_a=false; 
    Keyboard.release('a');
    delay(10);
  }
  
  /*pin6*/
   if (touch6 > trigger&&touch_z == false) //觸碰到感應點 
  {
    touch_z=true;
    Keyboard.press('z');
    delay(10);   
  }
  else if(touch6 < trigger) //偵測手離開感應點
  {
    touch_z=false; 
    Keyboard.release('z');
    delay(10);
  }
  
  /*pin7*/
  if (touch7 > trigger&&touch_w == false) //觸碰到感應點 
  {
    touch_w=true;
    Keyboard.press('w');
    delay(10);   
  }
  else if(touch7 < trigger) //偵測手離開感應點
  {
    touch_w=false; 
    Keyboard.release('w');
    delay(10);
  }
  
  /*pin8*/
  if (touch8 > trigger&&touch_s == false) //觸碰到感應點 
  {
    touch_s=true;
    Keyboard.press('s');
    delay(10);   
  }
  else if(touch8 < trigger) //偵測手離開感應點
  {
    touch_s=false; 
    Keyboard.release('s');
    delay(10);
  }

  /*pin9*/
  if (touch9 > trigger&&touch_x == false) //觸碰到感應點 
  {
    touch_x=true;
    Keyboard.press('x');
    delay(10);   
  }
  else if(touch9 < trigger) //偵測手離開感應點
  {
    touch_x=false; 
    Keyboard.release('x');
    delay(10);
  }

  /*pin10*/
  if (touch10 > trigger&&touch_e == false) //觸碰到感應點 
  {
    touch_e=true;
    Keyboard.press('e');
    delay(10);   
  }
  else if(touch10 < trigger) //偵測手離開感應點
  {
    touch_e=false; 
    Keyboard.release('e');
    delay(10);
  }


  /*pin11*/
  if (touch11 > trigger&&touch_d == false) //觸碰到感應點 
  {
    touch_d=true;
    Keyboard.press('d');
    delay(10);   
  }
  else if(touch11 < trigger) //偵測手離開感應點
  {
    touch_d=false; 
    Keyboard.release('d');
    delay(10);
  }
  delay(10); 
}
