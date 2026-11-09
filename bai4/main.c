#include<stdio.h>
#include<stdlib.h>

typedef struct    {
    	char hoten[30];
    	int masv;
    	float d1, d2, d3;
}Data;
typedef struct tagNode    {
    	Data infor;
    	struct tagNode *link;
}Node;
typedef struct    {
    	Node *pHead;  
    	Node *pTail;
    	int spt;
}LList;
/////////////////////////////////////
void initList(LList *L) //<- empty list
    {
    	L->pHead = NULL;
    	L->pTail = NULL;
    	L->spt = 0;
    }
/////////////////////////////////////
int emptyList(LList L) //this one checks the empty one
 {
    	return (L.spt == 0); 
}
/////////////////////////////////////
Node *searchNode(LList L, int masv){
	Node *pp = L.pHead;
	while(pp !=NULL && (pp->infor.masv != masv)){
		pp = pp->link;
	}
	return pp;
}
void insert_Head(LList *L, Data x) //Chen thong tin vao nut dau danh sach
    {
    	Node *pp; //Tao nut pp de chua X
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){ //Danh sach rong -> pHead = pTail = pp
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		pp->link = L->pHead;
    		L->pHead = pp;
    		}
    	L->spt++;
    }
void insert_Tail(LList *L, Data x)//Giong nhu tren, nhung vao nut cuoi danh sach.
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		L->pTail->link = pp; //node cuoi cu phai tro den node moi
    		L->pTail = pp;
    		}
    	L->spt++;
    }
void insert_After(LList *L, Node *q,Data x){ //Chen thong tin vao sau mot phan tu/nut (node) nao do
	Node *pp;
	if(q==NULL){
		return;
	}
	else{
		pp = (Node*) malloc(sizeof(Node));
		pp->infor = x;
		pp->link = q->link;
		q->link = pp;
		if(q==L->pTail){
			L->pTail = pp;
		}
		L->spt++;
	}
}
void chen_tang(LList *L, Data x){
	Node *pp = L->pHead, *q;
	while(pp!=NULL && pp->infor.masv < x.masv){
		q = pp;
		pp = pp->link;
	}
	if(pp == L->pHead){
		insert_Head(L,x);
	}
	else{
		insert_After(L,q,x);
	}
}
void tach(LList L, LList *L1, LList *L2){
	initList(L1);
	initList(L2);
	Node *pp = L.pHead;
	while(pp != NULL){
		if((pp->infor.d1 + pp->infor.d2 + pp->infor.d3)/3 >= 6){
			insert_Head(L1, pp->infor);
		}
		else{
			insert_Head(L2, pp->infor);
		}
	}
}
void ghep(LList L1, LList L2, LList *L){
	initList(L);
	Node *p1 = L1.pHead;
	Node *p2 = L2.pHead;
	if(L1.spt < L2.spt){
		while (p1!=NULL){
			insert_Head(L, p1-> infor);
			insert_Head(L, p2-> infor);
			p1 = p1 ->link;
			p2 = p2 ->link;
		}
		while (p2!=NULL){
			insert_Head(L, p2->infor);
			p2 = p2->link;
		}
	}
	else{
		while (p2!=NULL){
			insert_Head(L, p2-> infor);
			insert_Head(L, p1-> infor);
			p2 = p2 ->link;
			p1 = p1 ->link;
		}
		while (p1!=NULL){
			insert_Head(L, p1->infor);
			p1 = p1->link;
		}
	}
}
void del_Head(LList *L){
	Node *pp;
	if(emptyList(*L)){
		return;
	}
	else{
		pp = L->pHead;
		L->pHead = pp->link;
		free(pp);
		L->spt--;
		if(L->pHead==NULL){
			L->pTail = NULL;
		}
	}
}
void del_After(LList *L, Node *q){
	Node *pp;
	if(q == NULL){
		return;
	}
	else{
		pp = q->link;
		if(q->link == L->pTail){
			L->pTail = q;
		}
		q->link = pp->link;
		free(pp);
		L->spt--;
	}
}
void del_masv(LList *L, int masv){
	Node *pp = L->pHead, *q;
	while(pp!=NULL && (pp->infor.masv!=masv)){
		q = pp;
		pp = pp->link;
	}
	if(pp == NULL){
		return;
	}
	else{
		if(pp ==L->pHead){
			del_Head(L);
		}
		else{
			del_After(L,q);
		}
	}
}
///////////////////////////////////////
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ma sv: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 2: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void processList(LList L){
    Node *pp = L.pHead;
    while( pp != NULL ){
        	in(pp->infor); //in dữ liệu trong node 
        	pp = pp->link;
    	}
}
/////////////////////////////////////////

int main(){
    LList L;
	int kt = 0;
	Data x;
	initList(&L); //tao ra 1 ds rong
	do{
	    printf("\nChuong trinh lam viec voi DSLK don SV\n");
	    printf("\n1: Them nut vao dau danh sach");
	    printf("\n2: Them nut vao cuoi danh sach");
	    printf("\n3: Them nut vao sau mot nut khac trong danh sach");
		printf("\n4: Them nut theo thu tu tang dan");
		printf("\n5: Tach ds cho cac sinh vien co diem tb > 6");
		printf("\n6: Gop lai cac danh sach");
		printf("\n7: Xoa nut o dau danh sach");
		printf("\n8: Xoa nut o sau mot nut khac");
		printf("\n9: Xoa theo ma sv");
	    printf("\n10: Duyet ds");
	    printf("\n0: Thoat");
	    printf("\nMoi ban chon: ");
	    int chon;
	    scanf("%d", &chon);
	    switch(chon){
	        case 1: 
	            printf("Nhap thong tin sv can them: ");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Head(&L, x);
            	break;
            case 2:	
	            printf("Nhap thong tin sv can them: ");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Tail(&L, x);
            	break;
            case 3:
	            printf("Nhap thong tin sv can them: ");
	            nhap(&x);
	            if(x.masv > 0){
					Node *c;
					int masv;
					printf("Nhap ma sv muon chen sau: ");
					scanf("%d",&masv);
					c = searchNode(L, masv);
					if(c!=NULL){
                		insert_After(&L,c,x);
					}
				}
			case 4:
	            printf("Nhap thong tin sv can them: ");
	            nhap(&x);
	            if(x.masv > 0) 
                	chen_tang(&L, x);
            	break;
			case 5:
				LList *L1;
				LList *L2;
				tach(L,L1,L2);
				if(L1!=NULL && L2!=NULL){
					printf("Tach thanh cong\n");	
				}
				break;
			case 6:
				LList *l;
				LList l2 = *L2;
				LList l1 = *L1;
				ghep(l1,l2,l);
				L = *l;
					printf("Gop thanh cong\n");
			case 7:
				del_Head(&L);
				printf("Xoa Thanh Cong\n");
				break;
			case 8:
				printf("Nhap ma sv truoc sv can xoa: ");
				int masv;
				scanf("%d",&masv);
				if(masv > 0){
					Node *c;
					c = searchNode(L,masv);
					del_After(&L,c);
					printf("Xoa ok\n");
				}
				break;
			case 9:
				printf("Nhap ma sv truoc sv can xoa: ");
				int masv1;
				scanf("%d",&masv1);
				if(masv > 0){
					del_masv(&L,masv1);
				}
            case 10: 
                processList(L);
                break;    
            case 0: 
                printf("Bye bye\n");
	            kt = 1;
        }
	}while(kt==0); 
}