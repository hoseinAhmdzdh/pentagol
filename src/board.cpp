#include "board.h"
#include <bgi/graphics.h>

/*RECOGNIZIING THE POSITION OF CURSOR IN GRAPHIC PAGE......................................................*/
int recpositiong(int ie, int je)
{
	int a = 0, g = 0;

	if (ie == 35 && je == 35)
	{
		g = 1;
		a = 1;
	}
	if (ie == 95 && je == 35)
	{
		g = 2;
		a = 1;
	}
	if (ie == 155 && je == 35)
	{
		g = 3;
		a = 1;
	}
	if (ie == 275 && je == 35)
	{
		g = 5;
		a = 1;
	}
	if (ie == 335 && je == 35)
	{
		g = 6;
		a = 1;
	}
	if (ie == 395 && je == 35)
	{
		g = 7;
		a = 1;
	}
	/*2*/
	if (ie == 35 && je == 95)
	{
		g = 1;
		a = 2;
	}
	if (ie == 95 && je == 95)
	{
		g = 2;
		a = 2;
	}
	if (ie == 155 && je == 95)
	{
		g = 3;
		a = 2;
	}
	if (ie == 275 && je == 95)
	{
		g = 5;
		a = 2;
	}
	if (ie == 335 && je == 95)
	{
		g = 6;
		a = 2;
	}
	if (ie == 395 && je == 95)
	{
		g = 7;
		a = 2;
	}
	/*3*/
	if (ie == 35 && je == 155)
	{
		g = 1;
		a = 3;
	}
	if (ie == 95 && je == 155)
	{
		g = 2;
		a = 3;
	}
	if (ie == 155 && je == 155)
	{
		g = 3;
		a = 3;
	}
	if (ie == 275 && je == 155)
	{
		g = 5;
		a = 3;
	}
	if (ie == 335 && je == 155)
	{
		g = 6;
		a = 3;
	}
	if (ie == 395 && je == 155)
	{
		g = 7;
		a = 3;
	}
	/*5*/
	if (ie == 35 && je == 275)
	{
		g = 1;
		a = 5;
	}
	if (ie == 95 && je == 275)
	{
		g = 2;
		a = 5;
	}
	if (ie == 155 && je == 275)
	{
		g = 3;
		a = 5;
	}
	if (ie == 275 && je == 275)
	{
		g = 5;
		a = 5;
	}
	if (ie == 335 && je == 275)
	{
		g = 6;
		a = 5;
	}
	if (ie == 395 && je == 275)
	{
		g = 7;
		a = 5;
	}
	/*6*/
	if (ie == 35 && je == 335)
	{
		g = 1;
		a = 6;
	}
	if (ie == 95 && je == 335)
	{
		g = 2;
		a = 6;
	}
	if (ie == 155 && je == 335)
	{
		g = 3;
		a = 6;
	}
	if (ie == 275 && je == 335)
	{
		g = 5;
		a = 6;
	}
	if (ie == 335 && je == 335)
	{
		g = 6;
		a = 6;
	}
	if (ie == 395 && je == 335)
	{
		g = 7;
		a = 6;
	}
	/*7*/
	if (ie == 35 && je == 395)
	{
		g = 1;
		a = 7;
	}
	if (ie == 95 && je == 395)
	{
		g = 2;
		a = 7;
	}
	if (ie == 155 && je == 395)
	{
		g = 3;
		a = 7;
	}
	if (ie == 275 && je == 395)
	{
		g = 5;
		a = 7;
	}
	if (ie == 335 && je == 395)
	{
		g = 6;
		a = 7;
	}
	if (ie == 395 && je == 395)
	{
		g = 7;
		a = 7;
	}
	return g;
}

