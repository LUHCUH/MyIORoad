/*
#from http://218.62.22.215/problem.php?id=2634
#from https://www.acwing.com/problem/content/1320/
#from https://loj.ac/p/10241
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	cout<<(n%(k+1)==0?2:1)<<endl;
	return 0;
}
