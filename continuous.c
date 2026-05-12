#include<stdio.h>
#include<stdlib.h>

int main()
{
    int f[50] = {0};
    int st, len, i, ch;

    while(1)
    {
        int count = 0;

        printf("\nEnter starting block: ");
        scanf("%d", &st);

        printf("Enter length of file: ");
        scanf("%d", &len);

        // Check free blocks
        for(i = st; i < st + len; i++)
        {
            if(f[i] == 0)
            {
                count++;
            }
        }

        // Allocate file
        if(count == len)
        {
            printf("\nFile Allocated\n");

            for(i = st; i < st + len; i++)
            {
                f[i] = 1;
                printf("Block %d Allocated\n", i);
            }
        }
        else
        {
            printf("\nFile cannot be Allocated\n");
        }

        printf("\nEnter 1 for more file or 0 to exit: ");
        scanf("%d", &ch);

        if(ch == 0)
        {
            break;
        }
    }

    return 0;
}
