int prev_count_people=0;
long prev_seconds;
long prev_seconds2;


void telegram(){
  if(millis() != prev_seconds){
    prev_seconds=millis();
    if(Human_Counter_New > prev_count_people){
      bip1=true;
      prev_count_people=Human_Counter_New;
      Serial.println("Зайшов 1 чол.");
      Serial.println("Зараз людей: "+String(Human_Counter_New));    
      String msg0 = "Зайшов 1 чол.\n";
      msg0 += "Вдома: ";
      msg0 += Human_Counter_New;
      msg0 += " чол.\n";
      bot.sendMessage(CHAT_ID, msg0, "");
      sendtoweb(Human_Counter_New);
    }
    if(Human_Counter_New < prev_count_people){
      bip2=true;
      prev_count_people=Human_Counter_New;
      Serial.println("Вийшов 1 чол.");
      Serial.println("Зараз людей: "+String(Human_Counter_New));
      String msg0 = "Вийшов 1 чол.\n";
      msg0 += "Вдома: ";
      msg0 += Human_Counter_New;
      msg0 += " чол.\n";
      bot.sendMessage(CHAT_ID, msg0, "");
      sendtoweb(Human_Counter_New);
    }
    if(Ivalue>2 && Human_Counter_New==0 && ((millis()-prev_seconds2)>5000)){
      String msg0 = "Вдома нікого немає!\nА споживання струму: ";
      msg0 += Ivalue;
      msg0 += " А.\nВатт: ";
      msg0 += Ivalue*220;
      msg0 += " Вт/год.\n";
      bot.sendMessage(CHAT_ID, msg0, "");
      prev_seconds2=millis();
      }
  }
}
