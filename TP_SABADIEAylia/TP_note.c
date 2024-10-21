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

int verifier(int grille[9][9],int valeur, int colonne, int ligne, int taille)
{
	if (valeur >= 1 && valeur <= taille)
	{
		if (colonne <= taille && colonne>0 && ligne <= taille && ligne>0)
		{
			for (int i = 0; i < taille; i++)
			{
				if (grille[ligne-1][i] == valeur)
				{
					return 0;
				}
			}
			for (int j = 0; j < taille; j++)
			{
				if (grille[j][colonne-1] == valeur)
				{
					return 0;
				}
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
	return 1;
	
}

int remplir(int grille[9][9], int taille) {
	int ligne = 0;
	int colonne = 0;
	int valeur = 0;
	int continuer = 1;
	while (continuer == 1)
	{
		printf("\nQuelle ligne souhaitez-vous modifier? ");
		scanf_s("%d", &ligne);
		printf("\nQuelle colonne souhaitez-vous modifier? ");
		scanf_s("%d", &colonne);
		printf("\nQuelle est votre valeur? ");
		scanf_s("%d", &valeur);
		int verification = verifier(grille,valeur, colonne, ligne, taille);
		if (verification == 1)
		{
			grille[ligne - 1][colonne - 1] = valeur;
		}
		else
		{
			printf("\nLes caracteristiques de votre valeur sont incorrectes.\n");
		}
		printf("\nSouhaitez-vous modifier une autre valeur? (oui - 1 / non - 0) ");
		scanf_s("%d", &continuer);
	}
	return 0;
}

int preremplir(int grille[9][9], int taille, int remplissage)
{
	int nombre_valeurs = (taille*taille) / (remplissage + 1);
	srand(time(NULL));
	int ligne = 0;
	int colonne = 0;
	for (int i = 0; i < nombre_valeurs; i++)
	{
		ligne = rand() % taille;
		colonne = rand() % taille;
		while (grille[ligne][colonne] != 0)
		{
			ligne = rand() % taille;
			colonne = rand() % taille;
		}
		int nombre = rand() % taille + 1;
		grille[ligne][colonne] = nombre;
	}
	return 0;
}

int affichage(int grille[9][9], int taille)
{
	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			if (grille[i][j] == 0)
			{
				if (j == taille - 1)
				{
					printf(" ");
				}
				else
				{
					printf("   |  ");
				}
			}
			else if (j == taille - 1)
			{
				printf("%d", grille[i][j]);
			}
			else
			{
				printf("%d  |  ", grille[i][j]);
			}
		}
		printf("\n-");
		for (int j = 0; j < taille-1; j++)
		{
			printf("------");
		}
		printf("\n");
	}
	return 0;
}

int main()
{
	
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

	int taille =3;
	initialisation(grille_moyenne, taille);
	preremplir(grille_moyenne, taille, 2);
	affichage(grille_moyenne, taille);
	remplir(grille_moyenne, taille);
	affichage(grille_moyenne, taille);

	return 0;
}