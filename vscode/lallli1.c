#include<stdio.h>

void calculator(){
    char T;
    printf("enter which temp conversion\nC(Celsius) or F(Farenheit)\t");
    scanf(" %c ",&T);

    switch(T){
       case 'C':{
          float c;
       printf("enter C value\t");
          scanf("%f",&c);
          double f=(9*c/5)+32;
          printf("%f C in farenheit is %lf F", c,f);
          break;
       }
       case 'F':{
          float fa;
          printf("enter F value\t");
          scanf("%f",&fa);
          double ce=5*(fa-32)/9;
          printf("%f F in celcius is %lf C", fa,ce);
          break;
       }
       default:
       printf("\nEnter C or F for celsius or farenheit!");
       break;
       }

}


int main(){
   char key;
   do{
      calculator();
      printf("\nenter y or n\t");
      scanf("%s",&key);
   }while(key=='y');
   return 0;
}