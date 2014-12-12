#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char mozi[10+5];
	int mozi_len;
	int N;
	char ring_mozi[10+5];
	int count=0;
	int answer[100+5];
	int i,j,k;
	int sum=0;
	
	// データ取得
	scanf("%s", mozi);
	scanf("%d", &N);
	// データ確認
	printf("%s\n", mozi);
	printf("%d\n", N);
	
	
	
	
	for(i=0; i<N; i++){
		scanf("%s", ring_mozi);
		printf("%s\n", ring_mozi);

		answer[i]=0;
		for(j=0; j<10; j++){
			if(mozi[0]==ring_mozi[j]){	// 最初の文字があったら
				for(k=0; k<strlen(mozi); k++){
					if(mozi[k]==ring_mozi[(j+k)%10]){
						if(k==strlen(mozi)-1){	// 最後まで行けたら
							answer[i]=1;
						}
					}else{
						break;
					}
				}
			}
		}
	}
	
	for(i=0; i<N; i++){
		sum+=answer[i];
	}
	printf("\n%d", sum);
	return 0;
}
