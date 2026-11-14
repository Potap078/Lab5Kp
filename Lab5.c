#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Task 51
void task51()
{
    int a[100];
    int n, i;

    printf("\nTask 51\n");
    printf("Enter kilkist elementiv masyvu: ");
    scanf("%d", &n);

    if (n < 2 || n > 100) {
        printf("Error!\n");
        return;
    }

    printf("Enter A[0]: ");
    scanf("%d", &a[0]);

    if (a[0] == 0) {
        printf("Chislo ne maye buty nulem!\n");
        return;
    }

    for (i = 1; i < n; i++) {
        a[i] = a[i / 2] + a[i - 1];
    }

    printf("Masyv:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


// Task 58
void task58()
{
    int x[10], y[10], c[20];
    int i = 0, j = 0, k = 0;

    printf("\nTask 58\n");
    printf("Enter pershyi vporyadkovanyi masyv:\n");

    for (i = 0; i < 10; i++) {
        scanf("%d", &x[i]);
    }

    printf("Enter drugyi vporyadkovanyi masyv:\n");

    for (i = 0; i < 10; i++) {
        scanf("%d", &y[i]);
    }

    i = 0;

    // unite two masyvy
    while (i < 10 && j < 10) {
        if (x[i] < y[j]) {
            c[k] = x[i];
            i++;
        }
        else {
            c[k] = y[j];
            j++;
        }
        k++;
    }

    while (i < 10) {
        c[k] = x[i];
        i++;
        k++;
    }

    while (j < 10) {
        c[k] = y[j];
        j++;
        k++;
    }

    printf("Result:\n");

    for (i = 0; i < 20; i++) {
        printf("%d ", c[i]);
    }

    printf("\n");
}


// Task 77
void task77()
{
    int num, pos = 0;
    int first = 0;

    printf("\nTask 77\n");
    printf("Enter chysla (-1 dlya zavershennya):\n");

    while (1) {
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        pos++;

        if (first == 0 && num % 7 == 0) {
            first = pos;
        }
    }

    if (first != 0) {
        printf("Pershe chyslo, kratne 7, znakhodytsya na pozytsiyi %d\n", first);
    }
    else {
        printf("Chysel, kratnykh 7, nemaye.\n");
    }
}


// Task 114
void task114()
{
    int a[50];
    int n, k, i, value;

    printf("\nTask 114\n");
    printf("Enter kilkist elementiv: ");
    scanf("%d", &n);

    if (n < 10 || n > 49) {
        printf("Nepravylnyi rozmir masyvu!\n");
        return;
    }

    printf("Enter elementy masyvu:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter pozytsiyu dlya vstavky: ");
    scanf("%d", &k);

    if (k < 1 || k > n + 1) {
        printf("Neravylna pozytsiya!\n");
        return;
    }

    value = (a[4] + a[9]) * (a[4] + a[9]);

    // Shift the elements right
    for (i = n; i >= k; i--) {
        a[i] = a[i - 1];
    }

    a[k - 1] = value;
    n++;

    printf("Masyv pislya vstavky:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
}


// Task 175
void task175()
{
    int a[30];
    int n, i, max_diff, delta;

    printf("\nTask 175\n");
    printf("Enter kilkist elementiv: ");
    scanf("%d", &n);

    if (n < 2 || n > 30) {
        printf("Nepravylnyi rozmir!\n");
        return;
    }

    a[0] = 50 + rand() % 101;

    for (i = 1; i < n; i++) {
        max_diff = (int)(a[i - 1] * 0.1 + 0.5);

        if (max_diff < 1) {
            max_diff = 1;
        }

        delta = rand() % (2 * max_diff + 1) - max_diff;
        a[i] = a[i - 1] + delta;

        if (a[i] < 1) {
            a[i] = 1;
        }
    }

    printf("Zhenerovanyi masyv:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    printf("Riznytsya mizh susidnimy elementamy:\n");

    for (i = 1; i < n; i++) {
        double p = fabs((double)(a[i] - a[i - 1]) / a[i - 1]) * 100;
        printf("%.1f%% ", p);
    }

    printf("\n");
}


// Task 66
void task66()
{
    int a[50];
    int n, i, count = 0;
    long long dob = 1;

    printf("\nTask 66\n");
    printf("Enter kilkist elementiv: ");
    scanf("%d", &n);

    if (n < 1 || n > 50) {
        printf("Nepravylnyi rozmir!\n");
        return;
    }

    printf("Enter elementy masyvu:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        if (a[i] < 0) {
            dob *= a[i];
            count++;
        }
    }

    if (count == 0) {
        printf("Nema elementiv < 0.\n");
    }
    else {
        printf("Dobutok elementiv < 0: %lld\n", dob);
    }
}


// maib funktion
int main()
{
    int choice;

    srand(time(NULL));

    do {
        printf("\n========== Menyu ==========\n");
        printf("1 - Task 51\n");
        printf("2 - Task 58\n");
        printf("3 - Task 77\n");
        printf("4 - Task 114\n");
        printf("5 - Task 175\n");
        printf("6 - Task 66\n");
        printf("0 - Exit\n");
        printf("Vash vybir: ");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            task51();
            break;
        case 2:
            task58();
            break;
        case 3:
            task77();
            break;
        case 4:
            task114();
            break;
        case 5:
            task175();
            break;
        case 6:
            task66();
            break;
        case 0:
            printf("Kinec progtamy.\n");
            break;
        default:
            printf("Nepravylnyi vybir!\n");
        }

    } while (choice != 0);

    return 0;
}