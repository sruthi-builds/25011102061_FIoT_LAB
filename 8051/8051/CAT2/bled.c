#include<stdio.h>
#include<reg51.h>               
#include "delay.h"

sbit ledpin=P1^7;                
 
void main(){
	while(1){
	   ledpin=1;             
	   delay();            
	   ledpin=0;            
	   delay();              
	}
 }