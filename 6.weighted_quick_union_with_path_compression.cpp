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
        // 你既然找了一遍x的父节点了
        // 何不把他存起来呢？
        int root = find(father[x]);
        father[x] = root;
        return root;
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
    int n, m;
    scanf("%d %d", &n, &m);
    UnionSet u(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        switch (a) {
            case 1: u.merge(b, c); break;
            case 2: if (u.find(b) == u.find(c)) {
                printf("Yes\n");
            } else {
                printf("No\n");

            }
        }
    }
    return 0;
}
