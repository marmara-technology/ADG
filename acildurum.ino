int cevap1 =0;
int cevap2 =0;
int acil_durum = 0;
long uzaklik1;
long uzaklik2;
int yol;
int sensor1_cikis=2;
int sensor2_cikis=3;
int ambulans_kirmizi_led=4;

int ambulans_mavi_led=6;
int buzzer=7;
int trig1=8;
int echo1=9;
int trig2=10;
int echo2=11;

int adb = 13;
int i;
int a=0;

long cm1,cm2,inc1,inc2;

 void setup() {
  Serial.begin(9600);
  pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(adb,INPUT);
  pinMode(sensor1_cikis,OUTPUT);
  pinMode(sensor2_cikis,OUTPUT);
  pinMode(ambulans_kirmizi_led,OUTPUT);
  pinMode(ambulans_mavi_led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
}
void loop () {

acil_durum = digitalRead(adb);  
  if (acil_durum == HIGH) 
  {
  ambulans();
    
    //ses();  
    konumkontrol1();
    konumkontrol2();
   
    if(uzaklik1>0 && uzaklik1 < 10)
      {
      digitalWrite(sensor1_cikis,HIGH); 
      digitalWrite(sensor2_cikis,LOW); 
      
      }
     if ( uzaklik1>10)
      {       
  if(uzaklik2>0 && uzaklik2 < 10)
      {
      digitalWrite(sensor2_cikis,HIGH);
      digitalWrite(sensor1_cikis,LOW); 
      }
   else if ( uzaklik2>10 || uzaklik1>10 )
      {
          digitalWrite(sensor1_cikis,LOW); 
          digitalWrite(sensor2_cikis,LOW); 
      }
      
  }
  
}  
}
int konumkontrol1() {
 
digitalWrite(trig1,LOW);
delayMicroseconds(5);
digitalWrite(trig1,HIGH);
delayMicroseconds(10);
digitalWrite(trig1,LOW);
cevap1 = pulseIn(echo1, HIGH);
uzaklik1 = cevap1 /29.1/2;
Serial.println("Uzaklik ");  
 Serial.println(uzaklik1);
delayMicroseconds(200);

return uzaklik1;
}

int konumkontrol2() {
 
digitalWrite(trig2,LOW);
delay(2);
digitalWrite(trig2,HIGH);
delay(10);
digitalWrite(trig2,LOW);
cevap2 = pulseIn(echo2, HIGH);
uzaklik2 = cevap2 /29.1/2;
Serial.println("İkinci sensör Uzaklik ");  
  Serial.println(uzaklik2);
  delay(200);

return uzaklik2;
}
void ambulans()
{
for(i=0;i<4;i++){
digitalWrite(ambulans_kirmizi_led,HIGH);
delay(100);
digitalWrite(ambulans_kirmizi_led,LOW);
delay(100);
digitalWrite(ambulans_mavi_led,HIGH);
delay(100);
digitalWrite(ambulans_mavi_led,LOW);
delay(100);
}
}
void ses()
{
 
  for(a=700;a<800;a++)
  {
  tone(7,a);
  delay(15);
  
  }
  //  ambulans();
  
  for(a=800;a>700;a--)
  {
    
  tone(7,a);
  delay(15);
   }
 acil_durum = digitalRead(adb);
 if(acil_durum == LOW) noTone(7);

}
