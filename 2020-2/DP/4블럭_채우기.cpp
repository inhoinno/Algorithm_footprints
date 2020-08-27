#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int inf = 10000000;
int d[10*25][1<<10];
string a[25];
int n,m;
int go(int index, int state){
	if (index == n*m){
		if(state ==0) return 0;
		else return -inf;
	}
	if(index > n*m) return -inf;
	int &ans = d[index][state];
	if(ans != -1)return ans;
	int i = index/m;
	int j = index%m;
	if(a[i][j]=='1'){
		ans = go(index+1, state>>1) + 1;
		return ans;//1이 이미 채워졌으면 바로바로 ㄱㄱ
	}
	//1이 안채워졌으면
	//1을 채운거랑 
	//4를 채운거랑 MAX를 본다
	ans = go(index+1, state>>1);
	if((state & 1)==0)
		ans = max(ans,go(index+1, state>>1)+1);

	if(i != n-1 && j != m-1 && (state&1) ==0 && (state&2==0))
		if(a[i][j+1]=='.'&& a[i+1][j]=='.'&&a[i+1][j+1]=='.')
			ans = max(ans, go(index+1,(state >>2)|(1<<(m-1))|(1<<(m-2)))+16);

	return ans;
	
	
}
int main(int argc, char * argv[]){
	vector<string> b(n);
	//!! Improper Input
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	//!! Improper Input validation
	for(int i=0;i<n)
		cin >> b[i];

	for(int j=0; j<m; j++)
		for(int i=0; i<n; i++)
			a[j] += b[i][j];

	swap(n,m);
	memset(d,-1,sizeof(d));
	cout<< go(0,0) << '\n';
	return 0;

}
