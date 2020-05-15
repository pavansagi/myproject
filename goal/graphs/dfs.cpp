#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> gh;
vector<int> v;
void dfs(int x)
{
	v[x]=1;
	cout << x << " ";
	for(auto it=gh[x].begin();it!=gh[x].end();it++)
	{  /*if(v[*it])
		{cout << "cycle" << *it << x;
			exit(0);}*/
		if(!v[*it])
		dfs(*it);
	}
}
void dfsadj(int x,int n)
{
	v[x]=1;
	
	for(int i=0;i<n;i++)
	{
		
		if(gh[x][i]&&!v[i])
		dfsadj(i,n);
	}
	cout << x << " ";
}
int main()
{
	int n,n1;
	cin >> n >> n1;
	gh.resize(n);
	v.resize(n);
	int a,b;
	for(int i=0;i<n1;i++)
	{
		cin >> a >> b;
		gh[a].push_back(b);
		//gh[b].push_back(a);
	}
	/*dfs(2);
	cout << "no";*/
	/*for(int i=0;i<n1;i++)
	{
		cin >> a >> b;
		gh[a][b]=1;
		//gh[b][a]=1;
	}*/
	//dfsadj(2,n);
	
	int cp=0;//count connected components
	/*for(int i=0;i<n;i++)
	{  if(!v[i])
		{ dfsadj(i,n);
			cout << endl;cp++;}
		}
		cout << cp;*/
	return 0;
}
