#include <stdio.h>
#include <stdlib.h>

int main(){
	int sum=0;	// ‡Œv
	int time;
	int i;
	
	for(i=0; i<4; i++){
		scanf("%d", &time);
		sum+=time;
	}
	printf("%d\n", sum/60);
	printf("%d\n", sum%60);
	return 0;
}
