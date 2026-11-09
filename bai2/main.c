#include<stdio.h>
#include<stdlib.h>

void nhap(float **MaTran, int h, int c){
    for(int i = 0; i<h;i++){
        for(int j = 0;j<c;j++){
            scanf("%f",&MaTran[i][j]);
        }
    }
}

void in(float **MaTran, int h, int c){
    for(int i = 0; i<h;i++){
        for(int j = 0;j<c;j++){
            printf("%.2f ",MaTran[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int h,c;
    scanf("%d %d",&h,&c);

    float **MaTran = (float**)malloc(h*sizeof(float));
    if(MaTran==NULL){
        printf("Khong du bo nho.\n");
        return 1;
    }
    for(int i = 0; i < h; i ++){
        MaTran[i] = (float*)malloc(c*sizeof(float));
        if(MaTran[i]==NULL){
        printf("Khong du bo nho tai dong %d\n",i);
        return 1;
    }
}
    nhap(MaTran,h,c);
    printf("Ma Tran vua nhap: \n");
    in(MaTran,h,c);
    free(MaTran);

    return 0;

}