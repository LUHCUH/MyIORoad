#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=51000;
struct xy
{
	int k[N];long long sum;
	xy()
	{
		sum=0;
		memset(k,0,sizeof k);
	}
	void add(int x)
	{
		sum+=k[x]*2+1;
		k[x]++;
	}
	void del(int x)
	{
		k[x]--;
		sum-=k[x]*2+1;
	}
};
struct Node
{
	int l,r,q,id;
};
int n,m,k,Q;
xy q;Node s[N];int a[N];
long long ans[N];
bool cmp(Node a,Node b)
{
	if(a.q==b.q)return a.r<b.r;
	return a.q<b.q;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	Q=sqrt(n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&s[i].l,&s[i].r);
		s[i].id=i;
		s[i].q=(s[i].l+1)/Q;
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
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}
/*
6 4 3
1 3 2 1 1 3
1 4
2 6
3 5
5 6
*/