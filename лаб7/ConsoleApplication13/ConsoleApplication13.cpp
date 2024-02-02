#include <iostream>
#include <vector>

using namespace std;

struct element {
	int value;
	int length;

	element(int i) {
		value = i;
		length = 1;
	}
};


vector <element> subsequence(vector <element> sequence, int N) {
	int max = 0;
	for (int i = 1; i < sequence.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
		 	if (sequence[j].value < sequence[i].value && sequence[j].length >= sequence[i].length) {
				max = sequence[j].length + 1;
				sequence[i].length = max;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < sequence.size(); i++) {
		cout << sequence[i].value << " (" << sequence[i].length << ")  ";
	}

	cout << endl << endl;

	cout << max << endl;
	int counter = 1;
	for (int j = 0; j < sequence.size(); j++) {
		if (sequence[j].length == counter) {
			cout << sequence[j].value << " ";
			counter++;
		}
	}
	return sequence;
}

void main() {
	vector <element> sequence;
	int N;

	cout << "N = ";
	cin >> N;

	int el;

	for (int i = 0; i < N; i++) {
		cin >> el;
		sequence.push_back(el);
	}

	subsequence(sequence, N);
}