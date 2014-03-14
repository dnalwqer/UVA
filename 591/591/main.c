//
//  main.c
//  591
//
//  Created by dnalwqer on 14-3-14.
//  Copyright (c) 2014年 dnalwqer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 80
int height[MAXN];
int minus[MAXN];
int main()
{
    int n;
    int count=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        count++;
        int i,sum=0;
        memset(height,0,sizeof(height));
        memset(minus,0,sizeof(minus));
        int average,minpace=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&height[i]);
            sum+=height[i];
        }
        average=sum/n;
        for(i=0;i<n;i++)
        {
            minus[i]=height[i]-average;
            if(minus[i]>0)
                minpace+=minus[i];
        }
        printf("Set #%d\n",count);
        printf("The minimum number of moves is %d.\n",minpace);
        printf("\n");
    }
    return 0;
}

