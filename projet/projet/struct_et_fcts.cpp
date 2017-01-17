#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"struct_et_fcts.h"
int verification_date(int h, int mn, int s, int j, int m, int a)
{
	int verif_d = 0, verif_h = 0;
	if (m>=1 && m<=12)
	{
		if ((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)&&(j>=1 && j<=31)) verif_d=1;
		else if ((m==2)&&(j>=1 && j<=29)) verif_d=1;
		else if (j>=1 && j<=30) verif_d=1;

	}
	if ((h>=0 && h<=23) &&(mn>=0 && mn<=59)&&(s>=0 && s<=59)) verif_h = 1;
	return(verif_d && verif_h);
}
vol remplir_un_vol()
{
	vol v;
	printf("Numéro de vol :");
	scanf_s("%d", &v.idvol);
	printf("Aeroport de départ :");
	scanf_s("%s", v.aeroportdep);
	printf("Aeroport d'arrivé :");
	scanf_s("%s", v.aeroportarr);
	do
	{
		printf("Date de départ ");
		scanf_s("%d%d%d%d%d%d", &v.dep.jour, &v.dep.mois, &v.dep.annee, &v.dep.h, &v.dep.min, &v.dep.sec);
	} while (!verification_date(v.dep.jour, v.dep.mois, v.dep.annee, v.dep.h, v.dep.min, v.dep.sec));
	do
	{
		printf("Date d'arrivée ");
		scanf_s("%d%d%d%d%d%d", &v.arr.jour, &v.arr.mois, &v.arr.annee, &v.arr.h, &v.arr.min, &v.arr.sec);
	} while (!verification_date(v.arr.jour, v.arr.mois, v.arr.annee, v.arr.h, v.arr.min, v.arr.sec));
	do
	{
		printf("Etat de vol:");
		scanf_s("%s", &v.etatvol);
	} while (v.etatvol != "Programmée" || v.etatvol != "En vol" || v.etatvol != "Atterri" || v.etatvol != "Retradé" || v.etatvol != "Annulé");
	printf("Comapgnie:");
	scanf_s("%s", &v.compagnie);

	return v;
}
void remplir_vols(vol *v, int* n)
{
	printf("saisir le nombre maximal de vols");
	scanf_s("%d", n);
	v= (vol*)malloc(*n *sizeof(vol));
	if (!v) exit(-1);

	for (int i = 0; i < *n; i++)
		*(v + i) = remplir_un_vol();

}
void afficher_un_vol(vol v)
{
	printf("Numéro de vol :%d", v.idvol);
	printf("Aeroport de départ : %s", v.aeroportdep);
	printf("Aeroport d'arrivé : %s", v.aeroportarr);
	printf("Date de départ : %d/%d/%d %d:%d:%d ", v.dep.jour, v.dep.mois, v.dep.annee, v.dep.h, v.dep.min, v.dep.sec);
	printf("Date d'arrivée : %d/%d/%d %d:%d:%d", v.arr.jour, v.arr.mois, v.arr.annee, v.arr.h, v.arr.min, v.arr.sec);
	printf("Etat de vol: %s", v.etatvol);
	printf("Comapgnie: %s", v.compagnie);
}
void afficher_vols(vol *v, int n)
{
	int i;
	for (i = 0; i<n; i++)
		afficher_un_vol(*(v + i));
}
int rechercher_vol(int id, vol *T, int n)
{
	int i, j = -1;
	for (i = 0; i < n; i++)
	{
		if (T[i].idvol == id)
			j = i;

	}
	return(j);
}
void supprimer_case(vol *T, int n, int i)
{
	int j;
	for (j = i; j<n; j++)
		T[j] = T[j + 1];
	n--;
}
void supprimer(vol *T, int N)
{
eti:
	int a, b;
	printf("donnez l'id du vol à supprimer");
	scanf_s("%d", &a);
	b = rechercher_vol(a, T, N);
	if (b == -1)
		printf("ce vol  n'existe pas");
	else
		supprimer_case(T, N, b);
	printf("vol bien supprimé; Voulez vous supprimer un autre ?\n1.Oui\n2.Non\n");
	if (getchar() == '1')
		goto eti;
}
void modifier(vol *T, int N)
{
	int b, a;
	printf("donnez l'id du vol  à modifier");
	scanf_s("%d", &a);
	b = rechercher_vol(a, T, N);
	if (b==-1)
		printf("ce vol n'existe pas");
	else
	etiq:printf("veuillez entrer votre choix ");
	printf("1.Numéro de vol");
	printf("2.Ligne");
	printf("3.Date de départ");
	printf("4.Date d'arrivée");
	printf("5.Etat de vol");
	printf("6.Compagnie");
	printf("0.Menu principal");
	switch (getchar())
	{
	case '1':
		printf("donner le nouveau numéro");
		scanf_s("%d", &T[b].idvol);
		goto etiq;
		break;
	case '2':
		printf("donner la nouvelle ligne");
		scanf_s("%s%s", &T[b].aeroportdep, &T[b].aeroportarr);
		goto etiq;
		break;
	case '3':
		printf("donner la nouvelle date de départ");
		scanf_s("%d%d%d%d%d%d", &T[b].dep.jour, &T[b].dep.mois, &T[b].dep.annee, &T[b].dep.h, &T[b].dep.min, &T[b].dep.sec);
		goto etiq;
		break;
	case '4':
		printf("donner la nouvelle date d'arrivée");
		scanf_s("%d%d%d%d%d%d", &T[b].arr.jour, &T[b].arr.mois, &T[b].arr.annee, &T[b].arr.h, &T[b].arr.min, &T[b].arr.sec); break;
		goto etiq;
		break;
	case '5':
		printf("donner la nouvelle état de vol");
		scanf_s("%s", &T[b].etatvol);
		goto etiq;
		break;
		;
	case '6': printf("donner la nouvelle compagnie");
		scanf_s("%d", &T[b].compagnie);
		goto etiq;
		break;
	case'0': break;
	default:printf("\n ERREUR!!!! ENTRER VOTRE CHOIX DE NOUVEAU");
	}
}
void menuprincipal()
{
	printf("  \n MENU PRINCIPAL _\n");
	printf("\n 1. Créer une liste des vols   ");

	printf("\n 2. Ajouter un vol   ");

	printf("\n 3. Supprimer un vol ");

	printf("\n 4. Chercher un vol");

	printf("\n 5. Accéder à la liste des vols");

	printf("\n 6. Modifier les infos du vol ");

	printf("\n 7. Fermer l'application");

	printf("\n.................\n ");

	printf("Veuillez entrer votre choix:");

}
void fermerapplication()
{
	printf("   Fin......\n ");
	printf("Projet Réalisé par:");
	printf("lakhdar hayfa\n");
	printf("***1 ere annee genie informatique groupe B***\n");
	printf("Mansouri AmaL\n");
	printf("***1 ere annee genie informatique groupe A***\n");
	printf("Fermeture dans 3 secondes.........");

	exit(0);

}
void ajouter_vol(vol *v, int *n)
{
	v = (vol*)realloc(v, (*n + 1)*sizeof(vol));
	*(v + *n) = remplir_un_vol();
	*n++;
}

