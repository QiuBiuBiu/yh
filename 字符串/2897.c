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
        for(int i=0;i<len;i++) //ȫ��ת���ɴ�д��ĸ,ֻ��ʹ�ñ�д��ü򵥣������п����ݵĻ���WA
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
            char temp[N]=""; //�����ʼ��,��1
            while(str[i]!=' ' && str[i]!='-' && i<len)
            {
                temp[k++]=str[i++];
//                k++;
//                i++;
            }
            i++; //�����ո��-
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
            if(strcmp(s[i],"")!=0) //��Ϊ��ֵ����������2
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
