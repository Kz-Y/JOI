#include <stdio.h>

int main(){
	int L;	// 冬休みの日数
	int A;	// 国語のドリルのページ数
	int B;	// 算数のドリルのページ数
	int C;	// joiが1日に進めることができる国語ドリルの最大ページ数
	int D;	// joiが1日に進めることができる算数ドリルの最大ページ数
	int sansu;
	int kokugo;
	int i;

	// データ取得
	scanf("%d", &L);
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	scanf("%d", &D);

	// データ確認
	printf("L:%d\n", L);
	printf("A:%d\n", A);
	printf("B:%d\n", B);
	printf("C:%d\n", C);
	printf("D:%d\n", D);

	// 処理
	for(i=0; i<L; i++){	// 算数のドリル
		A-=C;
		if(A<=0){
			sansu=i;
			break;
		}
	}

	for(i=0; i<L; i++){	// 国語のドリル
		B-=D;
		if(B<=0){
			kokugo=i;
			break;
		}
	}

	printf("sansu:%d\n", sansu);
	printf("kokugo:%d\n", kokugo);

	if(kokugo<sansu){
		printf("%d", L-sansu-1);
	}else{
		printf("%d", L-kokugo-1);
	}

	return 0;
}