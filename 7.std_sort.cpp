/*************************************************************************
	> File Name: 7.std_quick_sort.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 四  2/10 17:23:34 2022
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

const int __threshold = 16;

void quick_sort_v1(vector<int> &nums, int l, int r) {
    int x = l, y = r, z = nums[l];
    while (x < y) {
        while (x < y && nums[y] >= z) y--;
        if (x < y) nums[x++] = nums[y];
        while (x < y && nums[x] < z) x++;
        if (x < y) nums[y--] = nums[x];
    }
    nums[x] = z;
    quick_sort_v1(nums, l, x - 1);
    quick_sort_v1(nums, x + 1, r);
    return ;
}

void quick_sort_v2(vector<int> &nums, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = nums[l];
        while (x < y) {
            while (x < y && nums[y] >= z) y--;
            if (x < y) nums[x++] = nums[y];
            while (x < y && nums[x] <= z) x++;
            if (x < y) nums[y--] = nums[x];
        }
        // 一次partition之后x，y都在同一个位置
        nums[x] = z;
        // 右侧还用递归
        quick_sort_v2(nums, x + 1, r);
        // 但是因为重设了r的值为左侧区间
        // 并且满足while循环条件
        // 左侧相当于用循环做
        // 这样就是相当于在一层的栈空间内完成
        // 少了一倍的栈空间展开
        r = x - 1;
    }
    return ;
}

int getMid(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return b;
}

void __quick_sort_v3(vector<int> &nums, int l, int r) {
    while (r - l > __threshold) {
        int x = l, y = r, z = getMid(nums[l], (nums[(l + r) >> 1]), nums[r]);
        do {
            while (nums[x] < z) x++;
            while (nums[y] > z) y--;
            if (x <= y) {
                swap(nums[x], nums[y]);
                x++, y--;
            }
        } while (x <= y);
        __quick_sort_v3(nums, x + 1, r);
        r = y;
    }
}

void final_insert_sort(vector<int> &nums, int l, int r) { 
    // 无监督
    // 先找到最小值放到第一位去
    // ind存最小值的下标
    int ind = l;
    for (int i = l + 1; i <= r; i++) {
        if (nums[i] < nums[ind]) ind = i;
    }
    while (ind > l) {
        swap(nums[ind], nums[ind - 1]);
        ind--;
    }
    // 还记得我们是分成了很多组么
    // 组间其实是内省排序
    // 组内是插入排序（小数据）
    for (int i = l + 2; i <= r; i++) {
        int j = i;
        while (nums[j] < nums[j - 1]) {
            swap(nums[j], nums[j - 1]);
            j--;
        }
    }
    return ;
}

void quick_sort_v3(vector<int> &nums, int l, int r) {
    __quick_sort_v3(nums, l, r);
    final_insert_sort(nums, l, r);
    return ;
}

int main() {
    return 0;
}
