#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    int pipe_pc[2]; // Pipe for parent to child
    int pipe_cp[2]; // Pipe for child to parent
    char message[BUFFER_SIZE];

    pipe(pipe_pc);
    pipe(pipe_cp);

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        close(pipe_pc[1]); // Close write end of parent to child pipe
        close(pipe_cp[0]); // Close read end of child to parent pipe

        while (1) {
            // Read from parent through the pipe
            read(pipe_pc[0], message, BUFFER_SIZE);
            printf("Child received: %s\n", message);

            printf("Child: Enter a message (or 'exit' to quit): ");
            read(STDIN_FILENO, message, BUFFER_SIZE); // Read from standard input
            message[strlen(message) - 1] = '\0'; // Remove trailing newline

            if (strcmp(message, "exit") == 0) {
                break;
            }

            // Write to parent through the pipe
            write(pipe_cp[1], message, strlen(message) + 1);
        }

        close(pipe_pc[0]);
        close(pipe_cp[1]);
    } else {
        // Parent process
        close(pipe_pc[0]); // Close read end of parent to child pipe
        close(pipe_cp[1]); // Close write end of child to parent pipe

        while (1) {
            printf("Parent: Enter a message (or 'exit' to quit): ");
            read(STDIN_FILENO, message, BUFFER_SIZE); // Read from standard input
            message[strlen(message) - 1] = '\0'; // Remove trailing newline

            if (strcmp(message, "exit") == 0) {
                break;
            }

            // Write to child through the pipe
            write(pipe_pc[1], message, strlen(message) + 1);

            // Read from child through the pipe
            read(pipe_cp[0], message, BUFFER_SIZE);
            printf("Parent received: %s\n", message);
        }

        close(pipe_pc[1]);
        close(pipe_cp[0]);
    }

    return 0;
}