//
//  main.cpp
//  133
//
//  Created by dnalwqer on 14-3-20.
//  Copyright (c) 2014年 dnalwqer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node * next;
    struct Node * pre;
}Node;

void createLinklist(Node *head,int num)
{
    Node *tmp=head;
    Node *temp1=head;
    int i;
    for(i=2;i<=num;i++)
    {
        Node *q=(Node *)malloc(sizeof(Node));
        q->value=i;
        q->next=tmp->next;
        tmp->next=q;
        q->pre=tmp;
        tmp=q;
    }
    tmp->next=temp1;
    temp1->pre=tmp;
}

Node *del(Node *head,int num,int position)
{
    Node *tmp=head;
    int i=0;
    if(position==1)
    {
        if(num==1)
            tmp=tmp->pre;
        else
        {
            while(tmp->next)
            {
                i++;
                if(num-1==i)
                    break;
                tmp=tmp->next;
            }
        }
    }
    else
    {
        if(num==1)
            tmp=tmp->next;
        else
        {
            while(tmp->pre)
            {
                i++;
                if(num-1==i)
                    break;
                tmp=tmp->pre;
            }
        }
    }
    return tmp;
}

int leng(Node* head)
{
    Node *q=head;
    Node *p=head;
    int len=0;
    while(q)
    {
        len++;
        q=q->next;
        if(q==p)
            break;
    }
    return len;
}
int main()
{
    int n,k,m;
    while(scanf("%d%d%d",&n,&k,&m)!=EOF)
    {
        if(n==0)
            break;
        Node *head=(Node *)malloc(sizeof(Node));
        head->value=1;
        head->next=NULL;
        head->pre=NULL;
        createLinklist(head,n);
        int len=leng(head);
        Node *one=head;
        Node *two=head->pre;
        Node *a,*b,*free1,*free2;
        int flag=1;
        while(len>0)
        {
            a=del(one,k,1);
            b=del(two,m,2);
            free1=a->next;
            free2=b->pre;
            int res=0;
            if(free1!=free2)
            {
                if(flag)
                {
                    printf("%3d%3d",free1->value,free2->value);
                    flag=0;
                }
                else
                    printf(",%3d%3d",free1->value,free2->value);
                if(a->next!=b)
                {
                    a->next=free1->next;
                    a->next->pre=a;
                    b->pre=free2->pre;
                    b->pre->next=b;
                }
                else
                {
                    a->pre->next=b->next;
                    b->next->pre=a->pre;
                    res=1;
                }
                len-=2;
            }
            else
            {
                if(flag)
                {
                    printf("%3d",free1->value);
                    flag=0;
                }
                else
                    printf(",%3d",free1->value);
                a->next=free1->next;
                a->next->pre=a;
                len--;
            }
            if(!res)
            {
                one=a->next;
                two=b->pre;
            }
            else
            {
                one=a->pre->next;
                two=b->next->pre;
            }
        }
        printf("\n");
    }
    return 0;
}
