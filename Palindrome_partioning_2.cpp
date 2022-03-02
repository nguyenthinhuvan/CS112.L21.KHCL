/*Exercises for Algorithms Design and Analysis
- Problem 3: Chuoi doi xung (Palindrome)
- There the task was to find the partitioning with minimum cuts in input string. Here we need to print all possible partitions.
The idea is to go through every substring starting from first character, check if it is palindrome. 
If yes, then add the substring to solution and recur for remaining part. Below is complete algorithm.*/


#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std; bool isPalindrome(string s, int l, int r)
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

void allPalPartUtil(vector<vector<string> >& allPart, vector<string>& currPart,
	int start, int n, string str)
{
	if (start >= n)
	{
		allPart.push_back(currPart);
		return;
	}
	for (int i = start; i < n; i++)
	{
		if (isPalindrome(str, start, i))
		{
			currPart.push_back(str.substr(start, i - start + 1));
			allPalPartUtil(allPart, currPart, i + 1, n, str);
			currPart.pop_back();
		}
	}
}


void allPalPartitions(string str)
{
	int n = str.length();
	vector<vector<string> > allPart;
	vector<string> currPart;
	allPalPartUtil(allPart, currPart, 0, n, str);
	for (int i = 0; i < allPart.size(); i++)
	{
		for (int j = 0; j < allPart[i].size(); j++)
			cout << allPart[i][j] << " ";
		cout << "\n";
	}
}

int main()
{
	string str;
	cin >> str;
	allPalPartitions(str);
	return 0;
}

