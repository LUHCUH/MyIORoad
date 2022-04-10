#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int N=310000;
namespace tree
{
	long long a[N];
	int lowbit(int x)
	{
		return x&(-x);
	}
	void add(int x,int k)
	{
		for(int i=x;i<N;i+=lowbit(i))
			a[i]+=k;
	}
	long long sum(int x)
	{
		long long ans=0;
		for(int i=x;i;i-=lowbit(i))
			ans+=a[i];
		return ans;
	}
}
vector<int> v[N];
int n,a[N],f[N];
map<int,int> M;
map<int,int>::iterator R;
long long ans=0;
void dfs(int x)
{
	ans+=tree::sum(a[x]-1);
	cout<<x<<" "<<tree::sum(a[x]-1)<<endl;
	tree::add(a[x],1);
	for(int i=0;i<v[x].size();i++)
	{
		if(f[x]==v[x][i])continue;
		f[v[x][i]]=x;
		dfs(v[x][i]);
	}
	tree::add(a[x],-1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),M.insert(make_pair(a[i],0));
	int col=1;
	for(R=M.begin();R!=M.end();R++)
		R->second=col++;
	for(int i=1;i<=n;i++)a[i]=M[a[i]];
	int x,y;
	for(int i=1;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}