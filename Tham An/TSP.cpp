// #include <stdio.h>
// #include <malloc.h>
// #include <string.h>
// #define size 30

// typedef struct 
// {
//     /* data */
//     float doDai;
//     int dau, cuoi;
// }canh;

// void ReadFromFile(canh a[], int *n){

//     FILE *f = fopen("TSP.txt", "r");

//     fscanf(f,"%d", n);
//     float temp;
//     int k = 0;
//     while(!feof(f)){
        
//         for(int i =0;i<*n;i++){
//             for(int j =0;j<*n;j++){

//                 if(i==j){
//                     for(int t = 0; t<=j;t++){
//                         fscanf(f,"%f", &temp);
//                     }
//                 }else{
//                     fscanf(f,"%f", &a[k].doDai);
//                     a[k].dau = i;
//                     a[k].cuoi = j;
//                     k++;
//                 }
                
//             }
//         }

//     }
//     *n = k;
//     fclose(f);

// }

// void swap(canh *x, canh *y){
//     canh temp = *x;
//     *x = *y;
//     *y = temp;
// }
// void BubbleSort(canh a[], int n){
//     for(int i = 0;i<=n-2;i++){
//         for(int j = n-1;j>=i+1; j--){
//             if(a[j].doDai>a[j-1].doDai){
//                 swap(&a[j], &a[j-1]);
//             }
//         }
//     }
// }

// void initForest(int parent[], int n){
//     for(int i =0;i<n;i++){
//         parent[i] = i;
//     }
// }
// int findRoot(int parent[], int u){
//     while(u!= parent[u]){
//         u = parent[u];
//     }
//     return u;
// }
// int chuTrinh(int r_dau, int r_cuoi){
//     return r_dau == r_cuoi;
// }
// void upDateForest(int parent[],int r1, int r2){
//     parent[r2] = r1;
// }

// int dinhCap3(canh PA[], int k, canh moi){

//     int i =0, dem = 1;

//     while(i<k && dem<3){
//         if(moi.dau == PA[i].dau || moi.dau == PA[i].cuoi){
//             dem++;
//         }
//         i++;
//     }
//     if(dem == 3)
//         return 1;

//     i =0;
//     dem =1;
//     while(i<k && dem<3){
//         if(moi.cuoi == PA[i].dau || moi.cuoi == PA[i].cuoi){
//             dem++;
//         }
//         i++;
//     }
//     return dem == 3;

// }

// void greedy(canh ds_canh[], int n, canh PA[]){

//     int parent[n];
//     initForest(parent, n);

//     int r_dau, r_cuoi;
//     int k = 0 ;
//     for(int i =0;i<n*(n-1)/2 && k<n-1 ; i++){
//         r_dau = findRoot(parent, ds_canh[i].dau);
//         r_cuoi = findRoot(parent, ds_canh[i].cuoi);

//         if(!dinhCap3(PA,k,ds_canh[i]) && !chuTrinh(r_dau, r_cuoi)){
//             //them vao
//             PA[k] = ds_canh[i];
//             k++;
//             upDateForest(parent, r_dau, r_cuoi);
//         }
//     }

//     for(int i =0;i<n*(n-1)/2; i++){
//         //neu no khong tao thanh dinh cap 3 va tao thanh chu trinh
//         r_dau = findRoot(parent, ds_canh[i].dau);
//         r_cuoi = findRoot(parent, ds_canh[i].cuoi);
//         if(!dinhCap3(PA,k,ds_canh[i]) && chuTrinh(r_dau, r_cuoi)){
//             PA[n-1] = ds_canh[i];
//             break;
//         }

//     }
// }
// void inPA(canh PA[], int n){
//     float tong = 0;
//     for(int i =0;i<n;i++){
//         tong+= PA[i].doDai;
//         printf("%d : %c - %c = %f", i+1, PA[i].dau + 97 , PA[i].cuoi+97, PA[i].doDai);
//     }
//     printf("\nTong do dai duong di la : %f", tong);
    
// }


