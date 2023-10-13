#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t child1, child2, child3, child4;
    child1 = fork();
    if (child1 == 0)
    {
        printf("Child 1 PID: %d\n", getpid());
    }
    else if (child1 > 0)
    {
        child2 = fork();

        if (child2 == 0)
        {
            printf("Child 2 PID: %d\n", getpid());
        }
        else if (child2 > 0)
        {
            child3 = fork();

            if (child3 == 0)
            {
                printf("Child 3 PID: %d\n", getpid());

            }
            else if (child3 > 0)
            {
                child4 = fork();
                sleep(100);

                if (child4 == 0) {
                    printf("Child 4 PID: %d\n", getpid());
                }
                else if (child4 > 0) {
                    sleep(100);
                    // Wait for all children to complete
                    wait(NULL);
                    wait(NULL);
                    wait(NULL);
                    wait(NULL);
                    printf("All children have completed.\n");
                }
                else
                {
                    perror("fork");
                }
            }
            else
            {
                perror("fork");
            }
        }
        else
        {
            perror("fork");
        }
    }
    else
    {
        perror("fork");
    }

    return 0;
}
