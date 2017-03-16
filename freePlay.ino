void freePlay()
{
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

