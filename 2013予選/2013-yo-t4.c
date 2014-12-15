#include <stdio.h>
#include <stdlib.h>

int main(){
	int D;	// 服の計画を立てる日数 
	int N;	// 服の種類
	int T[200+5];	// 最高気温
	int A[200+5];	// 服は最高気温がA以上B以下の時に着れる
	int B[200+5];
	int C[200+5];	// 派手さ
	int max_min[2][200+5];	// 着れる服の中の派手さの最大(max_min[0][])と最小(max_min[1][])
	int total[2+5];
	int box;
	int max[2+5];
	int i,j,k;
	// データ取得
	scanf("%d %d", &D, &N);
	for(i=0; i<D; i++){
		scanf("%d", &T[i]);
	}
	for(i=0; i<N; i++){
		scanf("%d %d %d", &A[i], &B[i], &C[i]);
	}
	// データ確認
	/*printf("%d %d\n", D, N);
	for(i=0; i<D; i++){
		printf("%d\n", T[i]);
	}
	for(i=0; i<N; i++){
		printf("%d %d %d\n", A[i], B[i], C[i]);
	}*/

	// 処理
	// maxとminの初期化
	for(i=0; i<D; i++){
		max_min[0][i]=0;
		max_min[1][i]=100;
	}

	for(i=0; i<D; i++){
		for(j=0; j<N; j++){
			if(A[j]<=T[i] && T[i]<=B[j]){	// 着れる服
				if(max_min[0][i]<C[j]){	// 派手さの最大
					max_min[0][i]=C[j];
				}
				if(max_min[1][i]>C[j]){	// 派手さの最小
					max_min[1][i]=C[j];
				}
			}
		}
	}
	
	// 派手さの差の合計

	// totalの初期化
	total[0]=0;
	total[1]=0;
	// pieceごとの派手さの差の最大値を求める
	/*
	 *total[0]:出口がmax 
	 *total[1]:出口がmin
	 */
	for(i=1; i<D; i++){
		//printf("a");	
		for(j=0; j<2; j++){
			max[j]=0;
			for(k=0; k<2; k++){
				box=total[k]+abs(max_min[k][i-1]-max_min[j][i]);
				if(max[j]<box){
					max[j]=box;
				}
			}
			//printf("%d ", max[j]);
		}
		//printf("\n");
		for(j=0; j<2; j++){
			total[j]=max[j];
		}
	}

	if(total[0]<total[1]){
		printf("%d\n", total[1]);
	}else{
		printf("%d\n", total[0]);
	}
	return 0;
}
