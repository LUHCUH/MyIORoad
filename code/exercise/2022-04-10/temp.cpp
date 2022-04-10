#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=125010;
int a[N];
long long sum[N];
int n,m,q;
long long mmax[300010],tag[300010];
struct node
{
	int x,c,y,op;
	long long ans;
};
node p[20010];
#define ls now<<1
#define rs now<<1|1
#define ld long double
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
void build(int now,int x,int l,int r)
{
	tag[now]=0;
	if(l==r)
	{
		mmax[now]=sum[l+x-1]-sum[l-1];
		return ;
	}
	int mid=(l+r)/2;
	build(ls,x,l,mid);build(rs,x,mid+1,r);
	mmax[now]=max(mmax[ls],mmax[rs]);
}
void psd(int now)
{
	if(tag[now])
	{
		tag[ls]+=tag[now];
		mmax[ls]+=tag[now];
		tag[rs]+=tag[now];
		mmax[rs]+=tag[now];
		tag[now]=0;
	}
}
void add(int now,int x,int y,int t,int l,int r)
{
	if(l==x&&r==y)
	{
		tag[now]+=t;
		mmax[now]+=t;
		return ;
	}
	psd(now);
	int mid=(l+r)/2;
	if(y<=mid) add(ls,x,y,t,l,mid);
	else if(mid<x) add(rs,x,y,t,mid+1,r);
	else add(ls,x,mid,t,l,mid),add(rs,mid+1,y,t,mid+1,r);
	mmax[now]=max(mmax[ls],mmax[rs]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=q;i++) scanf("%d%d%d",&p[i].x,&p[i].c,&p[i].y);
	for(int k=1;k<=min(2*m-1,n);k++)
	{
		build(1,k,1,n-k+1);
		for(int i=1;i<=q;i++)
		{
			if(max(p[i].x-k+1,1)<=min(p[i].x,n-k+1))
				add(1,max(p[i].x-k+1,1),min(p[i].x,n-k+1),p[i].c,1,n-k+1);
			if(p[i].y<=k)
			{
				if(p[i].op==0 || (ld)p[i].ans/p[i].op+1e-8<=(ld)mmax[1]/k)
					p[i].ans=mmax[1],p[i].op=k;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int g=gcd(p[i].ans%p[i].op,p[i].op);
		printf("%lld %d\n",p[i].ans/g,p[i].op/g);
	}
}