#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;

class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int sz)
    {
        parent.resize(sz);
        rank.resize(sz);
        for (int i = 0; i < sz; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int root(int a)
    {
        if (parent[a] == a)
        {
            return a;
        }
        return parent[a] = root(parent[a]);
    }
    bool is_same(int a, int b)
    {
        return root(a) == root(b);
    }
    void unite(int a, int b)
    {
        int x = root(a);
        int y = root(b);

        if (x == y)
        {
            return;
        }
        if (rank[x] > rank[y])
        {
            parent[y] = x;
        }
        else
        {
            parent[x] = y;
            if (rank[x] == rank[y])
            {
                rank[y]++;
            }
        }
    }
};
// https://judge.yosupo.jp/submission/69375
int main()
{
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    for (int i = 0; i < q; i++)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0)
        {
            uf.unite(u, v);
        }
        else
        {
            cout << uf.is_same(u, v) << endl;
        }
    }
}