#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100], b[100];
    int n1, n2, max = -10000;
    int w, s;
    
    printf("请输入第一个多项式的项数:");
    scanf("%d", &n1);
    int i = 0;
    for (i = 0; i < 100; i++)
    {
        a[i] = 0;
        b[i] = 0;
    }
    for (i = 0; i < n1; i++)
    {
        printf("请输入第%d项的系数和指数:", i + 1);
        scanf("%d %d", &s, &w);
        if (w >= max)
            max = w;
        a[w] = s;
    }
    printf("请输入第二个多项式的项数:");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
    {
        printf("请输入第%d项的系数和指数:", i + 1);
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
    printf("和多项式的各项为：\n");
    for (i = 0; i <= max; i++)
    {
        if (b[i] != 0)
        {
            j++;
            printf("第%d项,系数:%d:指数:%d", j, b[i], i);
            printf("\n");
        }
    }
    return 0;
}