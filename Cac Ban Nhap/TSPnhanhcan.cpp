#include <stdio.h>
#define size 30

typedef struct 
{
    /* data */
    float doDai;
    int dau, cuoi;
    int da_dung;
}canh;

void ReadFromFile(canh a[][size], int *n){
    FILE *f = fopen("TSPnhanhcan.txt", "r");

    fscanf(f,"%d", n);

    for(int i =0; i<*n; i++){
        for(int j =0; j<*n; j++){
            fscanf(f,"%f", &a[i][j].doDai);
            a[i][j].dau = i;
            a[i][j].cuoi = j;
            a[i][j].da_dung = 0;
        }
    }
    fclose(f);
}
void in_ma_tran(canh a[][size], int n){
	int i,j;
	printf("\nMa tran TRONG SO cua do thi\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			printf(" %c%c =%5.2f  ",a[i][j].dau+97, a[i][j].cuoi+97, a[i][j].doDai);
		printf("\n");
	}
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

float canh_NN(canh a[][size], int n){
    float Cmin=99999;
    for(int i =0; i<n; i++){
        for(int j =0; j<n;j++){
            if(i!=j && !a[i][j].da_dung&& a[i][j].doDai<Cmin)
                Cmin = a[i][j].doDai;
        }
    }
    return Cmin;
}

float canDuoi(float TGT, canh a[][size], int n, int i){
    return TGT+(n-i)*canh_NN(a, n);
}
void capNhat_PA_TNTT(canh x[], canh PA[],canh a[][size], int n, float TGT, float *GNNTT ){
    x[n-1]=a[x[n-2].cuoi][x[0].dau];
    TGT += x[n-1].doDai;
    if(*GNNTT>TGT){
        *GNNTT=TGT;
        for(int i =0; i<n; i++){
            PA[i]=x[i];
        }
    }
}
void reset(canh a[][size], int n){
    for(int i =0;i<n;i++){
        for(int j =0; j<n;j++){
            a[i][j].da_dung = 0;
        }
    }
}
int co_chu_trinh(canh x[], int k, int ke_tiep){
    int i =0, co_CT = 0;
    while(i<k && !co_CT){
        if(ke_tiep == x[i].dau)
            co_CT = 1;
        else
            i++;
    }
    return co_CT;
}


void Nhanh_Can(canh a[][size], int n, int i, int dau, float *TGT, float *CD, float *GNNTT, canh x[], canh PA[]){
	 int j; 	// j la dinh ke tiep 
	 for(j=0; j<n; j++) 	
		
		if (dau!=j && !a[dau][j].da_dung && !co_chu_trinh(x,i,j)){
		// Ung voi mot gia tri cua j la mot nut tren cay 
	 	// Tinh 2 dai luong cua mot nut trong
	 		
		 *TGT = *TGT + a[dau][j].doDai;
		 *CD = canDuoi(*TGT, a, n, i+1);
		  if(*CD < *GNNTT){ 	// Neu CD >= GNNTT thi cat tia 
		  // Neu khong co dieu kien nay thi chuong trinh la VET CAN
		  	x[i] = a[dau][j];
		  	a[dau][j].da_dung=1;
		  	a[j][dau].da_dung=1;
		  	
		   	if(i==n-2) { // Da xet het tat ca cac dinh nhung duong di moi co n-1 canh
			   	capNhat_PA_TNTT(x, PA, a, n, *TGT, GNNTT);
	    	}   	
		 	else
		 		Nhanh_Can(a, n, i+1, j, TGT, CD, GNNTT, x, PA); //Xet nut con cua nut i
	 	}
	 // Quay lui xet nut khac (ung voi gia tri khac cua j)
	 *TGT = *TGT - a[dau][j].doDai;	// Tra lai Tong gia tri cua nut cha
	 a[dau][j].da_dung=0;	// Tra lai Canh vua xet la chua su dung	 
	 a[j][dau].da_dung=0;
    }	
}

int main(){
    canh a[size][size];
    int n;
    ReadFromFile(a, &n);

    canh x[size], PA[size];
    float TGT =0.0, CD = 0.0, GNNTT = 99999999999;
    Nhanh_Can(a, n, 0, 'a'-97 ,&TGT, &CD, &GNNTT, x, PA );
    in_PA(PA, n);
    return 0;
}