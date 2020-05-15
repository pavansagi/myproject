#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> gh;
vector<int> v;
void bfs(int x)
{
	int p;
	queue<int> q;
	q.push(x);
	while(!q.empty())
	{  
		p=q.front();
		
		if(!v[p])
		{ v[p]=1;
			cout << p << " ";
			for(int j:gh[p]){q.push(j);}
			//cout << q.front() << " ";
			cout << endl;
		}
		q.pop();
	}
}
int main()
{
	int n,n1;
	cin >> n >> n1;
	int a,b;
	gh.resize(n);
	v.resize(n);
	for(int i=0;i<n1;i++)
	{
		cin >> a >> b;
		gh[a].push_back(b);
	
	}
	bfs(2);
	return 0;
}
