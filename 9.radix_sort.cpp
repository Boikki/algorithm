/*************************************************************************
	> File Name: 9.radix_sort.cpp
	> Author: Boyu.Ren
	> Mail: renboyu@hrbeu.edu.cn
	> Created Time: 二  4/11 16:04:08 2023
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
#define LOW 0xffff
#define HIGH 0xffff0000
#define MAX_N 65536

#define LOW16(a) ((a) & LOW)
// #define HIGH16(a) (65535 - ((a) & HIGH) >> 16)

// #define HIGH16(a) ((a & 0xffff0000) >> 16)

#define __HIGH16(a) (((a) & 0xffff0000) >> 16)
#define HIGH16(a) (__HIGH16(a) > INT16_MAX ? (__HIGH16(a) - 32768) : (__HIGH16(a) + 32768))
// 修改之后对负数也能排序
// 因为负数补码的表示形式
// 负数的第一位肯定是1
// 也就是高16位的值会大于0x1000 0000 0000 0000 也就是INT16_MAX
// 所以就要消除第一位符号位对排序的影响
// 也就是负数减去符号位 正数加上符号位


// 负数怎么排序呢？
// 因为负数补码的表示形式
// 他是1开头的，所以会排到正数的后面
// 不妨将负数看成-1和xx的结合
// 正数看成是+1和xx的结合

// n 是当前待排序数组的大小
void radix_sort(int *arr, int n) {
    // 分别处理低16位和高16位
    // cnt数组为存储低16位每位出现频率的
    // 也就是存前缀和的
    // 这样知道了低16位是多少
    // 就能知道它在前缀和排第几
    // 也就是temp数组中的位置
    int cnt[MAX_N] = {0};
    int *temp = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) cnt[LOW16(arr[i])] += 1;
    for (int i = 1; i < MAX_N; i++) cnt[i] += cnt[i - 1];
    // cnt 记录的是从1开始的
    // 然而temp是从0开始跌
    // 所以每次要--cnt
    for (int i = n - 1; i >= 0; --i) temp[--cnt[arr[i] & LOW]] = arr[i];
    for (int i = 0; i < MAX_N; i++) cnt[i] = 0;

    // HIGH16
    for (int i = 0; i < n; i++) cnt[HIGH16(temp[i])] += 1;
    for (int i = 1; i < MAX_N; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) arr[--cnt[HIGH16(temp[i])]] = temp[i];
    free(temp);
    return ;
}

int *getRandData(int n) {
    int *temp = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) temp[i] = rand();
    return temp;
}

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return ;
}

int main() {
    #define MAX_M 20
    int *arr = getRandData(MAX_M);
    output(arr, MAX_M);
    radix_sort(arr, MAX_M);
    output(arr, MAX_M);
    return 0;
}
