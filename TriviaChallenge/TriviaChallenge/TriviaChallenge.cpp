// Cpp_Lab_04.cpp : Defines the entry point for the console application.
// Michael Coyne & Matt Gilmore

#include "stdafx.h"
#include <iostream>
#include <string>
		//#include <cstdlib>

		using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	string player1 = "| Q |";
	string player2 = "| P |";
	string empty = "|< >|";
	int player1loc = 0;
	int player2loc = 0;
	string tied = "|QP|";
	bool correct = NULL;
	string turn = player1;
	string board[4] = { tied, "|< >|", "|< >|", "|< >|" };

	void display_board(string board[4]);

	display_board(board);


	while (player1loc < 3 && player2loc < 3)
	{
		if (correct == true)
		{
			if (turn == player1)
			{
				board[(player1loc)+1] = turn;
				board[player1loc] = empty;
			}
			else
			{
				board[(player2loc)+1] = turn;
				board[player2loc] = empty;
			}
		}
	}
	return 0;
}
void display_board(string board[4])
{
	system("CLS");
	cout << "===============" << endl;
	cout << "|<#><#><#><#><#>|" << endl;
	cout << "|<#>" << board[0] << "<#><#><#>|" << endl;
	cout << "|<#>" << board[1] << board[2] << board[3] << "<#>|" << endl;
	cout << "|<#><#><#><#><#>|" << endl;
	cout << "===============" << endl;
}



