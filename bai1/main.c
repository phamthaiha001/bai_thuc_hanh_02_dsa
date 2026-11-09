#include<stdio.h>
#include<stdlib.h>

void nhap(float *a, int n){
    for(int i=0;i<n;i++){
        printf("Nhap phan tu a[%d]: ",i);
        scanf("%f",a+i);
    }
}

void in(float *a, int n){
    for(int i=0;i<n;i++){
        printf("%.2f",*(a+i));
    }
}

int main(){
    int n;
    float *a = (float*)malloc(n*sizeof(float));
    printf("Nhap so phan tu: ");
    scanf("%d",&n);
    if(n <= 0) {
        printf("So phan tu phai lon hon 0.\n");
        return 1;
    }

    if(a==NULL){
        printf("Khong du bo nho de cap phat.\n");
        return 1;
    }
    nhap(a,n);
    printf("\nDL ban dau: \n");
    in(a,n);
    free(a);

    return 0;

}