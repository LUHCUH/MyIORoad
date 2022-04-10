#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=1100000,M=1100000;
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
		k[x]++;
		if(k[x]==1)sum++;
	}
	void del(int x)
	{
		k[x]--;
		if(!k[x])sum--;
	}
};
struct Node
{
	int l,r,q,id,t;
};
bool cmp(Node a,Node b)
{
	if(a.q==b.q)return a.r<b.r;
	return a.q<b.q;
}
int n,m,Q;
xy q;
Node s[N];int stop=1;
pair<int,int> p[N];int ptop=1;
int a[N],b[N];
char ch[3];
long long ans[N];

int main()
{
	scanf("%d%d",&n,&m);
	Q=sqrt(n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%s%d%d",ch,&l,&r);
		if(ch[0]=='Q')
		{
			s[stop].l=l;
			s[stop].r=r;
			s[stop].t=ptop-1;
			s[stop].id=stop;
			s[stop++].q=l/Q;
		}
		else
		{
			p[ptop].first=l;
			p[ptop++].second=r;
		}
	}
	sort(s+1,s+stop,cmp);
	int l=1,r=0;
	for(int i=1;i<stop;i++)
	{
		for(int j=1;j<=s[i].t;j++)
		{
			int kk=p[j].first,ss=p[j].second;
			if(l<=kk&&kk<=r)q.del(b[kk]),q.add(ss),b[kk]=ss;
			else b[kk]=ss;
		}
		while(l>s[i].l)q.add(b[--l]);
		while(r<s[i].r)q.add(b[++r]);
		while(l<s[i].l)q.del(b[l++]);
		while(r>s[i].r)q.del(b[r--]);
		ans[s[i].id]=q.sum;
		for(int j=1;j<=s[i].t;j++)
		{
			int kk=p[j].first;
			if(l<=kk&&kk<=r)q.del(b[kk]),q.add(a[kk]),b[kk]=a[kk];
			else b[kk]=a[kk];
		}
	}
	for(int i=1;i<stop;i++)
	{
		printf("%lld\n",ans[i]);
	}
	return 0;
}
/*
6 5
1 2 3 4 5 5
Q 1 4
Q 2 6
R 1 2
Q 1 4
Q 2 6
*/