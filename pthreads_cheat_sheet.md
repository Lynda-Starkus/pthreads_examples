## Exemples de programmes parallèles avec la librairie pthreads

### Création d'un thread :
> pthread_create(pthread_t* thread, NULL, (void*)(*)(void*) fonction, void* arg);

- Si on souhaite passer plusieurs arguments, faudrait passer en pointeur une structure.

### Attendre la fin d'exécution des threads au niveau du thread appelant :
> pthread_join(pthread_t thread, NULL);