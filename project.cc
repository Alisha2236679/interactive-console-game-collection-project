#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <windows.h>
#include <conio.h>
using namespace std;
char board[10];
int player = 1;
void playerboard();
int checkforwin();
void markingboard(int choice, char mark);
void tictoegame();
void guessnumbergame();
void stonepaperscissorgame();
void snakegame();
int height = 25, width = 30, x, y, fruitX, fruitY, flag, gameEnd , score , piece;
int tailX[100], tailY[100];
int main()
{
   int n;
   char playAgain;
   do
   {
      cout << endl
       << "Enter your choice " << endl;
      cout << "Enter 1 for Tictoe Game  " << endl;
      cout << "Enter 2 for Stone Paper Scissor Game " << endl;
      cout << "Enter 3 for number guess game " << endl;
      cout << "Enter 4 for snake game " << endl;
      cin >> n;
      if (n == 1)
      {
         tictoegame();
      }
      else if (n == 2)
      {
         stonepaperscissorgame();
      }
      else if (n == 3)
      {
         guessnumbergame();
      }
      else if (n == 4)
      {

         snakegame();
      }
      else
      {
         "Invalid choice ";
      }
      cout << endl
           << "Do you want to play again?" << endl;
      cout << "Enter 'y' for yes or 'n' for no: ";
      cin >> playAgain;
  } while (playAgain == 'y');
}
void tictoegame()
{
   int choice;
   int i;
   char mark;
   for (int i = 0; i < 10; ++i) {
    board[i] = '0' + i;
}
   do
   {
      playerboard();
      player = (player % 2 != 0) ? 1 : 2;

      if (player == 1)
      {  
         cout << "Its your turn" << endl;
         cout << "Enter your choice " << endl;
         cin >> choice;
      }
      else
      {
         cout << "Its computer turn" << endl;
         choice = ((rand() % 9) + 1);
      }
      system("cls");
      mark = (player == 1) ? 'x' : 'o';
      markingboard(choice, mark);
      i = checkforwin();
      player++;

   } while (i == -1);
   playerboard();
   if (i == 1)
   {
      player--;
      if (player == 1)
         cout << "-----------You are winner------------- ";
      else
         cout << "-----------Computer is winner------------- ";
   }
   else
      cout << "DRAW";
}
void playerboard()
{
   cout << "**TIC TAC TOE **" << endl;
   cout << "Player 1(X) ---Computer 2(o)" << endl;
   cout << "   |   |   | " << endl;
   cout << board[1] << "  | " << board[2] << " | " << board[3] << " | " << endl;
   cout << "___|___|___|___" << endl;
   cout << "   |   |   | " << endl;
   cout << board[4] << "  | " << board[5] << " | " << board[6] << " | " << endl;
   cout << "___|___|___|___" << endl;
   cout << "   |   |   | " << endl;
   cout << board[7] << "  | " << board[8] << " | " << board[9] << " | " << endl;
   cout << "___|___|___|_____" << endl;
}
void markingboard(int choice, char mark)
{
   if (choice == 1 && board[1] == '1')
      board[1] = mark;
   else if (choice == 2 && board[2] == '2')
      board[2] = mark;
   else if (choice == 3 && board[3] == '3')
      board[3] = mark;
   else if (choice == 4 && board[4] == '4')
      board[4] = mark;
   else if (choice == 5 && board[5] == '5')
      board[5] = mark;
   else if (choice == 6 && board[6] == '6')
      board[6] = mark;
   else if (choice == 7 && board[7] == '7')
      board[7] = mark;
   else if (choice == 8 && board[8] == '8')
      board[8] = mark;
   else if (choice == 9 && board[9] == '9')
      board[9] = mark;
   else
   {
      cout << "Invalid Choice ";
      player--;
   }
}
int checkforwin()
{
   if (board[1] == board[2] && board[2] == board[3])
      return 1;
   else if (board[4] == board[5] && board[5] == board[6])
      return 1;
   else if (board[7] == board[8] && board[8] == board[9])
      return 1;
   else if (board[1] == board[4] && board[4] == board[7])
      return 1;
   else if (board[2] == board[5] && board[5] == board[8])
      return 1;
   else if (board[3] == board[6] && board[6] == board[9])
      return 1;
   else if (board[1] == board[5] && board[5] == board[9])
      return 1;
   else if (board[3] == board[5] && board[5] == board[7])
      return 1;
   else if (board[1] != '1' && board[2] != '2' && board[3] != '3' && board[4] != '4' && board[5] != '5' && board[6] != '6' && board[7] != '7' && board[8] != '8' && board[9] != '9')
      return 0;
   else
      return -1;
}

