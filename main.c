#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"
#include "dijkstra.h"

// Print instructions
void printHelp() {
    printf("Commands:\n");
    printf("\tlist - list all cities\n");
    printf("\t<city1> <city2> - find the shortest path between two cities\n");
    printf("\thelp - print this help message\n");
    printf("\texit - exit the program\n");
}

// Check if there are 3 attributes being input by the user
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./map.out <vertices> <distances>\n");
        return 1;
    }

    // Initialize and allocate memory, load cities and distance. 
    Graph *g = initGraph(100);
    loadCities(g, argv[1]);
    loadDistances(g, argv[2]);

    printf("*******Welcome to the shortest path finder!********\n");
    printHelp();
    printf("*******************************************************\n");


    char input[100];
    while (1) {
        printf("Where do you want to go today? ");
        
        // Get input from the user
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        // Delete end of line
        input[strcspn(input, "\r\n")] = 0;
        // Check if the input is empty
        if (strlen(input) == 0) continue;

        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else if (strcmp(input, "help") == 0) {
            printHelp();
        } else if (strcmp(input, "list") == 0) {
            listCities(g);
        } else {
            // Get city name
            char *city1 = strtok(input, " ");
            char *city2 = strtok(NULL, " ");
            if (city1 != NULL && city2 != NULL) {
                int id1 = getCityIndex(g, city1);
                int id2 = getCityIndex(g, city2);

                if (id1 == -1 || id2 == -1) {
                    printf("Invalid Command\n"); 
                    printHelp();
                } else {
                    findShortestPath(g, id1, id2);
                }
            } else {
                printf("Invalid Command\n");
                printHelp();
            }
        }
    }
    // Free memory
    freeGraph(g);
    return 0;
}
