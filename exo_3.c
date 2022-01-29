/*
Exercice 03:
Ecrire un programme qui lance deux threads. Ces deux threads affichent un message en boucle 
infinie. Ce message est différent pour chaque thread (Ping pour l'un et Pong pour l'autre) et est 
affiché en alternance (après Ping c'est Pong et après Pong c'est Ping)

*/



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;

void* print_ping(){
    printf("Ping\n");
    pthread_mutex_unlock(&mutex);

}

void* print_pong(){
    pthread_mutex_lock(&mutex);
    printf("Pong\n");
}

int main (){

    pthread_t thread1, thread2;
    while(1){
        pthread_create(&thread1, NULL, print_ping, NULL);
        pthread_create(&thread2, NULL, print_pong, NULL);    
    }
    
}


