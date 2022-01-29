/*
Exercice 1
1. Ecrire un programme ayant le comportement suivant :
    - Deux threads sont crC)C)s.
    - Le premier thread affiche "Hello" et le second thread affiche "World".
    - Le thread principal attend la terminaison des deux threads crC)C)s.
    - L'ordre d'affichage ne doit pas forcC)ment C*tre respectC). On peut avoir comme rC)sultat 
    d'exC)cution "Hello World" comme "World Hello".
    
2. Ecrire un programme ayant le mC*me comportement que dans la question 1, mais oC9 l'ordre 
d'affichage doit C*tre respectC) (le rC)sultat d'exC)cution doit C*tre "Hello World").

*/

//Question 02

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NB_THREADS 2

pthread_t threads[NB_THREADS];  

pthread_mutex_t mutex;

void *print_hello(){
    printf("Hello\n");
    pthread_mutex_unlock(&mutex);
}
void *print_world(){
    pthread_mutex_lock(&mutex);
    printf("World\n");
}
int main (){
    

    pthread_create(&threads[1], NULL, print_hello, NULL);
    pthread_create(&threads[2], NULL, print_world, NULL);
    
    for(int i=0; i<NB_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
}
