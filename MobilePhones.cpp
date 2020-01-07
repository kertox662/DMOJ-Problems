#include <iostream>
#include <algorithm>

// short *createTree(int n);
void createTree(int tree[], int n);
void updateTree(int tree[], int n, int index, short val);
int getSum(int tree[], int index);
int rangeSum(int tree[], int low, int high);
int squareSum(int tree[], int x1, int y1, int x2, int y2, short size);

int main(){
    short instruction = 0;
    int *biTree = new int[1024 * 1024 + 1];
    short size;
    
    while (instruction != 3){
        std::cin >> instruction;
        switch(instruction){
            case 0:
                std::cin >> size;
                createTree(biTree, size*size);
                break;

            case 1:
                short x,y,val;
                std::cin >> x >> y >> val;
                updateTree(biTree, size * size, x + y*size, val);
                break;

            case 2:
                short x1, x2, y1, y2;
                std::cin >> x1 >> y1 >> x2 >> y2;
                // std::cout << "Min Element: " << *std::min_element(biTree, biTree + size*size + 1) << std::endl;
                std::cout << squareSum(biTree, x1, y1, x2, y2, size) << std::endl;
                break;
        }
    } 
    delete[] biTree;
    return 0;
}

void updateTree(int tree[], int n, int index, short val){
    index += 1;
    while (index <= n){
        tree[index] += val;
        index += index & (-index);
    }
}

int getSum(int tree[], int index){
    index += 1;
    int sum = 0;
    while (index > 0){
        sum += tree[index];
        index -= index & (-index);
    }

    return sum;
}

int rangeSum(int tree[], int low, int high){
    return getSum(tree, high) - getSum(tree, low - 1);
}

int squareSum(int tree[], int x1, int y1, int x2, int y2, short size){
    int sum = 0;
    for(int l = y1; l <= y2; l++) sum += rangeSum(tree, x1 + l * size, x2 + l * size);
    return sum;
}

// short *createTree(int n){
//     short *tree = new short[n+1];
//     return tree;
// }

void createTree(int tree[], int n){
    for(int i = 0; i <= n; i++)
        tree[i] = 0;
}