#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
#define A 10000

int main(void){
	int i;
	int j;
	int k;
	int r;
	int ans;
	int count = 0;
	int man[5] = {190,170,150,130,110};
	int woman[5] = {180,160,140,120,100};
	int allh[N] = {0};
	int alls[N] = {0};
	srand((unsigned int)time(NULL));
	for(k = 0; k < A; k++){
		for(i = 0; i < 5;i++){
			r = rand() % 10;

			//	printf("r = %d\n",r);
			if(allh[r] == 0 && alls[r] == 0){
				allh[r] = man[i];
				alls[r] = 1;
			}
			else i--;
		}

		for(i = 0; i < 5; i++){
			r = rand() % 10;
			if(allh[r] == 0 && alls[r] == 0){
				allh[r] = woman[i];
				alls[r] = 2;
			}
			else i--;
		}


		if(alls[0] == 2 || allh[9] == man[0]){
			for(j = 0; j < N; j++){
				allh[j] = 0;
				alls[j] = 0;
			}
			continue;
		}

		for(i = 0; i < N; i++){
			if(alls[i] == 1){
				continue;
			}

			else if(alls[i] == 2){
				for(j = 0; j < i; j++){
					if(alls[j] == 1 && (allh[j] > allh[i])){
						count++;
						break;
					}

					else continue;
				}
			}
		}
		if(count == 5){
					ans++;
					count = 0;
					for(j = 0;j < N;j++){
						allh[j] = 0;
						alls[j] = 0;
					}
		}
		else if(count != 5){
				count = 0;
				for(j = 0;j < N; j++){
					allh[j] = 0;
					alls[j] = 0;
				}
		}
	
	}
	printf("ans = %d\n", ans);
}
