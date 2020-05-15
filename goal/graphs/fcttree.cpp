#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define ll long long
#define fi first
#define se second
using namespace std;
const ll m=1e9+7;
int tim=1,j,res;
vector<pair<int,int>> ar[1000001];
vector<int> v[100001];
int flat[200002],start[100001],over[100001],val[100001],lca[100001][20],level[100001],ans[100001],inv[2000001],nodef[100001],elef[1000001];
struct query{
	int l,r,idx,flag,lca;};
query Q[100001];
ll modi(ll a,ll n)
{ll res=1;
	while(n)
	{if(n%2){res=(res*1LL*a)%m;}
	 n=n/2;
     a=(1LL*a*a)%m;
	}
	return res;
}
void init()
{
	ar[1].pb({1,0});
	for(int i=2;i<=1000000;i++)
	 {if(ar[i].size()==0)
		{ ar[i].pb({i,1});
		  for(j=i+i;j<=1000000;j=j+i)
		  { int cnt=0;
			 int x=j;
			 while(x%i==0)
			 cnt++,x=x/i;
			 ar[j].pb({i,cnt});
		 }
		}}
	inv[0]=inv[1]=1;
	for(int i=2;i<=2000000;i++)
	{inv[i]=(m-(((m/i)*1LL*inv[m%i])%m))%m;}
}
void initlca(int n)
{
	for(int i=1;i<20;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(lca[j][i-1]!=-1)
			{ lca[j][i]=lca[lca[j][i-1]][i-1];}
		}
	}
}
bool comp(query a,query b)
{
	int x=a.l/1200;
	int y=b.l/1200;
	if(x!=y)
	{ return x<y;}
	return x%2? a.r<b.r : a.r>b.r;
}
int getlca(int a,int b)
{
	if(level[a]>level[b])swap(a,b);
	int d=level[b] -level[a];
	int f=0;
	while(d)
	{
		if(d%2==1)
		{ b=lca[b][f];}
		d=d/2;
		f++;
	}
	if(a==b) return a;
	for(int j=19;j>=0;j--)
	{
	  if(lca[a][j]!=-1&&(lca[a][j]!=lca[b][j]))
	  a=lca[a][j],b=lca[b][j];
    }
	 return lca[a][0];
 }
 void add(int nd)
 {
	 nd=flat[nd];
	 nodef[nd]++;
	
	 if(nodef[nd]==1)
	 {   int ele=val[nd];
		 for(auto it:ar[ele])
		 {	int pre=elef[it.fi];
			elef[it.fi]+=it.se;
			int cur=elef[it.fi];  
			res=(res*1LL*(inv[pre+1]))%m;
		    res=(res*1LL*(cur+1))%m;
		 }
	 }
	 else
	 {   int ele=val[nd];
		for(auto it:ar[ele])
		 {	int pre=elef[it.fi];
			elef[it.fi]-=it.se;
			int cur=elef[it.fi];   
			res=(res*1LL*(inv[pre+1]))%m;
		    res=(res*1LL*(cur+1))%m;
		 } 
	 }
 }
 void remove(int nd)
 {
	 nd=flat[nd];
	 nodef[nd]--;
	 
	 if(nodef[nd]==1)
	 { int ele=val[nd];
		  for(auto it:ar[ele])
		 {	int pre=elef[it.fi]; 
			elef[it.fi]+=it.se;
			int cur=elef[it.fi];
			res=(res*1LL*(inv[pre+1]))%m;
		    res=(res*1LL*(cur+1))%m;
		 }
	 }
	 else
	 {  int ele=val[nd];
		for(auto it:ar[ele])
		 {	int pre=elef[it.fi]; 
			elef[it.fi]-=it.se;
			int cur=elef[it.fi];
			res=(res*1LL*(inv[pre+1]))%m;
		    res=(res*1LL*(cur+1))%m;
		 } 
	 }
 }
 int addlca(int lca)
 {  int tr=res;
	int ele=val[lca];
	for(auto it:ar[ele])
		 {	int pre=elef[it.fi];
			int cur=pre+it.se;  
			tr=(tr*1LL*(inv[pre+1]))%m;
		    tr=(tr*1LL*(cur+1))%m;
		 }
	int x=tr-res;
	if(x<0)x+=m;
	return x;
}
void dfs(int i,int par,int lvl)
{  level[i]=lvl;
	lca[i][0]=par;
    flat[tim]=i;
	start[i]=tim++;	
	for(int j:v[i])
	{   
		if(j!=par)dfs(j,i,lvl+1);
	}
	flat[tim]=i;
	over[i]=tim++;
}
void reset(int n)
{   rep(i,n)
	{  v[i].clear();
		for(int j=0;j<20;j++)
		lca[i][j]=-1;
		nodef[i]=0;}
   for(int i=1;i<=1000000;i++)
   { elef[i]=0;}
}	
int main()
{  init();   
	int n,a,b,t,q;
	cin >> t;
	while(t--)
	{   res=1;tim=1;
		cin >> n;
		reset(n);
       rep(i,n-1)
       {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	   }dfs(1,-1,0);initlca(n);
	   rep(i,n)cin >> val[i];
	   cin >> q;
	   for(int i=1;i<=q;i++)
	   { cin >> a >> b;
		   if(start[a]>start[b])swap(a,b);
		   int lca=getlca(a,b);
		   if(a!=lca)
		   {Q[i].l=over[a];Q[i].r=start[b];Q[i].flag=1;}
		   else{Q[i].l=start[a];Q[i].r=start[b];Q[i].flag=0;}
	       Q[i].idx=i;Q[i].lca=lca;
	   }
	   sort(Q+1,Q+q+1,comp);
	   int ML=1,MR=0;
	   for(int i=1;i<=q;i++)
	   { int L=Q[i].l,R=Q[i].r,idx=Q[i].idx,lca=Q[i].lca,flag=Q[i].flag;
         while(MR<R)MR++,add(MR);
          while(ML>L)ML--,add(ML);
         while(MR>R)remove(MR),MR--;
           while(ML<L)remove(ML),ML++; 	   
         ans[idx]=res;
         if(flag)
         { ans[idx]+=addlca(lca);
		   if(ans[idx]>=m)ans[idx] -= m;
	     }
	 }
	 rep(i,q)
	 cout <<  ans[i] << endl;
   }
}       

