// Trivia_Challenge.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string trivia_board[5] = { "", "", "", "", "" };
	string questions[2][5] = {
			{ "What is my middle name? ", "Do i play Terraria? ", "What is my favorite anime? ", "How old am i? ", "What is my favorite baseball team? " },
			{ "Christopher", "Yes", "Naruto", "17", "Cardinals" },
	};
	char player1;
	int player1_position = 0;
	char player2;
	int player2_position = 0;
	bool done = 1;

	cout << "Welcome To The Trivia Challenge Game." << endl;
	cout << "Pick a Object to represent your turn?" << endl;
	cout << "First Player: ";
	cin >> player1;
	cout << "Second Player: ";
	cin >> player2;

	trivia_board[player1_position] = player1;
	trivia_board[player2_position] += player2;

	while (done != 0){
		string player1_answer;
		string player2_answer;
		system("CLS");

		for (int i = 0; i < 5; i++){
			cout << "[" << trivia_board[i] << "]";

		}

		cout << endl;

		if (player1_position == 4 | player2_position == 4){
			done = 0;

		}
		else{
			cout << endl << "Player 1's turn. Your question: " << endl;
			cout << questions[0][player1_position];
			cin >> player1_answer;
			if (player1_answer == questions[1][player1_position]){
				player1_position += 1;
				cout << "Your answer was correct! You are now on space " << player1_position + 1 << endl << endl;

			}
			else{
				cout << "You got the answer wrong, and you did not move any spaces. " << endl;

			}

			cout << endl << endl << "Player 2's turn. Your question: " << endl;
			cout << questions[0][player2_position];
			cin >> player2_answer;
			if (player2_answer == questions[1][player2_position]){
				player2_position += 1;
				cout << "Your answer was correct! You are now on space " << player2_position + 1 << endl << endl;

			}
			else{
				cout << "You got the answer wrong, and you did not move any spaces. " << endl;

			}
			cin.ignore();
			cin.ignore();

		}

		for (int i = 0; i < 5; i++){
			trivia_board[i] = "";
			if (player1_position == i){
				trivia_board[i] += player1;

			}
			if (player2_position == i){
				trivia_board[i] += player2;

			}



		}

	}
	system("CLS");
	cout << "The game has ended." << endl;
	// congrats which players win... both players are able to win.
	if (player1_position == 4){
		cout << "Congratulations first player you win" << endl;

	}
	if (player2_position == 4){
		cout << "Congratulations second player you win! :) ";;

	}
	cin.ignore();
	cin.ignore();

	return 0;
}