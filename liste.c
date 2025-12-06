// creation liste vide
T_List creer_liste(){
    return NULL ;  // On retourne une liste qui pointe sur NULL
}


// ajout en tete de liste de element avec modification de la liste
void ajout_entete_liste(T_List *l, int element){
        T_List new = malloc(sizeof(T_Node)) ; 
        if (new ==  NULL){ 
            printf("Erreur d'allocation") ;
        }
        else {
        new -> value = element ;
        new -> next = *l ;
        *l = new ; 
        }
}

// ajout en tete selon une approche fonctionnelle sans modification de la liste
T_List ajouter_entete_fonc(T_List l, int element){ // ATTENTION, on ne veut pas modifier la liste donc on passe l pas *l
 T_List new = malloc(sizeof(T_Node)) ; 
        if (new ==  NULL){ // jamais de pointeur aprés malloc pour tester
            printf("Erreur d'allocation") ;
        }
        else {
        new -> value = element ;
        new -> next = l ;
        return new ;
        }
    }


// affichages
// itératif
void afficher_liste(T_List l){
    if(l==NULL) printf("liste vide") ;
    else {
        while(l!=NULL){
            printf("%d ", l->value);
            l = l->next ;
        }
    }
}


// récursif dans l ordre de la liste
void fafficher_dir_liste(T_List l){
    if(l==NULL) {
        printf("liste vide") ;
        return ;
    }
    else{
    printf("%d ", l->value) ; 
    fafficher_dir_liste(l->next) ;
}
}

// récursif dans l ordre inverse de la liste
void fafficher_inv_liste(T_List l){
    if(l==NULL) {
        printf("liste vide") ;
        return ;
    }
    fafficher_inv_liste(l->next) ;
    printf("%d ", l->value) ; 
}

// inversion iterative d'une liste selon une approche MIS
void inv_mis_liste(T_List *l){
    if(*l==NULL) printf("Liste vide") ;
    else {
        T_List courant = *l ; // car on a passé *l en arg
        int compteur = 0 ; 
        while(courant!=NULL){
            compteur ++ ;
            courant = courant -> next ;
        }
        T_List *tab_maillons = malloc(compteur*sizeof(T_List)) ; // car *l en arg
        if(tab_maillons==NULL) printf("Erreur d'allocation mémoire") ;
        else{
            courant = *l ;
            for (int i = 0; i <compteur; i++){
            tab_maillons[i] = courant ; 
            courant = courant -> next ; 
            }

        
        if(compteur < 2 ) printf("Inversion inutile"); 
        else{
        *l = tab_maillons[compteur - 1];
        for(int j = compteur-1; j > 0; j --){
            tab_maillons[j] -> next =  tab_maillons[j-1] ;
            
        }
        tab_maillons[0] -> next = NULL ;
    }

    }
     free(tab_maillons);
}
        }
    

// inversion iterative d'une liste selon une approche fonctionnelle
T_liste inv_fonc_liste(T_Liste l){
     if(l==NULL) printf("Liste vide") ;
    else {
        T_List courant = l ;
        int compteur = 0 ; 
        while(courant!=NULL){
            compteur ++ ;
            courant = courant -> next ;
        }
        T_List *tab_maillons = malloc(compteur * sizeof(T_List));
        if(tab_maillons==NULL) {
        printf("Erreur d'allocation mémoire") ;
        return l ; 
        }
        else{
            courant = l ;
            for (int i = 0; i <compteur; i++){
                tab_maillons[i] = courant ; 
                courant = courant -> next ; 
            }
            T_List nouvelle_tete = tab_maillons[compteur - 1];
            if(compteur < 2 ){
            printf("Inversion inutile"); 
            return l ;
            }
            else{
                tab_maillons[0]->next = NULL;
            for(int j = compteur-1; j > 0; j --){
                tab_maillons[j] -> next =  tab_maillons[j-1] ;
            
            }
            
    }

    }
     free(tab_maillons);
}
      
 return nouvelle_tete ; 
 }
        
        
T_List inv_fonc_liste(T_Liste l) {
    T_List nouvelle_tete = l; 
    if (l == NULL) {
        printf("Liste vide\n");
        return l ;
    
    } else {
        T_List courant = l; 
        int compteur = 0;

        while (courant != NULL) {
            compteur++;
            courant = courant->next;
        }

        T_List *tab_maillons = malloc(compteur * sizeof(T_List));
        if (tab_maillons == NULL) {
            printf("Erreur d'allocation mémoire\n");
            return l;
        } else {
            courant = l;
            for (int i = 0; i < compteur; i++) {
                tab_maillons[i] = courant;
                courant = courant->next;
            }

            nouvelle_tete = tab_maillons[compteur - 1]; 

            if (compteur < 2) {
                printf("Inversion inutile");
            } else {
                tab_maillons[0]->next = NULL;
                for (int j = compteur - 1; j > 0; j--) {
                    tab_maillons[j]->next = tab_maillons[j - 1];
                }
            }
           
            
        } 
        free(tab_maillons); 
    } 

    
    return nouvelle_tete;
}



// comptage du nombre d'elements d'une liste
// selon une approche recursive enveloppee
int long_env_helper(T_List l) {
    if (l == NULL) return 0;
    else return 1 + long_env_helper(l->next);
}

int long_env(T_List l) {
    if (l == NULL) return 0;
    else return long_tec_helper(l);
}
// selon une approche recursive terminale
int long_ter(T_List l, int nombre){
    if(l==NULL) return nombre; 
    else {
     return long_ter(l->next, nombre + 1);
    }
   

// inversion recursive enveloppee d'une liste
T_List inversion_rec_helper(T_List courant) {
    if (courant == NULL) {
        return NULL;
    }
    if (courant->next == NULL) {
        return courant;
    }
    T_List nouvelle_tete = inversion_rec_helper(courant->next);
    courant->next->next = courant; // on inverse car la liste courante devient le next du courant suivant
    courant->next = NULL;
    return nouvelle_tete;
}

T_List inversion_rec_env(T_List courant){
    return inversion_rec_helper(courant)
}
// inversion recursive terminale d'une liste
T_liste inversion_rec_term(T_List courant, T_List precedent){
    if(courant==NULL) return precedent ; 
    else {
        T_List suivant = courant ->next ;
        courant->next = precedent ; // On casse le suivant mais on l'a sauvegardé avant
        return inversion_rec_term(suivant, courant) ;
}
}

// liberation de la mémoire
void liberer_liste(T_List *l){
    if (*l==NULL) printf("Liste vide ") ; 
    else{
        T_List courant = *l ;
        while(courant != NULL){
        T_List suivant = courant->next ; // Obligatoire si on veut parcourir la liste à un instant t sinon on perd l'ordre
        free(courant) ;
        courant = suivant ;
    }
    *l = NULL ; 
}
}
