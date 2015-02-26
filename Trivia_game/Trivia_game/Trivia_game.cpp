// Trivia.cpp : Defines the entry point for the console application.
/***********************
* Brandon McCurry
* Trivia game
***********************/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>

using namespace std;

void display_board(char[2][40], int);

int main()
{
	/*************** Pseudocode ******************
	* create board
	* create questions
	* display characters in position
	* ask questions
	* if player is correct
	*		move their piece based on their roll
	*		change turns
	*		if player at end
	*			end game
	*			congradulate winner
	*********************************************/
	srand(time(0));
	char characters[2] = { '1', '2' };
	int player_pos[2] = { 0, 0 };
	int turn = 0;
	char board[2][40];
	int bSize = 39;
	// create board
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < bSize; j++)
		{
			board[i][j] = ' ';
		}
	}
	board[0][0] = characters[0];
	board[1][0] = characters[1];

	// create questions and answers
	int qSize = 9;
	string questions[] = { "Who coined the term debugging? ", "Who was the father of computing? ", "Who lost a war to emus? ",
		"Which king in a deck of cards has a mustache? ", "Can a match box? ", "Where is home? ", "Who wrote the first programming language? ",
		"What was the first programming language? ", "Which movie had an encrypted Ovaltine ad? ", "Who cracked enigma? ", "The CIA hid bugs inside what animal? ",
		"Who wrote pong? " };
	string answers[] = { "Grace Hopper", "Charles Babbage", "Australia", "Hearts", "No, but a tin can", "127.0.0.1", "IBM", "Fortran",
		"A Christmas Story", "Alan Turing", "Cats", "Allan Alcorn" };
	string response = "a";

	// play game
	while (player_pos[0] < bSize && player_pos[1] < bSize)
	{
		display_board(board, bSize);
		int qChoice = rand() % qSize;
		cout << "Player " << turn + 1 << ": " << questions[qChoice];
		getline(cin, response);
		if (response == answers[qChoice])
		{
			int spaces = rand() % 6 + 1;
			cout << "Correct!" << endl << "You rolled: " << spaces << endl;
			int i = 0;
			//move piece one space at a time
			while (player_pos[turn] + i < bSize && i < spaces)
			{
				board[turn][i + player_pos[turn]] = ' ';
				i++;
				board[turn][i + player_pos[turn]] = characters[turn];
				display_board(board, bSize);
				cout << "Moves left: " << spaces - i << endl;
			}
			player_pos[turn] += spaces;
		}
		else
		{
			cout << "No, the answer was: " << answers[qChoice] << endl;
			Sleep(1000);
		}
		turn = !turn;
	}
	cout << "Player " << turn + 1 << " won!";
	getchar();
}
void display_board(char board[2][40], int bSize)
{
	cout << endl;
	Sleep(1000);
	system("CLS");
	for (int i = 0; i < bSize; i++)
	{
		cout << "__";
	}
	cout << "_" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < bSize; j++)
		{
			cout << "|" << board[i][j];
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < bSize; i++)
	{
		cout << "__";
	}
	cout << "_" << endl;
}