/*************************************************************************
	> File Name: 5.heap.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 五  3/10 09:35:21 2023
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define MAX_N 1000
int data[MAX_N + 5], cnt = 0;


int top() { return data[0]; }
int size() { return cnt; }

void shift_up(int ind) {
    // 如何用子节点坐标获取父节点坐标？
    // 下标从0开始，子节点坐标分别为2i + 1和2i + 2
    // 这样(子节点坐标 - 1) / 2再向下取整
    // 正好就是父节点坐标
    while (ind && data[(ind - 1) / 2] < data[ind]) {
        std::swap(data[(ind - 1) / 2], data[ind]);
        ind = (ind - 1) / 2;
    }

}

void push(int x) {
    data[cnt++] = x;
    int ind = cnt;
    shift_up(cnt - 1);
    return ;
}

void shift_down(int ind) {
    int n = cnt - 1;
    while (ind * 2 + 1 <= n) {
        // 从上向下调整
        // 每次调整的目的就是将(ind, ind->left, ind->right)
        // 这个三元组中最大值换成用temp指向
        int temp = ind;
        if (data[temp] < data[ind * 2 + 1]) temp = ind * 2 + 1;
        // 比较left
        if (ind * 2 + 2 <= n && data[temp] < data[ind * 2 + 2]) temp = ind * 2 + 2;
        // 因为right很可能越界，所以先判断
        // 在比较right
        // 这样下来temp就指向了最大的值
        if (temp == ind) break;
        std::swap(data[ind], data[temp]);
        temp = ind;
    }
    return ;

}

void pop() {
    if (size() == 0) return ;
    std::swap(data[0], data[cnt - 1]);
    cnt -= 1;
    int ind = 0;
    // 因为cnt是数组长度，cnt - 1就是最大的下标
   shift_down(ind);
    return ;
}

void output(int n) {
    printf("heap : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return ;
}

int main() {
    int op, val;
    int max_n = 0;
    while (cin >> op) {
        switch (op) {
            case 0: {
                cin >> val;
                push(val);
                printf("push %d to heap\n", val);
                break;
            }
            case 1: {
                printf("pop %d from heap\n", top());
                pop();
                break;
            }
            case 2: {
                output(max_n);
                // 为什么我都pop完所有的元素了
                // output(max_n)还是会输出结果呢？
                // 因为堆的弹出是逻辑上的弹出！
                // 实际data数组并没有减少元素
                // 排序是一个任务
                // 堆只不过是实现排序的一种方式
            }
        }
        max_n = std::max(cnt, max_n);
        output(cnt);
    }

}