// int main(){
//     canh ds_canh[size];
//     int n;
//     ReadFromFile(ds_canh, &n);
//     BubbleSort(ds_canh, n);
//     canh PA[size];
//     greedy(ds_canh, n, PA );
//     inPA(PA, n);

//     return 0;
// }
//#include <stdio.h>
//#define size 30
//
//typedef struct 
//{
//    /* data */
//    float dodai;
//    int dau, cuoi;
//}canh;
//void readFromFile(canh a[], int *n){
//    FILE * f = fopen("TSP.txt", "r");
//
//    fscanf(f, "%d", n);
//    int k = 0;float temp;
//    //phai doc het nguyen bang, nhung bo nhung gia tri =0 va nam duoi so 0
//    while(!feof(f)){
//        
//        for(int i =0;i<*n;i++){
//            for(int j =i; j<*n;j++){
//                //doc luot bo vao temp
//                if(i == j){
//                    for(int t = 0; t<=j;t++){
//                        //doc bo
//                        fscanf(f, "%f", &temp);
//                    }
//                }else{
//                    fscanf(f, "%f", &a[k].dodai);
//                    a[k].dau = i;
//                    a[k].cuoi = j;
//                    k++;
//                }
//            }
//        }
//
//    }
//    fclose(f);
//}
//void swap(canh *x, canh *y){
//	canh temp= *x;
//	*x = *y;
//	*y = temp;
//}
//
//void bubble_sort(canh a[], int n){
//	int i,j;
//	for(i=0; i<n-1; i++)
//		for(j=n-1; j>i; j--)
//			if(a[j].dodai<a[j-1].dodai)	
//				swap(&a[j], &a[j-1]);
//}
//void init_forest(int parent[], int n){
//	int i;
//	for(i=0; i<n; i++) 
//		parent[i]=i;
//}
//
//int find_root(int parent[], int u){
//	while (u != parent[u])
//		u = parent[u];
//		return u;
//}
//
//int chu_trinh(int r_dau, int r_cuoi){
//	return (r_dau == r_cuoi);
//}
//
//void update_forest(int parent[], int r1, int r2){
//	parent[r2]= r1; //Hop nhat hai cay voi nhau
//}
//int dinhCap3(canh PA[], int k, canh moi){
//    int i, dem;
//	i =0, dem =1;
//    while(i<k && dem <3){
//        if(moi.dau == PA[i].dau || moi.dau == PA[i].cuoi){
//            dem++;
//        }
//        i++;
//    }
//    if(dem==3)
//        return 1;
//
//    i=0;
//    dem = 1;
//    while (i<k && dem <3){
//		if (moi.cuoi==PA[i].dau || moi.cuoi==PA[i].cuoi)
//		dem++;
//	i++;
//	}
//    return dem ==3;
//}
//
////int dinhCap3(canh PA[], int k, canh moi){
////	int i,dem;
////	i=0;
////	dem=1;
////	while (i<k && dem <3){
////		if (moi.dau==PA[i].dau || moi.dau==PA[i].cuoi)
////		dem++;
////	i++;
////	}
////	if (dem==3)	return 1;
////	
////	i=0;
////	dem=1;
////	while (i<k && dem <3){
////		if (moi.cuoi==PA[i].dau || moi.cuoi==PA[i].cuoi)
////		dem++;
////	i++;
////	}
////	return dem==3;
////}
//
//void greedy(canh ds_canh[], int n,canh PA[]){
//    int parent[n];
//    init_forest(parent, n);
//
//    int j =0;
//    int i, r_dau, r_cuoi;
//    for(int  i = 0; i<n*(n-1)/2&& j<n-1;i++){
//         r_dau = find_root(parent, ds_canh[i].dau);
//         r_cuoi = find_root(parent, ds_canh[i].cuoi);
//        if(!dinhCap3(PA, j, ds_canh[i]) && ! chu_trinh(r_dau, r_cuoi)){
//            PA[j] = ds_canh[i];
//            j++;
//            update_forest(parent, r_dau,r_cuoi);
//        }
//    }
//    
//    for(i=0; i<n*(n-1)/2; i++){
//		r_dau= find_root(parent, ds_canh[i].dau);
//		r_cuoi= find_root(parent, ds_canh[i].cuoi);
//		if ((!dinhCap3(PA, n-1, ds_canh[i])) && (chu_trinh(r_dau, r_cuoi))){
//			PA[n-1]= ds_canh[i];
//			break; //Ket thuc vi PA da co du n canh, tao thanh chu trinh
//		}
//	}
//}
////void greedy(canh ds_canh[], int n, canh PA[]){
////	int i,j;
////	int parent[n];
////	init_forest(parent,n);
////	int r_dau, r_cuoi;
////// Chon cac canh nho nhat khong tao thanh dinh cap 3 va khong tao thanh chu trinh de dua vao PA
////	j= 0;
////	for(i=0; i<n*(n-1)/2 && j<n-1; i++){
////		r_dau= find_root(parent, ds_canh[i].dau);
////		r_cuoi= find_root(parent, ds_canh[i].cuoi);
////		if (!dinhCap3(PA,j, ds_canh[i]) && !chu_trinh(r_dau, r_cuoi)){
////			PA[j]= ds_canh[i]; //ds_canh[i] khong tao dinh cap 3, khong tao thanh chu trinh thieu thi dua vao PA
////			j++;
////			update_forest(parent, r_dau, r_cuoi); //Hop nhat 2 cay: Dat cha cua goc cuoi bang goc dau
////		}
////	}
////	
////// Den day PA da co n-1 canh
////// Tim mot canh trong so cac canh chua xet dua vao PA neu no khong tao thanh dinh cap 3 nhung phai tao thanh CHU TRINH
////	for(; i<n*(n-1)/2; i++){
////		r_dau= find_root(parent, ds_canh[i].dau);
////		r_cuoi= find_root(parent, ds_canh[i].cuoi);
////		if ((!dinhCap3(PA, n-1, ds_canh[i])) && (chu_trinh(r_dau, r_cuoi))){
////			PA[n-1]= ds_canh[i];
////			break; //Ket thuc vi PA da co du n canh, tao thanh chu trinh
////		}
////	}
////}
//
//void in_ds_canh(canh a[], int m, int la_PA){
//	int i;
//	float tong=0.0;
//	for(i=0; i<m; i++){
//		printf("%3d %c%c=%8.2f\n", i+1, a[i].dau+97, a[i].cuoi+97, a[i].dodai);
//		if (la_PA)
//			tong+= a[i].dodai;
//	}
//		if (la_PA)
//			printf("Tong do dai cac canh = %5.2f\n", tong);
//}
//
//
//int main(){
//
//
//    canh ds_canh[size];
//    int n;
//    readFromFile(ds_canh, &n);
//    printf("Danh sach cac canh cua do thi:\n");
//	in_ds_canh(ds_canh, n*(n-1)/2, 0);
//	
//	bubble_sort(ds_canh, n*(n-1)/2);
//	printf("\nDanh sach cac canh cua do thi da SAP XEP:\n");
//	in_ds_canh(ds_canh, n*(n-1)/2, 0);
//	
//	canh PA[n];
//	greedy(ds_canh, n, PA);
//		
//	printf("\nPHUONG AN\n");
//	in_ds_canh(PA, n, 1);
//	
//
//    return 0;
//}
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define size 30

