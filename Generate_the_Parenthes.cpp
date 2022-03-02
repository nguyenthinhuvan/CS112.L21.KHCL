/*Exercises for Algorithms Design and Analysis
Problem 2: Generate the Parenthes*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void backtracking(string str, int open, int close, int max);

void generateTheParenthesis(int n) 
{
    backtracking("", 0, 0, n);
}

void backtracking(string s, int open, int close, int max) 
{

    if (s.length() == max * 2) 
    {
        cout << s << endl;
        return;
    }

    if (open < max)
        backtracking(s + "(", open + 1, close, max);
    if (close < open)
        backtracking(s + ")", open, close + 1, max);
}

int main() 
{
    int n;
    cin >> n;
    //cout << "\n";
    generateTheParenthesis(n);
    return 0;
}