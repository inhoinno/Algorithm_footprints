#include <iostream>
#include <cstring>
using namespace std;
int n,m;
char a[22][22];
int d[10][1<<10];

bool isset(int state, int i) //(현재상태state가)여기(i)에 앉았습니까?
{
	return (state & (1 << i)) > 0;	//ㅎ현재 상태 state 에서, i라는 수가 마스킹이 되었습니까? return [Y/N]
}

bool check(int row, int state)
{
	if (row<0) 
		return true;

	for (int j =0; j<m-1; j++){
		if(isset(state,j) && isset(state,j+1))//row행 학생들이앉아 있는 상태를 state, j를 앉아 있는 열의  위치라고 한다면
			// 양 옆에는 
			return false ;	// 앉을 수 없어요
	}
	for (int j=0; j<m; j++){
		if(a[row][j]=='x'&& isset(state,j))//다른 행으로 인해 앉을 수 없는 경우에 학생이 앉게 되는경우
			//앉을 수 없는걸 return
			return false;
	}

	return true;
}


int main(int argc, char* argv[]){
	if(argc!=1){
		cout<<"argv err"<<endl;
		return -1;
	}
	int t = atoi(argv[1]);
	int cnt=0;
	bool ok = true;
	m = 10; n =9;
	//while(t--){
		//cin >>n>>m;
		//for (int i=0; i<n; i++){cin<<a[i];}
	memset(d,0,sizeof(d));
	int ans =0;
	for (int row=0; row<n; row++){	//for every row
		for( int state=0; state<(1<<m); state++){	//for every state
			if(!check(row,state)) continue;		//check possible state

			//row 	,	state
			//row-1	,	pstate
			for (int pstate=0; pstate<(1<<m); pstate++){ //for every pstate
				if(!check(row,pstate)) continue;
				//if posible
				cnt = 0; 
				ok = true;
				for (int j=0; j<m; j++){
					if(isset(state,j)){	//if 
						cnt+=1;
						if((j-1 >= 0)&& isset(pstate, j-1)) ok =false;
						if((j+1 < m) && isset(pstate, j+1)) ok =false;

					}
				}
				if(ok){
					if(row ==0)
						d[row][state] = max(d[row][state], cnt);
					else
						d[row][state] = max(d[row][state], d[row-1][pstate+cnt])
				}
			}
		}
	
	}
	for(int state=0; state<(1<<m); state++){
		if(ans<d[n-1][state]){
			ans = d[n-1][state];
		}
	}
	cout<<ans<<endl;
	
	//}
}

