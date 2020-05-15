void initlca(int n)
{
	for(int i=1;i<20;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(lca[j][i-1]!=-1)
			{ lca[j][i]=lca[lca[j][i-1]][j-1];}
		}
	}
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
