#include <stdio.h>

#define MAX_LEN 100

int read_array(int *arr, int *len);
void print_array(const int *arr, int len);
int add(const int *A, int lenA, const int *B, int lenB, int *result, int *resLen);
int subtract(const int *A, int lenA, const int *B, int lenB, int *result, int *resLen);
int compare(const int *A, int lenA, const int *B, int lenB);

int main() {
    int A[MAX_LEN], B[MAX_LEN];
    int lenA = 0, lenB = 0;

    if (!read_array(A, &lenA) || lenA == 0) {
        printf("n/a\n");
        return 0;
    }

    if (!read_array(B, &lenB) || lenB == 0) {
        printf("n/a\n");
        return 0;
    }

    int sum[MAX_LEN + 1];
    int sumLen = 0;
    
    if (add(A, lenA, B, lenB, sum, &sumLen)) {
        print_array(sum, sumLen);
    } else {
        printf("n/a\n");
    }

    int diff[MAX_LEN];
    int diffLen = 0;

    if (subtract(A, lenA, B, lenB, diff, &diffLen)) {
        print_array(diff, diffLen);
    } else {
        printf("n/a\n");
    }

    return 0;
}

int read_array(int *arr, int *len) {
    int count = 0;
    int ch;
    
    while ((ch = getchar()) == ' ' || ch == '\n' || ch == '\r') {
    }
    
    if (ch == EOF) {
        return 0;
    }
    
    while (ch != '\n' && ch != '\r' && ch != EOF) {
        if (ch >= '0' && ch <= '9') {
            if (count >= MAX_LEN) {
                return 0;
            }
            *(arr + count) = ch - '0';
            count++;
        } else if (ch != ' ') {
            return 0;
        }
        
        ch = getchar();
    }
    
    *len = count;
    return (count > 0);
}

void print_array(const int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d", *(arr + i));
        if (i < len - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int compare(const int *A, int lenA, const int *B, int lenB) {
    if (lenA > lenB) return 1;
    if (lenA < lenB) return -1;
    
    for (int i = 0; i < lenA; i++) {
        if (*(A + i) > *(B + i)) return 1;
        if (*(A + i) < *(B + i)) return -1;
    }
    return 0;
}

int add(const int *A, int lenA, const int *B, int lenB, int *result, int *resLen) {
    int i = lenA - 1;
    int j = lenB - 1;
    int k = 0;
    int carry = 0;
    
    int temp[MAX_LEN + 1]; 

    while (i >= 0 || j >= 0 || carry > 0) {
        if (k >= MAX_LEN + 1) {
            return 0;
        }
        
        int sum = carry;
        if (i >= 0) {
            sum += *(A + i);
            i--;
        }
        if (j >= 0) {
            sum += *(B + j);
            j--;
        }
        
        temp[k] = sum % 10;
        carry = sum / 10;
        k++;
    }

    if (k > MAX_LEN) {
        return 0;
    }

    *resLen = k;
    for (int m = 0; m < k; m++) {
        *(result + m) = temp[k - 1 - m];
    }
    
    return 1;
}

int subtract(const int *A, int lenA, const int *B, int lenB, int *result, int *resLen) {
    if (compare(A, lenA, B, lenB) < 0) {
        return 0;
    }

    int i = lenA - 1;
    int j = lenB - 1;
    int k = 0;
    int borrow = 0;
    
    int temp[MAX_LEN];

    while (i >= 0) {
        int diff = *(A + i) - borrow;
        i--;

        if (j >= 0) {
            diff -= *(B + j);
            j--;
        }

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        temp[k] = diff;
        k++;
    }

    int nonZeroIndex = k - 1;
    while (nonZeroIndex > 0 && temp[nonZeroIndex] == 0) {
        nonZeroIndex--;
    }

    *resLen = nonZeroIndex + 1;

    for (int m = 0; m < *resLen; m++) {
        *(result + m) = temp[nonZeroIndex - m];
    }

    return 1;
}