typedef struct 
{
    /* data */
    float doDai;
    int dau, cuoi;
}canh;

void ReadFromFile(canh a[], int *n){

    FILE *f = fopen("TSP.txt", "r");

   fscanf(f,"%d",n); // Doc so dinh cua do thi n
	float temp;
	int k=0;
	for(int i=0; i<*n; i++)
		for(int j=i; j<*n; j++)
			if(i==j) for(int t=0; t<=j; t++)	fscanf(f,"%f",&temp); // Doc bo qua cac so duoi duong cheo chinh
			else {
				fscanf(f,"%f",&a[k].doDai); // Doc luu tru cac so tren duong cheo chinh
				a[k].dau=i;
				a[k].cuoi=j;
				k++;
				}
	fclose(f);
}

void swap(canh *x, canh *y){
    canh temp = *x;
    *x = *y;
    *y = temp;
}
void BubbleSort(canh a[], int n){
    for(int i = 0;i<=n-2;i++){
        for(int j = n-1;j>=i+1; j--){
            if(a[j].doDai<a[j-1].doDai){
                swap(&a[j], &a[j-1]);
            }
        }
    }
}

void initForest(int parent[], int n){
    for(int i =0;i<n;i++){
        parent[i] = i;
    }
}
int findRoot(int parent[], int u){
    while(u!= parent[u]){
        u = parent[u];
    }
    return u;
}
int chuTrinh(int r_dau, int r_cuoi){
    return r_dau == r_cuoi;
}
void upDateForest(int parent[],int r1, int r2){
    parent[r2] = r1;
}

