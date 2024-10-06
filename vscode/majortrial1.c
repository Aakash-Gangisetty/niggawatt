/*A program to imitate a bank or basically a better atm*/
#include<stdio.h>
#include<string.h>
#include<windows.h>

void setcolor(int textcolor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textcolor);
}
int main() 

{
    char user_name[100];
    int PIN, user_given_pin;
    char file_name[100];
    int balance;
    int withdraw, credit;
    int user_answer,buffer1,buffer2;
    FILE *file;

    setcolor(15);
    printf("Do you have an existing account?\n1 for yes\n2 for no\n");
    label6:
    scanf("%d", &user_answer);
    
    switch(user_answer) 
    {
        case 1: 
        {
            printf("Enter your username: ");
            scanf("%s", user_name);
            sprintf(file_name,"C:\\BANK_local_storage\\%s.txt",user_name);
                file = fopen(file_name, "r");
            if (file == NULL) 
            {
                printf("Looks like you don't actually have an account\n");
                goto label1;
            }

            fscanf(file, "balance: %d\n", &balance);
            fscanf(file, "PIN: %d\n", &PIN);
            printf("Enter your 6-digit PIN: ");
            scanf("%d", &user_given_pin);

            if (user_given_pin!=PIN) 
            {
                setcolor(4);
                printf("The pin you've typed is incorrect lmao try again\n");
                fclose(file);
                return 1;
            }

            setcolor(2);
            printf("You are logged in now\n");
            setcolor(15);
            printf("Your current balance is: %d\n", balance);

            fclose(file);
            break;
        }
        case 2: 
        {
            label1:
            printf("To create an account, enter your desired username: ");
            label4:
            scanf("%s", user_name);
            sprintf(file_name, "C:\\BANK_local_storage\\%s.txt", user_name);
            file = fopen(file_name, "w");
            if (file==NULL) 
            {
                setcolor(2);
                printf("an error has occured(perhaps someone already used your username?),so try something else\n");
                setcolor(15);
                return 1;
                goto label4;
            }

            printf("Enter your desired six-digit PIN: ");
            scanf("%d", &PIN);
            balance=1000000;
            fprintf(file, "balance: %d\n", balance);
            fprintf(file, "PIN: %d\n", PIN);
            fclose(file);
            setcolor(2);
            printf("An account has been made\n");
            setcolor(15);
            break;
        }

        default:
            setcolor(4);
            printf("\ngimme a proper answer nigga\n\n");
            setcolor(15);
            goto label6;
            return 1;
    }
    label5:
    printf("Would you like withdraw, credit or transfer money?\n1 for withdraw\n2 for credit\n3 for transfer\n");
    scanf("%d", &buffer1);
    file = fopen(file_name, "r+");
    if (file == NULL) 
    {
        setcolor(4);
        printf("Error\n");
        setcolor(15);
        return 1;
        goto label5;
    }

    fscanf(file, "balance: %d\n", &balance);
    
    if (buffer1==1) 
    {
        printf("Your current balance is: %d\n", balance);
        printf("Please enter the amount you would like to withdraw: ");
        scanf("%d", &withdraw);

        if (withdraw > balance) 
        {
            setcolor(4);
            printf("\nyou're too broke for this.\n\n");
            setcolor(15);
            goto label5;
        } 
        else 
        {
            balance -= withdraw;
            setcolor(2);
            printf("you have succuessfully withdrawn %d, Your new balance is: %d\n",withdraw,balance);
            setcolor(15);
            printf("would you like to make another transaction?\npress\n1 for yes\n2 to close\n");
            scanf("%d",&buffer2);
            if(buffer2==1)
            {
                goto label5;
            }
        }

    } 
    else if (buffer1==2) 
    {
        printf("Please enter the amount you would like to credit: ");
        scanf("%d", &credit);
        balance += credit;
        setcolor(2);
        printf("you have successfully credited %d, Your new balance is: %d\n\n",credit,balance);
        setcolor(15);
        printf("would you like to make another transaction?\npress \n1 for yes\n2 to close\n");
        scanf("%d",&buffer2);
        if(buffer2==1)
        {
            goto label5;
        }
    } 
    else if (buffer1==3)
    {
        setcolor(4);
        printf("\nThis is under develeopment please go fuck yourself\n\n");
        setcolor(15);
        goto label5;
    }
    else 
    {
        printf("\ngimme a proper answer nigga\n\n");
        goto label5;
    }
    rewind(file);
    fprintf(file, "balance: %d\n", balance);
    fprintf(file, "PIN: %d\n", PIN);

    fclose(file);
    setcolor(15);
    return 0;


}