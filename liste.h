/* En-tete de liste
   ----------------
   objectif : définir le TAA liste */
   
#ifndef _Liste_h
#define _Liste_h

// définir le type T_liste (typedef ...)
typedef struct node{
    int value ; 
    struct node *next ; 
}T_Node ; 
typedef T_Node *T_List ;

    
// prototypes des méthodes

// creation liste vide
T_List creer_liste();
// ajout en tete de liste de element avec modification de la liste
void ajout_entete_liste(T_List *l, int element);
// ajout en tete selon une approche fonctionnelle sans modification de la liste
T_List ajouter_entete_fonc(T_List l, int element);

// affichages
// itératif
void afficher_liste(T_List l);
// récursif dans l ordre de la liste
void fafficher_dir_liste(T_List l);
// récursif dans l ordre inverse de la liste
void fafficher_inv_liste(T_List l);



// inversion iterative d'une liste selon une approche MIS
void inv_mis_liste(T_List *l);
// inversion iterative d'une liste selon une approche fonctionnelle
T_List inv_fonc_liste(T_List l);

// comptage du nombre d'elements d'une liste
// selon une approche recursive enveloppee
int long_env(T_List l)
// selon une approche recursive terminale
int long_ter(T_List l, int nombre);

// inversion recursive enveloppee d'une liste
T_List inversion_rec_env(T_List courant);
// inversion recursive terminale d'une liste
T_List inversion_rec_term(T_List courant, T_List precedent);

// liberation de la mémoire
void liberer_liste(T_List *l);
#endif
