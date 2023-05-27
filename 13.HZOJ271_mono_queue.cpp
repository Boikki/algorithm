/*************************************************************************
	> File Name: 13.HZOJ271_mono_queue.cpp
	> Author: Boyu.Ren
	> Mail: renboyu@hrbeu.edu.cn
	> Created Time: 六  5/13 13:54:14 2023
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
    int n, k;
    std::vector<int> arr;
    std::cin >> n >> k;
    for (int i = 0, a; i < n; i++) {
        std::cin >> a;
        arr.push_back(a);
    }
    std::deque<int> q;
    for (int i = 0; i < n; i++) {
        // 入队列 -> 维护单调性
        // 先判断队尾元素是否违反单调性
        while (!q.empty() && arr[q.back()] > arr[i]) q.pop_back();
        q.push_back(i);
        // 下面进行滑动窗口越界头部元素的弹出
        // 但是queue中记录的是元素的值
        // 通过值可没法求滑动窗口的长度哎！
        // 所以存下标就可
        // 出队列 -> 维护元素生命周期
        if (i - q.front() == k) q.pop_front();
        if (i + 1 < k) continue;
        (i + 1 > k) && std::cout << " ";
        std::cout << arr[q.front()];
    }
    std::cout << std::endl;
    q.clear();
    for (int i = 0; i < n; i++) {
        while (!q.empty() && arr[i] > arr[q.back()]) q.pop_back();
        q.push_back(i);
        if (i - q.front() == k) q.pop_front();
        if (i + 1 < k) continue;
        // 因为第一次输出的时候是i + 1 == k
        // 即滑动窗口刚好 == k
        // 这样能除去多余的空格
        (i + 1 > k) && std::cout << " ";
        std::cout << arr[q.front()];
    }
    std::cout << std::endl;
    return 0;
}
