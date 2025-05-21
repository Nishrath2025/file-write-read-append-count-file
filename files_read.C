#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void writeToFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    printf("Enter text to write (end with ~ on a new line):\n");
    char ch;
    while ((ch = getchar()) != '~') {
        fputc(ch, fp);
    }

    fclose(fp);
    printf("Data written successfully.\n");
}

void readFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }

    char ch;
    printf("\n--- File Content ---\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

void appendToFile(const char *filename) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }

    printf("Enter text to append (end with ~ on a new line):\n");
    char ch;
    while ((ch = getchar()) != '~') {
        fputc(ch, fp);
    }

    fclose(fp);
    printf("Data appended successfully.\n");
}

void countFileContent(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }

    int chars = 0, words = 0, lines = 0;
    char ch, prev = ' ';
    while ((ch = fgetc(fp)) != EOF) {
        chars++;

        if (ch == '\n')
            lines++;

        if (isspace(ch) && !isspace(prev))
            words++;

        prev = ch;
    }

    fclose(fp);
    printf("\n--- File Statistics ---\n");
    printf("Characters: %d\n", chars);
    printf("Words     : %d\n", words);
    printf("Lines     : %d\n", lines);
}

int main() {
    const char *filename = "sample.txt";
    int choice;

    do {
        printf("\n===== File Operations Menu =====\n");
        printf("1. Write to file\n");
        printf("2. Read from file\n");
        printf("3. Append to file\n");
        printf("4. Count characters, words, lines\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1: writeToFile(filename); break;
            case 2: readFile(filename); break;
            case 3: appendToFile(filename); break;
            case 4: countFileContent(filename); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
