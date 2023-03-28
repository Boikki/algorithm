/*************************************************************************
	> File Name: 6.UnionSet.cpp
	> Author: Boyu.Ren 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 三  3/22 15:48:14 2023
 ************************************************************************/

#include <iostream>
using namespace std;

class UnionSet {
    int *father, n;
    UnionSet(int n) : n(n) {
        father = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            father[i] = i;
        }
    }
    int get(int x) {
        return father[x] == x ? x : get(father[x]);
    }
};
