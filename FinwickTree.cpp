class FenwickTree {
private:
    int n;
    vector<int> bit;

public:
    FenwickTree(int size) : n(size), bit(size + 1, 0) {}

    void update(int x, int delta) {
        while (x <= n) {
            bit[x] += delta;
            x += x & -x;
        }
    }

    int query(int x) const {
        int result = 0;
        while (x > 0) {
            result += bit[x];
            x -= x & -x;
        }
        return result;
    }

    int rangeQuery(int l, int r) const {
        return query(r) - query(l - 1);
    }

    void buildFromArray(const vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i)
            update(i + 1, arr[i]);
    }
};
