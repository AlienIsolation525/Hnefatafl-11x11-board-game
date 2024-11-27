#pragma once
#include <iostream>

class figurine
{
public:

	figurine(int _id, int _x, int _y)
	{
		id = _id;
		x = _x;
		y = _y;
	};
	~figurine() = default;
	//get, set
	int getx()
	{
		return x;
	};
	int gety()
	{
		return y;
	};
	void setx(int _x)
	{
		x = _x;
	};
	void sety(int _y)
	{
		y = _y;
	};

	void kill() 
	{
		id = 111;
	};
	bool alive()
	{
		if (id != 111) return 1;
		else return 0;
	}

private:

	int x, y, id;
};

