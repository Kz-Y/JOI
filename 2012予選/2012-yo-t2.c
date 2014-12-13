#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	int a;
	int b;
	int c;
	int d;
	int score[4950+5];
	int ranking=1;
	int max=0;
	int game=N*(N-1)/2;
	int i,j;

	// データ取得
	scanf("%d", &N);
	game=N*(N-1)/2;


	for(i=0; i<N; i++){
		score[i]=0;
	}
	for(i=0; i<game; i++){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(c==d){	// 引き分け
			score[a]+=1;
			score[b]+=1;
		}else if(c>d){	// aが勝つ
			score[a]+=3;
		}else{	// bが勝つ
			score[b]+=3;
		}
	}
	// 順位付け
	for(i=1; i<=N; i++){
		// printf("score:%d ", score[i]);
		for(j=1; j<=N; j++){
			if(score[i]<score[j]){
				ranking++;
			}
		}
		printf("%d\n", ranking);
		ranking=1;
	}


	return 0;
}
