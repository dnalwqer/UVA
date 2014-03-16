//
//  main.c
//  573
//
//  Created by dnalwqer on 14-3-15.
//  Copyright (c) 2014年 dnalwqer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int h,u,d,f;
    while(scanf("%d%d%d%d",&h,&u,&d,&f)!=EOF)
    {
        if(h==0)
            break;
        float total=0;
        float per=f/100.0;
        int i,flag=0;
        for(i=1;;i++)
        {
            total+=((u-u*per*(i-1))<=0)? 0: (u-u*per*(i-1));
            if(total>h)
            {
                flag=1;
                break;
            }
            total-=d;
            if(total<0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
            printf("success on day %d\n",i);
        else
            printf("failure on day %d\n",i);
    }
    return 0;
}

