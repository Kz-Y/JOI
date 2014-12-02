#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;	// 古い看板の枚数
	char board[25+5];	// 店の名前
	char old_boards[100+5];	// 古い看板の名前
	int char_count[25+5][100+5];	// 店の名前と古い看板のどこが重なっているか
	int size;	// 店の名前の長さ
	int old_size;	// 昔の看板の文字の長さ
	int kankaku[100+5];	// 文字との間隔
	int key;
	int count[100+5];
	int answer=0;
	int i,j,k,l,m;

	// データ取得
	scanf("%d", &N);
	scanf("%s", &board);	

	// 処理
	// 店の名前の長さ
	size=strlen(board);
	for(i=0; i<N; i++){
		// 古い看板取得
		scanf("%s", old_boards);
		// 古い看板の文字数
		old_size=strlen(old_boards);
		// char_count[][]の初期化(重なった:1,重ならない:0)
		for(j=0; j<size; j++){
			for(k=0; k<old_size; k++){
				char_count[j][k]=0;
			}
		}
		// 使う関数の初期化
		for(j=0; j<old_size; j++){
			kankaku[j]=0;
		}
		// どこと重なっているか
		for(j=0; j<size; j++){
			for(k=0; k<old_size; k++){
				if(board[j]==old_boards[k]){
					char_count[j][k]=1;
				}
			}
		}
		// 等間隔で文字が並んでいるか
		for(j=0; j<old_size; j++){
			if(char_count[0][j]==1){
				key=0;
				for(k=1; k<size; k++){
					if(k==1){	// 1回目だけ間隔を記録
						for(l=0; l<old_size; l++){
							if(j<l){
								if(char_count[k][l]==1){
									kankaku[key]=l-j;
									key++;
								}
							}
						}
					}else{
						for(l=0; l<key; l++){
							for(m=1; m<size; m++){
								if((j+kankaku[l]*(m))<old_size){
									if(char_count[m][j+kankaku[l]*(m)]==1){
										if(m==size-1){	// 最後まで行ったら
											count[i]=1;
											break;
										}
									}else{
										break;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	// 答え
	for(i=0; i<N; i++){
		answer+=count[i];
	}
	printf("%d\n", answer);

	return 0;
}