int recpositiona(int ie, int je)
{
	int a = 0, g = 0;
	if (ie == 35 && je == 35)
	{
		g = 1;
		a = 1;
	}
	if (ie == 95 && je == 35)
	{
		g = 2;
		a = 1;
	}
	if (ie == 155 && je == 35)
	{
		g = 3;
		a = 1;
	}
	if (ie == 275 && je == 35)
	{
		g = 5;
		a = 1;
	}
	if (ie == 335 && je == 35)
	{
		g = 6;
		a = 1;
	}
	if (ie == 395 && je == 35)
	{
		g = 7;
		a = 1;
	}
	/*2*/
	if (ie == 35 && je == 95)
	{
		g = 1;
		a = 2;
	}
	if (ie == 95 && je == 95)
	{
		g = 2;
		a = 2;
	}
	if (ie == 155 && je == 95)
	{
		g = 3;
		a = 2;
	}
	if (ie == 275 && je == 95)
	{
		g = 5;
		a = 2;
	}
	if (ie == 335 && je == 95)
	{
		g = 6;
		a = 2;
	}
	if (ie == 395 && je == 95)
	{
		g = 7;
		a = 2;
	}
	/*3*/
	if (ie == 35 && je == 155)
	{
		g = 1;
		a = 3;
	}
	if (ie == 95 && je == 155)
	{
		g = 2;
		a = 3;
	}
	if (ie == 155 && je == 155)
	{
		g = 3;
		a = 3;
	}
	if (ie == 275 && je == 155)
	{
		g = 5;
		a = 3;
	}
	if (ie == 335 && je == 155)
	{
		g = 6;
		a = 3;
	}
	if (ie == 395 && je == 155)
	{
		g = 7;
		a = 3;
	}
	/*5*/
	if (ie == 35 && je == 275)
	{
		g = 1;
		a = 5;
	}
	if (ie == 95 && je == 275)
	{
		g = 2;
		a = 5;
	}
	if (ie == 155 && je == 275)
	{
		g = 3;
		a = 5;
	}
	if (ie == 275 && je == 275)
	{
		g = 5;
		a = 5;
	}
	if (ie == 335 && je == 275)
	{
		g = 6;
		a = 5;
	}
	if (ie == 395 && je == 275)
	{
		g = 7;
		a = 5;
	}
	/*6*/
	if (ie == 35 && je == 335)
	{
		g = 1;
		a = 6;
	}
	if (ie == 95 && je == 335)
	{
		g = 2;
		a = 6;
	}
	if (ie == 155 && je == 335)
	{
		g = 3;
		a = 6;
	}
	if (ie == 275 && je == 335)
	{
		g = 5;
		a = 6;
	}
	if (ie == 335 && je == 335)
	{
		g = 6;
		a = 6;
	}
	if (ie == 395 && je == 335)
	{
		g = 7;
		a = 6;
	}
	/*7*/
	if (ie == 35 && je == 395)
	{
		g = 1;
		a = 7;
	}
	if (ie == 95 && je == 395)
	{
		g = 2;
		a = 7;
	}
	if (ie == 155 && je == 395)
	{
		g = 3;
		a = 7;
	}
	if (ie == 275 && je == 395)
	{
		g = 5;
		a = 7;
	}
	if (ie == 335 && je == 395)
	{
		g = 6;
		a = 7;
	}
	if (ie == 395 && je == 395)
	{
		g = 7;
		a = 7;
	}
	return a;
}



/*print the first graphical board..........................................................................*/
void graphicboard(void)
{
	initwindow(480, 480, "Pentagol");/*size and name of page*/

									 /*deawing first graphical board*/
									 /*back ground*/
	setfillstyle(1, 4);/*color*/
	bar(0, 0, 480, 480);/*back ground rectagle*/
						/*lines*/
	setcolor(15);
	line(240, 0, 240, 480);
	line(0, 240, 480, 240);
	setfillstyle(1, 4);
	/*circules*/
	/*radife 1*/
	fillellipse(60, 60, 20, 20);
	fillellipse(120, 60, 20, 20);
	fillellipse(180, 60, 20, 20);
	fillellipse(300, 60, 20, 20);
	fillellipse(360, 60, 20, 20);
	fillellipse(420, 60, 20, 20);
	/*radife 2*/
	fillellipse(60, 120, 20, 20);
	fillellipse(120, 120, 20, 20);
	fillellipse(180, 120, 20, 20);
	fillellipse(300, 120, 20, 20);
	fillellipse(360, 120, 20, 20);
	fillellipse(420, 120, 20, 20);
	/*radife 3*/
	fillellipse(60, 180, 20, 20);
	fillellipse(120, 180, 20, 20);
	fillellipse(180, 180, 20, 20);
	fillellipse(300, 180, 20, 20);
	fillellipse(360, 180, 20, 20);
	fillellipse(420, 180, 20, 20);
	/*radife 5*/
	fillellipse(60, 300, 20, 20);
	fillellipse(120, 300, 20, 20);
	fillellipse(180, 300, 20, 20);
	fillellipse(300, 300, 20, 20);
	fillellipse(360, 300, 20, 20);
	fillellipse(420, 300, 20, 20);
	/*radife 6*/
	fillellipse(60, 360, 20, 20);
	fillellipse(120, 360, 20, 20);
	fillellipse(180, 360, 20, 20);
	fillellipse(300, 360, 20, 20);
	fillellipse(360, 360, 20, 20);
	fillellipse(420, 360, 20, 20);
	/*radife 7*/
	fillellipse(60, 420, 20, 20);
	fillellipse(120, 420, 20, 20);
	fillellipse(180, 420, 20, 20);
	fillellipse(300, 420, 20, 20);
	fillellipse(360, 420, 20, 20);
	fillellipse(420, 420, 20, 20);
}