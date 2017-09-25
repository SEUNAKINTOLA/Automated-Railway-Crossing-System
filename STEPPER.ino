    /*
       BYJ48 Stepper motor code
       Connect :
       IN1 >> D8
       IN2 >> D9
       IN3 >> D10
       IN4 >> D11
       VCC ... 5V Prefer to use external 5V Source
       Gnd
       written By :Mohannad Rawashdeh    
      */





    #define IN1  11
    #define IN2  10
    #define IN3  9
    #define IN4  8



    int Steps = 0;
    boolean Direction = true;// gre
    unsigned long last_time;
    unsigned long currentMillis ;
    int steps_left=1095;
    long time1;
    int sensor = 2;
    int sensorState =1;
    int k;
    void setup()
    {
      

    Serial.begin(9600);
    pinMode(IN1, OUTPUT); 
    pinMode(IN2, OUTPUT); 
    pinMode(IN3, OUTPUT); 
    pinMode(IN4, OUTPUT); 
    // delay(1000);

    }
    void loop()
    {
 
          pinMode(sensor, INPUT); 
           sensorState = digitalRead(sensor);

         Serial.println(sensorState);
       
      if(sensorState == 0){ 
    k=2;
        
             loopss();
             delay(100);
}
  else {
   Serial.println("ant");
  }
    }



void loopss(){
    while (k>0)
    {
      while(steps_left>0){
      currentMillis = micros();
      if(currentMillis-last_time>=1000){
      stepper(1); 
      time1=time1+micros()-last_time;
      last_time=micros();
      steps_left--;
      }
      }
       Serial.println(time1);
      Serial.println("Wait...!");
      delay(1200);
      Direction=!Direction;
      steps_left=1095;
         k = k -1;
    }
 
}



    void stepper(int xw){
      for (int x=0;x<xw;x++){
    switch(Steps){
       case 0:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, HIGH);
       break; 
       case 1:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, HIGH);
       break; 
       case 2:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, LOW);
       break; 
       case 3:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, LOW);
       break; 
       case 4:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
       break; 
       case 5:
         digitalWrite(IN1, HIGH); 
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
       break; 
         case 6:
         digitalWrite(IN1, HIGH); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
       break; 
       case 7:
         digitalWrite(IN1, HIGH); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, HIGH);
       break; 
       default:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
       break; 
    }
    SetDirection();
    }
    } 
    void SetDirection(){
    if(Direction==0){ Steps++;}
    if(Direction==1){ Steps--; }
    if(Steps>7){Steps=0;}
    if(Steps<0){Steps=7; }
    }
