/**
 * @file Name    : 10.binary_search.cpp
 * @brief        : 
 * @author       : Ren Boyu
 * @mail         : renboyu@hrbeu.edu.cn
 * @created Time : 五  4/28 18:39:21 2023
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <ctime>
using namespace std;


void output_binary_search(int *arr, int n, int head, int tail, int mid) {
    int p1, p2, p3, len = 0;
    for (int i = 0; i < n; i++) {
        len += printf("%5d", i);
        if (i == head) p1 = len - 1;
        if (i == tail) p2 = len - 1;
        if (i == mid) p3 = len - 1;
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%5d", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < len; i++) {
        if (i == p1 || i == p2 || i == p3) {
            printf("^");
        } else {
            printf(" ");
        }
    }
    printf("\n");
    for (int i = 0; i < len; i++) {
        if (i == p1 || i == p2 || i == p3) {
            printf("|");
        } else {
            printf(" ");
        }
    }
    printf("\n\n");
    return ;
}


int binary_search(int *arr, int n, int x) {
    int head = 0, tail = n - 1, mid;
    // 为了防止基数偶数的问题
    // 和防止出现死循环
    // 可以这样写比较简单
    // 01 10
    // 也可以用
    while (tail - head > 3) {
    // while (head <= tail) {
        // haed tail 同时很大的时候
        // 就会越界了
        // mid = (head + tail) >> 1;
        // 可以这样修改
        mid = head + ((tail - head) / 2);
        output_binary_search(arr, n, head, tail, mid);
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    for (int i = head; i <= tail; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

int binary_search_01(int *arr, int n, int x) {
    int head = 0, tail = n - 1, mid;
    // 因为是找第一个1出现的位置
    // 那个时候必定head tail重合
    while (head < tail) {
        // haed tail 同时很大的时候
        // 就会越界了
        // mid = (head + tail) >> 1;
        // 可以这样修改
        mid = head + (tail - head) / 2;
        output_binary_search(arr, n, head, tail, mid);
        if (arr[mid] < x) head = mid + 1;
        // mid == 1不能跳过哦
        else tail = mid;
    }
    return head;
}
int *get_data(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    arr[0] = rand() % 10;
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] + rand() % 5 + 1;
    }
    return arr;
}

void output(int *arr, int n) {
    int len = 0;
    for (int i = 0; i < n; i++) {
        len += printf("%5d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%5d", arr[i]);
    }
    printf("\n");
    return ;
}

int main() {
    srand(time(0));
    int n, x;
    scanf("%d", &n);
    int *arr = get_data(n);
    output(arr, n);
    while (~scanf("%d", &x)) {
        printf("arr[%d] = %d\n", binary_search_01(arr, n, x), x);
    }
    return 0;
}

