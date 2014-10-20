#include <stdio.h>

int main(){
	int N;	//日数
	char sekinin[1000+5];	//責任者
	int count[1000+5][8+5];	//メンバーの組み合わせのカウント
	int total=0;	//組み合わせの合計
	int i,j,k;

	//データ取得
	scanf("%d",&N);
	scanf("%s",sekinin);
	//データ確認
	printf("%d\n",N);
	/*for (i=0; i<N; i++){
		printf("%c",sekinin[i]);
	}*/
	printf("%s\n",sekinin);
	
	//文字を数字に変換
	for(i=0; i<N; i++){
		switch(sekinin[i]){
			case 'J':
				sekinin[i]=4;
				break;
			case 'O':
				sekinin[i]=2;
				break;
			case 'I':
				sekinin[i]=1;
				break;
		}
		//printf("%d",sekinin[i]);
	}
	/*********************
		  joi
		0 000
		1 001	  i
		2 010	 o
		3 011	 oi
		4 100	j
		5 101	j i
		6 110	jo
		7 111	joi
	*********************/

	//count[][]の初期化
	//iは1から	
	for(i=0; i<=N; i++){
		for(j=0; j<8; j++){
			count[i][j]=0;
		}
	}

	count[0][4]=1;	//0日目はJが鍵を持っている

	//来れる組み合わせ
	for(i=1; i<=N; i++){
		printf("%d:",i);
		for(j=0; j<8; j++){
			if(count[i-1][j]>0){	//前日のメンバー
				for(k=0; k<8; k++){
					if((sekinin[i-1] & k)>0){	//今日の責任者(i-1)とk(メンバーの全通り)をAND演算,true:今日できる組み合わせ,else:絶対にならないメンバー
						if((j & k)>0){	//前日のメンバーとk(今日できる組み合わせ)をAND演算
							count[i][k]+=count[i-1][j];
						}
						count[i][k]=count[i][k]%10007;	//10007で割る
					}
				}
			}
			printf("%d ",count[i][j]);
		}
		printf("\n");
	}

	for(i=0; i<8; i++){
		total+=count[N][i];
	}
	total=total%10007;
	printf("\n%d",total);

	return 0;
}