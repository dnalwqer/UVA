//
//  main.c
//  UVA_list_of_conquest
//
//  Created by dnalwqer on 14-3-11.
//  Copyright (c) 2014年 dnalwqer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100
#define line 2100
char s[line][MAXN];
char temp[line][MAXN];
int num[line];
char place[line][MAXN];
char place_temp[line][MAXN];

int compare(const void *a,const void *b)
{
    return strcmp(a,b);
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    int i=0,k,m;
    int len,number=0;
    memset(s,0,sizeof(s));
    memset(temp,0,sizeof(temp));
    memset(num,0,sizeof(num));
    memset(place,0,sizeof(place));
    while(fgets(s[i],sizeof(s[i]),stdin)!=EOF)
    {
        int flag=0;
        len=strlen(s[i])-1;
        int j;
        for(j=0;j<len;j++)
        {
            if(s[i][j]!=' ')
            {
                temp[i][j]=s[i][j];
            }
            else if(s[i][j]==' ')
            {
                temp[i][j]='\0';
                break;
            }
        }
        
        for(j=0;j<number;j++)
        {
            if(strcmp(temp[i],place[j])==0)
            {
                flag=1;
                num[j]++;
                break;
            }
        }
        if(!flag)
        {
            strcpy(place[number],temp[i]);
            strcpy(place_temp[number],place[number]);
            num[number]=1;
            number++;
        }
        i++;
        if(i==n)
            break;
    }
    
    qsort(place_temp, number, sizeof(place_temp[0]), compare);
    
    for(k=0;k<number;k++)
    {
        for(m=0;m<number;m++)
        {
            if(strcmp(place_temp[k],place[m])==0)
                break;
        }
        printf("%s %d\n",place_temp[k],num[m]);
    }    
    return 0;
}

