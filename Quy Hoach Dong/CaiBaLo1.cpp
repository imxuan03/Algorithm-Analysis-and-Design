#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    /* data */
    char tenDoVat[50];
    int TL, GT, PA;
}DoVat;

typedef int bang[50][100];

DoVat *ReadFromFile(int *W, int *n){
     FILE *f;
     f = fopen("balo1.txt", "r");
     fscanf(f, "%d",W); // Xac dinh trong luong Ba lo
	 DoVat *dsdv;
	 dsdv=(DoVat*)malloc(sizeof(DoVat));
	 int i=0;
 	 while (!feof(f)){
	   fscanf(f, "%d%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].tenDoVat);
	   dsdv[i].PA=0;
	   i++;
	   dsdv=(DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));  
	 }
	 *n=i;
     fclose(f);
     return dsdv;
}

void InDSDV(DoVat *dsdv ,int n, int W){
	int i, TongTL=0, TongGT=0;
	printf("\nPhuong an Cai Ba lo 1 dung thuat toan QUY HOACH DONG nhu sau:\n");
		printf("|---|------------------|----------|---------|-----------|\n");
		printf("|STT|     Ten Do Vat   | T Luong  | Gia Tri | Phuong an |\n");
		printf("|---|------------------|----------|---------|-----------|\n");
	for(i=0;i<n;i++){
		printf("|%2d |%-18s|%5d     |%5d    |%6d     |\n",
		i+1,dsdv[i].tenDoVat,dsdv[i].TL,dsdv[i].GT,dsdv[i].PA);
		TongTL=TongTL+dsdv[i].PA * dsdv[i].TL;
		TongGT=TongGT+dsdv[i].PA * dsdv[i].GT;
	}	
	printf("|---|------------------|----------|---------|-----------|\n");	
	printf("Trong luong cua ba lo = %-9d\n",W);
	printf("Tong trong luong = %-9d\n",TongTL);
	printf("Tong gia tri = %-9d\n",TongGT);
}

void taoBang(DoVat *dsdv, int n, int W, bang F, bang X){
    
	for(int V =0; V<= W; V++){
		X[0][V] = V/dsdv[0].TL;
		F[0][V] = X[0][V]*dsdv[0].GT;
	}

	for(int k = 1;k<n;k++){
		for(int V = 0; V<= W; V++){
			int FMAX = F[k-1][V];
			int XMAX  = 0;

			int yk = V/dsdv[k].TL;
			for(int xk = 1; xk<= yk ; xk++){
				if(F[k-1][V-xk*dsdv[k].TL], xk*dsdv[k].GT <FMAX){
					FMAX=F[k-1][V-xk*dsdv[k].TL], xk*dsdv[k].GT;
					XMAX = xk;

				}
			}
			F[k][V]= FMAX;
			X[k][V] = XMAX;
		}
	}


}
void InBang(int n, int W, bang F, bang X){
	int V, k;
	for(k=0; k<n; k++){
		for(V=0; V<=W; V++)
		 	printf("|%4d%2d",F[k][V], X[k][V]);
		printf("\n");
	}
}

void TraBang(DoVat *dsdv, int n, int W, bang X) {
	int k, V;
	V = W;
	for(k= n-1; k>=0; k--) {
	 	dsdv[k].PA = X[k][V];
	 	V = V - X[k][V] * dsdv[k].TL;
	}
}


int main(){

	int n, W;
	DoVat *dsdv;
	dsdv = ReadFromFile(&W, &n);

	bang F,X;
	taoBang(dsdv,n,W,F,X);
	InBang(n,W,F,X);
	printf("\n");
	TraBang(dsdv,n,W,X);
	InDSDV(dsdv,n,W);

    return 0;
}