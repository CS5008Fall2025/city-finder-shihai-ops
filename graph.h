#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define INF 999999

typedef struct {
    char name[MAX_NAME];
    int id;
} City;

typedef struct {
    City *cities;
    int numCities;
    int capacity;
    int **adjMatrix;
} Graph;

Graph* initGraph(int initialCapacity);
void freeGraph(Graph *g);
void addCity(Graph *g, char *name);
int getCityIndex(Graph *g, char *name);
void addEdge(Graph *g, int src, int dest, int weight);
void loadCities(Graph *g, char *filename);
void loadDistances(Graph *g, char *filename);
void listCities(Graph *g);

#endif