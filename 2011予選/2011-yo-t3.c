#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	int K;
	int x[1000+5];	//a
	int y[1000+5];	//b
	int min1;
	int min2;
	int i;

	// データ取得
	scanf("%d", &N);
	scanf("%d", &K);

	for(i=0; i<K; i++){
		scanf("%d %d", &x[i], &y[i]);
	}

	// 処理
	for(i=0; i<K; i++){
		if(x[i]<N-x[i]+1){
			min1=x[i];
		}else{
			min1=N-x[i]+1;
		}

		if(y[i]<N-y[i]+1){
			min2=y[i];
		}else{
			min2=N-y[i]+1;
		}

		if(min1>min2){
			min1=min2;
		}
		if(min1<3){
			printf("%d\n", min1);
		}else{
			switch(min1%3){
				case 0:
						printf("3\n");
						break;
				case 1:
						printf("1\n");
						break;
				case 2:
						printf("2\n");
						break;

			}
		}
	}



	return 0;
}
