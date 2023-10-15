#include "permutation.hpp"

void nTuples(int n, int k){
    
    int* P = new int[k];
    for(int i = 0;i < k;i++)
        P[i] = 0;
    
    int q;
    do{
        for(int i = 0;i < k;i++)
            std::cout << P[i] + 1 << " ";
        std::cout << std::endl;

        q = k - 1;
        while(q >= 0){
            P[q]++;
            if (P[q] == n){
                P[q] = 0;
                q--;
            }else
                break;
        }
    }while(q >= 0);
    delete [] P;
}

void kCombinations(int n, int k){
    
    int i, j;
    bool b;
    int* P = new int[k];

    for(i = 0; i < k;i++)
        P[i] = i + 1;

    for(i = 0; i < k;i++)
        P[i] = i + 1;
    
    do{
        for(i = 0; i < k;i++)
            std::cout << P[i] << " ";
        std::cout << std::endl;
        b = false;
        for(i = k - 1; i >= 0;i--){
            if (P[i] < n - k + 1 + i){
                P[i]++;
                for(j = i + 1; j < k;j++)
                    P[j] = P[j -1] + 1;
                b = true;
                break;
            }
        }
    }while(b);
}