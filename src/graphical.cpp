/*final graphical code of PENTAGOl game*/
/*CA 1 ((ICSP))*/
/*hosein ahmadzadeh 1399/1/17 */

/*LIBRARIES*/
#include<stdio.h>
#include <bgi/graphics.h>
#include "board.h"
#include "rules.h"
#include "input.h"

/*+++++++++++++++++++++++  main function  +++++++++++++++++++++++++*/
int main(void)
{
	graphicboard();

					  /*printing the gude of the game*/
	puts("Pentagol | Two-player board game");
	puts("Move with w/a/s/d in the board window. Press f to place a marble.");
	puts("In this terminal, enter + (clockwise) or - (counterclockwise), then a quadrant.");
	puts("Quadrants: 1 upper right, 2 upper left, 3 lower left, 4 lower right.");

	int xe = 0, ye = 0, ze = 0;/*counter of fors in graphical cursor part*/
	int ie = 35, je = 35;/*counter of fors in graphical cursor part*/
	char ch;/*control keys of gracphical boards*/

	int t = 0, f = 0;/*t is counter of b conditios and f is the counter of w conditoins*/
	int x = 0;/*variable of number of square*/
	char q = 0;/*variable of routation direction*/
	int round = 1;/*counter of round */


			 /*MAIN ARRAY*/
	char arr[8][8] = { ' ','1','2','3',' ','5','6','7',
		'1','.','.','.','|','.','.','.',
		'2','.','.','.','|','.','.','.',
		'3','.','.','.','|','.','.','.',
		' ','_','_','_','+','_','_','_',
		'5','.','.','.','|','.','.','.',
		'6','.','.','.','|','.','.','.',
		'7','.','.','.','|','.','.','.' };

	/*++++++++++   MAIN LOOP OF THE GAME FOR UP TO 36 TURNS    +++++++++++*/

	for (round = 1; round < 37; round++)
	{
		/*recognazing whos turn is it?*/
		char z;/*recongnizer of who's turn to play*/
		if ((round % 2) == 0)
		{
			z = 'w';
		}
		else
		{
			z = 'b';
		}
		printf("********************\n");
		printf("%c PLAYER'S TURN TO PLAY \n", z);

		/*printing the first cursor in (1,1) circle*/
		setcolor(15);
		rectangle(ie, je, ie + 50, je + 50);

		int a = 0, g = 0, i = 0, j = 0;/*(pirnting new board)'s counters*/


		/* IN THIS WHILE WE MOVE THE CURSOR, THEN RECOGNIZE THE POSISIONS OF IT WHEN "F" CKICKED, AND THEN WE CHANGE THE COLOR OF CHOSEN CIRCLE AND LINKED INDEX OF ARRAY*/

		while (1)
		{
			/*++++++++++ moving the cursur by A,S,F,W   ++++++++*/
			while (1)
			{

				ze = 0;
				ch = getch();/*scaning the entered character*//*checking below if's and again coming back to this command until scaning 'f' and break the while(kbhit)*/
		/*checking if it is w,a,s and d or not*/
				if (ch == 'w' || ch == 'a' || ch == 's' || ch == 'd')
				{
					/*d conditions*/
					/*if it is d we print a new square in right side of privius one*/
					if (ch == 'd')
					{
						/*if we are in (n,3) circles we have to move twice in board to rich to the next circle*/
						if (ie == 155)
						{
							ze = 60;
						}
						/*if we are in rightest circle we have to leave it and do to change the curcor to right position*/
						if (ie == 395)
						{
							continue;
						}
						/*we change the position of cursor by incrising the x pixle of it (if it is not in (n,3) ze=0*/
						xe = ze + 60;
						ye = 0;
					}
					/*a conditions*/
					if (ch == 'a')
					{
						if (ie == 275)
						{
							ze = -60;
						}
						if (ie == 35)
						{
							continue;
						}
						xe = ze - 60;
						ye = 0;
					}
					/*s conditions*/
					if (ch == 's')
					{
						if (je == 155)
						{
							ze = 60;
						}
						if (je == 395)
						{
							continue;
						}
						xe = 0;
						ye = ze + 60;
					}
					/*w conditions*/
					if (ch == 'w')
					{
						if (je == 275)
						{

							ze = -60;

						}
						if (je == 35)
						{
							continue;
						}
						xe = 0;
						ye = ze - 60;
					}
					/*if any of those keys entered, we change the value of je and ie and print a new cursor with new values*/
					ie = ie + xe;
					je = je + ye;
					/*we remove the privius cursor by printing it with background's color(red)*/
					setcolor(4);
					rectangle(ie - xe, je - ye, ie - xe + 50, je - ye + 50);
					/*we print the new cursor with white color with new valus*/
					setcolor(15);
					rectangle(ie, je, ie + 50, je + 50);
				}
				/*if the player entered f after moving the cursor we save the ie and je and we break the while */
				else
				{
					if (ch == 'f')
					{
						/*if 'f' entered we break the while(kbhit) */
						break;
					}
				}
			}

			/*transforming the graphical postision of cursur*/

			/*transformig 'ie' and 'je' ((graphical Coordinates)) to 'a' and 'g' (( 2D array coordinate)) with conditions, to print the main array and new graphical board*/
			g = recpositiong(ie, je);
			a = recpositiona(ie, je);

			/*printing the chosen circle into black or white*/

			/*checking if the chosen circle is empty or not*/
			if (arr[a][g] == '.')
			{
				/*if it's black player''s turn to play*/
				if (z == 'b')
				{
					/*change the color of chosen cicle into black*/
					setfillstyle(1, 0);
					fillellipse(g * 60, a * 60, 20, 20);
				}
				/*if it is white player's turn to play*/
				if (z == 'w')
				{
					/*change the color of chosen circle into white*/
					setfillstyle(1, 15);
					fillellipse(g * 60, a * 60, 20, 20);
				}

				/*change the value of chosen index into black or white*/
				arr[a][g] = z;

				/*break the while(1) to check wining conditions for w and b*/
				break;

			}
			/*if it is full print error and come back to the first of while(1) to get the position of cursor */
			else
			{
				printf("ERROR: this place is full!! try again ");
			}
		}


		/*++++++++++++++++     CHECK IF HTE PLAYER HAS WON THE GAME OR NOT (AFTER CHOOSING THE CIRCLE)   ++++++++++++++++++*/



		f = iswwon(arr);
		t = isbwon(arr);

		/*if t inclreased and f didn't increase we understand that b has won the game*//*and we finish the program*/
		if (t > 0 && f == 0)
		{
			printf("\n PLAYER b HAS WON  !!!!!!!\n");
			printf("PRESS ANY KEY IN GRAPHIC PAGE TO EXIT  !!!!!!!\n");
			getch();
			return 0;
		}
		/*if f inclreased and t didn't increase we understand that w has won the game*//*and we finish the program*/
		if (f > 0 && t == 0)
		{
			printf("\n PLAYER w HAS WON !!!!!!!\n");
			printf("PRESS ANY KEY IN GRAPHIC PAGE TO EXIT  !!!!!!!\n");
			getch();
			return 0;
		}
		/*if f inclreased and t increased we understand that w and  b  have won the game and draw*//*and we finish the program*/
		if (f > 0 && t > 0)
		{
			printf("\n DRAW  !!!!!!!!!!\n");
			printf("PRESS ANY KEY IN GRAPHIC PAGE TO EXIT  !!!!!!!\n");
			getch();
			return 0;
		}



		/*++++++++++++      GETING THE NUMBER OF SQUARE AND ROUTING DIRECTION FROAM PLAYER      +++++++++++++++*/


		/*getting roatate direction*/
		q = read_choice("Rotation (+ clockwise, - counterclockwise): ", "+-");
		if (!q) return 0;
		x = read_choice("Quadrant (1 upper right, 2 upper left, 3 lower left, 4 lower right): ", "1234");
		if (!x) return 0;
		x -= '0';
		changesquare(x, q, arr);

		/*pirnt the new game board after routating the square*/

		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				if (arr[i][j] == 'b' || arr[i][j] == 'w' || arr[i][j] == '.')
				{
					setfillstyle(1, 4);
					fillellipse(j * 60, i * 60, 20, 20);
				}
			}
		}
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				if (arr[i][j] == 'b')
				{
					setfillstyle(1, 0);
					fillellipse(j * 60, i * 60, 20, 20);
				}
				if (arr[i][j] == 'w')
				{
					setfillstyle(1, 15);
					fillellipse(j * 60, i * 60, 20, 20);
				}
			}
		}

		printf("\n");

		/*+++++++++++++      CHECK IF THE PLAYER HAS WON THE GAME OR NOT (AFTER ROURATING THE SQUARE)      ++++++++++++++++*/


		t = isbwon(arr);
		f = iswwon(arr);

		/*if t inclreased and f didn't increase we understand that b has won the game*//*and we finish the program*/
		if (t > 0 && f == 0)
		{
			printf("\nPLAYER B HAS WON !!!!!!!\n");
			getch();
			return 0;

		}
		/*if f inclreased and t didn't increase we understand that w has won the game*//*and we finish the program*/
		if (f > 0 && t == 0)
		{
			printf("\nPLAYER W HAS WON !!!!!!!\n");
			printf("PRESS ANY KEY IN GRAPHIC PAGE TO EXIT  !!!!!!!\n");
			getch();
			return 0;
		}
		/*if f inclreased and t increased we understand that w and  b  have won the game and draw*//*and we finish the program*/
		if (f > 0 && t > 0)
		{
			printf("\nDRAW!!!!!!!!!!\n");
			printf("PRESS ANY KEY IN GRAPHIC PAGE TO EXIT  !!!!!!!\n");
			getch();
			return 0;
		}

		/*++++++++++++++      CHECK IF IS IT THE LAST ROUND OF THE GAME OR NOT     +++++++++++++*/


		if (round == 36)
		{
			/*if it is, the game is draw*/
			printf("DRAW....!!!!\n");
			printf("PRESS ANY KEY IN GRAPHIC PAGE TO EXIT  !!!!!!!\n");
			getch();
			return 0;
		}

	}
	/* THE MAIN LOOP FINISHED*/
}
