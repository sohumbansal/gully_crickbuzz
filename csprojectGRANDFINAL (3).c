#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int run=0;                         //global variables run and wicket used to store information about each player
int wicet=0;
int target=-1;

typedef struct player playerinfo;   //to store information about each player
struct player{
    char name[20];
    int runs,ballsplayed,four,six,wickets,oversbowled,runsgiven,ballsbowled;
   };
void toss(char call[])             //function responsible for simulating toss
{
    srand(time(0));                //this function gives the value of a as a random integer than based on whether it is odd or even,
    int a=rand()%2;                //we declare if the toss result is heads or tails
    char result[4];
    if(a==0)
    {
        result[0]='h';
        result[1]='e';
        result[2]='a';
        result[3]='d';
    }
    else
    {
        result[0]='t';
        result[1]='a';
        result[2]='i';
        result[3]='l';
    }
    printf("Toss Result: ");
    for(int i=0;i<4;i++)
    {
        printf("%c",result[i]);
    }
    char choice[4];
    if(call[0]==result[0])
    {
        printf("\nYou won the toss!\n");           
        printf("Sir, what do you choose (bat/bowl): ");    
        scanf("%s",choice);
    }
    else
    {
        printf("\nYou lost the toss!\n");
        printf("Student, what do you choose (bat/bowl): ");
        scanf("%s",choice);
    }
    printf("So, team1 will bat first.\n");
}
void innings(playerinfo team1[], playerinfo team2[], int overs, int n){
    int mainruns=0;                                                    // function to record the data of innings
    int wickets=0;
    int count = n-1;
    int b1=0;
    int b2=1;
    int next=2;
    playerinfo a=team1[b1];
    playerinfo b=team1[b2];
    playerinfo c=team2[count];
    a.ballsplayed=0;
    a.runs=0;
    b.ballsplayed=0;
    b.runs=0;
    int flag=-1;
    int d;
    for (int i = 1; i <= overs; i++)                                     //loop for doing calculations and maintaining scoreboard of batsmen
    {   d=0;
        printf("Over no.%d\n" ,i);
        printf("Bowler name %s\n" , team2[count].name);
       
        for (int j = 1; j <= 6; j++)
        {   team2[count].ballsbowled++;
            printf("Enter the input ball number %d:- " , j);
            char input;
            scanf(" %c", &input);
            if (flag==1 && d==0)
            {d++;
                switch(input){                                            //switch case is used for diffrent possible cases
                case '0':b.ballsplayed++;
                        printf("dot ball, short outside off,left alone to the keeper\n");

                         break;
                case '1':b.runs++;
                        mainruns++;
                        printf("1 run, tuck towars deep midwicket\n");

                        team2[count].runsgiven+=1;
                        c.runsgiven++;
                        b.ballsplayed++;
                         flag*=-1;
                          break;
                case '2':b.runs+=2;
                        mainruns+=2;
                        team2[count].runsgiven+=2;
                       printf("2 runs, banged short on off from the wicket.\n");

                        c.runsgiven+=2;
                        b.ballsplayed++;
                          break;
                case '3':b.runs+=3;
                        mainruns+=3;
                        team2[count].runsgiven+=3;
                         printf("fielding ka bhut hi khrab pradarshan aur 3 run\n");

                        c.runsgiven+=3;
                        b.ballsplayed++;
                        flag*=-1;
                          break;
                case '4':b.runs+=4;
                        mainruns+=4;
                        b.four++;
                        printf("it's a four, straight drive and a boundary\n ");

                        team2[count].runsgiven+=4;
                        c.runsgiven+=4;
                        b.ballsplayed++;
                          break;
                case '6':b.runs+=6;
                        mainruns+=6;
                        b.six++;
                        team2[count].runsgiven+=6;
                         printf("bowler ke sir ke upar se CHHAKKA!!\n");

                        c.runsgiven+=6;
                        b.ballsplayed++;
                        break;
                case 'W':printf("OUT\n");
                        team2[count].wickets++;
                        printf("ballebazZZ ko pta bhi nahi chla or saare dande ud gye\n");

                        c.wickets++;
                        wickets++;
                        if (wickets==n-1)
                        {
                            break;
                        }
                        if (flag==-1)
                        {
                            a.ballsplayed++;
                            team1[b1].ballsplayed++;
                            team1[b1]=a;
                            b1=next;
                            a=team1[next];
                            next++;
                        }
                        else
                        {
                            b.ballsplayed++;
                            team1[b2].ballsplayed++;
                            team1[b2]=b;
                            b2=next;
                            b=team1[next];
                            next++;
                        }
                        break;
                case 'w':mainruns++;
                        team2[count].runsgiven+=1;
                        c.runsgiven+=1;
                        j--;
                        team2[count].ballsbowled--;
                        printf("it's a wide ball\n");

                        break;
                default : printf("INVALID INPUT\n");
                            j--;
                            team2[count].ballsbowled--;
                }
                team1[b1] = a;                                    // Update team1[b1] with the modified value of a
                team1[b2] = b;                                    // Update team1[b2] with the modified value of b
            }
            if (flag==-1 && d==0)
            {d++;
                switch(input){
                case '0':a.ballsplayed++;                                             //loop for doing calculations and maintaining scoreboard of bowlers
                        printf("dot ball, short outside off,left alone to the keeper\n");
                         break;
                case '1':a.runs++;
                        mainruns++;
                        printf("1 run, tuck towars deep midwicket\n");
                        team2[count].runsgiven+=1;
                        c.runsgiven+=1;
                        a.ballsplayed++;
                         flag*=-1;
                          break;
                case '2':a.runs+=2;
                        mainruns+=2;
                        team2[count].runsgiven+=2;
                        printf("2 runs, banged short on off from the wicket.\n");
                        c.runsgiven+=2;
                        a.ballsplayed++;
                          break;
                case '3':a.runs+=3;
                        mainruns+=3;
                        team2[count].runsgiven+=3;
                        printf("fielding ka bhut hi khrab pradarshan aur 3 run\n");
                        c.runsgiven+=3;
                        a.ballsplayed++;
                        flag*=-1;
                          break;
                case '4':a.runs+=4;
                        mainruns+=4;
                        a.four++;
                        printf("it's a four, straight drive and a boundary\n ");
                        team2[count].runsgiven+=4;
                        c.runsgiven+=4;
                        a.ballsplayed++;
                          break;
                case '6':a.runs+=6;
                        mainruns+=6;
                        a.six++;
                         printf("bowler ke sir ke upar se CHHAKKA!!\n");
                        team2[count].runsgiven+=6;
                        c.runsgiven+=6;
                        a.ballsplayed++;
                        break;
                case 'W':printf("OUT\n");
                        team2[count].wickets++;
                        printf("ballebazZZ ko pta bhi nahi chla or saare dande ud gye\n");
                        c.wickets++;
                        wickets++;
                        if (wickets==n-1)
                        {
                            break;
                        }
                        
                        if (flag==-1)
                        {
                            a.ballsplayed++;
                            team1[b2].ballsplayed++;
                            team1[b1]=a;
                            b1=next;
                            a=team1[next];
                            next++;
                        }
                        else
                        {
                            b.ballsplayed++;
                            team1[b2].ballsplayed++;
                            team1[b2]=b;
                            b2=next;
                            b=team1[next];
                            next++;
                        }
                        
                        break;
                case 'w':mainruns++;
                        team2[count].runsgiven+=1;
                        c.runsgiven++;
                        j--;
                        team2[count].ballsbowled--;
                        printf("it's a wide ball\n");
                        break;
                default : printf("INVALID INPUT\n");
                            j--;
                            team2[count].ballsbowled--;
                }
                team1[b1] = a;                                     // Update team1[b1] with the modified value of a
                team1[b2] = b;                                      // Update team1[b2] with the modified value of b
            }
            if (wickets==n-1)
            {
                printf("\n Batting Team ALL OUT\n");
                
                break;
            }
            printf("Score: %d/%d\n" , mainruns,wickets);
            d=0;
            if (target>0 && mainruns>target)
            {
                break;
            }
            
        }
        if (target>0 && mainruns>target)
            {
                break;
            }
        flag*=-1;
        if (wickets==n-1)
            {   
                 printf("\nTotal Runs:%d     ", mainruns);
                printf("score of %s:%d(%d)    ",a.name,a.runs,a.ballsplayed);
                 printf("score of %s:%d(%d)\n    ",b.name,b.runs,b.ballsplayed);
                
    
                break;
            }
        team2[count].oversbowled++;
            
            printf("\nTotal Runs:%d     ", mainruns);
            printf("score of %s:%d(%d)    ",a.name,a.runs,a.ballsplayed);
            printf("score of %s:%d(%d)\n    ",b.name,b.runs,b.ballsplayed);
           
        c=team2[count];
        count--;
        if (count==-1)
        {
            count=n-1;
        }
    } 
    team1[b1]=a;
    team1[b2]=b;
    run = mainruns;
    wicet=wickets;
}
void bowlerscore(playerinfo a[], int n)                  //n is the number of players in each team
{                                                        //function to print the scoreboard of bowlers after one an inning
    printf ( "\n-----------------------------------------------------------------------\n " ) ;  
    printf ( "  Bowler        overs           runs        wicket       economy \n " ) ;  
    printf ( "-----------------------------------------------------------------------\n " ) ;  
    for ( int i = 0 ; i < n ; i++)  
    {  float eco;
            if (a[i].ballsbowled!=0)
            {
               eco = (((float)a[i]. runsgiven / a[i].ballsbowled)*6);
            }
            else
            {
                 eco=0;
            }
            
              
            printf ( " %-15s %d.%-14d %-13d %-11d %-11.2f \n\n " , a[i].name , a[i].oversbowled , a[i].ballsbowled%6, a[i].runsgiven , a[i].wickets ,  eco ) ;
        
    }
}
void batterscore(playerinfo a[],int n)                               //function to print the scoreboard of batsmen after one an inning
{
    printf( "\n------------------------------------------------------------------------------------------------\n " ) ;  
    printf ( "  Batter        runs           balls       fours         sixes         strike rate \n " ) ;  
    printf ( "------------------------------------------------------------------------------------------------\n " ) ;  
    for(int i=0;i<n;i++)  
    {  
        if(a[i].ballsplayed!=0)
        {
            float strike = ((float)a[i].runs/a[i].ballsplayed)*100;
            printf ( " %-15s %-14d %-13d %-11d %-11d %-11.2f \n\n " , a[i].name, a[i].runs, a[i].ballsplayed, a[i].four,  a[i].six, strike);
        }
        else
        {
            printf ( " %-15sDNB            DNB          DNB           DNB           DNB \n\n " , a[i]. name ) ;
        }
    }
}


