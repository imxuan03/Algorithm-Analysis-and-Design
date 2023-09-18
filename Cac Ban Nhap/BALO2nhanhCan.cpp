#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct 
{
    /* data */
    char tenDoVat[50];
    float TL, GT, DG;
    int PA;
}DoVat;

DoVat * ReadFromFile(float *W, int *n){
    FILE *f = fopen("BALO2nhanhcan.txt","r");

    fscanf(f,"%f",W);

    DoVat *dsdv;
    dsdv = (DoVat*)malloc(sizeof(DoVat));
    int i =0;
    while(!feof(f)){
        fscanf(f,"%f%f%[^\n]",&dsdv[i].TL, &dsdv[i].GT, &dsdv[i].tenDoVat);
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
	DoVat Temp;
	Temp = *x;
	*x   = *y;
	*y   = Temp;
}

void BubbleSort(DoVat *dsdv, int n){
	int i,j;
	for(i=0; i<=n-2; i++)
	   for (j=n-1; j>=i+1; j--){
	   	 if (dsdv[j].DG>dsdv[j-1].DG) 
			swap(&dsdv[j],&dsdv[j-1]);
	  }   
}

void InDSDV(DoVat *dsdv ,int n, float W){
	int i;
	float TongTL=0.0, TongGT=0.0;
	printf("\nPhuong an Cai Ba lo 2 dung thuat toan NHANH CAN nhu sau:\n");
	printf("|---|--------------------|---------|---------|---------|---------|-----------|\n");
	printf("|STT|     Ten Do Vat     |T. Luong | Gia Tri |So luong | Don gia | Phuong an |\n");
	printf("|---|--------------------|---------|---------|---------|---------|-----------|\n");
	for(i=0;i<n;i++){
		printf("|%2d |%-20s|%9.2f|%9.2f|%5d    |%9.2f|%6d     |\n",
		i+1,dsdv[i].tenDoVat,dsdv[i].TL,dsdv[i].GT,dsdv[i].DG, dsdv[i].PA);
		TongTL=TongTL+dsdv[i].PA * dsdv[i].TL;
		TongGT=TongGT+dsdv[i].PA * dsdv[i].GT;
	}	
	printf("|---|--------------------|---------|---------|---------|---------|-----------|\n");	
	printf("Trong luong cua ba lo = %-9.2f\n",W);
	printf("Tong trong luong = %-9.2f\n",TongTL);
	printf("Tong gia tri = %-9.2f\n",TongGT);
}
void taoNutGoc(float W, float *V,float *TGT, float *CT, float *GLNTT, float DG){
    *TGT = 0.0;
    *V= W;
    *GLNTT = 0.0;
    *CT = *V *DG;   
}
void capnhap_GLNTT(float *GLNTT, float TGT, int x[], DoVat *dsdv,int n ){
    if(*GLNTT<TGT){
        *GLNTT = TGT;
        for(int i =0; i<n; i++){
            dsdv[i].PA = x[i];
        }
    }
}

void nhanhCan(int i,float *V, float *TGT,float *GLNTT, float *CT, DoVat *dsdv, int n, int x[]){
    int yk = *V/dsdv[i].TL;
    for(int j= yk;j>=0; j-- ){
        *TGT += j*dsdv[i].GT;
        *V-= j*dsdv[i].TL;
        *CT = *TGT + *V*dsdv[i+1].DG;

        if(*CT>*GLNTT){
            x[i]=j;
            if(i ==n-1 || *V==0){
                capnhap_GLNTT(GLNTT, *TGT, x, dsdv, n);
            }else{
                nhanhCan(i+1, V, TGT, GLNTT, CT, dsdv, n, x);
            }
        }
        x[i]=0;
        *TGT -= j*dsdv[i].GT;
        *V+= j*dsdv[i].TL;
    }
}

int main(){
    float W; 
    int n;
    DoVat *dsdv;
    dsdv = ReadFromFile(&W, &n);

    float V, TGT, CT, GLNTT;

    int x[n];
    BubbleSort(dsdv, n);
    taoNutGoc(W, &V, &TGT, &CT, &GLNTT, dsdv[0].DG);
    nhanhCan(0, &V, &TGT, &GLNTT,&CT, dsdv, n, x);
    InDSDV(dsdv, n, W);
    return 0;
}