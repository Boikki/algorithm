/*************************************************************************
	> File Name: 13.HZOJ372_mono_queue.cpp
	> Author: Boyu.Ren
	> Mail: renboyu@hrbeu.edu.cn
	> Created Time: 六  5/13 15:23:07 2023
 ************************************************************************/

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

int main(int argc, char **argv) {
    int n;
    std::cin >> n;
    std::vector<int> a, b;
    for (int i = 0, aa; i < n; i++) {
        std::cin >> aa;
        a.push_back(aa);
    }
    for (int i = 0, bb; i < n; i++) {
        std::cin >> bb;
        b.push_back(bb);
    }
    std::deque<int> q1, q2;
    int p;
    for (p = 0; p < n; p++) {
        // 最小值  构建单增队列
        while (q1.size() && a[p] < q1.back()) q1.pop_back();
        while (q2.size() && b[p] < q2.back()) q2.pop_back();
        q1.push_back(a[p]);
        q2.push_back(b[p]);
        // 证明找到了第一个不同的p！
        if (q1.size() != q2.size()) break;
    }
    std::cout << p << std::endl;
    return 0;
}
