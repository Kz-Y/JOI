#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int pasta;
	int min_p=2000;
	int juice;
	int min_j=2000;
	int i;

	for(i=0; i<3; i++){
		scanf("%d", &pasta);
		if(min_p>pasta){
			min_p=pasta;
		}
	}
	for(i=0; i<2; i++){
		scanf("%d", &juice);
		if(min_j>juice){
			min_j=juice;
		}
	}

	printf("%d\n", min_p+min_j-50);



	return 0;
}
