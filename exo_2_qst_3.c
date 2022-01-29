/*
1. Ecrire un programme ayant le comportement suivant :
    - Quatre threads sont crC)C)s.
    - Chaque thread affiche le message "Hello World !", son PID (avec getpid( )) ainsi que la 
    valeur opaque retournC)e lors de sa crC)ation (son identifiant). 
    - Le thread principal attend la terminaison des quatre threads crC)C)s.
    
2. Modifier le programme de la question prC)cC)dente pour que chaque thread affiche en plus du 
message "Hello World !", son numC)ro d'ordre uniquement.

3. Modifier le programme de la question prC)cC)dente en dC)clarant une variable globale initialisC)e 
C  "0" de sorte que chaque thread, dans une boucle, lui ajoute 1000 fois son numC)ro d'ordre. La 
valeur obtenue doit C*tre affichC)e aprC(s la terminaison de tous les threads.
*/


//Quesion 3

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NB_THREADS 4

int sum = 0;
pthread_mutex_t mutex_sum;

void *print_message(void* cpt){
    pthread_mutex_lock(&mutex_sum);
    int cpt_int = (int*) cpt; 
    sum += 1000*cpt_int;
    pthread_mutex_unlock(&mutex_sum);
}
int main (){
    pthread_t threads[NB_THREADS];
    int cpt = 1;
    
    for(int i=0; i<NB_THREADS; i++){
        pthread_create(&threads[i], NULL, print_message, cpt);
        cpt++;
    }
    
    
    for(int i=0; i<NB_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    printf("La somme = %d", sum);
}
