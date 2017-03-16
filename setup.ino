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
