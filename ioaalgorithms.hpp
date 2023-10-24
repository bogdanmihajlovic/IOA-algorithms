#ifndef IOAALGORITHMS_H
#define IOALGROTIHMS_H
#include <iostream>

/*Variations with repetition n^k*/
void nTuples(int n, int k);

/*Combinations without repetition*/
void kCombinations(int n, int k);

void seqToSpanningTree(int* P, int len, int* T);

void printSpannigTree(int* T, int len);
#endif