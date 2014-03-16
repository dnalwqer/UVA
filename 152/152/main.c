//
//  main.c
//  152
//
//  Created by dnalwqer on 14-3-15.
//  Copyright (c) 2014年 dnalwqer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 6000
double input[MAXN][3]; //
int res[10];
int main()
{
    memset(input,0,sizeof(input));
    memset(res,0,sizeof(res));
    int i,j,k;
    for(i=0;;i++)
    {
        scanf("%lf%lf%lf",&input[i][0],&input[i][1],&input[i][2]);
        if(input[i][0]==input[i][1]&&input[i][1]==input[i][2]&&input[i][0]==0)  //遇上0 0 0 就结束输入
            break;
    }
    
    for(j=0;j<i;j++)  //双重循环判断每棵树的最近距离树
    {
        double min=1000000,temp;
        int result;
        for(k=0;k<i;k++)
        {
            if(j==k)
                continue;
            temp=sqrt((input[j][0]-input[k][0])*(input[j][0]-input[k][0])+(input[j][1]-input[k][1])*(input[j][1]-input[k][1])+(input[j][2]-input[k][2])*(input[j][2]-input[k][2]));
            if(min>temp)
            {
                min=temp;
            }
        }
        result=floor(min);
        if(result>=0&&result<10)  //当距离小于10的才会记录
            res[result]++;
    }
    
    for(j=0;j<10;j++)
        printf("%4d",res[j]);
    printf("\n");
    return 0;
}

