#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int initialisation(int grille[9][9], int taille) {
	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			grille[i][j] = 0;
		}
	}
	return 0;
}

int main()
{
	int grille_facile[9][9] = {
		{6, 0, 4, 9, 0, 0, 3, 0, 8},
		{3, 2, 0, 8, 0, 0, 4, 0, 0},
		{0, 0, 0, 6, 0, 4, 5, 2, 1},
		{1, 0, 2, 7, 4, 3, 8, 9, 6},
		{8, 0, 0, 0, 0, 0, 0, 0, 0},
		{9, 4, 7, 5, 8, 0, 0, 0, 0},
		{4, 9, 0, 2, 0, 8, 6, 0, 3},
		{0, 3, 6, 4, 0, 0, 0, 0, 0},
		{0, 7, 0, 0, 6, 9, 0, 0, 4}
	};

	int grille_moyenne[9][9] = {
		{1, 0, 0, 7, 0, 6, 0, 0, 0},
		{0, 0, 0, 0, 0, 8, 5, 6, 0},
		{6, 0, 8, 0, 5, 3, 4, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 6},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 3, 0, 0, 0, 0, 0, 0, 0},
		{8, 4, 0, 3, 0, 1, 0, 5, 9}
	};

	int taille = 3;
	initialisation(grille_facile, taille);
	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			printf("%d", grille_facile[i][j]);
		}
		printf("\n");
	}

	initialisation(grille_moyenne, taille);
	for (int i = 0; i < taille; i++)
	{
		printf("\n");
		for (int j = 0; j < taille; j++)
		{
			printf("%d", grille_moyenne[i][j]);
		}
	}

	return 0;




	return 0;
}