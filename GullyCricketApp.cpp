//============================================================================
// Name        : GullyCricketApp.cpp
// Author      : Navomi Maria Shajan
// Version     :version 6.3.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;

char Bat,Bowl;

class Team { //team class
	public:
		string TeamName;
		char Player1;
		char Player2;
		char Player3;
		int Runs;
};
void WelcomeUser();
void Display(string,char[],int);
char Choose(char[]);
void StartInning(char,char,int);
int PlayInning(int);
void ShowRuns(int);
void DecideWinner(int,int);

int main() {
	WelcomeUser();

	Team teamA;
	teamA.TeamName="Team A"; //assign team A
	teamA.Player1='a';
	teamA.Player2='b';
	teamA.Player3='c';
	char PlayersA[3]={teamA.Player1,teamA.Player2,teamA.Player3};
	teamA.Runs=0;
	Display(teamA.TeamName,PlayersA,teamA.Runs);//displays

	char Bat=Choose(PlayersA);//choose player from team A

	Team teamB;
	teamB.TeamName="Team B";//assign team B
    teamB.Player1='p';
	teamB.Player2='q';
	teamB.Player3='r';
	char PlayersB[3]={teamB.Player1,teamB.Player2,teamB.Player3};
	teamB.Runs=0;
	Display(teamB.TeamName,PlayersB,teamB.Runs);//displays

	char Bowl=Choose(PlayersB);//choose player from team B
	StartInning(Bat,Bowl,1);//display bat's man and bowler

	int RUNS1=0;
	RUNS1=PlayInning(RUNS1);//start playing
    ShowRuns(RUNS1);//shows runs

    int RUNS2=0;

	Bowl=Choose(PlayersA);//choose player from team A
	Bat=Choose(PlayersB);//choose player from team B
	StartInning(Bat,Bowl,2);//display bat's man and bowler

	RUNS2=PlayInning(RUNS2);//start playing
	ShowRuns(RUNS2);//shows runs
	Sleep(500);

	DecideWinner(RUNS1,RUNS2);//decides winner

	return 0;
}
void WelcomeUser() { //welcomes and greets user
	cout<<"Hello!!"<<endl;
	cout<<"Welcome to Gully Cricket App !!\n\n";
	Sleep(500);
	cout<<"Let's start the game......\n\n";
	Sleep(1200);
}
void Display(string a,char b[],int c) { //displays team details
	Sleep(1000);
	cout<<a<<"\t"<<"Details:\n";
	Sleep(1000);
	cout<<"Players:\n";
	cout<<b[0]<<"\n";
	cout<<b[1]<<"\n";
	cout<<b[2]<<"\n";
	cout<<"Runs="<<c<<endl<<endl;
	Sleep(1010);
}
char Choose(char arr[]) { //choose random player from teams
	srand(time(NULL));
	int randomValue=(rand()%3);
	return arr[randomValue];
}
void StartInning(char Bat,char Bowl,int n) {//displays batting and bowler details
	cout<<endl;
	cout<<"---------Inning:"<<n<<"----------\n";
	Sleep(500);
	cout<<"Batsman: "<<Bat<<endl;
	Sleep(500);
	cout<<"Bowler: "<<Bowl<<endl;
	Sleep(1000);
}
int PlayInning(int RUNS) { //plays cricket
	int run;
	for(int i=0;i<6;i++) {
		run=(rand()%2);
		RUNS=run+RUNS;
		}
	return RUNS;
}

void ShowRuns(int RUNS) { //displays runs secured
	cout<<"Total Runs=";
	Sleep(500);
	cout<<RUNS;
	Sleep(1000);
}
void DecideWinner(int A,int B) { //decide the winner
	cout<<endl;
	if(A>B) {
		cout<<"Team A Wins with "<<A<<" runs\n";
		}
	else if(B>A) {
		cout<<"Team B Wins with "<<B<<" runs\n";
		}
	else { //if both runs are equal then tie
		cout<<"TIE !!"<<endl;
	}
	Sleep(1001);
	cout<<"----------Thank You----------\n";
}
