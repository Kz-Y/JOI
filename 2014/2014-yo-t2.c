#include <stdio.h>
int main(){
	int N;	//競技の数
	int M;	//委員の数
	int A[1000+5];	//必要な費用
	int B[1000+5];	//審査基準
	int total[1000+5];	//各競技の投票の合計
	int max=0;	//最大
	int ans;	//最大の競技の番号
	int i,j;

	//データ取得
	//配列は1から
	scanf("%d %d",&N,&M);
	for(i=1; i<=N; i++){
		scanf("%d",&A[i]);
	}
	for(i=1; i<=M; i++){
		scanf("%d",&B[i]);
	}
	//データ確認
	printf("%d %d\n",N,M);
	for(i=1; i<=N; i++){
		printf("A[%d]=%d\n",i,A[i]);
	}
	for(i=1; i<=M; i++){
		printf("B[%d]=%d\n",i,B[i]);
	}

	//処理

	//total[]の初期化
	for(i=1; i<=N; i++){
		total[i]=0;
	}
	for(i=1; i<=M; i++){	//審査員i
		for(j=1; j<N; j++){	//競技j
			if(A[j]<=B[i]){	//費用が基準以下だったら
				total[j]++;
				break;
			}
		}
	}

	//totalの最大を求める
	for(i=1; i<=N; i++){
		if(max<total[i]){
			max=total[i];
			ans=i;
		}
	}
	//結果
	printf("%d",ans);

	return 0;

}