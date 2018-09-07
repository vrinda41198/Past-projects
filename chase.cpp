/* 
	An ASCII game based on the racing brick_game with added features
*/
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<iomanip.h>
#include<time.h>
#include<process.h>
#include <windows.h>
#define NUM_ROWS 25
#define NUM_COLS 60
#define MIN_SEP 8
#define SCORE_X 60
#define SCORE_Y 2
int lives=0,high1=0;
int score = 0,add1=2;
int track_size = 1;
int cx, cy;
int num_obstacles = 0;
int num_coins = 0;
char car=142;
struct boundary
{
  int xs, xe;
} track[NUM_ROWS];
struct point
{
	int x, y;
} obstacles[1000], coins[1000];

void delay2(float x)
{
	char r;
	clock_t start,stop;
	start=clock();
	stop=clock()+(x*1000);
	while(start<=stop)
	{
		if(kbhit())
			r=getch();
		start=clock();

	}
}
int opening() //opening screen menu
{
 char code;
 char ch;
 do
{
  clrscr();
  Z:cout<<"             WELCOME TO CHASE !!!!!   "<<endl;
  cout<<"  1.PLAY !!! :D  "<<endl;
  cout<<"  2.INSTRUCTIONS    "<<endl;
  cout<<"  3.EXIT :'(       "<<endl;
  cout<<"  4.CREDITS :)     "<<endl;
  cout<<"      Choose an option from above"<<endl;
  ch=getch();
  switch(ch)
  {
	case 49:
	 goto A;
	 break;
	case 50:
	 clrscr();
	 cout<<"                             Game Instructions    "<<endl;
	 cout<<" The game is very simple.. :)  You are being chased by cops for a robbery.. \n Go fast to save your life and keep on track to save time.\n Coz if you go off track the cops will catch up with you & you will be killed..\n But wait there's more : The cops have thrown random obstacles in your\n path which may or may not have bombs..\n If there is bomb they explode and you lose a life!!\n You have only 3 lives after which you die..\n SO BE CAREFUL!\n But if there is no bomb in the obstacles you are lucky, you get injured\n but you can move on.\n On the way you will encounter many banks and so many opportunities to \n collect money($) and become rich .. ;) \n BUT BUT BUT...Some banks are empty and you dont earn any money there.. "<<endl;
	 cout<<" It doesn't end here: After some time number of obstacles will increase\n and so will the speed of the cops."<<endl;
	 cout<<" So basically, there are 3 objectives :- "<<endl;
	 cout<<"          Keep the car on track "<<endl;
	 cout<<"          Dodge the obsacles  "<<endl;
	 cout<<"          Collect money :)"<<endl;
	 cout<<" CONTROL KEYS - "<<endl;
	 cout<<"                 A or a-TO MOVE THE CAR TO THE LEFT "<<endl;
	 cout<<"                 D or d-TO MOVE THE CAR TO THE RIGHT  "<<endl;
	 cout<<"  Scoring - "<<endl;
	 cout<<"  If you keep the car on the track you score 10 points "<<endl;
	 cout<<"  If the car touches any obstacle ,you lose"<<endl;
	 cout<<"  30 POINTS :("<< endl;
	 cout<<"  If the car collects money ,you gain 50 points "<<endl;
	 cout<<"     HAVE FUN !!! :D "<<endl;
	 cout<<" Press any key to go back to menu "<<endl;
	 code=getch();
	 break;
	case 51:
	 cout<<"Do you want to exit(y/n)"<<endl;
	 char op;
	 op=getch();
	 if (op=='y'||op=='Y')
	 {
		clrscr();
		delay2(1);
		gotoxy(15,1);
		cout<<" 010101010  0000000  0000000  1100        "<<endl;
		gotoxy(15,2);
		cout<<" 01         0000000  0000000  11 11       "<<endl;
		gotoxy(15,3);
		cout<<" 01         00   00  00   00  11   00     "<<endl;
		gotoxy(15,4);
		cout<<" 01  01010  00   00  00   00  11    11    "<<endl;
		gotoxy(15,5);
		cout<<" 01  0   0  00   00  00   00  11   00     "<<endl;
		gotoxy(15,6);
		cout<<" 01      0  0000000  0000000  11 11       "<<endl;
		gotoxy(15,7);
		cout<<" 010101010  0000000  0000000  1100        "<<endl;
		delay2(1);
		gotoxy(15,10);
		cout<<" 0101010100  11     11  11111111   |  |  "<<endl;
		gotoxy(15,11);
		cout<<" 01      00   00   00   11         |  |  "<<endl;
		gotoxy(15,12);
		cout<<" 01      00      11     11         |  |  "<<endl;
		gotoxy(15,13);
		cout<<" 0101010100      00     11111111   |  |  "<<endl;
		gotoxy(15,14);
		cout<<" 01      00      11     11         |  |  "<<endl;
		gotoxy(15,15);
		cout<<" 01      00      00     11         |  |  "<<endl;
		gotoxy(15,16);
		cout<<" 0101010100      11     11111111   o  o  "<<endl;
		delay2(1);
		clrscr();
		exit(0);
      }
	 else if(op=='n'||op=='N')
	 {
		clrscr();
		goto Z;
		break;
	 }
	 else
	 {
	  cout<<"Enter valid option "<<endl;
	  delay2(1);
	  clrscr();
	  goto Z;
	  break;
	  }
		case 52:
		clrscr();
		cout<<"                            CREDITS           "<<endl<<endl<<endl;
		cout<<" Creators/Authors: Vrinda"<<endl;
		cout<<" I would like to extend a sincere thanks to my computer teachers Mrs.Akshatha\n ma'am,Mrs.Poornima ma'am and Mrs.Bharghavi ma'am for their constant support\n and guidance without which this project would not have been possible.\n Also special thanks to Mr.Pulkit for his technical support and guidance.I \n hope you enjoyed playing the game as much as I did making it..\n Code is subject to copyright.."<<endl;
		cout<<" Enter any key to go back to main menu "<<endl;
		code=getch();
      break;

  }
 }while(ch>=49&&ch<=52);
 if(ch<49||ch>52)
 {
  clrscr();
  cout<<"Please enter valid option "<<endl;
  goto Z;
 }
 A:clrscr();
 gotoxy(NUM_COLS / 2, NUM_ROWS / 2);
 cout<<"ARE YOU READY ? "<<endl;
 delay2(1);
 clrscr();
 gotoxy(NUM_COLS / 2, NUM_ROWS / 2);
 cout<<"GET SET... "<<endl;
 delay2(1);
 clrscr();
 gotoxy(NUM_COLS / 2, NUM_ROWS / 2);
 cout<<"GO!!!! "<<endl;
 delay2(1);
 return 0;
}
void draw()
{
	char ob=15; //ASCII code of obstacle
	clrscr();
	int i;
	for (i = 0; i < num_coins; i++) //prints coins on track
		  {
		if (coins[i].x > 0 && coins[i].y > 0) //to check if there are any coins to be printed
		{
			gotoxy(coins[i].y, coins[i].x);
			printf("$");
		}
	}
	for (i = 1; i < NUM_ROWS; i++) //prints the track
		 {
		gotoxy(track[i].xs, i);
		printf("|");
		gotoxy(track[i].xe, i);
		printf("|");
		cout<<endl;
	}
	gotoxy(cy, cx);
	cout<<car;   //prints the car
	for (i = 0; i < num_obstacles; i++) //prints the obstacles on the track
	{
		gotoxy(obstacles[i].y, obstacles[i].x);
		cout<<ob;
	}
	gotoxy(SCORE_X, SCORE_Y);
	printf("Score: %d\n", score); //prints the score on the screen
	cout<<endl;
}

