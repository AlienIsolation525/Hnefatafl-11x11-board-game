#include "Tafl.h"

int main()
{
	// OPTIONS
	// 
	// Window size
	MoveWindow(GetConsoleWindow(), 50, 50, 650, 700, true);
	Tafl tafl;

	while (true)
	{
		tafl.constructEmptyboard();
		tafl.addFigurines();
		tafl.displayboard(999, 999);
		tafl.turn();
		bool isVictory = tafl.isVictory();
		if (isVictory == 1)
		{
			system("cls");
			cout << "\n* White side wins! *\n Battle history was saved in Battlelog.txt file \n";
			
			break;
		}

		else if (isVictory == 2)
		{
			system("cls");
			cout << "\n* Dark side wins! *\n Battle history was saved in Battlelog.txt file \n";
			break;
		}

		system("cls");
	}

	cin.get();
}