#include<iostream>
#define N 1000
int dp[N][N];
using namespace std;
int maxp(int i,int j,int n,int a[])
{
	if(i==j)
	{return (n-j+i)*a[i];}
	if(dp[i][j]==-1)
	{dp[i][j]=max((n-j+i)*a[i]+maxp(i+1,j,n,a),(n-j+i)*a[j]+maxp(i,j-1,n,a));}
	return dp[i][j];
} 	             
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	{ cin >> a[i];}
	for(int i=0;i<N;i++)
	 {for(int j=0;j<N;j++)
		{dp[i][j]=-1;}
	}
	int r=maxp(0,n-1,n,a);
	cout << r << endl;
	for(int i=0;i<n;i++)
	 {for(int j=0;j<n;j++)
		{cout << dp[i][j] << " ";}
		cout << endl;
	}
		
		
	return 0;
}
