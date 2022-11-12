/*************************************************************************
	> File Name: 1.linklist.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 二 11/ 8 19:07:07 2022
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// 构造一个简单的链表

struct Node {
    Node(int data) : data(data), next(NULL) {}
    int data;
    Node *next;
};

int main() {
    Node *head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    // 构造了一个 1->2->3->4的链表
    Node *p = head;
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    return 0;
}
