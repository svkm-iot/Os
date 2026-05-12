#include<stdio.h>

int main()
{
    int f[20] = {0};
    int index, n, block[20];
    int i;

    printf("Enter index block: ");
    scanf("%d", &index);

    if(f[index] == 1)
    {
        printf("Index block already allocated");
        return 0;
    }

    printf("Enter number of blocks needed: ");
    scanf("%d", &n);

    printf("Enter block numbers: ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &block[i]);
    }

    printf("\nAllocated Blocks are:\n");

    for(i = 0; i < n; i++)
    {
        if(f[block[i]] == 0)
        {
            f[block[i]] = 1;
            printf("%d -> %d\n", index, block[i]);
        }
        else
        {
            printf("Block %d already allocated\n", block[i]);
        }
    }

    return 0;
}
