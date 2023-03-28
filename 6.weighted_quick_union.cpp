/*************************************************************************
	> File Name: 6.union-find.cpp
	> Author: Boyu.Ren 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 一  3/20 14:12:05 2023
 ************************************************************************/

#include <iostream>
using namespace std;

class UnionSet {
public :
    int *father, *size, n;
    UnionSet(int n) : n(n) {
        size = new int[n + 1];
        father = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            father[i] = i;
            size[i] = 1;
        }
    }
    int find(int x) {
        if (father[x] == x) return x;
        return find(father[x]);
    }
    void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return ;
        // 把大的顶上去
        if (size[pa] < size[pb]) {
            father[pa] = pb;
            size[pb] += size[pa];
        } else {
            father[pb] = pa;
            size[pa] += size[pb];
        }
        return ;
    }
};


int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    UnionSet u(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        switch (a) {
            case 1: u.merge(b, c); break;
            case 2: if (u.find(b) == u.find(c)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
