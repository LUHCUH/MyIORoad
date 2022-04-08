/*
#from http://218.62.22.215/problem.php?id=2635
#from https://www.acwing.com/problem/content/4195/
#from https://loj.ac/p/10242
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;scanf("%d",&n);
	int ans=0,t;
	for(int i=1;i<=n;i++)scanf("%d",&t),ans^=t;
	if(ans)puts("win");
	else puts("lose");
	return 0;
}
