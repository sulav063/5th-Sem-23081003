# Run this exact version:
import heapq

class Node:
    def __init__(self, freq, symbol, left=None, right=None):
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right
        self.huff = ''

    def __lt__(self, other):
        return self.freq < other.freq

def print_huffman_codes(node, code=''):
    new_code = code + str(node.huff)

    if node.left:
        print_huffman_codes(node.left, new_code)
    if node.right:
        print_huffman_codes(node.right, new_code)

    if not node.left and not node.right:
        print(f"{node.symbol}: {new_code}")

# Sample data
chars = ['a', 'b', 'c', 'd', 'e', 'f']
freqs = [5, 9, 10, 15, 30, 45]

# Create priority queue
nodes = [Node(freqs[i], chars[i]) for i in range(len(chars))]
heapq.heapify(nodes)

# Build Huffman Tree
while len(nodes) > 1:
    left = heapq.heappop(nodes)
    right = heapq.heappop(nodes)

    left.huff = 0
    right.huff = 1

    merged = Node(left.freq + right.freq, left.symbol + right.symbol, left, right)
    heapq.heappush(nodes, merged)

# Output
print("Huffman Codes:\n")
print_huffman_codes(nodes[0])
