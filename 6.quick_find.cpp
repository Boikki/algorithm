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
    int *color, n;
    // 用相同的颜色代表连通性
    UnionSet(int n) : n(n) {
        color = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            color[i] = i;
        }
    }
    int find(int x) { return color[x]; }
    // quick_find
    // find 通过下标即可访问
    // 但是merge要遍历遍数组
    // 所以复杂度O(n)
    void merge(int a, int b) {
        if (color[a] == color[b]) return ;
        int cb = color[b];
        // 把b染成a的颜色
        for (int i = 0; i <= n; i++) {
            if (color[i] == cb) color[i] = color[a];
        }
        return ;
    }
};

// 下面以HZOJ71 朋友圈为例
// 介绍三种并查集算法的优劣

int main() {
    int n, m;
    cin >> n >> m;
    UnionSet u(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        switch(a) {
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