int dinhCap3(canh PA[], int k, canh moi){

    int i =0, dem = 1;

    while(i<k && dem<3){
        if(moi.dau == PA[i].dau || moi.dau == PA[i].cuoi){
            dem++;
        }
        i++;
    }
    if(dem == 3)
        return 1;

    i =0;
    dem =1;
    while(i<k && dem<3){
        if(moi.cuoi == PA[i].dau || moi.cuoi == PA[i].cuoi){
            dem++;
        }
        i++;
    }
    return dem == 3;

}

void greedy(canh ds_canh[], int n, canh PA[]){

    int parent[n];
    initForest(parent, n);

    int r_dau, r_cuoi;
    int k = 0 ;
    for(int i =0;i<n*(n-1)/2 && k<n-1 ; i++){
        r_dau = findRoot(parent, ds_canh[i].dau);
        r_cuoi = findRoot(parent, ds_canh[i].cuoi);

        if(!dinhCap3(PA,k,ds_canh[i]) && !chuTrinh(r_dau, r_cuoi)){
            //them vao
            PA[k] = ds_canh[i];
            k++;
            upDateForest(parent, r_dau, r_cuoi);
        }
    }

    for(int i =0;i<n*(n-1)/2; i++){
        //neu no khong tao thanh dinh cap 3 va tao thanh chu trinh
        r_dau = findRoot(parent, ds_canh[i].dau);
        r_cuoi = findRoot(parent, ds_canh[i].cuoi);
        if(!dinhCap3(PA,n-1,ds_canh[i]) && chuTrinh(r_dau, r_cuoi)){
            PA[n-1] = ds_canh[i];
            break;
        }

    }
}
void inPA(canh PA[], int n){
    float tong = 0;
    for(int i =0;i<n;i++){
        tong+= PA[i].doDai;
        printf("%d : %c - %c = %f\n", i+1, PA[i].dau + 97 , PA[i].cuoi+97, PA[i].doDai);
    }
    printf("\nTong do dai duong di la : %f", tong);
    
}
void in_ds_canh(canh a[], int m, int la_PA){
	int i;
	float tong=0.0;
	for(i=0; i<m; i++){
		printf("%3d %c%c=%8.2f\n", i+1, a[i].dau+97, a[i].cuoi+97, a[i].doDai);
		if (la_PA)
			tong+= a[i].doDai;
	}
		if (la_PA)
			printf("Tong do dai cac canh = %5.2f\n", tong);
}


int main(){
   canh ds_canh[size];
	int n;
		
	printf("Phuong an TSP dung thuat toan THAM AN:\n");
	ReadFromFile(ds_canh, &n);
	printf("Danh sach cac canh cua do thi:\n");
	in_ds_canh(ds_canh, n*(n-1)/2, 0);
	
	BubbleSort(ds_canh, n*(n-1)/2);
	printf("\nDanh sach cac canh cua do thi da SAP XEP:\n");
	in_ds_canh(ds_canh, n*(n-1)/2, 0);
	
	canh PA[n];
	greedy(ds_canh, n, PA);
		
	printf("\nPHUONG AN\n");
	in_ds_canh(PA, n, 1);

    return 0;
}