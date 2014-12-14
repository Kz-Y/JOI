#include <stdio.h>
#include <stdlib.h>

int main(){
	int score;
	int rank1=0,rank2,rank3;
	int total1,total2;
	int i;

	for(i=0; i<10; i++){
		scanf("%d", &score);
		if(rank1<score){
			rank3=rank2;
			rank2=rank1;
			rank1=score;
		}else if(rank2<score){
			rank3=rank2;
			rank2=score;
		}else if(rank3<score){
			rank3=score;
		}
	}
	total1=rank1+rank2+rank3;
	rank1=0,rank2=0,rank3=0;
	for(i=0; i<10; i++){
		scanf("%d", &score);
		if(rank1<score){
			rank3=rank2;
			rank2=rank1;
			rank1=score;
		}else if(rank2<score){
			rank3=rank2;
			rank2=score;
		}else if(rank3<score){
			rank3=score;
		}
	}
	total2=rank1+rank2+rank3;
	
	printf("%d %d\n", total1, total2);
	return 0;
}
