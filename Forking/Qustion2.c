#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    float a, b, c, d, e, f, h;
    printf("Enter the values of a, b, c, d, e, f, h: ");
    scanf("%f %f %f %f %f %f %f", &a, &b, &c, &d, &e, &f, &h);

    int child1_result, child2_result, child3_result;
    int status1, status2, status3;

    // Child 1: a * b
    if (fork() == 0) {
        child1_result = a + b;
        printf("Child 1 Result: %d\n", child1_result);
        _exit(0);
    }

    // Child 2: c / d
    if (fork() == 0) {
        child2_result = c - d;
        printf("Child 2 Result: %d\n", child2_result);
        _exit(0);
    }

    wait(&status1);
    wait(&status2);

    child3_result = e/f *h;
    printf("Child 3 Result: %d\n", child3_result);

    // Calculate the final result
    int x = WEXITSTATUS(status1) * WEXITSTATUS(status2) * child3_result;

    printf("Result: x = %d\n", x);

    return 0;
}
