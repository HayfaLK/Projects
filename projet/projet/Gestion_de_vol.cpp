#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"struct_et_fcts.h"

void main()
{
	vol *t;
	int n, id;
	menuprincipal();
	switch (getchar())
	{
	case '1':
		remplir_vols(t, &n);
		goto etiquette;
		break;
	case '2':
		ajouter_vol(t,&n);
		goto etiquette;
		break;
	case '3':
		supprimer(t, n);
		goto etiquette;
		break;
	case '4':
		printf("Saisir l' ID du vol :");
		scanf_s("%d", &id);
		rechercher_vol(id,*t, n);
		goto etiquette;
		break;
	case '5':
		afficher_vols(t, n);
		goto etiquette;
		break;
	case '6':
		modifier(t, n);
		goto etiquette;
		break;
	case '7':
		fermerapplication();
	default: printf("\nERREUR!!!! ENTRER VOTRE CHOIX DE NOUVEAU");

	}
etiquette:menuprincipal();
	_getch();
}