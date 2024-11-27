#pragma once
#include "Figurine.h"
#include <vector>
#include <iomanip>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
// 11x11 board classic Hnefatafl
#define boardsizex 13
#define boardsizey 13
#define coutwidth 2 
#define whitefirst 1

using namespace std;

class Tafl
{
public:

	Tafl();
	~Tafl();
	//getters, setters

	// Construct an empty board
	void constructEmptyboard();

	// Add (update) the figurine positions on board
	void addFigurines();

	// Show the board
	void displayboard(int x, int y);
	void displatnotatio();

	// Returns 1 if selected tile is a corner tile
	bool isCorner(int x, int y);

	// Player's turn
	void turn();

	// Is that turn valid?
	bool isturnvalid(int x, int y, int dx, int dy);

	// Show turns count and random quote from file
	void displayinfo();

	// Is victory yet??
	// returns 0 if not
	// returns 1 if Whotan's side wins
	// returns 2 if Giant's side wins
	int isVictory();

	// Kill the dead
	void killthedead();

private:

	// Size with desk boarders
	char board[boardsizex + 1][boardsizey + 1];
	int Hnefix, Hnefiy, HnefiSlained = 0;
	int turncount;

	// Vector contains black figurines
	std::vector <figurine> pool;
	// Vector contains white figurines
	std::vector <figurine> pool2;
};
