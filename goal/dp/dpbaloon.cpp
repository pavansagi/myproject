#include<bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> dp(n,vector<int>(n));
	int a[n];
	for(int i=0;i<n;i++)
	{ cin >> a[i];}
	for(int l=n-1;l>=0;l--)
	{ 
		for(int r=l;r<n;r++)
		{
			for(int i=l;i<=r;i++)
			{
				dp[l][r]=max(dp[l][r],(l?a[l-1]:1)*a[i]*(r==n-1?1:a[r+1])+(l<=i-1?dp[l][i-1]:0)+(i+1<=r?dp[i+1][r]:0));
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