int main(){
    printf("WELCOME TO GULLY CRICBIZZ\n");                         //the main function serves as entry point of the program
    char call[4];                   
    printf("Its the time for toss!!\n");                           // basic introduction for the function
    printf("Whats your call (tail/head): ");
    scanf("%s",call);
    toss(call);
    
    
    int mainscore1=0;
    int mainscore2=0;
    int wickets1=0;
    int wickets2=0;
    int p,o;
    printf("\n\nenter the number of players: ");     
    scanf("%d",&p);                                                 //no of players
    printf("enter the number of overs: ");       
    scanf("%d",&o);                                                 //no of overs
    
    
    playerinfo team1[p];                                     //initializing team player array
    playerinfo team2[p];

    printf("Enter Batsman in priority\n");             
    printf("\n\nBatting team enter your player's names: \n");
    for( int i = 0 ; i <p ; i++){
        printf( "Enter the name of player %d:" , i+1);          //taking names of players as input from user
        scanf( "%s" , team1[i].name);
        team1[i].runs=0;
        team1[i].ballsplayed=0;
        team1[i].four=0;                         
        team1[i].oversbowled=0;
        team1[i].runsgiven=0;
        team1[i].wickets=0;
        team1[i].six=0;
        team1[i].ballsbowled=0;

    }

    printf("\nBowling team enter your player's names: \n");                         
    for( int i = 0 ; i <p ; i++){
        printf( "Enter the name of player %d:" , i+1);                    //taking names of players as input from user
        scanf( "%s" , team2[i].name);
        team2[i].runs=0;
        team2[i].ballsplayed=0;
        team2[i].four=0;
        team2[i].oversbowled=0;
        team2[i].runsgiven=0;
        team2[i].wickets=0;
        team2[i].six=0;
        team2[i].ballsbowled=0;
    }

    printf("\n\nUSER GUIDE\n");
    printf("enter 4 for four runs\n");
    printf("enter 6 for six runs\n");
    printf("enter 0 for dot ball\n");
    printf("enter 1 for one run\n");
    printf("enter 2 for two runs\n");
    printf("enter 3 for three runs\n");
    printf("enter W for wicket\n"); 
    printf("enter w for wide ball\n\n\n");
    printf("\n----------------------------FIRST INNINGS-------------------------------------------\n");
    innings(team1,team2,o,p);
    mainscore1=run;
    wickets1=wicet;
    target=run;
    printf("\n-------------------------------------------------------INNINGS BREAK----------------------------------------------------------");
    printf("\n\nBOWLING SCORECARD\n");
    bowlerscore(team2,p);
    printf("\nBATTING SCORECARD\n");
    batterscore(team1,p);
    printf("Team1 Final Score:- %d/%d\n" , mainscore1,wickets1);
    printf("\n\n\n\n----------------------------SECOND INNINGS-------------------------------------------\n");
    innings(team2,team1,o,p);
    mainscore2=run;
    wickets2=wicet;
    printf("\n-------------------------------------------------------INNINGS BREAK----------------------------------------------------------");
    printf("\n\nBOWLING SCORECARD\n");
    bowlerscore(team1,p);
    printf("\nBATTING SCORECARD\n");
    batterscore(team2,p);

    int b;//inning1 team1 score
    int c;//inning2 team 2 score
    int e;
    int remaining;
    printf("Team1 Final Score:- %d/%d\n" , mainscore1,wickets1);
    printf("Team2 Final Score:- %d/%d\n" , mainscore2,wickets2);
    if(mainscore1>mainscore2)
    {
        e=mainscore1-mainscore2;
        printf("Team 1 won by %d runs", e);
    }
    else if(mainscore2>=mainscore1)
    {
        remaining=p-wickets2;
        printf("Team 2 won by %d wickets",remaining);
    }
    return 0;
}


