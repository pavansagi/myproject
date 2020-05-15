#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<vector<int>> gh;
int v[100000];
vector<int> clr;
vector<int> sp;
int c=0;
void dfs(int x,int z)
{   //cout << x  << " " << z << " " << clr[x] << endl;
	//v[x]=1;
	if(z==clr[x])
    {  if(sp[x]==0)c++;
        sp[x]=1;}
	//cout << c << "C";
	for(auto it=gh[x].begin();it!=gh[x].end();it++)
	{  
		//if(!v[*it])
		dfs(*it,z);
	}
}

int main()
{
	int n,n1;
	cin >> n;
	gh.resize(n+1);
	sp.resize(n+1);
	clr.resize(n+1);
	int a,b;
	v[1]=1;
	for(int i=1;i<n;i++)
	{
		cin >> a >> b;
		if(v[a]){gh[a].push_back(b);v[b]=1;}
		else{gh[b].push_back(a);v[a]=1;}
	}memset(v,0,sizeof v);
	
    //for(int i:v)cout << i << " ";
    //cout << endl;
	for(int i=1;i<=n;i++)cin >> clr[i];
	int q,p;
	cin >> q;
	
	//cout << n << endl;
	while(q--)
	{  cin >> p;
		if(c==n){cout << c << endl;continue;}
		//cout << "q" << q;
		dfs(p,clr[p]);
		
		cout << c << endl;
	    memset(v,0,sizeof v);
	}
}
		
		
	
