#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

bool backtracking(vector<vector<char>>& board, string word, int i, int j, int meow)  //meow for step 
{
    if (word.length() == 0)
    {
        return false;
    }
    if (meow == word.length())
        return true;
    if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0)
        return false;

    if (word[meow] == board[i][j])  
    {
        board[i][j] = '@';
        if  (  backtracking(board, word, i - 1, j, meow + 1) 
            || backtracking(board, word, i + 1, j, meow + 1) 
            || backtracking(board, word, i, j - 1, meow + 1) 
            || backtracking(board, word, i, j + 1, meow + 1) 
            || backtracking(board, word, i + 1, j + 1, meow + 1)
            || backtracking(board, word, i - 1, j - 1, meow + 1)
            || backtracking(board, word, i + 1, j - 1, meow + 1)
            || backtracking(board, word, i - 1, j + 1, meow + 1))
            return true;
        board[i][j] = word[meow];
    }
    return false;
}


bool exist(vector<vector<char>>& board, string word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (backtracking(board, word, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}


int main()
{
    string word;
    cin >> word;
    vector<vector<char>> board;
    char tmp;
    char temp;
    cin.ignore();
    while (tmp=getchar()) 
    {
        if (tmp != '.')
        {
            vector<char> newline;
            //newline.push_back(tmp);
            while (tmp != '\n')
            {
                newline.push_back(tmp);
                tmp = getchar();
            }
            //tmp = temp;
            board.push_back(newline);
        }
        else
        {
            break;
        }
    }
    if (exist(board, word))
        cout << "true";
    else
        cout << "false";
    //cout << board[0][0];
    return 0;
}
