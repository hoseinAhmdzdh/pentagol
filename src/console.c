/*final cmd code of PENTAGOl game*/
/* CA 1 (ICSP) */
/*hosein ahmadzadeh 1399/1/17 */

/*LIBRARIES*/
#include<stdio.h>

#include "rules.h"
#include "input.h"

/*+++++++++++++++++++++++  main function  +++++++++++++++++++++++++*/
int main(void)
{
	int a = 0, g = 0, i = 0, j = 0;/*(pirnting new board)'s counters*/
	int t = 0, f = 0;/*t is counter of b conditios and f is the counter of w conditoins*/
	int x = 0;/*variable of number of square*/
	char q = 0;/*variable of routation direction*/
	int round = 1;/*counter of round */

				  /*namayesh avalin safehe bazi*/
	char arr[8][8] = { ' ','1','2','3',' ','5','6','7',
		'1','.','.','.','|','.','.','.',
		'2','.','.','.','|','.','.','.',
		'3','.','.','.','|','.','.','.',
		' ','_','_','_','+','_','_','_',
		'5','.','.','.','|','.','.','.',
		'6','.','.','.','|','.','.','.',
		'7','.','.','.','|','.','.','.' };
	for (i = 0; i < 8; i++)
	{
		if (i >= 1)
		{
			printf("\n\n");
		}

		for (j = 0; j < 8; j++)
		{
			printf("%c\t", arr[i][j]);
		}
	}

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
		printf("\n********************\n");
		printf("%c PLAYER'S TURN TO PLAY \n", z);

       /*IN THIS WHILE WE GET THE POSTION OF NUT FROM PLAYER AND RECOGNIZE IF IT IS WALID PLACE OR NOT AND IF IT IS CORECT WE PRINT THE MEW BOARD*/
		while (1)
		{
			a = read_choice("Row (1, 2, 3, 5, 6, 7): ", "123567");
			if (!a) return 0;
			g = read_choice("Column (1, 2, 3, 5, 6, 7): ", "123567");
			if (!g) return 0;
			a -= '0';
			g -= '0';
			if (arr[a][g] == '.')
			{
				arr[a][g] = z;
				for (i = 0; i < 8; i++)
				{
					if (i >= 1)
					{
						printf("\n\n");
					}
					for (j = 0; j < 8; j++)
					{
						printf("%c\t", arr[i][j]);
					}
				}
				printf("\n");
				break;
			}
			else
			{
				puts("That position is occupied. Choose another.");
			}
		}

		/*++++++++++++++++     CHECK IF HTE PLAYER HAS WON THE GAME OR NOT (AFTER CHOOSING THE CIRCLE)   ++++++++++++++++++*/



		f = iswwon(arr);
		t = isbwon(arr);

		/*if t inclreased and f didn't increase we understand that b has won the game*//*and we finish the program*/
		if (t > 0 && f == 0)
		{
			printf("\n PLAYER b HAS WON  !!!!!!!\n");
			return 0;
		}
		/*if f inclreased and t didn't increase we understand that w has won the game*//*and we finish the program*/
		if (f > 0 && t == 0)
		{
			printf("\n PLAYER w HAS WON !!!!!!!\n");
			return 0;
		}
		/*if f inclreased and t increased we understand that w and  b  have won the game and draw*//*and we finish the program*/
		if (f > 0 && t > 0)
		{
			printf("\n DRAW  !!!!!!!!!!\n");
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

		/*pirnt the new game board afet routating*/
		for (i = 0; i < 8; i++)
		{
			if (i >= 1)
			{
				printf("\n\n");
			}

			for (j = 0; j < 8; j++)
			{
				printf("%c\t", arr[i][j]);
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
			return 0;

		}
		/*if f inclreased and t didn't increase we understand that w has won the game*//*and we finish the program*/
		if (f > 0 && t == 0)
		{
			printf("\nPLAYER W HAS WON !!!!!!!\n");
			return 0;
		}
		/*if f inclreased and t increased we understand that w and  b  have won the game and draw*//*and we finish the program*/
		if (f > 0 && t > 0)
		{
			printf("\nDRAW!!!!!!!!!!\n");
			return 0;
		}

		/*++++++++++++++      CHECK IF IS IT THE LAST ROUND OF THE GAME OR NOT     +++++++++++++*/


		if (round == 36)
		{
			/*if it is, the game is draw*/
			printf("DRAW....!!!!\n");
			return 0;
		}

	}
}
