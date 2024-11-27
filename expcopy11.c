#include<stdio.h>
#include<stdlib.h>

int a[20][20], visited[20], reach[20], n, i, j, count = 0, v;

void DFS_Connectivity(int v) {
    reach[v] = 1;  // Mark the current vertex as visited
    printf("\nVisited %d", v + 1);  // Output the visited vertex (1-based indexing for user clarity)
    count++;  // Increment the count of visited vertices

    // Explore all adjacent vertices of the current vertex
    for(i = 1; i <= n; i++) {
        if(a[v][i] && !reach[i]) {  // If there's an edge and the vertex has not been visited
            printf("\n%d->%d", v + 1, i + 1);  // Print the edge (1-based indexing for clarity)
            DFS_Connectivity(i);  // Recur to explore the vertex
        }
    }
}

void main() {
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    
    // Initialize visited and reach arrays
    for(i = 0; i < n; i++) {
        reach[i] = 0;
    }

    // Input graph data in adjacency matrix form (1-based for user clarity)
    printf("\nEnter graph data in matrix form (0 for no edge, 1 for edge):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Perform DFS to check connectivity starting from vertex 0
    printf("\nDFS Connectivity Check\n");
    DFS_Connectivity(0);

    // If all vertices have been visited, the graph is connected
    if(count == n) {
        printf("\nGraph is connected");
    } else {
        printf("\nGraph is not connected");
    }
}