void stonepaperscissorgame()
{
   int me = 0;
   int computer;
   int ROCK = 1;
   int PAPER = 2;
   int SCISSOR = 3;
   int EXIT = 4;
   int YOUR_SCORE = 0;
   int COMPUTER_SCORE = 0;
   srand(time(NULL));
   cout << endl
        << "1.Select rock";
   cout << endl
        << "2.Select paper";
   cout << endl
        << "3.Select scissor";
   cout << endl
        << "4.Exit";

   do
   {
      cout << endl
           << "Enter your choice from(1-4) ";
      cin >> me;

      computer = ((rand() % 3) + 1);
      cout << "Computer choice is " << computer;

      if (me >= 4)
      {
         cout << "\n GAME OVER";
      }
      else if (me == ROCK && computer == PAPER)
      {
         cout << endl
              << "Your choice is rock ,Computer choice is paper  **paper beat rock ";
         cout << endl
              << " YOU LOSS " << endl;
         COMPUTER_SCORE++;
      }
      else if (me == ROCK && computer == SCISSOR)
      {
         cout << endl
              << "Your choice is rock ,Computer choice is scissor  **rock beat scissor ";
         cout << endl
              << " YOU WON " << endl;
         YOUR_SCORE++;
      }

      else if (me == PAPER && computer == ROCK)
      {
         cout << endl
              << "Your choice is paper ,Computer choice is rock  **paper beats rock ";
         cout << endl
              << " YOU WON " << endl;
         YOUR_SCORE++;
      }
      else if (me == PAPER && computer == SCISSOR)
      {
         cout << endl
              << "Your choice is paper ,Computer choice is scissor  **scissor beats paper ";
         cout << endl
              << " YOU LOSS ";
         COMPUTER_SCORE++;
      }
      else if (me == SCISSOR && computer == ROCK)
      {
         cout << endl
              << "Your choice is scissor ,Computer choice is rock  **rock beats scissor ";
         cout << endl
              << "YOU LOSS " << endl;
         COMPUTER_SCORE++;
      }
      else if (me == SCISSOR && computer == PAPER)
      {
         cout << endl
              << "Your choice is scissor ,Computer choice is paper  **scissor beats paper ";
         cout << endl
              << " YOU WON " << endl;
         YOUR_SCORE++;
      }
      else
      {
         printf(" \n GAME DRAW \n");
      }
      cout << endl
           << "|---------------------------------------|";
      cout << endl
           << "|           FINAL SCORE                 |";
      cout << endl
           << "|---------------------------------------|";
      cout << endl
           << "|YOUR SCORE IS " << YOUR_SCORE << " | COMPUTER SCORE IS " << COMPUTER_SCORE << "  |";

      cout << endl
           << "|---------------------------------------|";
   } while (me < 4);
}
void guessnumbergame()
{
   srand(time(NULL));
   int winningnumber = rand() % 100;
   int number;
   int chance=1;
   cout<<"Guess a number from 1-100 ";
   cout << "You have 5 tries" << endl;
   cout << "LETS START " << endl;
   for (int i = 1; i <= 5; i++)
   {
      cout << "Enter a number " << endl;
      cin >> number;

      if (number == winningnumber)
      {
         cout << "-----YOU WON-----" << endl;
         break;
      }
      else
      {
          if(chance==5)
      {
         cout<<"-----YOU LOSS----- "<<endl;
      }
       else
      {
         cout << " YOUR GUESS IS WRONG TRY AGAIN  " << endl;
         if(number>winningnumber)
         {
         cout<<"Hint : Winning number is lesser than your choice "<<endl;
         }
         else
         {
            cout<<"Hint : Winning number is greater than your choice  "<<endl;
         }
         chance++;
      }
      }
   }
   cout << "Winning number is " << winningnumber<<endl;
}
void setCursorVisibility(bool visible)
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO cursorInfo;
   GetConsoleCursorInfo(consoleHandle, &cursorInfo);
   cursorInfo.bVisible = visible;
   SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void makelogic()
{
   int i, pevx, pevy, pev2x, pev2y;
   pevx = tailX[0];
   pevy = tailY[0];
   tailX[0] = x;
   tailY[0] = y;

   for (i = 1; i <= piece; i++)
   {
      pev2x = tailX[i];
      pev2y = tailY[i];
      tailX[i] = pevx;
      tailY[i] = pevy;
      pevx = pev2x;
      pevy = pev2y;
   }
   switch (flag)
   {
   case 1:
   {
      y--;
      break;
   }
   case 2:
   {
      y++;
      break;
   }
   case 3:
   {
      x--;
      break;
   }
   case 4:
   {
      x++;
      break;
   }
   }
   if (x == -1 || x == height - 1 || y == width - 1 || y == -1)
   {
      gameEnd = 1;
   }
   if (x == fruitX && y == fruitY)
   {

   label3:
      fruitX = rand() % 23;
      if (fruitX == 0 || fruitX == height)
         goto label3;


   label4:
      fruitY = rand() % 29;
      if (fruitY == 0 || fruitY == width)
         goto label4;
      score++;
      piece++;
   }
}

