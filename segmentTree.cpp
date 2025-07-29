
#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;

    // Build the tree from the input array
    void build(vector<int>& a, int node, int start, int end) {
        if (start == end) {
            tree[node] = a[start];
        } else {
            int mid = (start + end) / 2;
            build(a, 2 * node, start, mid);
            build(a, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1]; // Modify operation here
        }
    }

    // Query sum from l to r
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0; // Return identity for sum
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        int leftSum = query(2 * node, start, mid, l, r);
        int rightSum = query(2 * node + 1, mid + 1, end, l, r);
        return leftSum + rightSum; // Modify operation here
    }

    // Point update: update index idx to val
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node, start, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = tree[2 * node] + tree[2 * node + 1]; // Modify operation here
        }
    }

public:
    SegmentTree(vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(a, 1, 0, n - 1);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
};






