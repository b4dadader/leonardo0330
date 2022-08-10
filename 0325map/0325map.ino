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
CapacitiveSensor   cs_13_12 = CapacitiveSensor(13,12); 

//感應點會觸發的字母
char opKey[2] = {'o','p'};
char qKey[3] ={'q','a','z'} ;
char wKey[3] ={'w','s','x'} ;
char eKey[3] = {'e','d','c'};
char rKey[3] = {'r','f','v'};
char tKey[3] = {'t','g','b'};
char yKey[3] = {'y','h','n'};
char uKey[3] = {'u','j','m'};
char iKey[3] = {'i','k',','};
char QRKey = 'l';

int randNumber ;
//看哪個字母被輸入
bool op=false;
bool input_q[3]={false};
//哪組感應點被觸發
bool touch_q=false;
bool input_w[3]={false};
bool touch_w=false;
bool input_e[3]={false};
bool touch_e=false;
bool input_r[3]={false};
bool touch_r=false;
bool input_t[3]={false};
bool touch_t=false;
bool input_y[3]={false};
bool touch_y=false;
bool input_u[3]={false};
bool touch_u=false;
bool input_i[3]={false};
bool touch_i=false;
bool input_QR=false;
bool touch_QR=false;

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
  cs_13_12.set_CS_AutocaL_Millis(0xFFFFFFFF); 
  Serial.begin(9600);
  randomSeed(analogRead(A0));
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
  long touch12 = cs_13_12.capacitiveSensor(100);
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
  Serial.print(" ");
  Serial.println(touch12);
  //觸碰一下就播放，5秒後自動結束，一直摸著不會跑新的投影，放開再摸才會跑新的
  /*pin4*/
  if (touch4 > 10000&&touch_q==false) //觸碰到感應點 
  {
    //啟動新的投影
    op=false;
    touch_q=true;
    randNumber=random(3);
    input_q[randNumber]=true;

    Keyboard.press(qKey[randNumber]);
    delay(10);     
  }
  else if(touch4 < 10000) //偵測手離開感應點
  {
    touch_q=false;
    for(int i=0;i<3;i++)
    {
      if(input_q[i] == true)
      {               
        Keyboard.release(qKey[i]);
        delay(10);
        input_q[i] = false;                  
      }
    }
  }

  
  
  /*pin5*/
  if (touch5 > 10000&&touch_w==false) //觸碰到感應點 
  {
    //啟動新的投影
    op=false;
    touch_w=true;
    randNumber=random(3);
    input_w[randNumber]=true;
      
    Keyboard.press(wKey[randNumber]);    
    delay(10);     
  }
  else if(touch5 < 10000) //偵測手離開感應點
  {
    touch_w=false;
    for(int i=0;i<3;i++)
    {
      if(input_w[i] == true)
      {        
        Keyboard.release(wKey[i]);
        delay(10);
        input_w[i] = false;                  
      }
    }
  }
  
  /*pin6*/
  if (touch6 > 10000&&touch_e==false) //觸碰到感應點 
  {
    //啟動新的投影
    op=false;
    touch_e=true;
    randNumber=random(3);
    input_e[randNumber]=true;
      
    //Serial.print(randNumber);
    Keyboard.press(eKey[randNumber]);
    delay(10);      
  }
  else if(touch6 < 10000) //偵測手離開感應點
  {
    touch_e=false;
    for(int i=0;i<3;i++)
    {
      if(input_e[i] == true)
      {                
        Keyboard.release(eKey[i]);
        delay(10);
        input_e[i] = false;                  
      }
    }
  }
  
  /*pin7*/
  if (touch7 > 10000&&touch_r==false) //觸碰到感應點 
  {
    //啟動新的投影
    op=false;
    touch_r=true;
    randNumber=random(3);
    input_r[randNumber]=true;
      
    //Serial.print(randNumber);
    Keyboard.press(rKey[randNumber]);
    delay(10);      
  }
  else if(touch7 < 10000) //偵測手離開感應點
  {
    touch_r=false;
    for(int i=0;i<3;i++)
    {
      if(input_r[i] == true)
      {                
        Keyboard.release(rKey[i]);
        delay(10);
        input_r[i] = false;                  
      }
    }
  }
  
  /*pin8*/
  if (touch8 > 10000&&touch_t==false) //觸碰到感應點 
  {
    //啟動新的投影
    op=false;
    touch_t=true;
    randNumber=random(3);
    input_t[randNumber]=true;
      
    //Serial.print(randNumber);
    Keyboard.press(tKey[randNumber]);
    delay(10);      
  }
  else if(touch8 < 10000) //偵測手離開感應點
  {
    touch_t=false;
    for(int i=0;i<3;i++)
    {
      if(input_t[i] == true)
      {                
        Keyboard.release(tKey[i]);
        delay(10);
        input_t[i] = false;                  
      }
    }
  }
  
  /*pin9*/
  if (touch9 > 10000&&touch_y==false) //觸碰到感應點 
  {
    //啟動新的投影
    op=false;
    touch_y=true;
    randNumber=random(3);
    input_y[randNumber]=true;
      
    //Serial.print(randNumber);
    Keyboard.press(yKey[randNumber]);
    delay(10);      
  }
  else if(touch9 < 10000) //偵測手離開感應點
  {
    touch_y=false;
    for(int i=0;i<3;i++)
    {
      if(input_y[i] == true)
      {                
        Keyboard.release(yKey[i]);
        delay(10);
        input_y[i] = false;                  
      }
    }
  }
  
  /*pin10*/
  if (touch10 > 10000&&touch_u==false) //觸碰到感應點 
  {
    //啟動新的投影
    op=false;
    touch_u=true;
    randNumber=random(3);
    input_u[randNumber]=true;
      
    //Serial.print(randNumber);
    Keyboard.press(uKey[randNumber]);
    delay(10);      
  }
  else if(touch10 < 10000) //偵測手離開感應點
  {
    touch_u=false;
    for(int i=0;i<3;i++)
    {
      if(input_u[i] == true)
      {                
        Keyboard.release(uKey[i]);
        delay(10);
        input_u[i] = false;                  
      }
    }
  }
  
  /*pin11*/
  if (touch11 > 10000&&touch_i==false) //觸碰到感應點 
  {
    //啟動新的投影
    op=false;
    touch_i=true;
    randNumber=random(3);
    input_i[randNumber]=true;
      
    //Serial.print(randNumber);
    Keyboard.press(iKey[randNumber]);
    delay(10);      
  }
  else if(touch11 < 10000) //偵測手離開感應點
  {
    touch_i=false;
    for(int i=0;i<3;i++)
    {
      if(input_i[i] == true)
      {                
        Keyboard.release(iKey[i]);
        delay(10);
        input_i[i] = false;                  
      }
    }
  }
  
   /*pin12*/
  if (touch12 > 10000&&touch_QR==false) //觸碰到感應點 
  {
    //啟動新的投影
    op=false;
    touch_QR=true;
    input_QR=true;
      
    //Serial.print(randNumber);
    Keyboard.press(QRKey);
    delay(10);      
  }
  else if(touch12 < 10000) //偵測手離開感應點
  {
    touch_QR=false;
    if(input_QR == true)
    {              
      Keyboard.release(QRKey);
      delay(10);
      input_QR = false;                  
    }
  }
  

  
  if(touch4 < 10000 && touch5 < 10000 && touch6 < 10000 && touch7 < 10000 && touch8 < 10000 && touch9 < 10000 && touch10 < 10000 && touch11 < 10000 && touch12 < 10000)
  {
    if(op==false)
    {
      op=true;
      randNumber=random(2);
      Keyboard.press(opKey[randNumber]);
      Keyboard.release(opKey[randNumber]);
    }
  }
  delay(10); 
}
