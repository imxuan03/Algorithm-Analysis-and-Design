#include <stdio.h>
#include <malloc.h>
#define size 30

typedef struct 
{
    /* data */
    float doDai;
    int dau, cuoi;
    int da_dung;
}canh;

void readFile(canh a[][size], int *n){
    FILE *f = fopen("TSP.txt", "r");

    fscanf(f,"%d", n);

    for(int i = 0; i<*n; i++){
        for(int j =0; j<*n; j++){
            fscanf(f, "%f", &a[i][j].doDai);
            a[i][j].dau = i;
            a[i][j].cuoi = j;
            a[i][j].da_dung = 0;
        }
    }

    fclose(f);
}
void in_PA(canh PA[], int n){
	int i;
	float sum=0.0;
	printf("\nPHUONG AN TIM DUOC:\n");
	for(i=0; i<n; i++){
		sum+= PA[i].doDai;
		printf(" Canh %c%c = %5.2f\n", PA[i].dau+97, PA[i].cuoi+97, PA[i].doDai);
    }  
    printf("CHU TRINH : ");
	for(i=0; i<n; i++){
		printf("%c",PA[i].dau+97);
		printf("-> ");
    }  
	printf("%c",PA[0].dau+97);    
	printf("\nTong do dai cac canh cua chu trinh = %5.2f\n", sum);
}



int main(){

    return 0;
}