#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
//tao cau truc sinh vien
struct BenhNhan
{
    int ma;
    char ten[150];
};
//tao cau truc danh sach lien ket don
struct Node
{
    BenhNhan *data;
    Node *pNext;
};
struct SingleList
{
    Node *pHead;
};
//khoi tao danh sach lien ket don
void Initialize(SingleList *&list)
{
    list=new SingleList;
    list->pHead=NULL;
}
//nhap thong tin sinh vien
BenhNhan *NhapBenhNhan()
{
    BenhNhan *bn=new BenhNhan;
    cout<<"Nhap MSBN:";
    cin>>bn->ma;
    cin.ignore();
    cout<<"Nhap ho va ten:";
    gets(bn->ten);
    return bn;
}
//tao node sinh vien
Node *CreateNode(BenhNhan *bn)
{
    Node *pNode=new Node;
    if(pNode!=NULL)
    {
        pNode->data=bn;
        pNode->pNext=NULL;
    }
    else
    {
        cout<<"cap phat bo nho that bai!!!";
    }
    return pNode;
}
//them node vao cuoi danh sach
void InsertLast(SingleList *&list,BenhNhan *bn)
{
    Node *pNode=CreateNode(bn);
    if(list->pHead==NULL)
    {
        list->pHead=pNode;
    }
    else
    {
        Node *pTmp=list->pHead;
         
        while(pTmp->pNext!=NULL)
        {
            pTmp=pTmp->pNext;
        }
        pTmp->pNext=pNode;
    }
}
//hien thi danh sach
void PrintList(SingleList *list)
{
    Node *pTmp=list->pHead;
    if(pTmp==NULL)
    {
        cout<<"Danh sach rong";
        return;
    }
    while(pTmp!=NULL)
    {
        BenhNhan *bn=pTmp->data;
        cout<<bn->ma<<"\t"<<bn->ten<<"\n";
        pTmp=pTmp->pNext;
    }
}
//sap xep
void SortList(SingleList *&list)
{
    for(Node *pTmp=list->pHead;pTmp!=NULL;pTmp=pTmp->pNext)
    {
        for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
        {   
            BenhNhan *bnTmp=pTmp->data;
            BenhNhan *bnTmp2=pTmp2->data;
            if(bnTmp2->ma<bnTmp->ma)
            {
                int ma=bnTmp->ma;
                char ten[150];
                strcpy(ten,bnTmp->ten);
                 
                bnTmp->ma=bnTmp2->ma;
                strcpy(bnTmp->ten,bnTmp2->ten);
                bnTmp2->ma=ma;
                strcpy(bnTmp2->ten,ten);             
            }
        }   
    }
}
//xoa
void RemoveNode(SingleList *&list,int ma)
{
    Node *pDel=list->pHead;
    if(pDel==NULL)
    {
        cout<<"Danh sach rong!";
    }
    else
    {
        Node *pPre=NULL;
        while(pDel!=NULL)
        {
            BenhNhan *bn=pDel->data;
            if(bn->ma==ma)
                break;
            pPre=pDel;
            pDel=pDel->pNext;
        }
        if(pDel==NULL)
        {
            cout<<"khong tim thay MSBN: "<<ma;
        }
        else
        {
            if(pDel==list->pHead)
            {
                list->pHead=list->pHead->pNext;
                pDel->pNext=NULL;
                delete pDel;
                pDel=NULL;
            }
            else
            {
                pPre->pNext=pDel->pNext;
                pDel->pNext=NULL;
                delete pDel;
                pDel=NULL;
            }
        }
    }
}
int main(int argc, char** argv) {
    SingleList *list;
    Initialize(list);
   BenhNhan *teo=NhapBenhNhan();
    InsertLast(list,teo);
   BenhNhan *ty=NhapBenhNhan();
    InsertLast(list,ty);
    BenhNhan *bin=NhapBenhNhan();
    InsertLast(list,bin);
    PrintList(list);
    SortList(list);
    cout<<"\nSau khi sap xep:\n";
    PrintList(list);
    cout<<"\Ban muon xoa sinh vien co MSSV: ";
    int ma;
    cin>>ma;
    RemoveNode(list,ma);
    cout<<"\nSau khi xoa:\n";
    PrintList(list);
 
  cout<<"\n---------------------------\n";
  cout<<"Chuong trinh nay duoc dang tai Freetuts.net";
}
