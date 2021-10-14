/*
This is a magic card game.
In this game player choose a one number from 0 to 63.
Then enter y/Y if your number is in the card else type n/N.
Then last magic is program is give you a number which player choose.

Happy Magic :)

*/

#include <stdio.h>

int main()
{
	int choice,i,j,ans=0;
	char ans_c1,ans_c2,ans_c3,ans_c4,ans_c5,ans_c6;

	int card_1[8][4] = {	{1,3,5,7},
							{9,11,13,15},
							{17,19,21,23},
							{25,27,29,31},
							{33,35,37,39},
							{41,43,45,47},
							{49,51,53,55},
							{57,59,61,63}	};

	int card_2[8][4] = {	{2,3,6,7},
							{10,11,14,15},
							{18,19,22,23},
							{26,27,30,31},
							{34,35,38,39},
							{42,43,46,47},
							{50,51,54,55},
							{58,59,62,63}	};

	int card_3[8][4] = {	{4,5,6,7},
							{12,13,14,15},
							{20,21,22,23},
							{28,29,30,31},
							{36,37,38,39},
							{44,45,46,47},
							{52,53,54,55},
							{60,61,62,63}	};

	int card_4[8][4] = {	{16,17,18,19},
							{20,21,22,23},
							{24,25,26,27},
							{28,29,30,31},
							{48,49,50,51},
							{52,53,54,55},
							{56,57,58,59},
							{60,61,62,63}	};

	int card_5[8][4] = {	{32,33,34,35},
							{36,37,38,39},
							{40,41,42,43},
							{44,45,46,47},
							{48,49,50,51},
							{52,53,54,55},
							{56,57,58,59},
							{60,61,62,63}	};

	int card_6[8][4] = {	{8,9,10,11},
							{12,13,14,15},
							{24,25,26,27},
							{28,29,30,31},
							{40,41,42,43},
							{44,45,46,47},
							{56,57,58,59},
							{60,61,62,63}	};

	
	printf("\nChoose any number between 0 to 63.\n\n");

// card_1	
	printf("\ncard_1 \n");

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf(" %d  ",card_1[i][j]);
		}
		printf("\n");
	}

	printf("\nYour number is available in card 1 (Y or y)or(N or n)\n");
	scanf("%c",&ans_c1);
	scanf("%c");

	if (ans_c1 == 'Y' || ans_c1 == 'y')
	{
		ans=ans+card_1[0][0];
	}


// card_2

	printf("\ncard_2 \n");

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf(" %d  ",card_2[i][j]);
		}
		printf("\n");
	}

	printf("\nYour number is available in card 2 (Y or y)or(N or n)\n");
	scanf("%c",&ans_c2);
	scanf("%c");

	if (ans_c2 == 'Y' || ans_c2 == 'y')
	{
		ans=ans+card_2[0][0];
	}

// card_3

	printf("\ncard_3 \n");

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf(" %d  ",card_3[i][j]);
		}
		printf("\n");
	}

	printf("\nYour number is available in card 3 (Y or y)or(N or n)\n");
	scanf("%c",&ans_c3);
	scanf("%c");

	if (ans_c3 == 'Y' || ans_c3 == 'y')
	{
		ans=ans+card_3[0][0];
	}

// card_4

	printf("\ncard_4 \n");

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf(" %d  ",card_4[i][j]);
		}
		printf("\n");
	}

	printf("\nYour number is available in card 4 (Y or y)or(N or n)\n");
	scanf("%c",&ans_c4);
	scanf("%c");

	if (ans_c4 == 'Y' || ans_c4 == 'y')
	{
		ans=ans+card_4[0][0];
	}

// card_5

	printf("\ncard_5 \n");

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf(" %d  ",card_5[i][j]);
		}
		printf("\n");
	}

	printf("\nYour number is available in card 5 (Y or y)or(N or n)\n");
	scanf("%c",&ans_c5);
	scanf("%c");

	if (ans_c5 == 'Y' || ans_c5 == 'y')
	{
		ans=ans+card_5[0][0];
	}

// card_6

	printf("\ncard_6 \n");

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf(" %d  ",card_6[i][j]);
		}
		printf("\n");
	}

	printf("\nYour number is available in card 4 (Y or y)or(N or n)\n");
	scanf("%c",&ans_c6);
	scanf("%c");

	if (ans_c6 == 'Y' || ans_c6 == 'y')
	{
		ans=ans+card_6[0][0];
	}

	printf("\nYour number is:  %d",ans);

	return 0;
}
