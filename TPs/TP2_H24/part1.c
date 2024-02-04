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
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
// -------------------------------------------------

int main()
{
    // TODO
    int fd = open("output2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Appel systeme open a echouer\n");
        exit(EXIT_FAILURE);
    }

    char msgInput[] = "Saississez votre texte suivi de CTRL-D :\n";
    write(STDOUT_FILENO, msgInput, sizeof(msgInput) - 1);

    char chr;
    while(read(STDIN_FILENO, &chr, 1) > 0) {
        if (write(fd, &chr, 1) < 0) {
            perror("Erreur lors de l'ecriture dans le fichier\n");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    close(fd);
    return 0;
}
