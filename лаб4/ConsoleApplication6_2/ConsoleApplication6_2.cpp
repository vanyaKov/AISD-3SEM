#include <iostream>

const int INF = INT_MAX; // Бесконечность

void floydWarshall(int** dist, int** next, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void printPath(int i, int j, int** next) {
    if (i == j) {
        std::cout << i << " ";
    }
    else if (next[i][j] == -1) {
        std::cout << "No path exists.";
    }
    else {
        std::cout << i << " ";
        while (i != j) {
            i = next[i][j];
            std::cout << i << " ";
        }
    }
}

int main() {
    int n = 6; // Количество вершин

    int** dist = new int* [n];
    int** next = new int* [n];
    for (int i = 0; i < n; ++i) {
        dist[i] = new int[n];
        next[i] = new int[n];
    }

    // Инициализация матриц расстояний и последовательности вершин
    int distValues[6][6] = {
        {0, 28, 21, 59, 12, 27},
        {7, 0, 24, INF, 21, 9},
        {9, 32, 0, 13, 11, INF},
        {8, INF, 5, 0, 16, INF},
        {14, 13, 15, 10, 0, 22},
        {15, 18, INF, INF, 6, 0}
    };

    int nextValues[6][6] = {
        {0, 2, 3, 4, 5, 6},
        {1, 0, 3, 4, 5, 6},
        {1, 2, 0, 4, 5, 6},
        {1, 2, 3, 0, 5, 6},
        {1, 2, 3, 4, 0, 6},
        {1, 2, 3, 4, 5, 0}
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = distValues[i][j];
            next[i][j] = nextValues[i][j];
        }
    }

    floydWarshall(dist, next, n);

    // Вывод кратчайших расстояний между всеми парами вершин
    std::cout << "Shortest distances between all pairs of vertices:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                std::cout << "INF ";
            }
            else {
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << "\n";
    }

    // Восстановление путиМы решили проблему с несовместимостью типов указателей, но возникла еще одна проблема. Вам необходимо вводить номера вершин, начиная с 1, а не с 0. Для этого вам нужно уменьшить значение вершин на 1 при вводе. Вот обновленный фрагмент кода:

    int source, destination;
    std::cin >> source >> destination;
    source--; // Уменьшаем значение вершины на 1
    destination--; // Уменьшаем значение вершины на 1
    std::cout << "Shortest path between " << source + 1 << " and " << destination + 1 << ": ";
    printPath(source, destination, next);