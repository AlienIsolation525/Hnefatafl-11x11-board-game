#include"Tafl.h"

// Sets the color of output
template<int txt = 7, int bg = 0>
ostream& color(ostream& text) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
	return text;
}

// Change console's cursor's position
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Current console's cursor's position
int getXcoord()
{
	CONSOLE_SCREEN_BUFFER_INFO info_x;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info_x);
	return info_x.dwCursorPosition.X;
}

int getYcoord()
{
	CONSOLE_SCREEN_BUFFER_INFO info_y;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info_y);
	return info_y.dwCursorPosition.Y;
}

Tafl::Tafl()
	{
		turncount = 0;
		figurine _1b{ 1, 1, 4 };
		pool.push_back(_1b);
		figurine _2b{ 2, 1, 5 };
		pool.push_back(_2b);
		figurine _3b{ 3, 1, 6 };
		pool.push_back(_3b);
		figurine _4b{ 4, 1, 7 };
		pool.push_back(_4b);
		figurine _5b{ 5, 1, 8 };
		pool.push_back(_5b);

		figurine _6b{ 6, 4, boardsizey - 2 };
		pool.push_back(_6b);
		figurine _7b{ 7, 5, boardsizey - 2 };
		pool.push_back(_7b);
		figurine _8b{ 8, 6, boardsizey - 2 };
		pool.push_back(_8b);
		figurine _9b{ 9, 7, boardsizey - 2 };
		pool.push_back(_9b);
		figurine _10b{ 10, 8, boardsizey - 2 };
		pool.push_back(_10b);

		figurine _11b{ 11, boardsizex - 2, 8 };
		pool.push_back(_11b);
		figurine _12b{ 12, boardsizex - 2, 7 };
		pool.push_back(_12b);
		figurine _13b{ 13, boardsizex - 2, 6 };
		pool.push_back(_13b);
		figurine _14b{ 14, boardsizex - 2, 5 };
		pool.push_back(_14b);
		figurine _15b{ 15, boardsizex - 2, 4 };
		pool.push_back(_15b);

		figurine _16b{ 16, 8, 1 };
		pool.push_back(_16b);
		figurine _17b{ 17, 7, 1 };
		pool.push_back(_17b);
		figurine _18b{ 18, 6, 1 };
		pool.push_back(_18b);
		figurine _19b{ 19, 5, 1 };
		pool.push_back(_19b);
		figurine _20b{ 20, 4, 1 };
		pool.push_back(_20b);

		figurine _21b{ 21, 2, 6 };
		pool.push_back(_21b);
		figurine _22b{ 22, 6, 10 };
		pool.push_back(_22b);
		figurine _23b{ 23, 10, 6 };
		pool.push_back(_23b);
		figurine _24b{ 24, 6, 2 };
		pool.push_back(_24b);

		//12 white + king
		figurine _1w{ 1, 6, 4 };
		pool2.push_back(_1w);
		figurine _2w{ 2, 5, 5 };
		pool2.push_back(_2w);
		figurine _3w{ 3, 4, 6 };
		pool2.push_back(_3w);
		figurine _4w{ 4, 5, 7 };
		pool2.push_back(_4w);
		figurine _5w{ 5, 6, 8 };
		pool2.push_back(_5w);
		figurine _6w{ 6, 7, 7 };
		pool2.push_back(_6w);
		figurine _7w{ 7, 8, 6 };
		pool2.push_back(_7w);
		figurine _8w{ 8, 7, 5 };
		pool2.push_back(_8w);
		figurine _9w{ 9, 6, 5 };
		pool2.push_back(_9w);
		figurine _10w{ 10, 5, 6 };
		pool2.push_back(_10w);
		figurine _11w{ 11, 6, 7 };
		pool2.push_back(_11w);
		figurine _12w{ 12, 7, 6 };
		pool2.push_back(_12w);
		Hnefix = 6;
		Hnefiy = 6;
	};
Tafl::~Tafl() = default;

void Tafl::constructEmptyboard()
	{
		for (int i = 1; i <= boardsizex; i++)
			for (int j = 1; j <= boardsizey; j++)
			{
				if (i == 6 && j == 6)
					board[i][j] = '&';
				else if (isCorner(i, j))
					board[i][j] = '@';
				else
					board[i][j] = '#';
			}

		// Left frame
		for (int i = 0; i < boardsizex; i++)
			board[i][0] = '|';

		// Right frame 
		for (int i = 0; i < boardsizex; i++)
			board[i][boardsizey - 1] = '|';

		// Up frame
		for (int j = 0; j < boardsizey; j++)
			board[0][j] = '-';

		// Down frame
		for (int j = 0; j < boardsizey; j++)
			board[boardsizex - 1][j] = '-';

	};

