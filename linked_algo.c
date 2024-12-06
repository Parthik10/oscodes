// 1: Initialize `remainingSize` = fileSize.
// 2: Initialize `fileStartBlock` = NULL.
// 3: Initialize `currentBlock` = NULL.
// 	4: 	For each block in `diskBlocks[]` do:
// 	5: 	If the block is free:
// 	6: 	If `fileStartBlock` is NULL:
// 	7: 	Set `fileStartBlock` = current block.
// 	8: 	Set `currentBlock` = current block.
// 	9: 	Else
// 10: 	   Link `currentBlock` to the new block.
// 11.	Update `currentBlock` = new block.
// 12.	Mark the block as occupied.
// 13.	Decrement `remainingSize` by 1.
// 14.	End if
// 15.	If `remainingSize` == 0:
// 16.	Break the loop.
// 17.	End if
// 18.	End for
// 19.	If `remainingSize` > 0:
// 20.	Indicate that the file could not be allocated (insufficient free space).
// 21.	Else:
// 22.	Update the file allocation table (FAT) with the start block and the linked structure.
// 23.	Indicate successful allocation.

#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    int startBlock;
    int numBlocks;
    int blocks[100];
} File;

int main()
{
    int n;
    printf("Enter number of files: ");
    scanf("%d", &n);
    File files[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter file %d name: ", i + 1);
        scanf("%s", files[i].name);
        printf("Enter starting block of file %d: ", i + 1);
        scanf("%d", &files[i].startBlock);
        printf("Enter number of blocks in file %d: ", i + 1);
        scanf("%d", &files[i].numBlocks);
        printf("Enter blocks for file %d: ", i + 1);
        for (int j = 0; j < files[i].numBlocks; j++)
        {
            scanf("%d", &files[i].blocks[j]);
        }
    }
    char searchFile[20];
    printf("\nEnter the file name to be searched: ");
    scanf("%s", searchFile);
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(files[i].name, searchFile) == 0)
        {
            found = 1;
            printf("\nFile Name: %s\n", files[i].name);
            printf("Starting Block: %d\n", files[i].startBlock);
            printf("Number of Blocks: %d\n", files[i].numBlocks);
            printf("Blocks: ");
            for (int j = 0; j < files[i].numBlocks; j++)
            {
                printf("%d ", files[i].blocks[j]);
            }
            printf("\n");
            break;
        }
    }
    if (!found)
    {
        printf("\nFile %s not found!\n", searchFile);
    }
    return 0;
}
