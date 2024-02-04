/*
 * Ecole polytechnique de Montreal - GIGL
 * Hiver  2024
 * Initlab - part2.c
 *
 * ajoutez vos noms, prénoms et matricules
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// Si besoin, ajouter ici les directives d'inclusion et les déclarations globales
// -------------------------------------------------
// TODO
static const char* PRINT_MESSAGE = "77dbcb01f571f1c32e196c3a7d26f62e (printed using write)\n";
static const char* WRITE_MESSAGE = "77dbcb01f571f1c32e196c3a7d26f62e (printed using printf)";
// -------------------------------------------------
void part21 ()
{
 // TODO
 for (int i = 0; i < PRINT_MESSAGE[i] != '\0'; i++) {
    printf("%c", PRINT_MESSAGE[i]);
 }

 write(STDOUT_FILENO,WRITE_MESSAGE, strlen(WRITE_MESSAGE));
}

void part22 ()
{
 // TODO
 setvbuf(stdout, NULL, _IONBF, 0);
 for (int i = 0; i < PRINT_MESSAGE[i] != '\0'; i++) {
    printf("%c", PRINT_MESSAGE[i]);
 }

 write(STDOUT_FILENO,WRITE_MESSAGE, strlen(WRITE_MESSAGE));

}

int main (int argc, char* argv[])
{
    if (argc!=2)
    {   printf("Le programme a un seul paramètre : 1 ou 2\n");
        return 1;
    }
    switch (atoi(argv[1])) {
         case 1:        part21();
                        break;
         case 2:        part22();
                        break;
        default:        printf(" Le paramètre du programme est invalide\n");
                        return 1;
    }
    return 0;
}
