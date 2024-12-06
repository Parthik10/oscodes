// Algorithm 1 Sequential/Contiguous algorithm

// 1: Find a sequence of contiguous blocks that are large enough to store the file (fileSize).
// 2: If a suitable sequence is found:
// 3: Allocate these contiguous blocks to the file.
// 4: 	Update the disk block status to 'occupied' for these blocks.
// 5: 	    Update file allocation table (FAT)
// to record the starting block and block count.6 : else : 7 : Indicate that the file cannot be allocated due to fragmentation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[20];
    int start;
    int size;
    int blocks[1000];
} File;
File files[100];
int disk[1000];
int file_count = 0;

int allocateSequential(char *name, int start, int size)
{
    for (int i = start; i < start + size; i++)
    {
        if (i >= 1000 || disk[i] == 1)
        {
            return 0;
        }
    }
    File file;
    strcpy(file.name, name);
    file.start = start;
    file.size = size;
    for (int i = start; i < start + size; i++)
    {
        disk[i] = 1;
        file.blocks[i - start] = i;
    }
    files[file_count++] = file;
    return 1;
}
void search(char *name)
{
    for (int i = 0; i < file_count; i++)
    {
        if (strcmp(files[i].name, name) == 0)
        {
            printf("File name:%s\n", name);
            printf("Start Block:%d\n", files[i].start);
            printf("Size:%d\n", files[i].size);
            printf("Blocks:");
            for (int j = 0; j < files[i].size; j++)
            {
                printf("%d", files[i].blocks[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("File not found\n");
}

int main()
{
    int F, start, size;
    char name[20];
    for (int i = 0; i < 1000; i++)
    {
        disk[i] = 0;
    }
    printf("Enter no. of files to store:");
    scanf("%d", &F);
    for (int i = 0; i < F; i++)
    {
        printf("Enter the name,start block and size:");
        scanf("%s%d%d", name, &start, &size);
        if (allocateSequential(name, start, size))
        {
            printf("\nFile allocated successfully.....\n");
        }
        else
        {
            printf("\nError. Check disk space....\n ");
        }
    }
    printf("Enter the name of file to be searched:");
    scanf("%s", name);
    search(name);
    return 0;
}
