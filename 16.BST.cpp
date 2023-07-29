/*************************************************************************
	> File Name: 16.BST.cpp
	> Author: Boyu.Ren
	> Mail: renboyu@hrbeu.edu.cn
	> Created Time: 四  7/20 19:23:13 2023
 ************************************************************************/

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <pthread.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

struct Node {
    Node(int key = 0, Node *left = nullptr, Node *right = nullptr)
    : key(key), left(left), right(right) {}
    int key;
    Node *left, *right;
};

Node *getNewNode(int k) {
    return new Node(k);
}

Node *predecessor(Node *root) {
    Node *temp = root->left;
    while (temp->right) temp = temp->right;
    return temp;
}

Node *insert(Node *root, int k) {
    if (root == nullptr) return getNewNode(k);
    if (root->key == k) return root;
    if (root->key < k) root->right = insert(root->right, k);
    else root->left = insert(root->left, k);
    return root;
}

Node *erase(Node *root, int k) {
    if (root == nullptr) return root;
    if (k < root->key) 
        root->left = erase(root->left, k);
    else if 
        (k > root->key) root->right = erase(root->right, k);
    else {
        // case 0 dig
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            // return 删除后的新子树的根节点地址
            return nullptr;
        // case 1 dig
        } else if (root->left == nullptr || root->right == nullptr) {
            Node *temp = root->left ? root->left : root->right;
            delete root;
            // 因为删除的是度为1的节点
            // temp就是root的唯一子节点
            // 直接返回temp就是删除root之后在root位置的节点
            return temp;
        } else {
            // get predecessor or postdecessor
            // 都可
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->left = erase(root->left, temp->key);
        }
    }
    return root;
}

void clear(Node *root) {
    if (root == nullptr) return ;
    clear(root->left);
    clear(root->right);
    delete root;
    return ;
}

void output(Node *root) {
    if (root == nullptr) return ;
    output(root->left);
    std::cout << root->key << " ";
    output(root->right);
    return ;
}

int main(int argc, char **argv) {
    int op, val;
    Node *root = nullptr;
    while (std::cin >> op >> val) {
        switch (op) {
            case 0: root = insert(root, val); break;
            case 1: root = erase(root, val); break;
        }
        output(root);
        std::cout << std::endl;
    }
    return 0;
}
