#include<stdio.h>
#include<stdlib.h>

#define N 100+10

char s[N][N];
int main()
{
    char str[N];
    while(gets(str))
    {
        int len=strlen(str);
        for(int i=0;i<len;i++) //全部转换成大写字母,只是使得编写变得简单，但若有坑数据的话会WA
        {
            if(str[i]>='a' && str[i]<='z')
            {
                str[i]-=32;
            }
        }
        int tot=0;
        for(int i=0;i<len;)
        {
            int k=0;
            char temp[N]=""; //必须初始化,见1
            while(str[i]!=' ' && str[i]!='-' && i<len)
            {
                temp[k++]=str[i++];
//                k++;
//                i++;
            }
            i++; //跳过空格和-
            strcpy(s[tot++],temp);
        }

        char except[][N]={"THE","A","AN","FOR","AND","OF"};
        for(int i=0;i<tot;i++)
        {
//            1:
//            printf("%s\n",s[i]);
            for(int j=0;j<6;j++)
            {
                 if(strcmp(s[i],except[j])==0)
                 {
                     strcpy(s[i],"\0");
                 }
            }
        }
        for(int i=0;i<tot;i++)
        {
            if(strcmp(s[i],"")!=0) //若为空值则跳过，见2
                putchar(s[i][0]);
        }
        puts("");
//        2:
//        puts("");
//        char tt[N]="\0";
//        putchar(tt[0]);
//        puts("ok");
    }
    return 0;
}
