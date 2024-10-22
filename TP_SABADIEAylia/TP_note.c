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
		if (colonne < taille && colonne>=0 && ligne < taille && ligne>=0)
		{
			for (int i = 0; i < taille; i++)
			{
				if (grille[ligne][i] == valeur || grille[i][colonne] == valeur)
				{
					return 0;
				}
			}
			return 1;
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
}

int gagner(int grille[9][9], int taille)
{
	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			if (grille[i][j] == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

int remplir(int grille[9][9], int taille) {
	int ligne = 0;
	int colonne = 0;
	int valeur = 0;
	int continuer = 1;
	int victoire = 0;
	while (continuer == 1)
	{
		printf("\nQuelle ligne souhaitez-vous modifier? ");
		scanf_s("%d", &ligne);
		printf("\nQuelle colonne souhaitez-vous modifier? ");
		scanf_s("%d", &colonne);
		printf("\nQuelle est votre valeur? ");
		scanf_s("%d", &valeur);
		int verification = verifier(grille,valeur, colonne-1, ligne-1, taille);
		if (verification == 1)
		{
			grille[ligne - 1][colonne - 1] = valeur;
		}
		else
		{
			printf("\nLes caracteristiques de votre valeur sont incorrectes.\n");
		}
		victoire = gagner(grille, taille);
		if (victoire == 1)
		{
			printf("\nFelicitations, vous avez gagne!");
			continuer = 0;
		}
		else
		{
			printf("\nSouhaitez-vous modifier une autre valeur? (oui - 1 / non - 0) : ");
			scanf_s("%d", &continuer);
		}
	}
	printf("\n");
	return 0;
}

int preremplir(int grille[9][9], int taille, int remplissage)
{
	int nombre_valeurs = (taille*taille) / (remplissage + 1);
	int ligne = 0;
	int colonne = 0;
	int nombre = 0;
	int verification = 0;
	for (int i = 0; i < nombre_valeurs; i++)
	{
		ligne = rand() % taille;
		colonne = rand() % taille;
		while (grille[ligne][colonne] != 0)
		{
			ligne = rand() % taille;
			colonne = rand() % taille;
		}
		nombre = rand() % taille + 1;
		verification = verifier(grille, nombre, colonne, ligne, taille);
		if (verification == 1)
		{
			grille[ligne][colonne] = nombre;
		}
		else
		{ 
			while (verification == 0)
			{
				nombre = rand() % taille +1;
				verification = verifier(grille, nombre, colonne, ligne, taille);
				if (verification == 1)
				{
					grille[ligne][colonne] = nombre;
				}
			}
		}
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
	srand(time(NULL));
	int continuer = 1;
	
	while (continuer==1)
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

		int taille =9;
		int initialiser = 0;
		int aleatoire = 0;
		int niveau = 0;
		int resoudre = 0;
		printf("Voici votre grille actuelle par defaut :\n\n");
		affichage(grille_moyenne, taille);
		printf("\nVeuillez saisir la taille de la grille voulue comprise entre 1 et 9 : ");
		scanf_s("%d", &taille);
		if (taille >= 1 && taille <= 9)
		{
			printf("\nVoulez-vous initialiser la grille? (oui - 1 / non - 0) : ");
			scanf_s("%d", &initialiser);
			if (initialiser == 1)
			{
				initialisation(grille_moyenne, taille);
				printf("\nVoulez-vous remplir aleatoirement ou manuellement la grille? (aleatoirement - 1 / manuellement - 2) : ");
				scanf_s("%d", &aleatoire);
				if (aleatoire == 1)
				{
					printf("\nVeuillez saisir votre niveau (1, 2 ou 3) : ");
					scanf_s("%d", &niveau);
					preremplir(grille_moyenne, taille, niveau);
					printf("\nVoici votre grille :\n\n");
					affichage(grille_moyenne, taille);
				}
				else if (aleatoire == 2)
				{
					remplir(grille_moyenne, taille);
					printf("\nVoici votre grille :\n\n");
					affichage(grille_moyenne, taille);
				}
			}

			int tailleGrille = sizeof(grille_moyenne) / sizeof(grille_moyenne)[0];
			printf("\nVoulez-vous tenter de resoudre la grille? (oui - 1 / non - 0) : ");
			scanf_s("%d", &resoudre);
			if (resoudre == 1)
			{
				if ((initialiser == 1 && (aleatoire == 1 || aleatoire == 2)) || taille == tailleGrille)
				{
					remplir(grille_moyenne, taille);
				}
				else
				{
					printf("\nIl n'y a pas de grille a resoudre.");
				}
			}
			if (taille == tailleGrille)
			{
				printf("Voici votre grille :\n\n");
				affichage(grille_moyenne, taille);
			}
		}
		else
		{
			printf("\nLa taille de la grille est incorrecte.");
		}
		printf("\n\nVoulez-vous recommencer? (oui - 1 / non - 0) : ");
		scanf_s("%d", &continuer);
		printf("\n");
	}
	return 0;
}