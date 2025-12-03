#include "graph.h"


// initialize the diagram
Graph* initGraph(int initialCapacity) {
    Graph *g = malloc(sizeof(Graph));
    if (g == NULL) {
        perror("Failed to allocate graph");
        exit(1);
    }
    g->numCities = 0;
    g->capacity = initialCapacity;

    // Allocate memory to city array
    g->cities = malloc(sizeof(City) * initialCapacity);
    if (g->cities == NULL) {
        perror("Failed to allocate cities array");
        free(g);
        exit(1);
    }
    // Allocate memory to adjacency matrix for every row.  
    g->adjMatrix = malloc(sizeof(int*) * initialCapacity);
    if (g->adjMatrix == NULL) {
        perror("Failed to allocate adjacency matrix rows");
        free(g->cities);
        free(g);
        exit(1);
    }
     // Allocate memory to adjacency matrix for every column.  
    for(int i = 0; i < initialCapacity; i++) {
        g->adjMatrix[i] = malloc(sizeof(int) * initialCapacity);
        if (g->adjMatrix[i] == NULL) {
            perror("Failed to allocate adjacency matrix columns");
            exit(1);
        }
        for(int j = 0; j < initialCapacity; j++) {
            // The diagonal of the matrix points the node to itself, hence they are 0, other nodes have been set to INF for initialize. 
            g->adjMatrix[i][j] = (i == j) ? 0 : INF;
        }
    }
    return g;
}

// Release the memory
void freeGraph(Graph *g) {
    if (g == NULL) return;
    for (int i = 0; i < g->capacity; i++) {
        free(g->adjMatrix[i]);
    }
    free(g->adjMatrix);
    free(g->cities);
    free(g);
}

// Add city
void addCity(Graph *g, char *name) {
    if (g->numCities >= g->capacity) {
        fprintf(stderr, "Error: Graph capacity reached. Cannot add more cities.\n");
        return;
    }

    // Copy name and set ID
    strncpy(g->cities[g->numCities].name, name, MAX_NAME - 1);
    g->cities[g->numCities].name[MAX_NAME - 1] = '\0';
    g->cities[g->numCities].id = g->numCities;
    
    g->numCities++;
}

// Find city ID by their name. Return -1 if not found. 
int getCityIndex(Graph *g, char *name) {
    for (int i = 0; i < g->numCities; i++) {
        if (strcmp(g->cities[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Add edges
void addEdge(Graph *g, int src, int dest, int weight) {
    if (src >= 0 && src < g->numCities && dest >= 0 && dest < g->numCities) {
        g->adjMatrix[src][dest] = weight;
        g->adjMatrix[dest][src] = weight; 
    }
}

// Load cities from files
void loadCities(Graph *g, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening city file");
        exit(1);
    }

    char buffer[MAX_NAME];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        buffer[strcspn(buffer, "\r\n")] = 0;

        if (strlen(buffer) > 0) {
            addCity(g, buffer);
        }
    }
    fclose(fp);
}

// Load distance from file
void loadDistances(Graph *g, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening distance file");
        exit(1);
    }

    char city1[MAX_NAME];
    char city2[MAX_NAME];
    int dist;

    // the format must be: city1 city2 distance
    while (fscanf(fp, "%s %s %d", city1, city2, &dist) == 3) {
        int id1 = getCityIndex(g, city1);
        int id2 = getCityIndex(g, city2);

        if (id1 != -1 && id2 != -1) {
            addEdge(g, id1, id2, dist);
        }
    }
    fclose(fp);
}

// List all cities
void listCities(Graph *g) {
    for (int i = 0; i < g->numCities; i++) {
        printf("%s\n", g->cities[i].name);
    }
}
