#include<reg51.h>

sbit sw1=P2^7;
sbit sw2=P2^1;
sbit sw3=P2^6;
sbit sw4=P2^2;

int mode=1;
void delay(){
	int i,j;
	for(i=0;i<300;i++){
	 for(j=0;j<122;j++);
 }
 }
 
 void check_button(){
 if(sw1==0){
 while(sw1==0);
 mode=mode+1;
 if(mode>4){
 mode=1;
 }
 }	 
 else if(sw3==0){
	 while(sw3==0);
		 mode=mode-1;
		 if(mode<1){
			 mode=4;
		 }
 }
  P1=0x00;
}
 void main(){
 int count;
 
 sw1=1;
 sw2=0;
	 sw3=1;
	 sw4=0;
 
 P1=0x00;
 
 while(1){
 if(mode==1){
 check_button();
 P1=0x02;
 delay();
 check_button();
 P1=0x04;
 delay();
 check_button();
 P1=0x08;
 delay();
 check_button();
 P1=0x10;
 delay();
 }
 
 else if(mode==2){
 for(count=0;count<16;count=count+1){
 check_button();
 if(mode!=2)
 break;
 
 P1=(count*2);
 delay();
 }
 }
 
 else if(mode==3){
 check_button();
 P1=0x0A;
 delay();
 check_button();
 P1=0x14;
 delay();
 }
 
 else if(mode==4){
 check_button();
 P1=0x1E;
 delay();
 check_button();
 P1=0x00;
 delay();
 }
 }
 }