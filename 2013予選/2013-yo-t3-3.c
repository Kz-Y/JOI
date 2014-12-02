#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;	// 古い看板の枚数
	char board[25+5];	// 店の名前
	char old_boards[100+5];	// 古い看板の名前
	int count=0;
	int key=0;
	int i,j,k,l,m;

	// データ取得
	scanf("%d", &N);
	scanf("%s", board);	

	// 処理
	for(i=0; i<N; i++){
		scanf("%s", old_boards);
		for(j=0; j<strlen(old_boards); j++){
			if(board[0]==old_boards[j]){	// 1文字目があるところ
				for(k=1; k<=strlen(old_boards)-j; k++){	// 間隔	
					for(l=1; l<strlen(board); l++){
						if((j+l*k)<strlen(old_boards)){
							if(board[l]==old_boards[j+l*k]){
								if(l==strlen(board)-1){	// 最後まで行ったら
									if(key==0){
										count++;
										key++;
										//printf("a");
										break;
									}
									
								}	
							}else{
								break;
							}
						}
					}
					if(board[l]==old_boards[j+l*k]){
						break;
					}
				}
			}
		}
		key=0;
		//printf("\n");
	}

	printf("%d", count);
	return 0;
}