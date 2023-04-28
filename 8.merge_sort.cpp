/*************************************************************************
	> File Name: 8.merge_sort.cpp
	> Author: Boyu.Ren
	> Mail: renboyu@hrbeu.edu.cn
	> Created Time: 日  4/ 2 17:07:41 2023
 ************************************************************************/

#include <iostream>
using namespace std;

void merge_sort(int *arr, int l, int r) {
    // 递归的边界条件：只有一个元素就不用排序
    if (l >= r) return ;
    int mid = (l + r) >> 1;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    // 因为是回溯过程才实现的排序
    // 所以写在递归下面
    // 递归深度logn 空间开销是logn ^ 2
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int k = 0, p1 = l, p2 = mid + 1;
    while (p1 <= mid || p2 < r) {
        // 两种情况将拿左边
        // 1. 右边没元素了
        // 2. 左边元素有并且较小
        if ((p2 > r) || (p1 <= mid && arr[p1] <= arr[p2])) {
            temp[k++] = arr[p1++];
        } else {
            temp[k++] = arr[p2++];
        }
    }
    for (int i = l; i <= r; i++) arr[i] = temp[i - l];
    free(temp);
    return ;
}

int main() {
    return 0;
}
