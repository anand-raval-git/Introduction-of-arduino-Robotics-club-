//put this code in the ide of Arduino from this line  
       void setup()  
      {  
       pinMode(A2,OUTPUT);  
       pinMode(A3,OUTPUT);  
       }  
       void loop()  
       {  
       analogWrite(A2,50); // Clock wise direction of motor 
       analogWrite(A3,50);  
       delay(1000);  
       analogWrite(A2,100); // Anti clock wise direction of motor  
       analogWrite(A3,100);  
       delay(1000);  
       }  

