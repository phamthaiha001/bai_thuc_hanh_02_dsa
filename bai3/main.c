#include<stdio.h>
#include<stdlib.h>
//Giong nhu bai 1, nhung ma voi mang nay thi phai tu viet ham nhap/in (scanf/printf) cho struct
typedef struct{
    char HoTen[30];
    int MaSV;
    float d1, d2, d3;
}SV;

void nhap(SV *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->MaSV));
    if(x->MaSV > 0){
        printf("Nhap ma sv: ");
        scanf("%s", (x->HoTen));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
void in(SV x){ //ko de *x vi no se thanh con tro
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 2: %.2f\n", 
            x.HoTen, x.MaSV, x.d1, x.d2, x.d3);
}

void nhapds(SV *x, int n){
    for(int i = 0;i<n;i++){
        printf("Nhap thong tin sv %d ",i);
        nhap(x+i);
    }
}

void inds(SV *x, int n){
    for(int i = 0; i<n; i++){
        in(*(x+i));
    }
}

int main(){
    int n;
    printf("Nhap so luong sinh vien");
    scanf("%d",&n);
    if(n<=0){
        printf("Khong hop le");
        return 1;
    }
    SV *sv = (SV*)malloc(n*sizeof(SV));
    if(sv == NULL){
        printf("nah bro");
        return 1;
    }
    nhapds(sv, n);
    inds(sv, n);
    free(sv);
    return 0;
}