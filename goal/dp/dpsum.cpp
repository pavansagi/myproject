#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> a;
	int n,x;
	cin >> n;
	while(n--)
	{
		cin >> x;
		a.push_back(x);
	}
	
	int N;
	cin >> N;
	
	int arr[N+1];
	for(int i=0;i<N+1;i++)
	{
		arr[i]=0;
	}
	arr[0]=1;
	
	for(int i=1;i<N+1;i++)
	{
		for(auto it=a.begin();it!=a.end();it++)
		{
			if(i-*it>=0)
			{
				arr[i]+=arr[i-*it];
			}
		}
	}
	for(int i=0;i<N+1;i++)
	{
		cout << arr[i] << " ";
	}
	
	return 0;
}
