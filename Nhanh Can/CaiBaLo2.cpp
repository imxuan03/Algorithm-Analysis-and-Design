#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct 
{
    /* data */
    char tenDoVat[50];
    float TL, GT, DG;
    int PA, SL;
}DoVat;

DoVat * ReadFromFile(float *W, int *n){
    FILE *f = fopen("balo2.txt","r");

    fscanf(f,"%f",W);

    DoVat *dsdv;
    dsdv = (DoVat*)malloc(sizeof(DoVat));
    int i =0;
    while(!feof(f)){
        fscanf(f,"%f%f%d%[^\n]",&dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL, &dsdv[i].tenDoVat);
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
		i+1,dsdv[i].tenDoVat,dsdv[i].TL,dsdv[i].GT,dsdv[i].SL,dsdv[i].DG, dsdv[i].PA);
		TongTL=TongTL+dsdv[i].PA * dsdv[i].TL;
		TongGT=TongGT+dsdv[i].PA * dsdv[i].GT;
	}	
	printf("|---|--------------------|---------|---------|---------|---------|-----------|\n");	
	printf("Trong luong cua ba lo = %-9.2f\n",W);
	printf("Tong trong luong = %-9.2f\n",TongTL);
	printf("Tong gia tri = %-9.2f\n",TongGT);
}
void taoNutGoc(float W, float *V, float *CT, float *GLNTT, float *TGT, float DG){
    *TGT = 0.0;
    *V = W;
    *CT = DG*W;
    *GLNTT = 0.0;
}
void capNhap_GLNTT(float TGT, float *GLNTT, int x[], DoVat *dsdv, int n){
    if(*GLNTT<TGT){
        *GLNTT = TGT;
        for(int i =0;i<=n;i++){
            dsdv[i].PA = x[i];
        }
    }
}
int min(int a, int b){
    return a>b?b:a;
}
void nhanhCan(int i, float *TGT, float *GLNTT, float *CT, float *V, int x[], DoVat *dsdv, int n){
    int yk = min(dsdv[i].SL, *V/dsdv[i].TL);
    for(int j = yk; j>=0;j--){

        *TGT+= j*dsdv[i].GT;
        *V = *V - j*dsdv[i].TL;
        *CT = *TGT + *V*dsdv[i+1].DG;

        if(*CT>*GLNTT){
            x[i] = j;
            if(i==n-1 || *V==0)
                capNhap_GLNTT(*TGT, GLNTT, x, dsdv, n);
            else   
                nhanhCan(i+1, TGT, GLNTT,CT, V, x, dsdv, n);
        }

        x[i]=0;
        *TGT-= j*dsdv[i].GT;
        *V = *V + j*dsdv[i].TL;

    }
}

int main(){
	DoVat *dsdv;
    float W;
    int n;
    dsdv = ReadFromFile(&W, &n);

    float TGT;
    float CT, GLNTT, V;

    int x[n];

    BubbleSort(dsdv, n);
    taoNutGoc(W, &V, &CT, &GLNTT, &TGT, dsdv[0].DG);
    nhanhCan(0, &TGT, &GLNTT, &CT, &V, x, dsdv, n);
    InDSDV(dsdv, n, W);

    return 0;
}
