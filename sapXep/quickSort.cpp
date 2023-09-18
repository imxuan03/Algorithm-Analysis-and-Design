#include <stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct 
{
    /* data */
    keytype key;
    othertype otherfields;
}recordtype;

void swap(recordtype *x, recordtype *y){
    recordtype temp = *x;
    *x =*y;
    *y = temp;
}
void ReadFromFile(recordtype a[], int *n){
    FILE *f;
    f = fopen("data.txt","r");
    if(f==NULL)
        return ;

    int i =0;
    while(!feof(f)){
        fscanf(f,"%d%f",&a[i].key, &a[i].otherfields);
        i++;
    }
    *n = i;
    fclose(f);
}

void inDS(recordtype a[], int n){
    for(int i =0;i<=n-1;i++){
        printf("%d %f\n", a[i].key, a[i].otherfields);
    }

}

int findPivot(recordtype a[], int i, int j){

    int k = i+1;

    while(k<=j && a[k].key == a[i].key) k++;

    if(k>j)
        return -1;

    if(a[k].key>a[i].key)
        return k;
    return i;
}
int Partition(recordtype a[], int L, int R, int Pivot){
    while(L<=R){
        while(a[L].key<Pivot) L++;
        while(a[R].key>=Pivot) R--;
        if(L<R)
            swap(&a[L], &a[R]);
    }
    return L;
}
void QuickSort(recordtype a[], int i , int j){
    int indexPivot = findPivot(a, i, j);
    if(indexPivot !=-1){
        int k = Partition(a, i,j , a[indexPivot].key);
        QuickSort(a, i, k-1);
        QuickSort(a, k, j);
    }
}
int main(){
   int n;
   recordtype a[30];
   ReadFromFile(a, &n);
   QuickSort(a, 0, n-1);
   inDS(a, n);
    return 0;
}