#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/* ---------- liste.h ----------- */

typedef struct Point
{
    int x;
    int y;
    int z;

}Point;

typedef struct ElementListe
{
  Point pt;
  struct ElementListe *suivant;
} Element;
typedef struct ListeRepere
{
  Element *debut;
  Element *fin;
  int taille;
} Liste;

extern void initialisation (Liste * liste);
extern int insListeVide (Liste * liste, Point *point);
extern int insDebutListe (Liste * liste, Point *point);
extern int insFinListe (Liste * liste, Element * courant, Point *point);
extern int insListe (Liste * liste, Point *point, int pos);
extern int suppDebut (Liste * liste);
extern int suppDansListe (Liste * liste, int pos);
extern int menu (Liste *liste,int *k);
extern void affiche (Liste * liste);
extern void detruire (Liste * liste);

/* -------- FIN liste.h --------- */
#endif // LIST_H_INCLUDED

