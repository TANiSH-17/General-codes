


#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    // Define the structure of each node in the segment tree
    struct Node {
        int start, end;      // The range [start, end] this node covers
        long long sum;       // The sum of elements in the range [start, end]
        Node* left;          // Pointer to left child (covers left half)
        Node* right;         // Pointer to right child (covers right half)

        // Constructor to initialize the node with given range
        Node(int s, int e) : start(s), end(e), sum(0), left(nullptr), right(nullptr) {}
    };

    Node* root;  // Root of the segment tree

    // Recursively build the segment tree from the input array
    Node* build(const vector<int>& arr, int start, int end) {
        Node* node = new Node(start, end);  // Create a new node for range [start, end]
        if (start == end) {
            // Leaf node: store the value from array
            node->sum = arr[start];
        } else {
            int mid = (start + end) / 2;
            // Recursively build left and right subtrees
            node->left = build(arr, start, mid);
            node->right = build(arr, mid + 1, end);
            // Set current node's sum as the sum of its children
            node->sum = node->left->sum + node->right->sum;
        }
        return node;
    }

    // Recursively update the value at index idx to val
    void update(Node* node, int idx, int val) {
        if (node->start == node->end) {
            // Leaf node: directly update the value
            node->sum = val;
        } else {
            int mid = (node->start + node->end) / 2;
            // Recurse to the left or right child depending on idx
            if (idx <= mid)
                update(node->left, idx, val);
            else
                update(node->right, idx, val);
            // Recalculate current node's sum after update
            node->sum = node->left->sum + node->right->sum;
        }
    }

    // Recursively compute the sum in the range [l, r]
    long long query(Node* node, int l, int r) {
        if (!node || r < node->start || node->end < l)
            return 0;  // No overlap with current segment

        if (l <= node->start && node->end <= r)
            return node->sum;  // Complete overlap: return precomputed sum

        // Partial overlap: query both children and combine the result
        return query(node->left, l, r) + query(node->right, l, r);
    }

public:
    // Constructor: builds the tree from input array
    SegmentTree(const vector<int>& arr) {
        root = build(arr, 0, arr.size() - 1);
    }

    // Public update method: sets arr[idx] = val
    void update(int idx, int val) {
        update(root, idx, val);
    }

    // Public query method: returns sum from arr[l] to arr[r]
    long long query(int l, int r) {
        return query(root, l, r);
    }

    // Helper to print the tree (optional, for debugging)
    void printTree(Node* node) {
        if (!node) return;
        cout << "[" << node->start << ", " << node->end << "] → Sum: " << node->sum << "\n";
        printTree(node->left);
        printTree(node->right);
    }

    // Overload: starts print from root
    void printTree() {
        printTree(root);
    }
};
