#include "liste.h"

int main (void)
{
  char choix;
  Point point;
  Liste *liste;
  //Element *courant;
  if ((liste = (Liste *) malloc (sizeof (Liste))) == NULL)
    return -1;
  //courant = NULL;
  choix = 'o';
  initialisation (liste);
  int pos, k;
  while (choix != 7){
      choix = menu (liste, &k);
      switch (choix){
        case 1:
          printf ("Entrez 3 elements : ");
          scanf ("%d", &point.x);
          scanf ("%d", &point.y);
          scanf ("%d", &point.z);
          getchar ();
          if (liste->taille == 0)
            insListeVide(liste, &point);
          else
            insDebutListe (liste, &point);
          printf ("%d elements:deb=%d %d %d,fin=%d %d %d\n", liste->taille,
                  liste->debut->pt.x,liste->debut->pt.y,liste->debut->pt.z,liste->fin->pt.x,liste->fin->pt.y,liste->fin->pt.z);
          affiche (liste);
          break;
        case 2:
          printf ("Entrez 3 elements : ");
          scanf ("%d", &point.x);
          scanf ("%d", &point.y);
          scanf ("%d", &point.z);
          getchar ();
          insFinListe (liste, liste->fin, &point);
          printf ("%d elements:deb=%d %d %d,fin=%d %d %d\n", liste->taille,
                  liste->debut->pt.x,liste->debut->pt.y,liste->debut->pt.z,liste->fin->pt.x,liste->fin->pt.y,liste->fin->pt.z);
          affiche (liste);
          break;

        case 3:
          printf ("Entrez 3 elements : ");
          scanf ("%d", &point.x);
          scanf ("%d", &point.y);
          scanf ("%d", &point.z);
          getchar ();
          do{
              printf ("Entrez la position : ");
              scanf ("%d", &pos);
     }
          while (pos < 1 || pos > liste->taille);
          getchar ();
          if (liste->taille == 1 || pos == liste->taille){
              k = 1;
              printf("-----------------------------------------------\n");
              printf("Insertion echouée.Utilisez le menu {1|2}  \n");
              printf("-----------------------------------------------\n");
              break;
     }
          insListe (liste, &point, pos);
          printf ("%d elements:deb=%d %d %d,fin=%d %d %d\n", liste->taille,
                  liste->debut->pt.x,liste->debut->pt.y,liste->debut->pt.z,liste->fin->pt.x,liste->fin->pt.y,liste->fin->pt.z);
          affiche (liste);
          break;

        case 4:
          suppDebut (liste);
          if (liste->taille != 0)
            printf ("%d elements:deb=%d %d %d,fin=%d %d %d\n", liste->taille,
                    liste->debut->pt.x,liste->debut->pt.y,liste->debut->pt.z,liste->fin->pt.x,liste->fin->pt.y,liste->fin->pt.z);
          else
            printf ("liste vide\n");
          affiche (liste);
          break;
        case 5:
          do{
              printf ("Entrez la position : ");
              scanf ("%d", &pos);
     }
          while (pos < 1 || pos > liste->taille);
          getchar ();
          suppDansListe (liste, pos);
          if (liste->taille != 0)
            printf ("%d elements:deb=%d %d %d,fin=%d %d %d\n", liste->taille,
                    liste->debut->pt.x,liste->debut->pt.y,liste->debut->pt.z,liste->fin->pt.x,liste->fin->pt.y,liste->fin->pt.z);
          else
            printf ("liste vide\n");
          affiche (liste);
          break;

        case 6:
          detruire (liste);
          printf ("la liste a ete detruite : %d elements\n", liste->taille);
          break;
      }
  }
  return 0;
}
