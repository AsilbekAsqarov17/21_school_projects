#include <stdio.h>

int sum_numbers(const int *buffer, int length);
int find_numbers(const int *buffer, int length, int number, int *numbers);
void input(int *buffer, int *length, int *error);
void output(const int *buffer, int length, int sum);

int main(void) {
    int length = 0;
    int error = 0;

    int buffer[10];
    int result_buffer[10];

    input(buffer, &length, &error);


    if (error || length <= 0 || length > 10) {
        printf("n/a\n");
        return 0;
    }

    int sum = sum_numbers(buffer, length);

    if (sum == 0) {
        printf("n/a\n");
        return 0;
    }

    int result_length = find_numbers(buffer, length, sum, result_buffer);

    output(result_buffer, result_length, sum);

    return 0;
}

int sum_numbers(const int *buffer, int length) {
    int sum = 0;
    int has_even = 0;
    for (int i = 0; i < length; i++) {
        if (*(buffer + i) % 2 == 0) {
            sum += *(buffer + i);
            has_even = 1;
        }
    }
    return has_even ? sum : 0;
}

int find_numbers(const int *buffer, int length, int number, int *numbers) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        int current = *(buffer + i);
        if (current != 0 && number % current == 0) {
            *(numbers + count) = current;
            count++;
        }
    }
    return count;
}

void input(int *buffer, int *length, int *error) {
    if (scanf("%d", length) != 1 || *length <= 0 || *length > 10) {
        *error = 1;
        return;
    }
    for (int i = 0; i < *length; i++) {
        if (scanf("%d", (buffer + i)) != 1) {
            *error = 1;
            return;
        }
    }
}

void output(const int *buffer, int length, int sum) {
    printf("%d\n", sum);
    for (int i = 0; i < length; i++) {
        printf("%d", *(buffer + i));
        if (i < length - 1) {
            printf(" ");
        }
    }
    if (length > 0) {
        printf("\n");
    }
}
