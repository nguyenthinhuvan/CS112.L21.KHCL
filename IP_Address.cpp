/*Exercises for Algorithms Design and Analysis
Problem 4: Dia chi IP (IP Address)*/

#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

vector<string> ans;

string innerJoin(const string& s, vector<int>& split) 
{
    string ip = s;

    for (int i = split.size() - 1; i >= 0; --i) 
    {
        ip.insert(ip.begin() + split[i], '.');
    }
    return ip;
}

bool isValuable(string s)
{
    if (s.empty() || s.size() > 3)
        return false;
    if (s.size() == 3 && stoi(s) >= 256)
        return false;
    if (s.size() > 1 && s[0] == '0')
        return false;
    return true;
}

void backtracking(string& s, int start, vector<int>& split) 
{
    if (split.size() == 3)
    {
        if (isValuable(s.substr(split.back())))
        {
            ans.push_back(innerJoin(s, split));
        }
    }
    else {
        for (int len = 1; len <= 3 && start + len < s.size(); ++len) 
        {
            if (!isValuable(s.substr(start, len)))
                continue;
            //now s[start:start+len-1] is valid
            //'.' will be the (start+len)th char
            split.push_back(start + len);
            backtracking(s, start + len, split);
            split.pop_back();
        }
    }
}

vector<string> IP_Address(string s) 
{
    vector<int> split;
    backtracking(s, 0, split);
    return ans;
}


int main()
{
    string s;
    cin >> s;
    vector<string> result = IP_Address(s);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        cout << "\n";
    }
    return 0;
}

//restore_IP_Addresses