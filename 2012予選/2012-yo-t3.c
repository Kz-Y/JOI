#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	int A,B;
	int kizi;	// 生地のカロリー
	int D[100+5];
	int rank[100+5];
	int count=0;
	int calorie;
	int piza_c;	// ピザのトッピングありのカロリー
	int i,j;

	// データ取得
	scanf("%d", &N);
	scanf("%d %d", &A, &B);
	scanf("%d", &kizi);
	for(i=0; i<N; i++){
		scanf("%d", &D[i]);
	}

	// データ確認
	/*printf("%d\n", N);
	printf("%d %d\n", A, B);
	printf("%d\n", kizi);
	for(i=0; i<N; i++){
		printf("%d:%d\n", i, D[i]);
	}*/

	// 処理
	calorie=kizi/A;
	// トッピングのカロリーの順位付け
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(D[i]<D[j]){
				count++;
			}
		}
		rank[i]=count;
		count=0;
	}
	

	piza_c=kizi;
	count=0;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(rank[j]==i){
				piza_c+=D[j];
				count++;
				//printf("%d ", D[j]);
				if(calorie<piza_c/(A+B*(count))){
					//printf("%d ", piza_c);
					calorie=piza_c/(A+B*(count));
				}
			}
		}
		//printf("\n");
	}
	printf("%d\n", calorie);


	return 0;
}
