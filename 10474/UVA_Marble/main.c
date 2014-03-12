//
//  main.c
//  UVA_Marble
//
//  Created by dnalwqer on 14-3-11.
//  Copyright (c) 2014年 dnalwqer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXN 20000 //数组开的大一点，一开始开的2000，runtime error
int a[MAXN],b[MAXN];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int m,n,i,k;
    int count=0;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m==0&&n==0)
            break;
        int flag;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        count++;
        for(i=0;i<m;i++)
            scanf("%d",&a[i]);
        qsort(a,m,sizeof(int),cmp);
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);
        printf("CASE# %d:\n",count);
        for(i=0;i<n;i++)
        {
            flag=0;
            for(k=0;k<m;k++)
            {
                if(b[i]==a[k])
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
                printf("%d not found\n",b[i]);
            else
                printf("%d found at %d\n",b[i],k+1);
        }
    }
    return 0;
}

