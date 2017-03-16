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
