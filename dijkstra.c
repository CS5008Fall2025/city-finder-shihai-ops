#include "dijkstra.h"
#include <stdbool.h>


int minDistance(int dist[], bool visited[], int numCities) {
    int min = INF;
    int min_index = -1;

    for (int v = 0; v < numCities; v++) {
        if (visited[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPathRecursively(Graph *g, int currentVertex, int parent[]) {
    if (currentVertex == -1) {
        return;
    }
    printPathRecursively(g, parent[currentVertex], parent);
    printf("\t%s\n", g->cities[currentVertex].name);
}

void findShortestPath(Graph *g, int startID, int endID) {
    int numCities = g->numCities;
    int *dist = malloc(sizeof(int) * numCities);
    bool *visited = malloc(sizeof(bool) * numCities);
    int *parent = malloc(sizeof(int) * numCities);
    for (int i = 0; i < numCities; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[startID] = 0;

    for (int count = 0; count < numCities - 1; count++) {
        int u = minDistance(dist, visited, numCities);
        if (u == -1 || dist[u] == INF) break;
        if (u == endID) break; 

        visited[u] = true;

        // 更新 u 的邻接点 v
        for (int v = 0; v < numCities; v++) {
            if (!visited[v] && 
                g->adjMatrix[u][v] != INF && 
                dist[u] != INF && 
                dist[u] + g->adjMatrix[u][v] < dist[v]) {
                
                dist[v] = dist[u] + g->adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    if (dist[endID] == INF) {
        printf("Path Not Found...\n");
    } else {
        printf("Path Found...\n");
        printPathRecursively(g, endID, parent);
        printf("Total Distance: %d\n", dist[endID]);
    }

    free(dist);
    free(visited);
    free(parent);
}