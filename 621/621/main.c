//
//  main.c
//  621
//
//  Created by dnalwqer on 14-3-13.
//  Copyright (c) 2014年 dnalwqer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 30
char s[MAXN];
int main()
{
    int n,len;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        scanf("%s",s);
        len=strlen(s);
        if(len<=2)
            printf("+\n");
        else if(s[len-2]=='3'&&s[len-1]=='5')
            printf("-\n");
        else if(s[0]=='9'&&s[len-1]=='4')
            printf("*\n");
        else
            printf("?\n");
    }
    return 0;
}

