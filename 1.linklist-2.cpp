/*************************************************************************
	> File Name: 1.linklist-2.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 二 11/ 8 20:16:55 2022
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// 链表的数组实现形式

int data[10]; 
int next[10];

// 在ind节点后添加节点p[val]
void add(int ind, int p, int val) {
    next[ind] = p;
    data[p] = val;
    return ;
}

int main() {
    int head = 3;
    data[head] = 0;
    add(3, 5, 7);
    add(5, 2, 2);
    add(2, 4, 6);
    add(4, 8, 8);
    // 上面构造完了链表
    int p = head;
    while (p) {
        // p->next next到头就是0了
        // 数组为空的元素是自动补0
        printf("%d->", data[p]);
        p = next[p];
    }
    return 0;

}
