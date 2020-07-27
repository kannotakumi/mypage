#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define N 6
#define K 100000

int main(void){
	int i;
	int j;
	int h;
	int l = 0;
	int count = 0;
	int check = 0;
	int dice[N];
	srand((unsigned int)time(NULL));
	for(l=1;l <= K;l++){	
	    for(j = 0; j < N; j++){    
		int s = rand() % 6 + 1;
		dice[j] = s;
	    }
	    for(h = 1; h < N; h++){   
		if(dice[0] == dice[h]){
		check++;
		}
	    }
	    if (check == 5){
	    	count++;
		check = 0;
	    }
	    else if(check != 5){
		check = 0;
	    }
	}
	printf("試行回数:%d\n 一致回数:%d\n",K,count);
}
