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
    *x = *y;
    *y = temp;
}
void ReadFromFile(recordtype a[],int *n){
    FILE *f= fopen ("data.txt","r");

    int i = 0;
    while(!feof(f)){
        fscanf(f,"%d%f", &a[i].key, &a[i].otherfields);
        i++;
    }
    *n = i;
    fclose(f);

}
void inDS(recordtype a[], int n){
    for(int i =0; i<n;i++){
        printf("%d %f\n", a[i].key, a[i].otherfields);
    }
}
// void selection(recordtype a[], int n){
//     for(int i =0;i<=n-2;i++){
//         int lowIndex = i;
//         int lowKey = a[i].key;
//         for(int j = i+1; j<=n-1; j++){
//             if(a[j].key<lowKey){
//                 lowKey = a[j].key;
//                 lowIndex = j;
//             }
//         }
//         swap(&a[i], &a[lowIndex]);
//     }
// }
// void insert(recordtype a[], int n){
//     for(int i =1; i<=n-1; i++){
//         int j =i;
//         while(j>0 && a[j].key<a[j-1].key){
//             swap(&a[j], &a[j-1]);
//             j--;
//         }
//     }
// }
// void bubble(recordtype a[], int n){
//     for(int i =0; i<=n-2; i++){
//         for(int j =n-1; j>=i+1; j--){
//             if(a[j-1].key>a[j].key){
//                 swap(&a[j], &a[j-1]);
//             }
//         }
//     }
// }
// int FindPivot(recordtype a[], int i, int j){
//     int k = i+1;
//     while(k<=j && a[i].key == a[k].key)k++;

//     if(k>j )
//         return -1;

//     if(a[k].key>a[i].key)
//         return k;

//     return i;
// }
// int Partition(recordtype a[], int L, int R, int Pivot){

//     while(L<=R){
//         while(a[L].key<Pivot)L++;
//         while(a[R].key>=Pivot)R--;
//         if(L<R){
//             swap(&a[L], &a[R]);
//         }
//     }
//     return L;
// }
// void quick(recordtype a[], int i, int j){
//     int indexPivot = FindPivot(a, i, j);

//     if(indexPivot!=-1){

//         int k = Partition(a, i, j, a[indexPivot].key);
//         quick(a, i, k-1);
//         quick(a, k, j);
//     }
// }
void PushDow(recordtype a[], int first, int last){

    int r = first;
    while(r<=(last-1)/2){
        if(last == 2*r+1){
            if(a[r].key>a[2*r+1].key){
                swap(&a[r], &a[2*r+1]);
            }
            r =last;
        }else if(a[r].key>a[2*r+1].key &&a[2*r+1].key<=a[2*r+2].key ){
            swap(&a[r], &a[2*r+1]);
            r = 2*r+1;
        }else if(a[r].key>a[2*r+2].key &&a[2*r+1].key>a[2*r+2].key ){
            swap(&a[r], &a[2*r+2]);
            r = 2*r+2;
        }else   
            r=last;
    }
}
void heap(recordtype a[], int n){
    for(int i =(n-2)/2;i>=0;i--){
        PushDow(a, i, n-1);
    }

    for(int i = n-1; i>=2; i--){
        swap(&a[0], &a[i]);
        PushDow(a, 0, i-1);
    }
    swap(&a[0], &a[1]);
}
int main(){
    
    recordtype a[30];
    int n;
    ReadFromFile(a, &n);
    heap(a, n);
    
    
    inDS(a, n);

    return 0;
}