void Tafl::addFigurines()
	{
	for (int i = 0; i < 24; i++)
		if (pool[i].alive())
			board[pool[i].getx()][pool[i].gety()] = 'B';
	for (int i = 0; i < 12; i++)
		if (pool2[i].alive())
			board[pool2[i].getx()][pool2[i].gety()] = 'W';
		// Add Hnefi on board
		board[Hnefix][Hnefiy] = 'H';
	};

void Tafl::displatnotatio()
	{
		cout << "   ";
		// ordinate 
		for (int i = 1; i <= 11; i++)
			cout << setw(coutwidth) << i;
		cout << endl << endl;
		// abscissa
		for (int i = 1; i <= 11; i++)
			cout << i << endl;
	}

void Tafl::displayboard(int x, int y)
	{
		displatnotatio();
		for (int i = 0; i < boardsizex; i++)
		{
			gotoxy(1, 1 + i);
			for (int j = 0; j < boardsizey; j++)
			{
				if (board[i][j] == '#')
					cout << setw(coutwidth) << color<12, 0> << board[i][j] << color;
				else if (board[i][j] == '@' || board[i][j] == '&')
					cout << setw(coutwidth) << color<14, 0> << board[i][j] << color;
				else
				{
					if (i == x && j == y)
						cout << setw(coutwidth) << color<10, 0> << board[i][j] << color;
					else
						cout << setw(coutwidth) << board[i][j];
				}
			}
			cout << "\n";
		}
	};

bool Tafl::isCorner(int x, int y)
	{
		if ((x == 1 && y == 1)
			|| (x == 1 && y == boardsizey - 2)
			|| (x == boardsizex - 2 && y == 1)
			|| (x == boardsizex - 2 && y == boardsizey - 2))
			return 1;
		else
			return 0;
	};

int Tafl::isVictory()
	{
	 bool flag;
	// Wotan's side wins IF
		// Hnefi hits the corner
		if (isCorner(Hnefix, Hnefiy)) 
			return 1;
		// Enemy has no figures alive
		flag = 0;
		for (int i = 0; i < pool.size(); i++)
			if (pool[i].alive()) flag = 2;
		if (flag == 0)
			return 1;

	// Giant's side wins IF
		// Enemy Hnefi was slained
		if (HnefiSlained) 
			return 2;
		// Enemy has no figures alive
		flag = 0;
		for (int i = 0; i < pool2.size(); i++)
			if (pool2[i].alive()) flag = 1;
		if (flag == 0)
			return 2;

		return 0;
				
	};

void Tafl::turn()
	{
		turncount++;
		int x, y;
		int dx, dy;
		bool wotanturn;
		if (whitefirst == 1 && turncount % 2 != 0) wotanturn = 1;
		else wotanturn = 0;
		displayinfo();
		// Enter cords of figure to move
		while (true) 
		{

			while (true)
			{
				if (wotanturn)
					cout << "\n Wotan's side\n";
				else cout << "\n Giant's side\n";
				cout << "Enter cordinates of figure to move... \n";
				cin >> x >> y;

				if (wotanturn)
				{
					if (board[x][y] == 'W' || board[x][y] == 'H') break;
					else cout << "Wrong tile chosen\n";
				}
				else
				{
					if (board[x][y] == 'B') break;
					else cout << "Wrong tile chosen\n";
				}
			}
			// Clear console and show board
			system("cls");
			displayboard(x, y);
			displayinfo();

			// Enter destination cords
			while (true)
			{
				cout << "Where you want to move figure? \n      (111 111 to choose figure again):\n           ";
				cin >> dx >> dy;
				if ( (!isturnvalid(x, y, dx, dy)) && (dx != 111 && dy != 111) ) cout << "Invalid turn\n";
				else break;
			}

			if (dx != 111 && dy != 111) break;
		}

		// Change cordinates
		if (wotanturn)
		{
			if (x == Hnefix && y == Hnefiy)
			{
				Hnefix = dx;
				Hnefiy = dy;
			}
			for (int i = 0; i < pool2.size(); i++)
				if (pool2[i].getx() == x && pool2[i].gety() == y)
				{
					pool2[i].sety(dy);
					pool2[i].setx(dx);
					break;
				}
		}
		else
		{
			for (int i = 0; i < pool.size(); i++)
				if (pool[i].getx() == x && pool[i].gety() == y)
				{
					pool[i].sety(dy);
					pool[i].setx(dx);
					break;
				}
		}
		
		// Save battle log
		savebattlelog(x, y, dx, dy);

		// Check is there dead ones if so - delete them from the board
		killthedead();
	};

void Tafl::savebattlelog(int x, int y, int dx, int dy)
{
	string temp = "Turn " + to_string(turncount) + " Move: " + to_string(x) + ";" + to_string(y) + " -> " +
		to_string(dx) + ";" + to_string(dy) + " (" + board[x][y] + ") ";

	ofstream bl(battlelog, ios::app);
	bl << temp;
	bl << endl;
	bl.close();
}

