#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ma[1100000];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		ma[x]=max(ma[x],z);
		ma[y]=max(ma[y],z);
	}
	int mi=1;
	for(int i=1;i<=n;i++)
		if(ma[mi]>ma[i])mi=i;
	printf("%d\n",mi);
	return 0;
}
/*
4
1 2 1
2 3 2
1 4 3
*/