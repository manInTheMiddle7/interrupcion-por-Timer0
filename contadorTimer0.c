#include <18F4620.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
//#use FAST_IO(ALL)
int16 contador100MiliSegundos=0;
int16 contador500MiliSegundos=0;
int16 contador1000MiliSegundos=0;
int16 contador1500MiliSegundos=0;
unsigned int8 ledsContador100=128;
unsigned int8 ledsContador500=128;
unsigned int8 ledsContador1000=128;
unsigned int8 ledsContador1500=128;

#int_timer0
void timer0(){ 
   contador100MiliSegundos++;
   contador500MiliSegundos++;
   contador1000MiliSegundos++;
   contador1500MiliSegundos++;
   //
   if(contador100MiliSegundos==100)
   {
      output_a(ledsContador100);
      ledsContador100>>=1;
       if(ledsContador100==0)
       {          
          ledsContador100=128;          
       }
     contador100MiliSegundos=0;
   }
   //
   if(contador500MiliSegundos==500)
   {
      output_b(ledsContador500);
      ledsContador500>>=1;
       if(ledsContador500==0)
       {          
          ledsContador500=128;          
       }        
      contador500MiliSegundos=0;
   }
   //
   if(contador1000MiliSegundos==1000)
   {
      output_c(ledsContador1000);
      ledsContador1000>>=1;
       if(ledsContador1000==0)
       {          
          ledsContador1000=128;          
       }
      contador1000MiliSegundos=0;   
   }
   //
   if(contador1500MiliSegundos==1500)
   {
      output_d(ledsContador1500);
      ledsContador1500>>=1;
       if(ledsContador1500==0)
       {          
          ledsContador1500=128;          
       }
      contador1500MiliSegundos=0;   
   }
}

void main(){
set_tris_a(0x00);
set_tris_b(0x00);
set_tris_c(0x00);
set_tris_d(0x00);
//setup_oscillator(OSC_NORMAL);
setup_timer_0(RTCC_INTERNAL|RTCC_DIV_16|RTCC_8_BIT);
SET_TIMER0(131);
enable_interrupts(INT_TIMER0); // Habilitamos la interrupción que deseamos
enable_interrupts(GLOBAL); //Habilita interrupcion global 

while(TRUE);

}
