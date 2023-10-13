#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t child1, child2, child3, child4, child5, child6;
    child1 = fork();
    //C1
    if (child1 == 0)
    {
        printf("Child 1 PID: %d\n", getpid());
        child5 = fork();
        if (child5==0)
        {
            printf("Child 5 PID: %d\n", getpid());
        }
        else if(child5 >0)
        {
            printf("Parent of Child 5 PID: %d\n", getpid());
        }
    }
        //P1
    else if (child1 > 0) {
        child2 = fork();
        //C2
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
            else if (child3 >0)
            {
                child4 = fork();

                if (child4 == 0) {
                    printf("Child 4 PID: %d\n", getpid());
                }
                else if (child4 > 0) {
                    printf("All children have completed.\n");
                }
            }
        }

    }
    else
    {
        perror("fork");
    }

    return 0;
}

