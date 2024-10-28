/*Shopping cart trial one*/
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
	
  int n,add_it;
	int item_co[100];
	char item_n[100][100];
	int tot_co=0;
	int buff1,buff2;

  char user_name[100];
  int PIN, user_given_pin;
  char file_name[100];
  char transfer_acc[100];
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
      label1a:
      printf("Enter your username: ");
      scanf("%s", user_name);
      sprintf(file_name,"C:\\BANK_local_storage\\%s.txt",user_name);
      
			file = fopen(file_name, "r");
      if (file == NULL) 
      {
        printf("Looks like you don't actually have an account\n");
        goto label1a;
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
        setcolor(15);
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
      printf("To create an account, enter your desired username: ");
      label4:
      scanf("%s", user_name);
      sprintf(file_name, "C:\\BANK_local_storage\\%s.txt", user_name);
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
	
	printf("How many items would you like to add to your shopping cart?\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter your item %d with it's price beside it\n",i+1);
		scanf("%s %d",&item_n[i],&item_co[i]);
	}
	printf("would you like to review your cart?\npress 1 for yes\nor any other number for no\n");
	scanf("%d",&buff1);

	if(buff1==1)
	{
		for(int i=0;i<n;i++)
		{
			printf("%-20s %d\n",item_n[i],item_co[i]);
		}
	}
	label1:
	printf("would you want the bill now?\n1 for yes\n2 for i would like to add more items\n");
	scanf("%d",&buff2);

	switch(buff2)
	{
		case 2:
		{
			printf("how many additoinal items would you like to add?\n");
			scanf("%d",&add_it);
			buff2=n;
			n+=add_it;

			for(int i=buff2;i<n;i++)
			{
				printf("Enter your item %d with it's price beside it\n",i+1);
				scanf("%s %d",&item_n[i],&item_co[i]);
			}
		}
		goto label1;
		return 1;
		break;

		default:
		{
			for(int i=0;i<n;i++)
			{
				tot_co+=item_co[i];
			}
			printf("The final bill is:\n");
			for(int i=0;i<n;i++)
			{
				printf("%-20s %d\n",item_n[i],item_co[i]);
			}
			printf("total                %d\n",tot_co);
		}
		break;
	}

	printf("please re-enter your PIN to pay and completing the purchase.");
	scanf("%d",&PIN);
  if (user_given_pin!=PIN) 
  {
    setcolor(4);
    printf("The pin you've typed is incorrect lmao try again\n");
    setcolor(15);
    fclose(file);
  	return 1;
  }
	else if (user_given_pin==PIN)
	{
		if(tot_co<balance)
		{
      {
       withdraw=tot_co;
        {
          balance -= withdraw;
          setcolor(2);
          printf("An amount of %d has been taken from your account.\n%d is your balance now\n",withdraw,balance);
          setcolor(15);  
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
              fprintf(file, "\nAn amount of %d was withdrawn from %s on %02d/%02d/%04d at %02d:%02d:%02d for your cart",
              withdraw,user_name,time_info->tm_mday,time_info->tm_mon+1,time_info->tm_year+1900,time_info->tm_hour,time_info->tm_min,time_info->tm_sec);
            }
          } 	
        }		
		  }
	  }
    else if (tot_co > balance) //not enough money
    {
      setcolor(4);
      printf("\nyou're too broke for this shit.\n");
      setcolor(2);
      printf("would you like to credit some money with which you can complete the purchase\n1 for yes\n2 to cLose, your list will be saved\n");
      setcolor(15);
      scanf("%d",&buffer2);
      if(buffer2==1)
      {
        credit=balance-tot_co;
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
        }
      }
    } 
     
  }
}