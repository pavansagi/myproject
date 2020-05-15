#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<vector<int>> gh;
vector<int> v;
stack<int> st;
void tsort(int x)
{
	v[x]=1;
	for(auto it=gh[x].begin();it!=gh[x].end();it++)
	{ 
		if(!v[*it])
		tsort(*it);
	}
	st.push(x);
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
	for(int i=0;i<n;i++)
	{ if(!v[i])tsort(i);}
	while(st.size())
	{ cout << st.top() << " ";
		st.pop();
	}
	return 0;
}
