#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=110000,M=(1<<19);
struct xy
{
	int k[M];long long sum;
	xy()
	{
		sum=0;
		memset(k,0,sizeof k);
	}
	void add(int x)
	{
		sum+=k[x];
		k[x]++;
	}
	void del(int x)
	{
		k[x]--;
		sum-=k[x];
	}
};
struct Node
{
	int l,r,q,id;
};
int n,m,Q;
xy q;Node s[N];int a[N];
long long ans[N];
bool cmp(Node a,Node b)
{
	if(a.q==b.q)return a.r<b.r;
	return a.q<b.q;
}
int main()
{
	scanf("%d%d",&n,&m);
	Q=sqrt(n);
	a[0]=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=a[i]^a[i-1];
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
		printf("%lld\n",ans[i]);
	}
	return 0;
}
/*
10 5
2 2 3 1 3 3 1 2 1 3
3 7
4 9
1 5
7 8
2 10
*/