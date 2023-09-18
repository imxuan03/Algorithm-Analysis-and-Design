#include <stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct 
{
    /* data */
    keytype key;
    othertype otherfields;
}recordtype;

void ReadFromFile(recordtype a[],int *n){
    FILE *f = fopen ("data.txt", "r");

    int i =0;
    while(!feof(f)){
        fscanf(f,"%d%f", &a[i].key, &a[i].otherfields);
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
void SelectionSort(recordtype a[], int n){
    for(int i =0; i<=n-2; i++){
        int lowIndex = i;
        int lowKey = a[i].key;
        for(int j = i+1; j<=n-1; j++){
            if(a[j].key<lowKey){
                lowIndex=j;
                lowKey= a[j].key;
            }
        }
        swap(&a[i], &a[lowIndex]);
    }
}
void inDS(recordtype a[], int n){
    for(int i =0;i<n; i++){
        printf("%d %f\n", a[i].key, a[i].otherfields);
    }
}
int main(){
    int n;
    recordtype a[100];
    ReadFromFile(a, &n);
    SelectionSort(a, n);
    inDS(a, n);


    return 0;
}