void erase_track()
 {
	for (int i = 0;i  < track_size -1; i++) //when end of screen is reached it deletes the first row of the track
	{
	  track[i] = track[i + 1];
	}
	track_size--;
}
void add_track()
{
	int beg, end;
	while (1)
	{
	  beg = track[track_size - 1].xs + rand() % 3 - 1;    //stores values of track in 2 temporary variables
	  end = track[track_size - 1].xe + rand() % 3 - 1;
	  if (end - beg >= 5 && end-beg <= 30 && beg >= 0 && end <= NUM_COLS) //makes sure width of track is greater than 5 and less than 30
		  break;
	 }
	 track[track_size].xs = beg; //changes track coordinates
	 track[track_size].xe = end;
	 int st = 0, i;
	 for (i = 0; i < num_obstacles; i++) //when new screen is created it pushes obstacles of previous screen 1 row up
	 {
		 if (obstacles[i].x != 0)
		 {
			  obstacles[st] = obstacles[i];
			  obstacles[st].x --;
			  st++;
		 }
	 }
	 int new_obstacles = rand() % add1; //tells how many new obstacles to add
	 for (i = 0; i < new_obstacles; i++) //adds new obstacles to last row when new frame is created
		  {
		  obstacles[st].x = track_size;
		  obstacles[st].y = beg+(rand() % (end-beg));
		  st++;
	 }
	 num_obstacles = st;
	 st = 0;
	 for (i = 0; i < num_coins; i++)    //this loop is to shift coins to upper line when new track is formed
	 {
		 if (coins[i].x > 1)
		 {
			  coins[st] = coins[i];
			  coins[st].x --;
			  st++;
		 }
	 }
	 int new_coins = rand() % 2; //tells how many coins to add
	 for (i = 0; i < new_coins; i++)   //adds new coins to last row when new frame is created
	 {
		  coins[st].x = track_size;
		  coins[st].y = beg + rand() % (end - beg);    //makes sure coins lie inside track
		  st++;
	 }
	 num_coins = st;
	 track_size++; //increases no of rows created
}

