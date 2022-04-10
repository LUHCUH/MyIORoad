/*
from http://218.62.22.215/problem.php?id=2577
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=2100000;
int sum[N];
int q[N*2],qhead=0,qtail=0;
int main()
{
	int n,a,b;scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a,&b),sum[i+n]=sum[i]=a-b;//距离 油
	for(int i=1;i<=n*2;i++)sum[i]+=sum[i-1];
	for(int i=1;i<=n;i++)
	{
		while(qhead<qtail&&q[qhead]+n<i)qhead++;
		while(qhead<qtail&&q[qtail]>=sum[i])qtail--;
	}
	return 0;
}
