//********************revised borrowed code*********************
#define Cd 262
#define CSd 277
#define Dd 294
#define DSd 311
#define Ed 330
#define Fd 349
#define FSd 370
#define Gd 392
#define GSd 415
#define Ad 440
#define ASd 466
#define Bd 494
#define Cf 523
#define CSf 554
#define Df 587
#define DSf 622
#define Ef 659
//The original code was using C4-E5. However, this cause my sensors
//don't work properly. Not sure why...
//Author:gunpole
//Source：guokr
//Link：http://www.guokr.com/article/7848/
//***************************************************************
const int S_a=0;
const int S_b=1;
const int S_c=2;
const int S_d=3;
const int S_e=4;
const int S_f=5;
const int S_g=6;
const int S_x=7;
const int S_y=8;
const int S_i=9;


const int buzzerPin=9;

int scale[]={Cd,Dd,Ed,Fd,Gd,Ad,Bd,Cf,Df,Ef};
float l0=0;
float l1=0;
float l2=0;
float l3=0;
float l4=0;
int k0=0;
int k1=0;
int k2=0;
int k3=0;
int k4=0;
const int th=1000;
int button=0;

int progress=0;

void setup() 
{
  // put your setup code here, to run once:
   pinMode(buzzerPin,OUTPUT);
   pinMode(2,INPUT);
   pinMode(A0, INPUT);
   pinMode(A1, INPUT);
   pinMode(A2, INPUT);
   pinMode(A3, INPUT);
   pinMode(A4, INPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(8, OUTPUT);
   
   Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  static int state = S_a;
  
  //store the user's choice
  static unsigned int choice;
  
 
  switch (state)
  {
    case S_a:
      Serial.println("Please Choose a Model:");
      Serial.println("1 for Playing Model, 2 for Learning Model:");
      progress=0;
      noTone(buzzerPin);

      state=S_b;
      
      break;

    case S_b:
      choice = Serial.read()-48;

      if(choice==1)
      state=S_c;
      else if(choice==2)
      state=S_d;
      else
      {
        state=S_b;
      }
      
      break;

    case S_c:
      Serial.println("You Choosed Playing Model ");
      Serial.println("Touch The Sensor To Play~");
      Serial.println("press 1 to reset");
 

      state=S_i;
      
      break;
      
    case S_d:
      Serial.println("You Choosed Learning Model ");
      Serial.println("Choose a Song You Want to Learn:");
      Serial.println("1: Ode to Joy; 2: Edelweiss");
      
      state=S_e;
      
      break;

    case S_e:
      choice = Serial.read()-48;

      if(choice==1)
      state=S_f;
      else if(choice==2)
      state=S_g;
      else
      {
        state=S_e;
      }
      
      break;

    case S_f:
      Serial.println("You Choosed to Learn Ode to Joy");
      state=S_x;
      
      break;
       
    case S_g:
      Serial.println("You Choosed to Learn Edelweiss");
      state=S_y;
      
      break;   

    case S_x:
    
    progress=startLearningOdeToJoy(progress); 
   // Serial.print(progress); 
      if (progress>=15)
        state=S_a;
      else state=S_x;
 
      break; 

    case S_y:
    progress=startLearningEdelweiss(progress);
      if (progress>=26)      
        state=S_a;
 
      break; 

    case S_i:
      choice = Serial.read()-48;
      freePlay();
      if(choice==1)
      state=S_a;
      else
      {
        state=S_i;
      }
      
      break;    
  }

  
}
 
int startLearningOdeToJoy(int progress)
//没有声音,可以尝试call free play,或者额外加
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

int startLearningEdelweiss(int progress)
{
    int notes[]={3,5,9,8,5,4,3,3,3,4,5,6,5,3,5,9,8,5,4,3,5,5,6,7,8,8};
    //tones of Edelweiss



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
        if ((key[ledPin-3]==0)&&(button==1))//或者button等于0,需要测试
        {
          progress++;
          digitalWrite(ledPin,LOW);
          digitalWrite(8,LOW);
        }
      }
      if (progress==26)
      delay(200);

   
    //Serial.println(progress);
    return progress;
}

void freePlay()
{
//const int buzzerPin=9;
//
//int scale[]={Cd,Dd,Ed,Fd,Gd,Ad,Bd,Cf,Df,Ef};
//int k0=0;
//int k1=0;
//int k2=0;
//int k3=0;
//int k4=0;
//int th=990;
  
  int button=digitalRead(2);
  float l0=analogRead(A0);
  float l1=analogRead(A1);
  float l2=analogRead(A2);
  float l3=analogRead(A3);
  float l4=analogRead(A4);

  Serial.print(l0);
  Serial.print(l1);
  Serial.print(l2);
  Serial.print(l3);
  Serial.println(l4);

  k0 = (l0<th)?1:0;
  k1 = (l1<th)?1:0;
  k2 = (l2<th)?1:0;
  k3 = (l3<th)?1:0;
  k4 = (l4<th)?1:0;

  if(button==0)
{
  if (k0==0) tone(buzzerPin,scale[0]);
  else  if (k1==0) tone(buzzerPin,scale[1]);
  else  if (k2==0) tone(buzzerPin,scale[2]);
  else  if (k3==0) tone(buzzerPin,scale[3]);
  else  if (k4==0) tone(buzzerPin,scale[4]);
  else if(k0&k1&k2&k3&k4==1) noTone(buzzerPin);
}
else
{
  if (k0==0) tone(buzzerPin,scale[5]);
  else  if (k1==0) tone(buzzerPin,scale[6]);
  else  if (k2==0) tone(buzzerPin,scale[7]);
  else  if (k3==0) tone(buzzerPin,scale[8]);
  else  if (k4==0) tone(buzzerPin,scale[9]);
  else if(k0&k1&k2&k3&k4==1) noTone(buzzerPin);
}

}

