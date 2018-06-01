#include "liste.h"

void initialisation (Liste * liste)
{
  liste->debut = NULL;
  liste->fin = NULL;
  liste->taille = 0;
}

int insListeVide(Liste * liste,Point *point){

  Element *nouveau_element;
  if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)
    return -1;

    nouveau_element->pt.x = point->x;
    nouveau_element->pt.y = point->y;
    nouveau_element->pt.z = point->z;

  nouveau_element->suivant = NULL;
  liste->debut = nouveau_element;
  liste->fin = nouveau_element;
  liste->taille++;
  return 0;
}

int insDebutListe (Liste * liste, Point *point){
 Element *nouveau_element;
  if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)
    return -1;

  nouveau_element->pt.x = point->x;
  nouveau_element->pt.y = point->y;
  nouveau_element->pt.z = point->z;

  nouveau_element->suivant = liste->debut;
  liste->debut = nouveau_element;
  liste->taille++;
  return 0;
}

int insFinListe (Liste * liste, Element * courant, Point *point){
  Element *nouveau_element;
  if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)
    return -1;

  nouveau_element->pt.x = point->x;
  nouveau_element->pt.y = point->y;
  nouveau_element->pt.z = point->z;

  courant->suivant = nouveau_element;
  nouveau_element->suivant = NULL;
  liste->fin = nouveau_element;
  liste->taille++;
  return 0;
}

/* insertion à la position demandée */
int insListe (Liste * liste, Point *point, int pos){
  if (liste->taille < 2)
    return -1;
  if (pos < 1 || pos >= liste->taille)
    return -1;
  Element *courant;
  Element *nouveau_element;
  int i;
  if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)
    return -1;
  courant = liste->debut;
  for (i = 1; i < pos; ++i)
    courant = courant->suivant;
  if (courant->suivant == NULL)
    return -1;

  nouveau_element->suivant = courant->suivant;
  courant->suivant = nouveau_element;
  liste->taille++;
  return 0;
}

int suppDebut (Liste * liste){
  if (liste->taille == 0)
    return -1;
  Element *supp_element;
  supp_element = liste->debut;
  liste->debut = liste->debut->suivant;
  if (liste->taille == 1)
    liste->fin = NULL;
  free (supp_element);
  liste->taille--;
  return 0;
}

/* supprimer un element après la position demandée */
int suppDansListe (Liste * liste, int pos){
  if (liste->taille <= 1 || pos < 1 || pos >= liste->taille)
    return -1;
  int i;
  Element *courant;
  Element *supp_element;
  courant = liste->debut;
  for (i = 1; i < pos; ++i)
    courant = courant->suivant;
  supp_element = courant->suivant;
  courant->suivant = courant->suivant->suivant;
  if(courant->suivant == NULL)
          liste->fin = courant;
  free (supp_element);
  liste->taille--;
  return 0;
}

/* affichage de la liste */
void affiche (Liste * liste){
  Element *courant;
  courant = liste->debut;
  while (courant != NULL){
      printf ("%d - %d -%d \n",courant->pt.x,courant->pt.y,courant->pt.z);
      courant = courant->suivant;
  }
}
/* detruire la liste */
void detruire (Liste * liste){
  while (liste->taille > 0)
    suppDebut (liste);
}

int menu (Liste *liste,int *k){
  int choix;
  printf("********** MENU **********\n");
  if (liste->taille == 0){
    printf ("1. Ajout du 1er element\n");
    printf ("2. Quitter\n");
  }else if(liste->taille == 1 || *k == 1){
    printf ("1. Ajout au debut de la liste\n");
    printf ("2. Ajout a la fin de la liste\n");
    printf ("4. Suppression au debut de la liste\n");
    printf ("6. Detruire la liste\n");
    printf ("7. Quitter\n");
  }else {
    printf ("1. Ajout au debut de la liste\n");
    printf ("2. Ajout a la fin de la liste\n");
    printf ("3. Ajout apres la position specifie\n");
    printf ("4. Suppression au debut de la liste\n");
    printf ("5. Suppression apres la position specifie\n");
    printf ("6. Detruire la liste\n");
    printf ("7. Quitter\n");
  }
  printf ("\n\nFaites votre choix : ");
  scanf ("%d", &choix);
  getchar();
  if(liste->taille == 0 && choix == 2)
    choix = 7;
  return choix;
}

