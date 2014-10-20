#include <stdio.h>
#include <stdlib.h>

int main(){
	int W;	//南北W本
	int H;	//東西H本
	int N;	//観光スポットの数
	int x[10000+5];
	int y[10000+5];
	int x_d;	//現在地と次の場所の差(diffirent)
	int y_d;	//現在地と次の場所の差(diffirent)
	int max;	//x[i]とy[i]どっちが大きいか
	int count=0;	//道の合計の本数
	int i;

	//データ取得
	//配列1から
	scanf("%d %d %d",&W,&H,&N);
	for(i=1; i<=N; i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	//データ確認
	printf("W=%d,H=%d,N=%d\n",W,H,N);
	for(i=1; i<=N; i++){
		printf("%d=(%d,%d)\n",i,x[i],y[i]);
	}
	//処理
	for(i=1; i<N; i++){
		x_d=x[i+1]-x[i];	//現在地と次の場所の差
		y_d=y[i+1]-y[i];

		if(x_d<=0 && y_d<=0 || x_d>0 && y_d>0){	//斜めを使う
			x_d=abs(x_d);	//絶対値
			y_d=abs(y_d);
			if(x_d<=y_d){
				count+=y_d;
			}else{
				count+=x_d;
			}
			//printf("a");
		}else{	//斜めを使えない
			x_d=abs(x_d);	//絶対値
			y_d=abs(y_d);
			count+=x_d+y_d;
			//printf("b");
		}
	}
	//結果
	printf("\n%d",count);

	return 0;
}
