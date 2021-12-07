#include <stdio.h>
#include <stdlib.h>
#define min(a, b) (a <= b) ? a : b

int main()
{

    int N;
    int i, *bufA, *bufB, *bufC, *buf;
    scanf("%d", &N);
    bufA = (int*) malloc(N * sizeof(int));
    bufB = (int*) malloc(N * sizeof(int));
    bufC = (int*) malloc(N * sizeof(int));
    buf = (int*) malloc(N * sizeof(int));

    for (i = 0; i < N; i++)
    {
        scanf("%d", &bufA[i]);
        scanf("%d", &bufB[i]);
        scanf("%d", &bufC[i]);
    }
    
    buf[0] = bufA[0];
    if (N >= 2)
        buf[1] = min(bufA[0] + bufA[1], bufB[0]);

    if (N >= 3)
        buf[2] = min(bufC[0], min(buf[0] + bufB[1], buf[1] + bufA[2]));

    if (N >= 4)    
        for (i = 3; i < N; i++)
        {
            buf[i] = min(buf[i - 3] + bufC[i - 2], min(buf[i - 2] + bufB[i - 1], buf[i - 1] + bufA[i]));
            //printf("%d ", buf[i]);
        }
    
    printf("%d", buf[N - 1]);

    
    return 0;
}