void Tafl::displayinfo()
{
	int cursorx = getXcoord();
	int cursory = getYcoord();
	int y = 1;
	gotoxy(30, y);
	cout << "Turn " << turncount << endl << endl;

	// Quote
	std::string line;
	std::ifstream in("Edda quotes.txt");
	srand(time(NULL));
	int x = rand() % 100 + 1;
	std::string xstr = std::to_string(x);
	while (std::getline(in, line))
		if (line == xstr)
		{
			while (std::getline(in, line) && line != "|")
			{
				y++;
				gotoxy(30, y);
				std::cout << color<14, 0> << line << color << std::endl;
			}
			break;
		}
	in.close();
	gotoxy(cursorx, cursory);
}

bool Tafl::isturnvalid(int x, int y, int dx, int dy)
	{
		bool flag = 1;

		// Out of board exñ
		if (dx > boardsizex - 2 || dx < 1)flag = 0;
		if (dy > boardsizey - 2 || dy < 1)flag = 0;

		// Rook-like movement exñ
		if (!((x == dx) || (y == dy)))flag = 0;

		if (y < dy)// right
		{
			for (int i = y + 1; i <= dy; i++)
			{
				if (x == Hnefix && y == Hnefiy)
				{
					if (board[x][i] != '#' && board[x][i] != '@' && board[x][i] != '&') 
					{
						flag = 0;
						break;
					}
				}
				else
					if (board[x][i] != '#' || board[dx][dy] == '&') 
					{
						flag = 0;
						break;
					}
			}
		}
		else if (y > dy)// left
		{
			for (int i = y - 1; i >= dy; i--)
			{
				if (x == Hnefix && y == Hnefiy)
				{
					if (board[x][i] != '#' && board[x][i] != '@' && board[x][i] != '&') 
					{
						flag = 0;
						break;
					}
				}
				else
					if (board[x][i] != '#' || board[dx][dy] == '&') 
					{
						flag = 0;
						break;
					}
			}
		}
		else if (x < dx)// down
		{
			for (int i = x + 1; i <= dx; i++)
			{
				if (x == Hnefix && y == Hnefiy)
				{
					if (board[i][y] != '#' && board[i][y] != '@' && board[i][y] != '&')
					{
						flag = 0;
						break;
					}
				}
				else
					if (board[i][y] != '#' || board[dx][dy] == '&') 
					{
						flag = 0;
						break;
					}
			}
		}
		else if (x > dx)// up
		{
			for (int i = x - 1; i >= dx; i--)
			{
				if (x == Hnefix && y == Hnefiy)
				{
					if (board[i][y] != '#' && board[i][y] != '@' && board[i][y] != '&')
					{
						flag = 0;
						break;
					}
				}
				else
					if (board[i][y] != '#' || board[dx][dy] == '&') 
					{
						flag = 0;
						break;
					}
			}
		}
		return flag;
	};

void Tafl::killthedead()
{
	//   *
	// * H *
	//   *
	if ((board[Hnefix][Hnefiy - 1] == 'B' || board[Hnefix][Hnefiy - 1] == '@') &&
		(board[Hnefix][Hnefiy + 1] == 'B' || board[Hnefix][Hnefiy + 1] == '@'))
		if ((board[Hnefix - 1][Hnefiy] == 'B' || board[Hnefix - 1][Hnefiy] == '@') &&
			(board[Hnefix + 1][Hnefiy] == 'B' || board[Hnefix + 1][Hnefiy] == '@')) HnefiSlained = 1;

	// Wotan's side
	for (int i = 0; i < pool2.size(); i++)
	{
		int x = pool2[i].getx();
		int y = pool2[i].gety();

		// * W *
		if ((board[x][y - 1] == 'B' || board[x][y - 1] == '@') &&
			(board[x][y + 1] == 'B' || board[x][y + 1] == '@')) pool2[i].kill();

		// *
		// W
		// *
		if ((board[x - 1][y] == 'B' || board[x - 1][y] == '@') &&
			(board[x + 1][y] == 'B' || board[x + 1][y] == '@')) pool2[i].kill();
	}

	// Giant's side
	for (int i = 0; i < pool.size(); i++)
	{
		int x = pool[i].getx();
		int y = pool[i].gety();

		// * B *
		if ((board[x][y - 1] == 'W' || board[x][y - 1] == '@' || board[x][y - 1] == 'H') &&
			(board[x][y + 1] == 'W' || board[x][y + 1] == '@' || board[x][y + 1] == 'H')) pool[i].kill();

		// *
		// B
		// *
		if ((board[x - 1][y] == 'W' || board[x - 1][y] == '@' || board[x - 1][y] == 'H') &&
			(board[x + 1][y] == 'W' || board[x + 1][y] == '@' || board[x + 1][y] == 'H')) pool[i].kill();
	}
}
