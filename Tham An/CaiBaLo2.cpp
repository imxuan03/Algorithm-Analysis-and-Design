#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct 
{
    /* data */
    char tenTien[100];
    float TL, GT,DG;
    int PA, SL;
}DoVat;

DoVat *ReadFileFrom(float *W, int *n){
    FILE *f = fopen("balo2.txt", "r");

    DoVat *dsdv;
    dsdv = (DoVat*)malloc(sizeof(DoVat));

    int i=0;
    fscanf(f,"%f", W);
    while(!feof(f)){
        
        fscanf(f, "%f%f%d%[^\n]", &dsdv[i].TL, &dsdv[i].GT,&dsdv[i].SL, &dsdv[i].tenTien);
        dsdv[i].PA = 0;
        dsdv[i].DG =  dsdv[i].GT/ dsdv[i].TL;
        i++;
        dsdv = (DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));
    }
    *n = i;
    fclose(f);
    return dsdv;
}

void swap(DoVat *x, DoVat *y){
    DoVat temp = *x;
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
int min(int a, int b){
    return a>b?b:a;
}
void Greedy(DoVat *dsdv, int n, int W){
    int i = 0;
    while(i<n&& W>0){
        dsdv[i].PA = min( W/dsdv[i].TL, dsdv[i].SL  );
        W-=dsdv[i].PA*dsdv[i].TL;
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
    dsdv = ReadFileFrom(&W, &n);
    BubbleSort(dsdv, n);
    Greedy(dsdv, n, W);
    inDS(dsdv, n, W);

    return 0;
}