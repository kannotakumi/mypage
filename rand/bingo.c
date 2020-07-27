#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define A 7
#define K 100000

void BingoCard(int bingo[5][5]);
void Lot(int lotretu[5]);
void Check(int bingo[5][5], int lotretu[75]);
int  Bingo(int bingo[5][5]);


int main(void){
	int B,I,N,G,O = 0;
	int i,j,k,l,m;
	int lotcount = 0;
	int ans = 0;
	int lot;
	int count = 0;

	srand((unsigned int)time(NULL));
	for(m = 0; m < K; m++){
		int bingo[5][5] = {0};
		int lotretu[75] = {0};
		BingoCard(bingo);
		Lot(lotretu);
		Check(bingo, lotretu);

		count = Bingo(bingo);
		if((bingo[0][0] == 0 && bingo[1][1] == 0 && bingo[2][2] == 0 && bingo[3][3] == 0 && bingo[4][4] == 0) /*|| (bingo[0][4] == 0 && bingo[1][3] == 0 && bingo[2][2] == 0 && bingo[3][1] == 0 && bingo[4][0] == 0)*/){
		for(i = 0; i < 5; i++){
			for(j = 0; j < 5; j++){
				printf("|%d  " ,bingo[j][i]);
			}
			printf("|\n");
		}
		printf("\n");
		}
	
		/*if(count > 0){

			printf("count = %d \n",count);

			for(i = 0; i < A; i++){
				printf(" %d回目:%d", i, lotretu[i]);
			}
			printf("\n");
			for(i = 0; i < 5; i++){
				for(j = 0; j < 5; j++){
					printf("|%d  " ,bingo[j][i]);
				}
				printf("|\n");
			}
		}

		if(count > 0){
			ans++;
			count = 0;
		}*/
	}

	//printf("ans=%d\n",ans);
}

void BingoCard(int bingo[5][5]){
	int B,I,N,G,O = 0;
	int i,j,k;

	for(i = 0;i < 5; i++){
		if(i == 0){
			for(j = 0; j < 5; j++){
				B = rand() % 15 + 1;
				bingo[i][j] = B;
				for(k = 0; k < j; k++){
					if(bingo[i][j] == bingo[i][k]){
						bingo[i][j] = 0;
						j--;
						break;
					}
				}
			}
		}
		else if(i == 1){
			for(j = 0; j < 5; j++){
				I = rand() % 15 + 16;
				bingo[i][j] = I;
				for(k = 0; k < j; k++){
					if(bingo[i][j] == bingo[i][k]){
						bingo[i][j] = 0;
						j--;
						break;
					}
				}
			}
		}

		else if(i == 2){
			for(j = 0; j < 5; j++){
				N = rand() % 15 + 31;
				bingo[i][j] = N;
				for(k = 0; k < j; k++){
					if(bingo[i][j] == bingo[i][k]){
						bingo[i][j] = 0;
						j--;
						break;
					}
				}
			}
		}

		else if(i == 3){
			for(j = 0; j < 5; j++){
				G = rand() % 15 + 46;
				bingo[i][j] = G;
				for(k = 0; k < j; k++){
					if(bingo[i][j] == bingo[i][k]){
						bingo[i][j] = 0;
						j--;
						break;
					}
				}
			}
		}

		else if(i == 4){
			for(j = 0; j < 5; j++){
				O = rand() % 15 + 61;
				bingo[i][j] = O;
				for(k = 0; k < j; k++){
					if(bingo[i][j] == bingo[i][k]){
						bingo[i][j] = 0;
						j--;
						break;
					}
				}
			}
		}
	}

	bingo[2][2] = 0;

}
void Lot(int lotretu[75]){
	int l;
	int lotcount;
	int i,lot;
	for(l = 0; l < 75; l++){
			lotcount = 0;
			lot = rand() % 75 +1;
		//		printf("抽選結果:%d\n",lot);

		for(i = 0; i < 75; i++){
			if(lotretu[i] == lot){
				lotcount++;
				//	printf("やりなおし\n");
				break;
			}
		}

		if(lotcount > 0){
			l--;
			continue;
		}

		else if(lotcount == 0){
			lotretu[l] = lot;
		}

	}
}
void Check(int bingo[5][5], int lotretu[75]){
	int i,j;
	for(i = 0; i < A; i++){
		if (lotretu[i] >= 1 && lotretu[i] <= 15){
			for(j = 0; j < 5; j++){
				if(lotretu[i] == bingo[0][j]){
					bingo[0][j] = 0;
					break;
				}
			}
		}

		else if (lotretu[i] >= 16 && lotretu[i] <= 30){
			for(j = 0; j < 5; j++){
				if(lotretu[i]== bingo[1][j]){
					bingo[1][j] = 0;
					break;
				}
			}
		}

		if (lotretu[i] >= 31 && lotretu[i] <= 45){
			for(j = 0; j < 5; j++){
				if(lotretu[i] == bingo[2][j]){
					bingo[2][j] = 0;
					break;
				}
			}
		}

		else if (lotretu[i] >= 46 && lotretu[i] <= 60){
			for(j = 0; j < 5; j++){
				if(lotretu[i] == bingo[3][j]){
					bingo[3][j] = 0;
					break;
				}
			}
		}

		else if (lotretu[i] >= 61 && lotretu[i] <= 75){
			for(j = 0; j < 5; j++){
				if(lotretu[i] == bingo[4][j]){
					bingo[4][j] = 0;
					break;
				}
			}
		}
	}

}
int Bingo(int bingo[5][5]){
	int count = 0;
	int ver,side,diar,dial=0;
	int i,j;
	for(i = 0; i < 5; i ++){
			for(j = 0; j < 5; j++){
				if(bingo[i][j] == 0){
					ver++;
				}
			}
			if(ver == 5){
				ver = 0;
				count++;
				break;
			}
			else if(ver != 5){
				ver = 0;
			}
		}

		for(j = 0; j < 5; j++){
			for(i = 0; i < 5; i++){
				if(bingo[i][j] == 0){
					side++;
				}
			}
			if (side == 5){
				side = 0;
				count++;
				break;
			}
			else if(side != 5){
				side = 0;
			}
		}

		for(i = 0; i < 5; i++){
			if(bingo[i][i] == 0){
				diar++;
			}
		}
		if (diar == 5){
				count++;
				diar = 0;
			}
			else if(diar != 5){
				diar = 0;
			}

		for(i = 4; i >= 0; i--){
			if(bingo[i][4-i] == 0){
				dial++;
			}
		}
		if(dial == 5){
				dial = 0;
				count++;
			}
			else if(dial != 0){
				dial = 0;
			}


		return count;
}


