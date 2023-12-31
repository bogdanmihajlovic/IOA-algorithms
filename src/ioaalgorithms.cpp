#include "ioaalgorithms.hpp"

void nTuples(int n, int k){
    
    int* P = new int[k];
    for(int i = 0;i < k;i++)
        P[i] = 0;
    
    int q;
    do{
        for(int i = 0;i < k;i++)
            std::cout << P[i] + 1<< " ";
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

void seqToSpanningTree(int* P, int len, int* T) {
    int i = 0;
    int j = 0;
    int q = 0;

    int n = len + 2;
    int* V = new int[n];
    for (i = 0; i < n; i++)
    V[i] = 0;

    for (i = 0; i < len; i++)
        V[P[i] - 1] += 1;

    for (i = 0; i < len; i++) {
        for (j = 0; j < n; j++) {
            if (V[j] == 0) {
                V[j] = -1;
                T[q++] = j + 1;
                T[q++] = P[i];
                V[P[i] - 1]--;
                break;
            }
        }
    }   

    j = 0;
    for (i = 0; i < n; i++) {
        if (V[i] == 0 && j == 0) {
            T[q++] = i + 1;
            j++;
        }else if (V[i] == 0 && j == 1) {
            T[q++] = i + 1;
            break;
        }
    }
    delete[] V;
}

void printSpanningTree(int* T, int len) {
    for (int i = 0; i < 2*(len + 1); i++) {
        std::cout << " " << T[i];
        if ((i + 1) % 2 == 0 && i < 2 * len)
            std:: cout<< " - ";
    }
    std::cout << std::endl;
}