# Philosophers par Mathis Serrier

## Résumé
Le projet "Philosophers" est une exploration approfondie de la programmation multithread et de la synchronisation des processus à l'aide de mutex. Inspiré par un scénario où des philosophes sont assis autour d'une table pour manger, penser ou dormir, ce projet met en œuvre un simulateur où la gestion des ressources (les fourchettes) et l'état de chaque philosophe est cruciale pour éviter un "décès" par inanition.

## Introduction
Philosophie et informatique se rencontrent dans ce projet pour illustrer des problèmes fondamentaux de synchronisation et de partage de ressources dans un environnement multithread. Chaque philosophe, représenté par un thread, doit alterner entre manger, penser et dormir, avec des contraintes spécifiques pour accéder aux ressources limitées (les fourchettes).

## Règles Globales
- Pas de variables globales.
- Les paramètres du simulateur incluent le nombre de philosophes, le temps pour mourir, manger, dormir, et éventuellement, le nombre de repas que chaque philosophe doit prendre.

## Partie Obligatoire
- Nom du programme : philo
- Fichiers à soumettre : Makefile, *.h, *.c, dans le répertoire philo/
- Fonctions externes autorisées : `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`.
- Chaque philosophe est un thread et chaque fourchette est protégée par un mutex.

## Instructions de Compilation et d'Exécution
1. Clonez le dépôt : `git clone [URL_DU_DÉPÔT]`.
2. Allez dans le répertoire du projet et compilez avec : `make`.
3. Exécutez le programme : `./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]`.

## Objectifs d'Apprentissage
- Comprendre et appliquer les concepts de multithreading.
- Gérer la synchronisation entre threads avec des mutex.
- Appliquer les principes de la programmation en C dans un contexte complexe et multithread.

## Auteur
- Mathis Serrier

## Licence
Ce projet est publié sous la licence [Insérer le type de licence ici].

---
Développé avec rigueur et passion par Mathis Serrier.
