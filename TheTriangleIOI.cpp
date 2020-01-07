#include <iostream>
#include <cmath>

int tSum(int x){
    if(x > 1)
        return x + tSum(x - 1);
    return x;
}

int main(){
    int triangle[5050], sums[5050];
    int layers;
    std::cin >> layers;
    int tSums[layers];
    for(int i = 0; i <= layers; i++){
        tSums[i] = tSum(i);
    }

    for(int i = 0; i < layers; i++){
        for(int j = 0; j < i+1; j++){
            std::cin >> triangle[tSum(i) + j];
        }
    }

    for(int i = layers - 1; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(i == layers - 1) sums[tSums[i] + j] = triangle[tSums[i] + j];
            else{
                sums[tSums[i] + j] = triangle[tSums[i] + j] + std::max(sums[tSums[i + 1] + j], sums[tSums[i + 1] + j + 1]);
            }

        }
    }
    std::cout << sums[0] << std::endl;
    return 0;
}
