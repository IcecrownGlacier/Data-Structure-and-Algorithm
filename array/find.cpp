#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row = array.size();
		int col = array[0].size();
		
		int i = row - 1;
		int j = 0;

		while (i >= 0 && j < col)
		{
			if (target > array[i][j])
			{
				j++;
			}
			else if (target < array[i][j])
			{
				i--;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};

/*
int main()
{
	int target = 5;
	vector<vector<int> > array = { {1, 2, 3}, 
								   {3, 4, 8} };
	bool re;
	Solution s;
	re = s.Find(target, array);
	
	cout << re << endl;
	system("pause");
	return 0;
}
*/