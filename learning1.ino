int startLearningOdeToJoy(int progress)

{
int notes[]={3,3,4,5,5,4,3,2,1,1,2,3,3,2,2};//tones of Ode To Joy


int button=digitalRead(2);
float l0=analogRead(A0);
float l1=analogRead(A1);
float l2=analogRead(A2);
float l3=analogRead(A3);
float l4=analogRead(A4);
/*
  Serial.print(l0);
  Serial.print(l1);
  Serial.print(l2);
  Serial.print(l3);
  Serial.println(l4);
*/
//those codes help to check for the thershold

k0 = (l0<th)?1:0;
k1 = (l1<th)?1:0;
k2 = (l2<th)?1:0;
k3 = (l3<th)?1:0;
k4 = (l4<th)?1:0;
int key[]={k0,k1,k2,k3,k4};
freePlay();
      int ledPin = (notes[progress]<6)?(notes[progress]+2):(notes[progress]-3);
      //Serial.println(ledPin);
      if (notes[progress]<6)
      {
        digitalWrite(ledPin,HIGH);
        if ((key[ledPin-3]==0)&&(button==0))
        {
          progress++;
          digitalWrite(ledPin,LOW);
        }
      }
      else 
      {
        digitalWrite(ledPin,HIGH);
        digitalWrite(8,HIGH);
        if ((key[ledPin-3]==0)&&(button==1))
        {
          progress++;
          digitalWrite(ledPin,LOW);
          digitalWrite(8,LOW);
        }
      }

   if (progress==15)
   delay(200);
    //Serial.println(progress);
    return progress;
}
