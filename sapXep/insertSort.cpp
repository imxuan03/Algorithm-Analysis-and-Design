#include <stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct 
{
    keytype key;
    othertype otherfields;
}recordtype;

void readFromFile(recordtype a[], int *n){
    FILE *f = fopen("data.txt", "r");

    int i =0;
    while(!feof(f)){
        fscanf(f,"%d%f",&a[i].key, &a[i].otherfields);
        i++;
    }
    *n = i;
    fclose(f);

}
void swap(recordtype *x, recordtype *y){
    recordtype temp = *x;
     *x = *y;
     *y = temp;
}

void inDS(recordtype a[], int n){
    for(int i =0; i< n; i++){
        printf("%d %f\n", a[i].key, a[i].otherfields);
    }
}
void insertSort(recordtype a[], int n){
    for(int i =1; i<=n-1;i++){
        int j =i;
        while(j>0 && a[j].key<a[j-1].key){
            swap(&a[j], &a[j-1]);
            j--;
        }
    }
}
int main(){
    int n;
    recordtype a[30];

    readFromFile(a, &n);
    insertSort(a, n);
    inDS(a, n);

    return 0;
}