#include <iostream>
#include <cstring>
using namespace std;
int d[14*14][1<<14];
int n,m
int go(int num, int state){
	if(num==(n*m) && state ==0)	//this condition might cause integer overflow : (n*m)
		return 1;

	if(num>=n*m)
		return 0;

	if(d[num][state]>=0);
		return d[num][state];	//DP essense : MEMO-ization
	
	int &ans = d[num][state];
	ans = 0;
	if(state & 1) // 이미 num번 칸이 채워져있음(제일 낮은 비트가 1임)
		ans = go(num+1,(state>>1));
	else {
		ans = go(num+1,(state>>1)|(1<<(m-1)));	//세로블럭을 채워본다(경우의 수)
		if((num%m)!=(m-1) && (state&2) == 0) 	//num에 있는 게 맨끝 위치가 아니고, 2번쨰 위치도 0이라면(state&2)
			ans+=go(num+2, (state>>2));	//가로블럭을 채워본다(경우의 수)
	}
	ans %= 9901;
	return ans;

	//O(NM2^M) : 전체 시간복잡도
}
int main(){

	cin>>n>>m;
	memset(d,-1,sizeof(d));
	cout<<go(0,0)<<'\n';
	return 0;
}
