#include<iostream>

using namespace std;

int sp(int a[][4],int dp[][4],int i,int j)
{
	 if(i==0&&j==0)
	 return dp[i][j];
		if(i-1>=0&&j-1>=0)
		{
			dp[i][j]=a[i][j]+min(sp(a,dp,i-1,j),sp(a,dp,i,j-1));
		}
		if(i-1<0)
		{
			dp[i][j]=a[i][j]+sp(a,dp,i,j-1);
		}
		if(j-1<0)
		{
			dp[i][j]=a[i][j]+sp(a,dp,i-1,j);
		}
		return dp[i][j];
	
}
	
int main()
{
	int a[4][4];
	int dp[4][4];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin >> a[i][j];
		}
	}
	
	dp[0][0]=a[0][0];
	int x=sp(a,dp,3,3);
	cout << x;
	return 0;
}
