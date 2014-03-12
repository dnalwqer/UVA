//
//  main.c
//  UVA
//
//  Created by dnalwqer on 14-3-10.
//  Copyright (c) 2014年 dnalwqer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int code[1000];
int guess[1000][1000];

int main()
{
	int n,count=0;
	while(scanf("%d",&n)!=EOF)
	{
		memset(code,0,sizeof(code));
		memset(guess,0,sizeof(guess));
		if(n==0)
			break;
		count++;
		int i,j,k;
		for(i=0;i<n;i++)
			scanf("%d",&code[i]);
		j=0;
		while(1)
		{
			int flag=0;
			for(i=0;i<n;i++)
				scanf("%d",&guess[j][i]);
			for(i=0;i<n;i++)
				if(guess[j][i]!=0)
					flag=1;
			j++;
			if(!flag)
				break;
		}
		
		int strong=0,weak=0;
		int pos1[1000];
		int pos2[1000];
		int temp=0;
		printf("Game %d:\n",count);
		for(i=0;i<j-1;i++)
		{
			memset(pos1,0,sizeof(pos1));
			memset(pos2,0,sizeof(pos2));
			for(k=0;k<n;k++)
				if(code[k]==guess[i][k])
				{
					strong++;
					pos1[k]=1;
					pos2[k]=1;
				}
			for(k=0;k<n;k++) 
			{
				if(pos1[k]==1)
					continue;
				for(temp=0;temp<n;temp++)
				{
					if(pos2[temp]==1)
						continue;
					if(code[k]==guess[i][temp])
					{
						weak++;
						pos1[k]=1;
						pos2[temp]=1;
						break;
					}
				}
			}
			printf("    (%d,%d)\n",strong,weak);
			strong=0;
			weak=0;
		}
	}
	
    return 0;
}

