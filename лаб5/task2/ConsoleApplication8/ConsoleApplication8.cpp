#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int matrix[8][8] = { { INT_MAX,  2,  INT_MAX,  8,  2,  INT_MAX,  INT_MAX, INT_MAX },
				 { 2,  INT_MAX,  3, 10,  5,  INT_MAX,  INT_MAX, INT_MAX },
				 { INT_MAX,  3,  INT_MAX,  INT_MAX, 12,  INT_MAX,  INT_MAX, 7 },
				 { 8, 10,  INT_MAX,  INT_MAX, 14,  3,  1, INT_MAX },
				 { 2,  5, 12, 14,  INT_MAX, 11,  4, 8 },
				 { INT_MAX,  INT_MAX,  INT_MAX,  3, 11,  INT_MAX,  6, INT_MAX },
				 { INT_MAX,  INT_MAX,  INT_MAX,  1,  4,  6,  INT_MAX, 9 },
				 { INT_MAX,  INT_MAX,  7,  INT_MAX,  8,  INT_MAX,  9, INT_MAX } };

void Kruskal() {
	std::vector <int> visitied;
	std::vector <int> min_distanses;

	do {
		int min = INT_MAX;
		int next_node = INT_MAX;
		int next_i;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				auto iter = std::find(visitied.begin(), visitied.end(), i);

				if (min > matrix[i][j] && iter == visitied.end()) {
					min = matrix[i][j];
					next_node = j;
					next_i = i;
				}
			}
		}

		if (next_node != INT_MAX)
		{
			min_distanses.push_back(min);
			matrix[next_node][next_i] = INT_MAX;
			matrix[next_i][next_node] = INT_MAX;
			visitied.push_back(next_i);
			cout << next_i + 1 << " -> " << next_node + 1 << ":  " << min << endl;
		}
	} while (min_distanses.size() != 7);
	int sum = 0;

	for (auto i = 0; i < min_distanses.size(); i++) {
		sum += min_distanses[i];
	}
	std::cout << "Вес МОД: " << sum << std::endl;
}

void main() {
	setlocale(LC_ALL, "Ru");
	Kruskal();
}