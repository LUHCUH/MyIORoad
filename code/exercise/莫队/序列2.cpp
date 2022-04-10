#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
const int N=1100000,MM=2200000;
struct xy
{
	int k[MM];long long sum;
	void init()
	{
		sum=0;
		memset(k,0,sizeof k);
	}
	void add(int x)
	{
		k[x]++;
		if(k[x]==1)
		{
			int ss=0;
			if(k[x-1])ss++;
			if(k[x+1])ss++;
			if(ss==2)sum-=2;
			else if(ss==0)sum+=2;
		}
	}
	void del(int x)
	{
		k[x]--;
		if(k[x]==0)
		{
			int ss=0;
			if(k[x-1])ss++;
			if(k[x+1])ss++;
			if(ss==2)sum+=2;
			else if(ss==0)sum-=2;
		}
	}
};
struct Node
{
	int l,r,q,id;
};
bool cmp(Node a,Node b)
{
	if(a.q==b.q)return a.r<b.r;
	return a.q<b.q;
}
map<int,int> M;
map<int,int>::iterator R;
int n,m,Q;
xy q;Node s[N];int a[N];
long long ans[N];
int main()
{
	int T,t;scanf("%d",&T);
	while(T--)
	{
		M.clear();q.init();
		scanf("%d%d",&n,&m);Q=sqrt(n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),M.insert(make_pair(a[i],0));
		int old=-2,col=2;
		for(R=M.begin();R!=M.end();R++)
		{
			if(old+1!=R->first)col++,col++,R->second=col;
			else col++,R->second=col;
			old=R->first;
		}
		for(int i=1;i<=n;i++)a[i]=M[a[i]];
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&s[i].l,&s[i].r);
			s[i].id=i;
			s[i].q=s[i].l/Q;
		}
		sort(s+1,s+1+m,cmp);
		
		int l=1,r=0;
		for(int i=1;i<=m;i++)
		{
			while(l>s[i].l)q.add(a[--l]);
			while(r<s[i].r)q.add(a[++r]);
			while(l<s[i].l)q.del(a[l++]);
			while(r>s[i].r)q.del(a[r--]);
			ans[s[i].id]=q.sum;
		}
		for(int i=1;i<=m;i++)
		{
			if(ans[i]==2)puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
/*
2
3 3
3 1 2
2 3
1 3
1 2
5 3
1 2 2 4 5
1 5
1 3
3 3

YES
YES
NO
NO
YES
YES
*/