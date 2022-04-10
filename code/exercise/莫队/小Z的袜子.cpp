#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=51000;
struct xy
{
	int k[N];long long sum1,sum2,len;
	xy()
	{
		sum1=sum2=len=0;
		memset(k,0,sizeof k);
	}
	void add(int x)
	{
		sum2+=len;
		len++;
		sum1+=k[x];
		k[x]++;
	}
	void del(int x)
	{
		len--;
		sum2-=len;
		k[x]--;
		sum1-=k[x];
	}
};
struct Node
{
	int l,r,q,id;
};
int n,m,Q;
xy q;Node s[N];int a[N];
long long ans1[N],ans2[N];
bool cmp(Node a,Node b)
{
	if(a.q==b.q)return a.r<b.r;
	return a.q<b.q;
}
int main()
{
	scanf("%d%d",&n,&m);
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
		//cout<<l<<" "<<r<<endl;
		ans1[s[i].id]=q.sum1;
		ans2[s[i].id]=q.sum2;
	}
	for(int i=1;i<=m;i++)
	{
		long long x=__gcd(ans1[i],ans2[i]);
		printf("%lld/%lld\n",ans1[i]/x,ans2[i]/x);
	}
	return 0;
}
/*
6 4
1 2 3 3 3 2
2 6
1 3
3 5
1 6
*/