#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	int M;
	int order[1000+5];
	int saikoro[1000+5];
	int now=1;
	int count=0;
	int i;

	// データ取得
	scanf("%d %d", &N, &M);
	for(i=1; i<=N; i++){
		scanf("%d", &order[i]);
	}
	for(i=0; i<M; i++){
		scanf("%d", &saikoro[i]);
	}

	// 処理
	for(i=0; i<M; i++){
		now+=saikoro[i];	// 進む
		now+=order[now];	// 指示を受ける
		count++;
		if(now>=N){
			printf("%d\n", count);
			break;
		}
	}

	return 0;
}
