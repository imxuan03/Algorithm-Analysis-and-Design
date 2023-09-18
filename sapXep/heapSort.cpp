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
    for(int i =0; i<n; i++){
        printf("%d %f\n", a[i].key, a[i].otherfields);
    }
}

void PushDown(recordtype a[], int first, int last){

    int r = first;
    while(r<=(last-1)/2){
        if(last == 2*r+1){
            //chi co con trai
            if(a[r].key>a[2*r+1].key)
                swap(&a[r],&a[2*r+1]);

            r = last;
        }else if(a[r].key>a[2*r+1].key&& a[2*r+1].key<=a[2*r+2].key){
            swap(&a[2*r+1], &a[r]);
            r = 2*r+1;
        }else if(a[r].key>a[2*r+2].key&& a[2*r+1].key>a[2*r+2].key){
            swap(&a[2*r+2], &a[r]);
            r = 2*r+2;
        }else   
            r = last;
    }

}
void heapSort(recordtype a[], int n){
    for(int i = (n-2)/2;i>=0; i--){
        PushDown(a, i, n-1);
    }
    for(int i = n-1; i>=2; i--){
        swap(&a[0], &a[i]);
        PushDown(a, 0, i-1);
    }
     swap(&a[0], &a[1]);
}


int main(){
    int n;
    recordtype a[100];
    ReadFromFile(a, &n);
    heapSort(a, n);
    inDS(a, n);
    return 0;
}