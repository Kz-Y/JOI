#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	int M;
	int a[10000+5];
	int b[10000+5];
	int count[500+5];
	int total=0;
	int i,j;

	// データ取得
	scanf("%d", &N);
	scanf("%d", &M);
	for(i=0; i<M; i++){
		scanf("%d %d", &a[i], &b[i]);
	}
	

	// 処理
	for(i=1; i<=N; i++){
		count[i]=0;
	}
	for(i=0; i<M; i++){
		if(a[i]==1){
			count[b[i]]=1;
			for(j=0; j<M; j++){	// 友達の友達
				if(b[i]==a[j])count[b[j]]=1;
				if(b[i]==b[j])count[a[j]]=1;
			}
		}
		if(b[i]==1){
			count[a[i]]=1;
			for(j=0; j<M; j++){	// 友達の友達
				if(a[i]==a[j])count[b[j]]=1;
				if(a[i]==b[j])count[a[j]]=1;
			}
		}
	}
	for(i=2; i<=N; i++){	// 自分は除く
		total+=count[i];
	}
	printf("%d\n", total);

	return 0;
}
