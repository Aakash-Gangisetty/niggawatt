/*reverse of a number*/
#include <stdio.h>
int reverseNumber(int num) {
    int reverse = 0;
    
    while (num != 0) {
        int digit = num % 10;  
        reverse = reverse * 10 + digit;  
        num /= 10;  
    }
    
    return reverse;
}

int main() {
    int num;
    
    printf("Enter a number to find its reverse: ");
    scanf("%d", &num);
    printf("The reverse of %d is %d.\n", num, reverseNumber(num));
    
    return 0;
}
