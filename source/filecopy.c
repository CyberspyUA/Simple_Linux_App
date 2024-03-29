#include "filecopy.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

const int bufferSize = 10000;
bool copyFile(const char* sourceFileName, const char* destinationFileName){
    int sourceFolder, destinationFolder;
    off_t offset = 0;
    char buffer[bufferSize];
    ssize_t bytesRead, bytesWritten;
    struct stat statisticsSource;

    // Open source file
    sourceFolder = open(sourceFileName, O_RDONLY);
    if (sourceFolder == -1) {
        perror("Error opening source file");
        return false;
    }

    // Get source file stats
    if (fstat(sourceFolder, &statisticsSource) == -1) {
        perror("Error getting source file stats");
        close(sourceFolder);
        return false;
    }

    // Open destination file
    destinationFolder = open(destinationFileName, O_WRONLY | O_CREAT | O_TRUNC, statisticsSource.st_mode);
    if (destinationFolder == -1) {
        perror("Error opening destination file");
        close(sourceFolder);
        return false;
    }

    // Copy file using standard I/O functions
    while ((bytesRead = read(sourceFolder, &buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(destinationFolder, &buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            perror("Error writing to destination file");
            close(sourceFolder);
            close(destinationFolder);
            return false;
        }
    }

    // Close files
    close(sourceFolder);
    close(destinationFolder);

    return true; // Copying successful
}