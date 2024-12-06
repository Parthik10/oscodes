// 1: Initialize `remainingSize` = fileSize.
// 2: Initialize `indexBlock` = NULL.
// 3: Initialize `allocatedBlocks[]` = empty list.
// 	4: 	Allocate the index block.
// 	5: 	For each block in `diskBlocks[]` do:
// 	6: 	If the block is free:
// 	7: 	Set `indexBlock` = current block.
// 	8:    	Mark the block as occupied.
// 	9: 	Break the loop.
//    10: 	   end if
// 11.	end for
// 12.	If `indexBlock` == NULL:
// 13.	Indicate that the file cannot be allocated (no free blocks for index block).
// 14.	Exit
// 15.	Allocate data blocks for the file.
// 16.	For each block in `diskBlocks[]` do:
// 17.	If the block is free and `remainingSize > 0`:
// 18.	Add the block address to `allocatedBlocks[]`.
// 19.	Mark the block as occupied.
// 20.	Decrement `remainingSize` by 1.
// 21.	End if
// 22.	If `remainingSize` == 0:
// 23.	Break the loop.
// 24.	end if
// 25.	end for
// 26.	Check for successful allocation.
// 27.	If `remainingSize > 0`:
// 28.	Indicate that the file cannot be fully allocated (insufficient free space).
// 29.	Release the allocated blocks and reset `indexBlock`.
// 30.	else:
// 31.	Update the index block to store the addresses in `allocatedBlocks[]`.
// 32.	Indicate successful allocation.


#include <stdio.h>
#include <string.h>

// Structure to store file details
typedef struct {
    char name[20];       // File name
    int indexBlock;      // Index block number
    int numBlocks;       // Number of blocks
    int blocks[100];     // Block numbers
} File;

int main() {
    int n;
    printf("Enter the number of files: ");
    scanf("%d", &n);

    File files[n];

    // Input file details
    for (int i = 0; i < n; i++) {
        printf("\nFile %d Name: ", i + 1);
        scanf("%s", files[i].name);
        printf("Index Block: ");
        scanf("%d", &files[i].indexBlock);
        printf("Number of Blocks: ");
        scanf("%d", &files[i].numBlocks);
        printf("Blocks: ");
        for (int j = 0; j < files[i].numBlocks; j++) {
            scanf("%d", &files[i].blocks[j]);
        }
    }

    // Search for a file
    char searchName[20];
    printf("\nEnter the file name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(files[i].name, searchName) == 0) {  // File found
            found = 1;
            printf("\nFile Name: %s\n", files[i].name);
            printf("Index Block: %d\n", files[i].indexBlock);
            printf("Number of Blocks: %d\n", files[i].numBlocks);
            printf("Blocks: ");
            for (int j = 0; j < files[i].numBlocks; j++) {
                printf("%d ", files[i].blocks[j]);
            }
            printf("\n");
            break;
        }
    }

    // If not found
    if (!found) {
        printf("\nFile '%s' not found!\n", searchName);
    }

    return 0;
}
