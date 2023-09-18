#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    /* data */
    char tenDoVat[25];
    float TL,GT,DG;
    int PA;
}DoVat;

DoVat * ReadFromFile(float *W, int *n){
    FILE *f = fopen("balo1.txt", "r");

    DoVat *dsdv;
    dsdv = (DoVat*)malloc(sizeof(DoVat));

    int i = 0;
    fscanf(f,"%f",W);
    while(!feof(f)){
        
        fscanf(f,"%f%f%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].tenDoVat);
        dsdv[i].PA = 0;
        dsdv[i].DG = dsdv[i].GT/dsdv[i].TL;
        i++;
        dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));
    }
    *n = i;
    fclose(f);
    return dsdv;
}
void swap(DoVat *x, DoVat *y){
    DoVat temp = *x ;
    *x = *y;
    *y = temp;
}

void BubbleSort(DoVat *dsdv, int n){
    for(int i =0;i<= n-2;i++){
        for(int j =n-1;j>=i+1;j--){
            if(dsdv[j].DG>dsdv[j-1].DG)
                swap(&dsdv[j],&dsdv[j-1]);
        }
    }
}

void greedy(DoVat *dsdv, int n, int W){
    int i =0;
    while(i<n && W>0){
        dsdv[i].PA = W/dsdv[i].TL;
        W-=  dsdv[i].PA*dsdv[i].TL;
        i++;
    }
}
void inDS(DoVat *dsdv, int n, int W){
    printf("Phuong an la :");
    for(int i =0;i<n;i++){
        printf("%d ",dsdv[i].PA );
    }
    printf("\nTong gia tri la:");
    float  tongGT = 0;

    for(int i =0;i<n;i++){
        tongGT += dsdv[i].PA*dsdv[i].GT;
    }
    printf("%f", tongGT);
    printf("\nTong trong luong la:");
    float  tongTL = 0;

    for(int i =0;i<n;i++){
        tongTL += dsdv[i].PA*dsdv[i].TL;
    }
    printf("%f", tongTL);
}
int main(){
    int n;
    float W;
    DoVat *dsdv;
    dsdv = ReadFromFile(&W, &n);
    BubbleSort(dsdv, n);
    greedy(dsdv, n, W);
    inDS(dsdv, n, W);
    return 0;
}


