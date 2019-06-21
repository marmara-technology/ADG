int acil_durum = 0;
int adb = 13;
int i;
int a=0;
int buzzer = 7;
int ambulans_kirmizi_led = 6;
int ambulans_mavi_led = 5;
 void setup() {
  pinMode(adb,INPUT);
  pinMode(ambulans_kirmizi_led,OUTPUT);
  pinMode(ambulans_mavi_led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  
}
void loop () {
Serial.println("low");
acil_durum = digitalRead(adb);  
delay(100);
  if (acil_durum == HIGH) 
  {
     if (acil_durum == HIGH) 
    delay(3000);
    acil_durum = digitalRead(adb);
     if (acil_durum == HIGH) { 
    Serial.println("high");
 sess();
 
      
  }
  
}  
}
void ambulans()
{
for(i=0;i<4;i++){
digitalWrite(ambulans_kirmizi_led,HIGH);
delay(20);
digitalWrite(ambulans_kirmizi_led,LOW);
delay(20);
digitalWrite(ambulans_mavi_led,HIGH);
delay(20);
digitalWrite(ambulans_mavi_led,LOW);
delay(20);
}
}
void sess()
{
 ambulans();
  for(a=700;a<800;a++)
  {
    if (a == 750) ambulans();
  tone(7,a);
  delay(15);
  
  }
  ambulans();
  
  for(a=800;a>700;a--)
  {
    if (a == 750) ambulans();
  tone(7,a);
  delay(15);
   }
 acil_durum = digitalRead(adb);
 delay(100);
 if(acil_durum == LOW) {
  delay(2000);
  acil_durum = digitalRead(adb);
   if (acil_durum == LOW) noTone(7)
 }

}