void snake()
{
   if (_kbhit())
   {
      switch (_getch())
      {
      case 75:
      {
         flag = 1;
         break;
      }
      case 77:
      {
         flag = 2;
         break;
      }
      case 72:
      {
         flag = 3;
         break;
      }
      case 80:
      {
         flag = 4;
         break;
      }
      }
   }
}

void setup()
{
   srand(time(0));
   x = height / 2;
   y = width / 2;
   fruitX = rand() % 20;
   fruitY = rand() % 20;
   flag = 0; 
   gameEnd = 0;
   score = 0;
   piece = 0;
   for (int i = 0; i < 100; ++i)
   {
      tailX[i] = 0;
      tailY[i] = 0;
   }

   setCursorVisibility(false);

label1:
   fruitX = rand() % 20;
   if (fruitX == 0 || fruitX == height)
      goto label1;

label2:
   fruitY = rand() % 20;
   if (fruitY == 0 || fruitY == width)
      goto label2;
   gameEnd = 0;
   score = 0;
}


void snakeboard()
{
   system("cls");
   int i, j, ch;
   
  for (i = 0; i < height; i++)
   {
      for (j = 0; j < width; j++)
      {
         if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
         {
            cout << " #";
         }
         else
         {
            cout << " ";
            if (i == x && j == y)
            {
               cout <<"0";
            }
            else if (i == fruitX && j == fruitY)
            {
               cout << "F";
            }
            else
            {
               ch = 0;
               for (int k = 0; k < piece; k++)
               {
                  if (i == tailX[k] && j == tailY[k])
                  {
                     cout <<"o";
                     ch = 1;
                  }
               }
               if (ch == 0)
               {
                  cout << " ";
               }
            }
         }
      }
      cout << endl;
   }
}
void snakegame()
{
   setup();
   while (gameEnd != 1)
   {
      snake();
      snakeboard();
      makelogic();
      Sleep(100);
   }
   cout << endl<< "|---------------------------------------|" << endl;
   cout << "|         YOUR SCORE  IS " << score << "              |" << endl;
   cout << "|---------------------------------------|" << endl;
}


