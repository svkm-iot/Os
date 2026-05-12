#include<stdio.h>

int main()
{
    int f[20] = {0};
    int start, len, i;

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter length of file: ");
    scanf("%d", &len);

    // Check and allocate blocks
    for(i = start; i < start + len; i++)
    {
        if(f[i] == 0)
        {
            f[i] = 1;
            printf("Block %d allocated\n", i);
        }
        else
        {
            printf("Block %d already allocated\n", i);
        }
    }

    return 0;
}
