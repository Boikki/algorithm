/*************************************************************************
	> File Name: 6.72.cpp
	> Author: Boyu.Ren 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 六  3/25 11:05:48 2023
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 10000

class UnionSet {
public :
    int *father, *val, n;
    // val存的就是权值
    // 最开始初始化成0
    UnionSet(int n) : n(n) {
        father = new int[n + 1];
        val = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            father[i] = i;
            val[i] = 0;
        }
    }
    int get(int x) {
        if (father[x] == x) return x;
        int root = get(father[x]);
        val[x] += val[father[x]];
        val[x] %= 3;
        return father[x] = root;
    }
    void merge(int a, int b, int c) {
        int fa = get(a), fb = get(b);
        if (fa == fb) return ;
        father[fa] = fb;
        val[fa] = (c + val[b] - val[a] + 3) % 3;
        return ;
    }
};

void read(int &n, int &m) {
    cin >> n >> m;
    return ;
}

int main() {
    int n, m;
    read(n, m);
    UnionSet u(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            u.merge(b, c, 2);
        } else {
            if (u.get(b) != u.get(c)) {
                cout << "Unknown" << endl;
            } else {
                switch ((u.val[b] - u.val[c] + 3) % 3) {
                    case 0: cout << "Tie" << endl; break;
                    case 1: cout << "Loss" << endl; break;
                    case 2: cout << "Win" << endl; break;
                }
            }
        }
    }
    return 0;
}
