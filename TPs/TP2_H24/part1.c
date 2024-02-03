/*
 * Ecole polytechnique de Montreal - GIGL
 * Hiver  2024
 * Initlab - part1.c
 *
 * ajoutez vos noms, prénoms, matricules et votre section de laboratoire
 */

// TODO
// Si besoin, ajouter ici les directives d'inclusion et les déclarations globales
// -------------------------------------------------
#include <fcntl.h>  // Pour les constantes O_WRONLY, O_CREAT, O_TRUNC
#include <unistd.h> // Pour read, write, close
#include <stdio.h>  // Pour perror et printf
#include <stdlib.h> // Pour exit

// -------------------------------------------------

int main()
{
    // TODO
    int fd;
    char c;

    // Ouvrir le fichier en écriture, le créer s'il n'existe pas avec des droits 0644, et utiliser O_TRUNC pour le vider s'il existe déjà
    fd = open("output2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        // Gestion d'erreur si open échoue
        perror("Appel système open a échoué");
        exit(EXIT_FAILURE);
    }

    // Afficher à l'écran la demande de saisie
    printf("Saisissez votre texte suivi de CTRL-D :\n");

    // Lire caractère par caractère depuis l'entrée standard (clavier)
    while (read(STDIN_FILENO, &c, 1) > 0)
    {
        // Écrire le caractère lu dans le fichier
        if (write(fd, &c, 1) != 1)
        {
            perror("Erreur lors de l'écriture dans le fichier");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    // Fermer le fichier
    if (close(fd) == -1)
    {
        perror("Erreur lors de la fermeture du fichier");
        exit(EXIT_FAILURE);
    }

    return 0;
}
