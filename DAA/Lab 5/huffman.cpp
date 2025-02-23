#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char character;
    int frequency;
    Node *left, *right;

    Node(char c, int f) : character(c), frequency(f), left(NULL), right(NULL) {}
};

// Comparison function for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency; // Min-heap based on frequency
    }
};

// Function to generate Huffman codes
void generateCodes(Node* root, string code, pair<char, string> huffmanCodes[], int& index) {
    if (!root) return;
    if (root->character != '#') { // Leaf node
        huffmanCodes[index++] = make_pair(root->character, code);
    }
    generateCodes(root->left, code + "0", huffmanCodes, index);
    generateCodes(root->right, code + "1", huffmanCodes, index);
}

// Function to print Huffman codes
void printCodes(pair<char, string> huffmanCodes[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << huffmanCodes[i].first << ": " << huffmanCodes[i].second << endl;
    }
}

// Huffman coding algorithm
Node* huffmanCoding(pair<char, int> characters[], int n) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create initial nodes and push to priority queue
    for (int i = 0; i < n; ++i) {
        pq.push(new Node(characters[i].first, characters[i].second));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* x = pq.top(); pq.pop();
        Node* y = pq.top(); pq.pop();

        Node* z = new Node('#', x->frequency + y->frequency);
        z->left = x;
        z->right = y;
        pq.push(z);
    }

    return pq.top();
}

// Function to encode characters using Huffman codes
string encodeCharacters(pair<char, int> characters[], int n, pair<char, string> huffmanCodes[], int size) {
    string encodedString = "";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < size; ++j) {
            if (characters[i].first == huffmanCodes[j].first) {
                encodedString += huffmanCodes[j].second;
                break;
            }
        }
    }
    return encodedString;
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    pair<char, int> characters[100];
    cout << "Enter characters and their frequencies:\n";
    for (int i = 0; i < n; ++i) {
        cin >> characters[i].first >> characters[i].second;
    }

    Node* root = huffmanCoding(characters, n);
    pair<char, string> huffmanCodes[100];
    int index = 0;
    generateCodes(root, "", huffmanCodes, index);

    cout << "Huffman Codes:\n";
    printCodes(huffmanCodes, index);

    cout << "Encoded string: " << encodeCharacters(characters, n, huffmanCodes, index) << endl;

    return 0;
}
