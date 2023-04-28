/*************************************************************************
	> File Name: 8.merge_file.cpp
	> Author: Boyu.Ren
	> Mail: renboyu@hrbeu.edu.cn
	> Created Time: 日  4/ 2 21:39:59 2023
 ************************************************************************/

#include <iostream>
using namespace std;

struct Data {
    FILE *fin;
    int val, flag;
};

int main(int argc, char *argv[]) {
    int n = argc - 1;
    Data *data = (Data *)malloc(sizeof(Data) * n);
    for (int i = 1; i < n + 1; i++) {
        data[i - 1].fin = fopen(argv[i], "r");
        if (fscanf(data[i - 1].fin, "%d", &data[i - 1].val) == EOF) {
            data[i - 1].flag = 1;
        } else {
            data[i - 1].flag = 0;
        }
    }
    FILE *fout = fopen("output", "w");
    while (true) {
        int flag = 0;
        int ind = -1;
        int min_val = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (data[i].flag) continue;
            if (ind == -1 || data[i].val < data[ind].val) {
                ind = i;
            }
        }
        if (ind != -1) {
            fprintf(fout, "%d\n", data[ind].val);
            if (fscanf(data[ind].fin, "%d", &data[ind].val) == EOF) {
                data[ind].flag = 1;
            } else {
                data[ind].flag = 0;
            }
            flag = 1;
        }
        if (flag == 0) break;
    }
    return 0;
}
