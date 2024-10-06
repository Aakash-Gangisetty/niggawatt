#include<stdio.h>
#include<stdlib.h>
#include<time.h>//added this library so that srand uses the time to give a random value 

int comp_pick();//computer will choose 1(rock), 2(paper), or 3(scissors) at random

int main(){
    printf("game of Rock Paper Scissors\nBest of 3\n");
    int player_count=0;
    int comp_count=0;

    do{
        int player;
       printf("Comp VS Player:\nEnter 1(rock), 2(paper) or 3(scissors): ");
       scanf("%d", &player);  //player pick rock, paper or scissors

       switch(comp_pick()){  //tells us what the computert played
        case 1:
        printf("Comp played rock\n\n");
        break;
        case 2:
        printf("Comp played paper\n\n");
        break;
        case 3:
        printf("Comp played scissors\n\n");
       }

       if(player==comp_pick()+1){  //if player plays a move whose value is just greater by 1 than what the computer played, he wins the round 
        player_count++;
       }
       else if(player==comp_pick()-1){ //if player plays a move whose value is just lesser by 1 than what the computer played ,Comp wins the round
        comp_count++;
       }
       else if(player==comp_pick()-2){ //if player plays a move whose value is just lesser by 2 than what the computer played ,player wins the round
        player_count++;
       }
       else if(player==comp_pick()+2){ //if player plays a move whose value is just greater by 2 than what the computer played ,Comp wins the round
        comp_count++;
       }
       else{  //if its a tie both of them win the round
        comp_count++;
        player_count++;
       }

       if(comp_count+player_count==2){
       /* if(comp_count>player_count){
            printf("Computer wins!:\n");
            break;
        }
        if(player_count>comp_count){
            printf("Player wins!\n");
            break;
        }*/    //is wrong as even if the second round is a tie depending on who one the first round it will just tell they won and stop
       }       //actually its not wrong but it feels weird to end a match just because you won one round and got a tie in the next sooo.....
               //yeah it is correct but ehhh.
    }while((player_count+comp_count)<3);

    if(player_count>comp_count){
        printf("Player wins!\n");
    }
    else if(comp_count>player_count){
        printf("Computer wins!\n");
    }
    else printf("It's a tie\n");
    int off;
    printf("Enter a number to close the game: "); //this line is just to see the result you got in the executable. Otherwise
    scanf("%d", &off);                            //it just closes after the task is done(at least if u coded it using vs-code)
    
}

int comp_pick(){
    srand(time(NULL)); //makes sure rand gives a different pattern of numbers each time the program is run
    return 1+rand()%3 ; //returns a random integer between 1 to 3
}