int check_coin()
 {
	int i;
	for (i = 0; i < num_coins; i++) //checks if car is collecting coins
	{
		if (cx == coins[i].x && cy == coins[i].y)
	  {
			coins[i].x = coins[i].y = 0;
			return 1;
		}
	}
	return 0;
}

int check_collision()      //function to check for collision with bomb
 {
	int i;
	for (i = 0; i < num_obstacles; i++) //checks if car is colliding with obstacles
	{
		if (cx == obstacles[i].x && cy == obstacles[i].y) //checks if coordinates of car and bomb match
			return 1;
	}
	if (track[cx].xs >= cy || track[cx].xe <= cy)
		return 1;
	return 0;
}

void wait(double seconds)
{
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC; /*clocks_per_sec is a constant different for different systems.
																	This is a delay function independen of the system*/
	while (clock() < endwait);
}

void main()
{
	 B:char option;
	 opening();
	 track[0].xs = NUM_COLS * 1 / 3.0; //left side of track
	 track[0].xe = NUM_COLS * 2 / 3.0; //right side of track
	 while (track_size < NUM_ROWS)
	 {
		  add_track();             //stores values of where elements are to be printed in each row
	 }

	 cy = NUM_COLS / 2;                //coordinates of car(block)
	 cx = NUM_ROWS / 2;
	 double speed = 0.35;
	 int steps = 0;
	 while (1)
	{
		  steps++;
		  if (kbhit())            //to see that code runs even if no input is given
		  {
			  char ch = getch(); //takes input for direction of movement of car
			  if (ch == 'a'||ch=='A')
			  {
				cy-=2;
			 }
			else if (ch == 'd'||ch=='D')
			 {
				cy+=2;
			}
		  }
		 draw();  //to draw elements of track
		erase_track(); //to erase first row of track when screen size is complete
		add_track();
		if (check_collision())  //checks if car hits obstacles
		 {
		  score-=30;
		  ++lives;
		  if(lives<=2)
		  {
		  gotoxy(48,5);
		  cout<<"LOOK OUT!!YOU JUST LOST A LIFE.. "<<endl;
		  }
		  else if(lives==3)
		  {
			 gotoxy(48,5);
			 cout<<"OH OH.. :( "<<endl;
			 delay2(1);
			 break;
		 }
		  else if(score<0)
		  {
			gotoxy(48,5);
			cout<<"WATCH OUT.. :( "<<endl;
			delay2(.5);
			break;
			}
		  }
			if (check_coin())      //checks if car is collecting coins
			{
			  score += 50;
			}
			score += 10;
			wait(speed);
			if (steps % 1000 == 0 && speed > 1) //keeps increasing the speed of the track after some time
			{
					 speed -= 0.01;
					 add1=3;                     //changes no of obstacles after some time
			}
	  }
	 clrscr();
	 gotoxy(NUM_COLS / 2, NUM_ROWS / 2); //shows final result of game
	 cout << "SORRY!!GAME OVER!!YOU DIED *_* ";
			gotoxy(NUM_COLS / 2, (NUM_ROWS / 2)+1);
			if(score>=0)
			cout<<"Final Score    : " << score << endl;
			else cout<<"YOUR SCORE WAS VERY LOW.YOU DONT WANT TO SEE IT :( "<<endl;
			gotoxy(NUM_COLS / 2, (NUM_ROWS / 2)+2);
			if(score>high1)
			{
			 high1=score;
			 cout<<"CONGRATULATIONS!!HIGHEST SCORE : "<<high1;
			}
			else cout<<"Sorry you couldn't reach highest score  ";
			C:gotoxy(NUM_COLS / 2, (NUM_ROWS / 2)+3);
			cout<<"Do you want to go back to main menu(y or n) "<<endl;
			delay2(1);
			gotoxy(NUM_COLS / 2, (NUM_ROWS / 2)+4);
			option=getch();
			if(option=='y' ||option=='Y')
			{
			 clrscr();
			 score = 0;
			 track_size = 1;
			 num_obstacles = 0;
			 num_coins = 0;
			 goto B;
			}
			else if(option=='n'||option=='N')
			{
			 clrscr();
			 delay2(1);
			 gotoxy(15,1);
			 cout<<" 010101010  0000000  0000000  1100        "<<endl;
			 gotoxy(15,2);
			 cout<<" 01         0000000  0000000  11 11       "<<endl;
			 gotoxy(15,3);
			 cout<<" 01         00   00  00   00  11   00     "<<endl;
			 gotoxy(15,4);
			 cout<<" 01  01010  00   00  00   00  11    11    "<<endl;
			 gotoxy(15,5);
			 cout<<" 01  0   0  00   00  00   00  11   00     "<<endl;
			 gotoxy(15,6);
			 cout<<" 01      0  0000000  0000000  11 11       "<<endl;
			 gotoxy(15,7);
			 cout<<" 010101010  0000000  0000000  1100        "<<endl;
			 delay2(1);
			 gotoxy(15,10);
			 cout<<" 0101010100  11     11  11111111   |  |  "<<endl;
			 gotoxy(15,11);
			 cout<<" 01      00   00   00   11         |  |  "<<endl;
			 gotoxy(15,12);
			 cout<<" 01      00      11     11         |  |  "<<endl;
			 gotoxy(15,13);
			 cout<<" 0101010100      00     11111111   |  |  "<<endl;
			 gotoxy(15,14);
			 cout<<" 01      00      11     11         |  |  "<<endl;
			 gotoxy(15,15);
			 cout<<" 01      00      00     11         |  |  "<<endl;
			 gotoxy(15,16);
			 cout<<" 0101010100      11     11111111   o  o  "<<endl;
			 delay2(1);
			 clrscr();
			 exit(0);
	     }
			else
			{
          clrscr();
			 gotoxy(NUM_COLS / 2, (NUM_ROWS / 2)+2);
			 cout<<"Enter valid option "<<endl;
			 goto C;
			}
}
