bool IR1_state_old=0;
bool IR2_state_old=0;
bool IR1_state_new=0;
bool IR2_state_new=0;

void counter() 
{
  if(analogRead(33)<1000){IR1_state_new=false;}
  else{IR1_state_new=true;}
  if(analogRead(32)<1000){IR2_state_new=false;}
  else{IR2_state_new=true;}

if(IR1_state_new != IR1_state_old || IR2_state_new != IR2_state_old) // изменение состояния
{
 if(IR1_state_new != IR1_state_old && IR2_state_new != IR2_state_old)
 {
  // одновременно изменилось состояние у обоих датчиков
  // определить направление невозможно
 }
 else
 {
  if(IR2_state_new != IR2_state_old)
  {
   if(IR2_state_new == 1 && IR1_state_new == 1)
   {
    Human_Counter_New++;
  // человек заходит, но пока находиться в проходе
   }
   if(IR2_state_new == 0 && IR1_state_new == 1)
   {
    Human_Counter_New--;
    // человек находился в проходе, выходит из комнаты
   }
  }
 }
IR1_state_old=IR1_state_new;
IR2_state_old=IR2_state_new;
}
if ( Human_Counter_New < 0 ) { Human_Counter_New = 0; }
}
