#include <vector>
#include <algorithm>
#include <iostream>

#define V 8

int matrix[V][V] = { { INT_MAX,  2,  INT_MAX,  8,  2,  INT_MAX,  INT_MAX, INT_MAX },
				 {       2,  INT_MAX,  3, 10,  5,  INT_MAX,  INT_MAX, INT_MAX },
				 { INT_MAX,  3,  INT_MAX,  INT_MAX, 12,  INT_MAX,  INT_MAX, 7 },
				 { 8, 10,  INT_MAX,  INT_MAX, 14,  3,  1, INT_MAX },
				 { 2,  5, 12, 14,  INT_MAX, 11,  4, 8 },
				 { INT_MAX,  INT_MAX,  INT_MAX,  3, 11,  INT_MAX,  6, INT_MAX },
				 { INT_MAX,  INT_MAX,  INT_MAX,  1,  4,  6,  INT_MAX, 9 },
				 { INT_MAX,  INT_MAX,  7,  INT_MAX,  8,  INT_MAX,  9, INT_MAX } };

using namespace std;

bool isVisited(vector<int> visited, int check)
{
	for (int g = 0; g < visited.size(); g++)
		if (check == visited[g])
			return true;
	return false;
}

void PrimAlgorithm(int graph[V][V]) {
	std::vector<int> visited;
	visited.push_back(0);

	int result[V][V] = {};

	while (visited.size() != V) {
		int weight = INT_MAX;
		int start = INT_MAX;
		int current = INT_MAX;

		for (int a = 0; a < visited.size(); a++) {
			for (int i = 0; i < V; i++) {
				if (graph[visited[a]][i] < weight && !isVisited(visited, i)) {
					weight = graph[visited[a]][i];
					current = i;
					start = visited[a];
				}
			}
		}
		result[start][current] = weight;
		visited.push_back(current);
		std::cout << start + 1 << " -> " << current + 1 << ":  " << weight << "\n";
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	cout << "Алгоритм Прима:" << endl;
	PrimAlgorithm(matrix);
	return 0;
}