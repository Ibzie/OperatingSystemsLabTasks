#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>

using namespace std;

int main() {
    int fd;
    bool isWriter = false;

    while (1) {
        if (isWriter) {
            fd = open("/home/ibz/Desktop/PIPE1", O_WRONLY);
            char buf[100];
            cout << "Enter to write: ";
            cin.getline(buf, sizeof(buf));
            // Writing to the pipe
            write(fd, buf, strlen(buf) + 1);
            close(fd);
        } else {
            fd = open("/home/ibz/Desktop/PIPE1", O_RDONLY);
            char buf[100];
            // Reading from the pipe
            read(fd, buf, sizeof(buf));
            cout << "Received: " << buf << endl;
            close(fd);
        }

        isWriter = !isWriter; // Toggle between writer and reader
    }
}
