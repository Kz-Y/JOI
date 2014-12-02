#include <stdio.h>

int main(){
	int N;	// プレイヤーの人数
	int number[200+5][3+5];
	int score[200+50][3+5];	// 得点
	int total=0;	// 得点の合計
	int i,j,k;

	// データ取得
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d %d %d", &number[i][0], &number[i][1], &number[i][2]);
	}
	// データ確認
	printf("%d", N);
	for(i=0; i<N; i++){
		printf("%d:", i);
		for(j=0; j<3; j++){
			printf("%d ", number[i][j]);
		}
		printf("\n");
	}
	// 処理
	for(i=0; i<3; i++){	// ゲームi回戦
		for(j=0; j<N; j++){
			for(k=0; k<N; k++){
				if(number[j][i]==number[k][i]){	// 重なる
					if(j!=k){	// 自分と重複しない
						score[j][i]=0;
						break;
					}
				}else{	//重ならない
					score[j][i]=number[j][i];
				}
			}
		}
	}

	// 得点の合計
	for(i=0; i<N; i++){
		for(j=0; j<3; j++){
			total+=score[i][j];
		}
		printf("%d\n", total);
		total=0;
	}
	return 0;
}