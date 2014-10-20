#include <stdio.h>

int main(){
	int student[5+2];	//生徒の点数
	int total=0;	//点数の合計
	int i;
	for(i=0; i<5; i++){
		scanf("%d",&student[i]);	//データ取得
		
		printf("%d=",i);	//データ確認
		printf("%d\n",student[i]);
	}
	//処理
	for(i=0; i<5; i++){
		if(student[i]<40){	//40点未満を40点に
			student[i]=40;
		}
		total+=student[i];
	}
	//結果
	printf("%d",total/5);
	
	return 0;
}