/*Exercises for Algorithms Design and Analysis
Problem 3: Chuoi doi xung (Palindrome)*/

#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;


bool isPalindrome(string s, int l, int r)
{
	while (l < r)
	{
		if (s[l] != s[r])
			return false;
		l++;
		r--;
	}
	return true;
}

void backtracking(vector<vector<string>>& r, string& s, int start, vector<string>& c)
{
	if (start >= s.length())
	{
		r.push_back(c);
	}
	for (int i = start; i < s.length(); i++)
	{
		if (isPalindrome(s, start, i))
		{
			c.push_back(s.substr(start, i - start + 1));
			backtracking(r, s, i + 1, c);
			c.pop_back();
		}
	}
}
int main()
{
	vector<vector<string>> result;
	vector<string> current;
	string s;
	cin >> s;
	backtracking(result, s, 0, current);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

//dfs

/*bool isPalindrome(string& s, int l, int r)
{
	while (l < r)
	{
		if (s[l++] != s[r--])
			return false;
	}
	return true;
}*/
