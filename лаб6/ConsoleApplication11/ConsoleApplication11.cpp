#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

// узел дерева Хаффмана
struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};
// сравнения двух узлов по их частоте
struct Compare {
    bool operator()(HuffmanNode* lhs, HuffmanNode* rhs) {
        return lhs->frequency > rhs->frequency;
    }
};
// обход дерева и формирования кодовых последовательностей
void traverseHuffmanTree(HuffmanNode* node, string code, unordered_map<char, string>& codes) {
    if (node == nullptr) {
        return;
    }
    if (node->left == nullptr && node->right == nullptr) {
        codes[node->data] = code;
    }
    traverseHuffmanTree(node->left, code + "0", codes);
    traverseHuffmanTree(node->right, code + "1", codes);
}

//построение дерева Хаффмана и получения кодовых последовательностей
void buildHuffmanTree(string text, unordered_map<char, string>& codes) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    // Подсчет частоты встречаемости символов
    unordered_map<char, int> freqMap;
    for (char c : text) {
        freqMap[c]++;
    }
    // создание узлов дерева и добавление их в очередь с приоритетом
    for (auto& pair : freqMap) {
        HuffmanNode* node = new HuffmanNode(pair.first, pair.second);
        pq.push(node);
    }
    // построение дерева Хаффмана
    while (pq.size() > 1) {
        HuffmanNode* min1 = pq.top();
        pq.pop();
        HuffmanNode* min2 = pq.top();
        pq.pop();
        HuffmanNode* newNode = new HuffmanNode('$', min1->frequency + min2->frequency);
        newNode->left = min1;
        newNode->right = min2;
        pq.push(newNode);
    }
    // обход дерева и формирование кодовых последовательностей
    if (!pq.empty()) {
        HuffmanNode* root = pq.top();

        string code;
        traverseHuffmanTree(root, code, codes);

        delete root;
    }
}
// преобразование текста в кодовую последовательность с использованием таблицы кодов
string encodeText(string text, unordered_map<char, string>& codes) {
    string encodedText;
    for (char c : text) {
        encodedText += codes[c];
    }
    return encodedText;
}

int main() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);
    unordered_map<char, string> codes;
    buildHuffmanTree(text, codes);
    // вывод таблицы встречаемости символов в тексте
    cout << "Symbol occurrence table :" << endl;
    unordered_map<char, int> freqMap;
    for (char c : text) {
        freqMap[c]++;
    }
    for (auto& pair : freqMap) {
        double frequency = (static_cast<double>(pair.second) / text.length()) * 100;
        cout << pair.first << ": " << frequency << "%" << endl;
    }
    cout << endl;
    // вывод таблицы соответствия символов и кодовых последовательностей
    cout << "Sequence table:" << endl;
    for (auto& pair : codes) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;
    cout << encodeText(text, codes);
}