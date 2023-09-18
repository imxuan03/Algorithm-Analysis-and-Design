#include <stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct 
{
    keytype key;
    othertype otherfields;
}recordtype;

void readFromFile(recordtype a[], int *n){
    FILE *f= fopen("data.txt", "r");

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

void bubbleSort(recordtype a[], int n){
    for(int i =0; i<= n-2; i++){
        for(int j = n-1; j>=i+1; j--){
            if(a[j].key<a[j-1].key){
                swap(&a[j], &a[j-1]);
            }
        }
    }
}


int main(){
    int n;
    recordtype a[30];
    readFromFile(a, &n);
    bubbleSort(a, n);
    inDS(a, n);

    return 0;
}