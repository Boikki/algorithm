/*************************************************************************
	> File Name: 4.BST.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 四  2/16 01:22:22 2023
 ************************************************************************/

#include <iostream>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;

struct Node {
public :
    Node(int key, Node *lchild, Node *rchild) : key(key), lchild(lchild), rchild(rchild) {}
    int key;
    struct Node *lchild;
    struct Node *rchild;
};

Node *getNewNode(int key) {
    Node *p = new Node(key, nullptr, nullptr);
    return p;
}

Node *random_insert(Node *root, int key) {
    if (root == nullptr) return getNewNode(key);
    if (rand() % 2) {
        root->lchild = random_insert(root->lchild, key);
    } else {
        root->rchild = random_insert(root->rchild, key);
    }
    return root;
}

void pre_order(Node *root) {
    if (root == nullptr) return ;
    cout << root->key << " ";
    pre_order(root->lchild);
    pre_order(root->rchild);
    return ;
}

void in_order(Node *root) {
    if (root == nullptr) return ;
    in_order(root->lchild);
    cout << root->key << " ";
    in_order(root->rchild);
    return ;
}

int main(int argc, char *argv[]) {
    srand(time(0));
    if (argc != 2) return 0;
    int MAX_N = atoi(argv[1]);
    Node *root = nullptr;
    for (int i = 1; i <= MAX_N; i++) {
        root = random_insert(root, i);
    }
    pre_order(root);
    cout << endl;
    in_order(root);
    return 0;
}
