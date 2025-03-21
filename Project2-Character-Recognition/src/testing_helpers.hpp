#pragma once

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <ctime>

template<typename T>
int cmpArrays(int n, T *a, T *b) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            printf("    a[%d] = %d, b[%d] = %d\n", i, a[i], i, b[i]);
            return 1;
        }
    }
    return 0;
}

void printDesc(const char *desc) {
    printf("==== %s ====\n", desc);
}

template<typename T>
void printCmpResult(int n, T *a, T *b) {
    printf("    %s \n",
            cmpArrays(n, a, b) ? "FAIL VALUE" : "passed");
}

template<typename T>
void printCmpLenResult(int n, int expN, T *a, T *b) {
    if (n != expN) {
        printf("    expected %d elements, got %d\n", expN, n);
    }
    printf("    %s \n",
            (n == -1 || n != expN) ? "FAIL COUNT" :
            cmpArrays(n, a, b) ? "FAIL VALUE" : "passed");
}

void zeroArray(int n, int *a) {
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
}

void onesArray(int n, int *a) {
	for (int i = 0; i < n; i++) {
		a[i] = 1;
	}
}

void genArray(int n, int *a, int maxval) {
    srand(time(nullptr));

    for (int i = 0; i < n; i++) {
        a[i] = rand() % maxval;
    }
}

//initialize weight matrix within a certain range -- should that be sequential?
void init_weight_matrix(int n, int hidden_num,  float* weight_matrix, float range_min = 0, float range_max = 1)
{
    srand(time(nullptr));
    for (int i = 0; i < n * hidden_num; ++i)
    {
        weight_matrix[i] = range_min + (static_cast <float> (rand()) / (static_cast <float> (RAND_MAX))) * (range_max - range_min);
        if (weight_matrix[i] > range_max)
        {
            std::cout << "weight matrix index " << i << " has problem, its value is " << weight_matrix[i] << std::endl;
            weight_matrix[i] = range_max;
        }
        else if (weight_matrix[i] < range_min)
        {
            std::cout << "weight matrix index " << i << " has problem, its value is " << weight_matrix[i] << std::endl;
            weight_matrix[i] = range_min;
        }
    }
}

void init_bais_vec(int n, float *mat)
{
    for (int i = 0; i < n; ++i)
    {
        mat[i] = 0;
    }
}

void init_input(int n, float* input) {
    for (int i = 0; i < n; ++i)
    {
        input[i] = i % 2 == 0 ? 1 : 0;
    }
}

void printArray(int n, int *a, bool abridged = false) {
    printf("    [ ");
    for (int i = 0; i < n; i++) {
        if (abridged && i + 2 == 15 && n > 16) {
            i = n - 2;
            printf("... ");
        }
        printf("%3d ", a[i]);
    }
    printf("]\n");
}

void printFloatArray(int n, float *a, bool abridged = false) {
    printf("    [ ");
    for (int i = 0; i < n; i++) {
        if (abridged && i + 2 == 15 && n > 16) {
            i = n - 2;
            printf("... ");
        }
        printf("%.3f ", a[i]);
    }
    printf("]\n");
}

template<typename T>
void printElapsedTime(T time, std::string note = "")
{
	std::cout << "   elapsed time: " << time << "ms    " << note << std::endl;
}