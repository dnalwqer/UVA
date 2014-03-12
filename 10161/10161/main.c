//
//  main.c
//  10161
//
//  Created by dnalwqer on 14-3-12.
//  Copyright (c) 2014年 dnalwqer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        int i,flag=1;
        int total;
        for(i=1;;i++)
        {
            total=i*i-i+1;
            flag*=-1;
            if(abs(total-n)<=i-1)
                break;
        }
        if(flag==1)
        {
            if(n>=total)
                printf("%d %d\n",i,i-n+total);
            else
                printf("%d %d\n",i-total+n,i);
        }
        else
        {
            if(n>=total)
                printf("%d %d\n",i-n+total,i);
            else
                printf("%d %d\n",i,i-total+n);
        }
    }
    return 0;
}

