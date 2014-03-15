//
//  main.c
//  107
//
//  Created by dnalwqer on 14-3-15.
//  Copyright (c) 2014年 dnalwqer. All rights reserved.
//

//这道题主要就是解方程，注意精度
// N^k=n
//(N+1)^k=m
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m==0&&n==0)
            break;
        int k;
        for(k=0;;k++)
        {
            if((int)(pow(1+pow(n,1.0/k),k)+0.5)>=m)
                break;
        }
        
        int N=(int)(pow(n, 1.0/k)+0.5);
        
        int totalHeight=0,notWorking=0;
        int j;
        for(j=0;j<k;j++)
        {
            notWorking+=(int)(pow(N,j)+0.5);
            totalHeight+=((int)(pow(N,j)+0.5)/pow(N+1,j)*m);
        }
        totalHeight+=n;
        printf("%d %d\n",notWorking,totalHeight);
        
    }
    return 0;
}
