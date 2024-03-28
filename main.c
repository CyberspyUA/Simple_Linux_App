#include <stdio.h>
#include "source/filecopy.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    const char* sourceFileName = argv[1];
    const char* destinationFilename = argv[2];
    if (copyFile(sourceFileName, destinationFilename)) 
    {
        printf("File copied successfully.\n");
    } 
    else 
    {
        fprintf(stderr, "Error copying file.\n");
        return 1;
    }

    return 0;
}
