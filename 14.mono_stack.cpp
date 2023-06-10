/*************************************************************************
	> File Name: 14.mono_stack.cpp
	> Author: Boyu.Ren
	> Mail: renboyu@hrbeu.edu.cn
	> Created Time: 六  5/27 12:39:24 2023
 ************************************************************************/

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void output(vector<int> arr, const char *s) {
    printf("%s", s);
    for (auto x : arr) {
        printf("%5d", x);
    }
    printf("\n");
    return ;
}

int main() {
    int n;
    cin >> n;
    vector<int> ind(n);
    vector<int> arr(n);
    // pre nex  分别维护元素前面、后面比他小的元素！
    // 所以用单增栈
    vector<int> pre(n), nex(n);
    stack<int> s;
    for (int i = 0; i < n; ++i) ind[i] = i;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    // 每个元素依次压入s
    // pre和nex存前边后边比他小的最近元素的下标
    // 所以维护递增栈
    for (int i = 0; i < n; ++i) { 
        // 是否违反单调性
        while (s.size() && arr[i] < arr[s.top()]) { 
            // arr[i]是当前是违反单调性的
            // 也就是你能打动的所有元素的后边最近的最小值
            // 也就是🟦
            // 也就是nex记录了若干🟨后面最近的最小
            nex[s.top()] = i;
            s.pop();
        }
        // 这里对于s为空的情况处理下
        // s为空之后 证明前面没有比他小的了
        // 所以设成-1
        if (s.size() == 0) pre[i] = -1;
        // 那么当前到的i位置即为不能打动的即不违反单调性的位置了
        // 也就是🟩 前面最近最小的
        // 也就是pre记录了新入栈元素的前面的最小
        else pre[i] = s.top();
        s.push(i);
    }
    // 走到这一步说明后面没有比他更小的了
    // 那就设成最后一位 也就是-1 n都是边界
    while (s.size()) nex[s.top()] = n, s.pop();
    output(ind, "ind: ");
    output(arr, "now: ");
    output(pre, "pre: ");
    output(nex, "nex: ");
    return 0;
}
