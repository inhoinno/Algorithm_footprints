//2019 카카오 개발자 겨울 인턴십 문제
//
//문제 1. 5X5 ~ 30X30 배열에서, boards
//크레인 작동의 moves, 가장 위쪽녀석을 뽑아오며, 
//없는 경우 아무 일도 일어나지 않음
//result : 해당 moves로 인해남게 되는 바구니 안의 인형 개수
//

int board[6][6] = {
	// 1 2 3 4 5
	{0,0,0,0,0,0},
	{0,0,0,1,0,3},
	{0,0,2,5,0,1},
	{0,4,2,4,4,2},
	{0,3,5,1,3,1}
	} 
int moves[1001] = {1,5,3,5,1,2,1,4,0,}

//result =4
//

int invert_board(int [][] mboard, int [][] inv_board, ){
	//make board inverted
	inv_board[i][j] = mboard[j][i] 
}

//뽑는 함수

int board_pop(int [][] inv_board, int moves)
{
	//1. pop from board 
	//ret = inv_board[moves][값이 0ㅇ이 아닌 가장 작은 index] -> 우리는 state[5](배열)으로 시작을 알려줄수 있다, 
	// if(state[moves] == 0)
	// 	//then return 0; Empty board here
	//inv_board[moves][mindex] = 0;
	//state[moves] -=1;
	//return ret;

}

int basket_drop(int basket [], int first_in){
	//basket:LIFO
	//if(seek(basket)==first_in)
	//	then pop(basket)
	//return size(basket)
}


