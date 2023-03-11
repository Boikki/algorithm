/*************************************************************************
	> File Name: 5.c++_heap.cpp
	> Author: rEn Chong 
	> Mail: renboyu@hrbeu.edu.cn 
	> Created Time: 五  3/10 21:57:53 2023
 ************************************************************************/

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

template<typename T>
class Heap : public vector<T> {
public :
    template<typename Func_T>
    Heap(Func_T cmp) : cmp(cmp) {}
    void push(const T &a) {
        this->push_back(a);
        push_heap(this->begin(), this->end, cmp);
        return ;
    }
    void pop(const T &a) {
        pop_heap(this->begin(), this->end, cmp);
        this->pop_back(a);
        return ;
    }
    T &top() { return this->at(0); } 
private :
    std::function<bool(T, T)> cmp;
};

int main() {
    Heap<int> h1{std::less<int>()}; 
    // 传入< 代表小的优先级高 小顶堆
    Heap<int> h2{std::greater<int>()};
    return 0;
}
