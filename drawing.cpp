/*


*/
#include<iostream>
#include<conio.h>
#include<vector>
#include<Windows.h>
#include<string>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
using namespace std;

//function prototypes
void menu ();
void drawMap();
void gotoxy(int, int);
void movement();
bool isValidNumber(string);

//global variables
int x = 2;
int y = 1;
int xBefore;
int yBefore;
char inputKey;

//board array
int board [250] [250];

int main()
{
	while (true)
	menu();
}//end of main
//functions
void menu ()
{
	system("cls");

	gotoxy(2,1);
	cout<<" Create new file";
	gotoxy(2,2);
	cout<<" Open existing file";
	gotoxy(2,3);
	cout<<" Exit";
	
	gotoxy(xBefore, yBefore);
    cout << " ";

    gotoxy(x, y);
    cout << ">";
	
		
    inputKey = _getch();

    xBefore = x;
    yBefore = y;

	if(inputKey == 'd') x = x + 1;
	if(inputKey == 'a') x = x - 1;
	if(inputKey == 's') y = y + 1;
	if(inputKey == 'w') y = y - 1;
	if(inputKey == '\r')
	{
		if (y == 1)
		{
			system("cls");
			int numberOfCols = 0;
			bool isValid = false;
			vector <int> colorList(14);
				for (int x = 0; x < 16; x++)
				{
					colorList.push_back(x);
					cout<<colorList.at(x);
				}
/*
			
			do
			{
				system("cls");
				cout<<"How many colors would you like in your color pallet?(max:15)";
				cout<<"\nEnter number here: ";
				cin>>numberOfCols;
				if(cin.fail() || numberOfCols > 15 || numberOfCols < 0)
				{
					cin.clear(); // clears the error flags
					// this line discards all the input waiting in the stream
					cin.sync();
					system("CLS");
					cout<<"Not a valid input! Try again.\n";
					system("pause");
				}
				else
					isValid = true;
			} while(isValid == false);
			*/
			isValid = false;
			x = 0, y = 1;
			do
			{
				//system("CLS");
				

				string wantedColors = "";
				gotoxy(0,0);
				
				cout<<"Which colors would you like in your pallet?: \n";
				x = 0, y = 1;
				for(int x = 0; x < colorList.size()-1; x++)
				{
					switch(x)
					{
						case 0:
							{
								gotoxy(x,y+1);
								cout<<" Black \n";
								break;
							}
						case 1:
							{
								gotoxy(x,y+=1);
								cout<<" Blue \n";
								break;
							}
						case 2:
							{
								gotoxy(x,y+=1);
								cout<<" Green \n";
								break;
							}
						case 3:
							{
								gotoxy(x,y+=1);
								cout<<" Cyan \n";
								break;
							}
						case 4:
							{
								gotoxy(x,y+=1);
								cout<<" Red \n";
								break;
							}
						case 5:
							{
								gotoxy(x,y+=1);
								cout<<" Magenta \n";
								break;
							}
						case 6:
							{
								gotoxy(x,y+=1);
								cout<<" Brown \n";
								break;
							}
						case 7:
							{
								gotoxy(x,y+=1);
								cout<<" Light Gray \n";
								break;
							}
						case 8:
							{
								gotoxy(x,y+=1);
								cout<<" Dark Gray \n";
								break;
							}
						case 9:
							{
								gotoxy(x,y+=1);
								cout<<" Light Blue \n";
								break;
							}
						case 10:
							{
								gotoxy(x,y+=1);
								cout<<" Light Green \n";
								break;
							}
						case 11:
							{
								gotoxy(x,y+=1);
								cout<<" Light Cyan \n";
								break;
							}
						case 12:
							{
								gotoxy(x,y+=1);
								cout<<" Light Red \n";
								break;
							}
						case 13:
							{
								gotoxy(x,y+=1);
								cout<<" Light Magenta \n";
								break;
							}
							case 14:
							{
								gotoxy(x,y+=1);
								cout<<" Yellow \n";
								break;
							}
							case 15:
							{
								gotoxy(x,y+=1);
								cout<<" White \n";
								break;
							}
					}
				}
				cout<<"\n Done\n";

				bool searching = true;
				while(searching == true)
				{
					gotoxy(xBefore, yBefore);
					cout << " ";

					gotoxy(x, y);
					cout << ">";
					gotoxy(10, 15);
		
					inputKey = _getch();

					xBefore = x;
					yBefore = y;

					if(inputKey == 'd') x = x + 1;
					if(inputKey == 'a') x = x - 1;
					if(inputKey == 's')
					{
						y = y + 1;
						if(y == 15) y ++;
					}
					if(inputKey == 'w') 
					{
						y = y - 1;
						if(y == 15) y --;
					}
					if(x < 0 || x > 0)
					{
						x = xBefore;
					}
					if(y < 1 || y > 16)
					{
						y = yBefore;
					}
				}
			}while(isValid = false);
		}
		else if (y == 2)
		{

		}
		else
		{
			system("cls");
			cout<<"Thanks for using the program, hope if was helpful!\n";
			system("pause");
			exit(0);
		}
	}
	if(x > 2 || x < 2)
	{
		x = xBefore;
	}
	if(y < 1 || y > 3)
	{
		y = yBefore;
	}
}
void drawMap()
{
	system("cls");

	for (int counter = 0; counter <= 50; counter ++)
	{

		for (int newCounter = 0; newCounter <= 50; newCounter ++)
		{
			switch (board[newCounter][counter])
			{
			case 0:
				cout << " ";
				break;
			case 1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << char(219);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				break;
			case 2:
				cout << " ";
				break;
			}
		}
		cout << " " << endl;
	}

	for(int x = 0; x < 50; x++)
		for(int y = 0; y < 50; y++)
		{
			gotoxy(x + 25,y + 25);
			cout<<board[x][y];
		}
}
void gotoxy(int xInput, int yInput)
{
	COORD coord;
	coord.X = xInput;
	coord.Y = yInput;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord );

}
void movement()
{
	gotoxy(xBefore, yBefore);
    cout << " ";

    gotoxy(x, y);
    cout << ">";
	gotoxy(10, 15);
		
    inputKey = _getch();

    xBefore = x;
    yBefore = y;
	//makes the person move
	if(inputKey == 'd') x = x + 1;
	if(inputKey == 'a') x = x - 1;
	if(inputKey == 's') y = y + 1;
	if(inputKey == 'w') y = y - 1;
	if(inputKey == 'p')
	{
		board [x][y] = 1;
		drawMap();
	}
}
bool isValidNumber(string num)
{
	bool validAnswerEntered = false;
	
		for(int x = 0; x < num.length(); x++)
		{
			if(num.substr(x,1) >= "0" && num.substr(x,1) <= "9" && x == num.length())
			{
				if(num >= "0" && num <= "15")
				validAnswerEntered = true;
			}		
		}//end for

		if(validAnswerEntered == false)
		{
			system("cls");
			cout<<"Sorry! Thats not a valid number, try again"<<endl;
			system("pause");
			system("cls");
		}

		return validAnswerEntered;
}