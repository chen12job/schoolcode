#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100], b[100];
    int n1, n2, max = -10000;
    int w, s;
    
    printf("�������һ������ʽ������:");
    scanf("%d", &n1);
    int i = 0;
    for (i = 0; i < 100; i++)
    {
        a[i] = 0;
        b[i] = 0;
    }
    for (i = 0; i < n1; i++)
    {
        printf("�������%d���ϵ����ָ��:", i + 1);
        scanf("%d %d", &s, &w);
        if (w >= max)
            max = w;
        a[w] = s;
    }
    printf("������ڶ�������ʽ������:");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
    {
        printf("�������%d���ϵ����ָ��:", i + 1);
        scanf("%d %d", &s, &w);
        if (w >= max)
            max = w;
        b[w] = s;
    }
    for (i = 0; i <= max; i++)
    {
        b[i] += a[i];
    }
    int j = 0;
    printf("�Ͷ���ʽ�ĸ���Ϊ��\n");
    for (i = 0; i <= max; i++)
    {
        if (b[i] != 0)
        {
            j++;
            printf("��%d��,ϵ��:%d:ָ��:%d", j, b[i], i);
            printf("\n");
        }
    }
    return 0;
}