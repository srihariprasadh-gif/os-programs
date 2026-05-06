#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int src, dest;
    char buffer[100];
    int bytes;

    // Open source file (same directory)
    src = open("Source.txt", O_RDONLY);

    if (src < 0) {
        perror("Error opening source file");
        return 1;
    }

    // Create destination file
    dest = open("Dest.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (dest < 0) {
        perror("Error creating destination file");
        return 1;
    }

    // Copy content
    while ((bytes = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }

    close(src);
    close(dest);

    printf("File copied successfully!\n");

    return 0;
}


