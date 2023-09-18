#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    /* data */
    float doDai;
    int dau, cuoi;
}canh;

void ReadFromFile(canh a[],int *n){
    FILE *f = fopen("TSPthaman.txt", "r");
    fscanf(f,"%d", n);
    int k = 0;
    float temp;
    for(int i = 0;i<*n; i++){
        for(int j = i ; j<*n; j++){
            if(i==j){
                for(int t = 0; t<= j; t++){
                    fscanf(f,"%f", &temp);
                }
            }else{
                fscanf(f, "%f", &a[k].doDai);
                a[k].dau = i;
                a[k].cuoi = j;
                k++;
            }
        }
    }
    fclose(f);
}

void swap(canh *x, canh *y){
    canh temp = *x;
    *x = *y;
    * y = temp;
}

void BubbleSort(canh a[], int n){
    for(int i = 0 ; i<=n-2;i++){
        for(int j = n-1; j>= i+1; j--){
            if(a[j].doDai<a[j-1].doDai){
                swap(&a[j], &a[j-1]);
            }
        }
    }
}

int dinhCap3(canh PA[], int k, canh moi){
    int dem = 1; 
    int i =0;
    while(i<k && dem <3){
        if(moi.dau == PA[i].dau || moi.dau ==PA[i].cuoi){
            dem++;
        }
        i++;
    }
    if(dem==3)
        return 1;

    i = 0;
    dem = 1;
    
    while(i<k && dem <3){
        if(moi.cuoi == PA[i].dau || moi.cuoi ==PA[i].cuoi){
            dem++;
        }
        i++;
    }

    return dem == 3;
}

void initForest(int parent[], int n){
    for(int i = 0; i<n; i++){
        parent[i]= i;
    }
}

int chuTrinh(int r1, int r2){
    return r1==r2;
}

void upDate(int parent[], int r1, int r2){
    parent[r2] = r1;
}
int findRoot(int parent[],int u){
    while(u!=parent[u]){
        u = parent[u];
    }
    return u;
}

void Greedy(canh a[], int n, canh PA[]){
    int parent[n];
    initForest(parent, n);
    int k = 0;
    for(int i = 0; i<n*(n-1)/2 && k<n-1; i++ ){
        int r_dau = findRoot(parent, a[i].dau);
        int r_cuoi = findRoot(parent, a[i].cuoi);
        if(!dinhCap3(PA, k, a[i])&& !chuTrinh(r_dau, r_cuoi)){
            PA[k] = a[i];
            k++;
            upDate(parent, r_dau, r_cuoi);
        }
    }
    
    for(int i = 0; i<n*(n-1)/2; i++ ){
        int r_dau = findRoot(parent, a[i].dau);
        int r_cuoi = findRoot(parent, a[i].cuoi);
        if(!dinhCap3(PA, n-1, a[i])&& chuTrinh(r_dau, r_cuoi)){
            PA[n-1] = a[i];
            break;
        }
    }
}

void inDS(canh PA[] , int n){
    float tong = 0;
    for(int i =0; i<n; i++){
        tong+= PA[i].doDai;
    }
    printf("%f", tong);
}

int main(){
   
    int n;
    canh a[30];

    ReadFromFile(a, &n);
    BubbleSort(a, n*(n-1)/2);
    canh PA[n];
    Greedy(a, n, PA);
    inDS(PA, n);

    return 0;
}