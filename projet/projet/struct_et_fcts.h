struct DATE
{
	int h;
	int min;
	int sec;
	int jour;
	int mois;
	int annee;
};
typedef DATE date;

struct VOL
{
	int idvol;
	char aeroportdep[50];
	char aeroportarr[50];
	date dep;
	date arr;
	char etatvol[10];
	char compagnie[50];

};
typedef VOL vol;
int verification_date(int, int, int, int, int, int);
vol remplir_un_vol();
void remplir_vols(vol*, int*);
void afficher_un_vol(vol);
void ajouter_vol(vol*, int*);
void afficher_vols(vol*, int);
int rechercher_vol(int, vol, int);
void supprimer_case(vol*, int, int);
void supprimer(vol*, int);
void modifier(vol*, int);
void menuprincipal();
void fermerapplication();