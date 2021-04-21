unsigned long bipstart;
unsigned long bipbipstart;
boolean bip1=false;
boolean bip2=false;

void bip(){
  if(bip1==true){
    bipstart=millis();
    digitalWrite(14, HIGH);
    bip1=false;
  }
  if((millis()-bipstart)>200 && (millis()-bipstart)<250){
    digitalWrite(14, LOW);
  }
  
  if(bip2==true){
    bipbipstart=millis();
    digitalWrite(14, HIGH);
    bip2=false;
  }
  if((millis()-bipbipstart)>200 && (millis()-bipbipstart)<250){
    digitalWrite(14, LOW);
  }
  if((millis()-bipbipstart)>250 && (millis()-bipbipstart)<450){
    digitalWrite(14, HIGH);
  }
  if((millis()-bipbipstart)>450 && (millis()-bipbipstart)<500){
    digitalWrite(14, LOW);
  }
}
