#include<stdio.h>

void calculator(){
    char T;
    printf("Enter which temp conversion\nC (Celsius) or F (Fahrenheit):-\t");
    scanf(" %c", &T);

     switch(T){
      case 'C': {
         float c;
         printf("Enter Celsius value:\t");
         scanf("%f", &c);
         double f = (9 * c / 5) + 32;
         printf("%f C in Fahrenheit is %lf F\n", c, f);
         break;
      }
       case 'F': {
         float fa;
         printf("Enter Fahrenheit value:\t");
         scanf("%f", &fa);
         double ce = 5 * (fa - 32) / 9;
         printf("%f F in Celsius is %lf C\n", fa, ce);
         break;
      }
      default:
         printf("\nEnter 'C' or 'F' for Celsius or Fahrenheit!\n");
         break;
     }

}


int main(){
    char key;
    do {
        calculator();
        printf("\nDo you want to use the temp conversion calculator again?");
        printf("\nenter y(for yes) or n(for no)\t");
        scanf("%s", &key);
    }while(key == 'y');

    return 0;
}
