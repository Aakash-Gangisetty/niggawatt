/*A program to imitate a bank or basically a better atm*/
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>

void setcolor(int textcolor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textcolor);
}
int main() 
{
    time_t current_time;
    struct tm *time_info;
    
    char user_name[100];
    int PIN, user_given_pin;
    char file_name[100];
    char transfer_acc[100];
    char transfer_file[100];
    int transfer_amo;
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
        case 1: //existing account
        {
            printf("Enter your username: ");
            scanf("%s", user_name);
            sprintf(file_name,"C:\\Users\\gangi\\OneDrive\\Desktop\\stuff\\School\\vscode\\local_storage\\ATM\\%s.txt",user_name);
                file = fopen(file_name, "r");
            if (file == NULL) 
            {
                printf("Looks like you don't actually have an account\n");
                goto label1;
            }

            fscanf(file, "balance: %d\n", &balance);
            fscanf(file, "PIN: %d\n", &PIN);
            printf("Enter your 6-digit PIN: ");
            label9:
            scanf("%d", &user_given_pin);

            if (user_given_pin!=PIN) 
            {
                setcolor(4);
                printf("The pin you've typed is incorrect lmao try again\n");
                fclose(file);
                goto label9;
                return 1;
            }

            setcolor(2);
            printf("You are logged in now\n");
            setcolor(15);
            printf("Your current balance is: %d\n", balance);

            fclose(file);
            break;
        }
        case 2: //no account
        {
            label1:
            printf("To create an account, enter your desired username: ");
            label4:
            scanf("%s", user_name);
            sprintf(file_name, "C:\\Users\\gangi\\OneDrive\\Desktop\\stuff\\School\\vscode\\local_storage\\ATM\\%s.txt", user_name);
            file = fopen(file_name, "w");
            if (file==NULL) 
            {
                setcolor(4);
                printf("an error has occured(perhaps someone already used your username?),so try something else\n");
                setcolor(15);
                return 1;
                goto label4;
            }

            printf("Enter your desired six-digit PIN: ");
            scanf("%d", &PIN);
            balance=1000000;//setting default balance
            fprintf(file, "balance: %d\n", balance);
            fprintf(file, "PIN: %d\n", PIN);
            fprintf(file, "\nHistory:\n");
            fclose(file);
            setcolor(2);
            printf("An account has been made\n");
            setcolor(15);
            break;
        }

        default: //gave a non expentent answer
        {
            setcolor(4);
            printf("\ngimme a proper answer nigga\n\n");
            setcolor(15);
            goto label6;
            return 1;
        }
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
    
    if (buffer1==1) //requested withdraw
    {
        printf("Your current balance is: %d\n", balance);
        printf("Please enter the amount you would like to withdraw: ");
        scanf("%d", &withdraw);

        if (withdraw > balance) //not enough money
        {
            setcolor(4);
            printf("\nyou're too broke for this shit.\n\n");
            setcolor(15);
            goto label5;
        } 
        else //enough money
        {
            balance -= withdraw;
            setcolor(2);
            printf("you have succuessfully withdrawn %d, Your new balance is: %d\n",withdraw,balance);
            
            rewind(file);
            fprintf(file, "balance: %d\n", balance);
            fprintf(file, "PIN: %d\n", PIN);
            fclose(file);

            if(withdraw!=0)
            {
                setcolor(14);
                printf("You're transaction has been saved at:\n %s\n", file_name);
                setcolor(15);
            
                fopen(file_name, "a");
                {
                    time(&current_time);
                    time_info = localtime(&current_time);
                    fprintf(file, "\nAn amount of %d was withdrawn from %s on %02d/%02d/%04d at %02d:%02d:%02d",
                    withdraw,user_name,time_info->tm_mday,time_info->tm_mon+1,time_info->tm_year+1900,time_info->tm_hour,time_info->tm_min,time_info->tm_sec);
                }
            }    
            fclose(file);
            printf("would you like to make another transaction?\npress\n1 for yes\n2 to close\n");
            scanf("%d",&buffer2);

            if(buffer2==1)
            {
                goto label5;
            }
        }

    } 
    else if (buffer1==2) //requested credit
    {
        label8:
        printf("Please enter the amount you would like to credit: ");
        scanf("%d", &credit);
        balance += credit;
        setcolor(2);
        printf("you have successfully credited %d, Your new balance is: %d\n\n",credit,balance);
        
        rewind(file);
        fprintf(file, "balance: %d\n", balance);
        fprintf(file, "PIN: %d\n", PIN);
        fclose(file);
        
        if(credit!=0)
        {
            setcolor(14);
            printf("You're transaction has been saved at\n %s\n", file_name);
            setcolor(15);
            fopen(file_name, "a");
            {
                time(&current_time);
                time_info = localtime(&current_time);
                fprintf(file, "\nAn amount of %d was credited to %s on %02d/%02d/%04d at %02d:%02d:%02d",
                credit,user_name,time_info->tm_mday,time_info->tm_mon+1,time_info->tm_year+1900,time_info->tm_hour,time_info->tm_min,time_info->tm_sec);
            }
        }
        fclose(file);
        
        printf("would you like to make another transaction?\npress \n1 for yes\n2 to close\n");
        scanf("%d",&buffer2);
        if(buffer2==1)
        {
            goto label5;
        }
    } 
    else if (buffer1==3) //requested transfer
    {
        printf("which account do you want to transfer money to?\n");
        label7:
        scanf("%s",transfer_acc);
        sprintf(transfer_file,"C:\\Users\\gangi\\OneDrive\\Desktop\\stuff\\School\\vscode\\local_storage\\ATM\\%s.txt",transfer_acc);
        fopen(transfer_file, "r+");
        if(file==NULL)
        {
            setcolor(4);
            printf("account not found please enter a valid account\nplease try again\n");
            setcolor(15);
            goto label7;
        }
        else if(file!=NULL)
        {
        printf("What amount of money would you like to tranfer to this account?\n");
        scanf("%d",&transfer_amo);
        fclose(file);
        fopen(file_name, "r+");
        fscanf(file, "balance: %d", &balance);
        
        if(transfer_amo<=balance)
        {
            balance-=transfer_amo;

            setcolor(2);
            rewind(file);
            fprintf(file, "balance: %d\n", balance);
            fclose(file);printf("An amount of %d has been transfered from",transfer_amo);
            printf(" %s to %s\n",user_name,transfer_acc);
            setcolor(15);
            printf("your new balance is %d\n",balance);
            file = fopen(transfer_file, "r+");

            rewind(file);
            fscanf(file, "balance: %d\n", &balance);
            
            balance+=transfer_amo;
            
            fprintf(file, "balance: %d", balance);

            rewind(file);
            fprintf(file, "balance: %d\n", balance);
            fprintf(file, "PIN: %d\n", PIN);
            fclose(file);

            if(transfer_amo!=0)
            {
                setcolor(14);
                printf("You're transaction has been saved at\n %s\n", file_name);
                setcolor(15);

                fopen(file_name, "a");
                {
                    time(&current_time);
                    time_info = localtime(&current_time);
                    fprintf(file, "\nAn amount of %d was transferred from %s to %s on %02d/%02d/%04d at %02d:%02d:%02d",
                    transfer_amo,user_name,transfer_acc,
                    time_info->tm_mday,time_info->tm_mon+1,time_info->tm_year+1900,time_info->tm_hour,time_info->tm_min,time_info->tm_sec);
                }   
                fclose(file);
                fopen(transfer_file, "a");
                {
                    time(&current_time);
                    time_info = localtime(&current_time);
                    fprintf(file, "\nAn amount of %d was transferred from %s to you on %02d/%02d/%04d at %02d:%02d:%02d",
                    transfer_amo,user_name,
                    time_info->tm_mday,time_info->tm_mon+1,time_info->tm_year+1900,time_info->tm_hour,time_info->tm_min,time_info->tm_sec);
                }
            }
        }
        else
        {
            setcolor(4);
            printf("you're too broke for this\n");
            setcolor(15);
            printf("would like you to credit money to your account first?\n1 for yes\n2 to close\n");
            scanf("%d", user_answer);
            if(user_answer==1)
            {
                goto label8;
            }
        }
        }
        printf("would you like to make another transaction?\npress \n1 for yes\n2 to close\n");
        scanf("%d",&buffer2);
        if(buffer2==1)
        {
            goto label5;
        }
    }
    else //gave a weird answer
    {
        printf("\ngimme a proper answer nigga\n\n");
        goto label5;
    }

    return 0;

}