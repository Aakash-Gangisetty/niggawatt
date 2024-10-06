#include <stdio.h>
#include <math.h>

int isEven(int num) {
    return num % 2 == 0;
}
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

    int isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int n = countDigits(num);
    
    while (num != 0) {
        int digit = num % 10;
        sum += pow(digit, n);  
        num /= 10;
    }
   
    return (sum == originalNum);
}

int main() {
    int num;
    
    printf("Enter an even number: ");
    scanf("%d", &num);
    
    if (!isEven(num)) {
        printf("%d is not an even number.\n", num);
        return 0;
    }


    if (isArmstrong(num)) {
        printf("%d is an even Armstrong number.\n", num);
    } else {
        printf("%d is an even number but not an Armstrong number.\n", num);
    }
    
    return 0;
}
