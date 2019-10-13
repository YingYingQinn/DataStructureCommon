#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class edge{
	int i;
	int j;
};
class graph{
public:
	vector<vector<int>> graphs;
	int N;
	graph(int n){
		for (int i = 0; i < n; i++)
			graphs.push_back(vector<int>());
	}
	void addedge(int i, int j)
	{
		graphs[i].push_back(j);
		graphs[j].push_back(i);
	}
};

int main()
{
	int n;
	cin >> n;
	graph g(n);
	vector<int> nums(n,0);
	int i, j;
	while (cin >> i >> j)
	{
		g.addedge(i, j);
		g.addedge(j, i);
		nums[i]++;
		nums[j]++;
	}
	vector<int> res;
	bool flag = true;
	while (flag)
	{
		bool flagtmp = false;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 1)
			{
				for (int j = 0; j < g.graphs[i].size(); j++)
				{
					int tmp = g.graphs[i][j];
					if (nums[tmp] != -1)
					{
						res.push_back(tmp);
						nums[tmp]--;
						break;
					}
				}
				nums[i] = -1;
				flagtmp = true;
			}
		}
		if (!flagtmp)
			flag = false;
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}