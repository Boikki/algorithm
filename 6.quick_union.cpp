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
    int *father, n;
    UnionSet(int n) : n(n) {
        father = new int[n + 1];
        // 一开始father是自己
        for (int i = 0; i <= n; i++) {
            father[i] = i;
        }
    }
    // 返回x的父节点
    int find(int x) {
        if (father[x] == x) return x;
        return find(father[x]);
    }
    // 因为只需要一行就可链接节点
    // 所以叫quick union
    // find操作最差会O(n)
    void merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return ;
        // 让a的父节点链接到b的父节点
        // 这样就一下子链接了一个数
        father[fa] = fb;
        return ;
    }
};


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
