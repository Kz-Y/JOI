#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int total;
	int book;
	
	int i;

	// データ取得
	scanf("%d", &total);
	for(i=0; i<9; i++){
		scanf("%d", &book);
		total-=book;
	}
	
	printf("%d\n", total);
	return 0;
}
