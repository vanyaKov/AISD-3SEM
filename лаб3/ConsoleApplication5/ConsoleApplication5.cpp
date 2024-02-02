#include <iostream>
#include <limits.h>
using namespace std;

#define V 9

int min(int distance[], bool visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!visited[v] && distance[v] <= min)
            min = distance[v], min_index = v;

    return min_index;
}

void dk(int mas[V][V], int start) {
    int distance[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[start] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = min(distance, visited);

        visited[u] = true;

        for (int v = 0; v < V; v++)
            if (!visited[v] && mas[u][v] && distance[u] != INT_MAX && distance[u] + mas[u][v] < distance[v])
                distance[v] = distance[u] + mas[u][v];
    }

    cout << "Shortest way from vertex: " << start << "\n";
    for (int i = 0; i < V; i++)
        cout << "Vertex" << i << ": " << distance[i] << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int mas[9][9] = {
        //A  B  C   D  E  F  G  H  I
        { 0, 7, 10, 0, 0, 0, 0, 0, 0},   //A
        { 7, 0, 0, 0, 0, 9, 27, 0, 0},   //B
        { 10, 0, 0, 0, 31, 8, 0, 0,0},   //C
        { 0, 0, 0, 0, 31, 0, 0, 17,21},  //D
        { 0, 0, 31, 32, 0, 0, 0, 0,0},   //E
        { 0, 9, 8, 0, 0, 0, 0, 11, 0},   //F
        { 0, 27, 0, 0, 0, 0, 0, 0,15},   //G
        { 0, 0, 0, 17, 0, 11, 0, 0,15},  //H
        { 0, 0, 0, 21, 0, 0, 15, 15,0}   //I
    };

    int vertex;
    cin >> vertex;

    dk(mas, vertex);

    return 0;
}