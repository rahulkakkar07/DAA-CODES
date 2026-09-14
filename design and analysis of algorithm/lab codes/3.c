#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
struct Edge
{
    int src;
    int dest;
    int weight;
};

// ----------------------------------------------------
// Find function with Path Compression
// ----------------------------------------------------
int find(int parent[], int vertex)
{
    if (parent[vertex] != vertex)
    {
        parent[vertex] = find(parent, parent[vertex]);
    }

    return parent[vertex];
}

// ----------------------------------------------------
// Union function using Union by Rank
// ----------------------------------------------------
void unionSets(int parent[], int rank[], int u, int v)
{
    int rootU = find(parent, u);
    int rootV = find(parent, v);

    if (rootU != rootV)
    {
        if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else if (rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// ----------------------------------------------------
// Comparison function for qsort()
// Sorts edges in ascending order of weight
// ----------------------------------------------------
int compareEdges(const void *a, const void *b)
{
    const struct Edge *edge1 = (const struct Edge *)a;
    const struct Edge *edge2 = (const struct Edge *)b;

    if (edge1->weight < edge2->weight)
        return -1;

    if (edge1->weight > edge2->weight)
        return 1;

    return 0;
}

// ----------------------------------------------------
// Main Function
// ----------------------------------------------------
int main()
{
    int V, E;
    int i;

    int edgeCount = 0;
    int totalCost = 0;

    struct Edge edges[MAX];

    int parent[MAX];
    int rank[MAX];

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Input number of edges
    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Input all edges
    printf("Enter source, destination and weight of each edge:\n");

    for (i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    // ------------------------------------------------
    // STEP 1: Sort edges in increasing order of weight
    // ------------------------------------------------
    qsort(edges, E, sizeof(struct Edge), compareEdges);

    // ------------------------------------------------
    // STEP 2: Initialize Disjoint Set
    // ------------------------------------------------
    for (i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    // ------------------------------------------------
    // STEP 3: Process edges from smallest to largest
    // ------------------------------------------------
    for (i = 0; i < E && edgeCount < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        int rootU = find(parent, u);
        int rootV = find(parent, v);

        // If roots are different, adding the edge
        // will NOT create a cycle
        if (rootU != rootV)
        {
            printf("%d - %d : %d\n",
                   u,
                   v,
                   edges[i].weight);

            totalCost += edges[i].weight;

            // Combine the two sets
            unionSets(parent, rank, u, v);

            edgeCount++;
        }
    }

    // Check whether MST was successfully formed
    if (edgeCount == V - 1)
    {
        printf("\nMinimum Cost = %d\n", totalCost);
    }
    else
    {
        printf("\nMinimum Spanning Tree cannot be formed.\n");
    }

    return 0;
}