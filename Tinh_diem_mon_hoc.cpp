// Backtracking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int n = 0;
int* C = NULL;
double average = 0;
double* S = NULL;
int Sum_C = 1;


double averagePoint(double* A, int N, int*& C)
{
    if (N <= 0)
    {
        return 0.0;
    }
    if (C == NULL)
    {
        C = new int[N] {1};
    }
    double Sum = 0.0;
    for (int i = 0; i < N; ++i)
    {
        Sum += A[i] * C[i];
    }
    Sum /= Sum_C;
    return Sum;
}

double roundf(double k, int p) 
{
    int x = 0;
    for (int i = 1; i <= p; ++i) 
    {
        k *= 10;
    }
    x = int(k);
    if (int((k - x) * 10) >= 5) 
    {
        x++;
    }
    k = x;
    for (int i = 1; i <= p; ++i) 
    {
        k /= 10;
    }
    return k;
}


void output(double* A, int N)
{
    if (A != NULL)
    {
        for (int i = 0; i < N; ++i)
        {
            cout << A[i] << ' ';
        }
        cout << endl;
    }
}

void backtracking(int i, int N)
{
    S[i] = 0.25;
    while (S[i] <= 10.00)
    {
        if (i == N - 1)
        {
            double avg_p = roundf(averagePoint(S, N, C), 1);
            if (avg_p == average) 
            {
                if (average - 0.05 <= avg_p && avg_p < average + 0.05)
                {
                    output(S, N);
                }
            }
            else if (avg_p >= average + 0.05)
            {
                return;
            }
        }
        else
        {
            backtracking(i + 1, N);
        }
        S[i] += 0.25;
    }
}


int main()
{
    cin >> n;
    if (n > 0)
    {
        C = new int[n] {0};
        S = new double[n] {0};
        for (int i = 0; i < n; ++i)
        {
            cin >> C[i];
        }
        Sum_C = 100;
        cin >> average;
        backtracking(0, n);
        //delete[] C;
        //delete[] S;
    }
    return 0;
}