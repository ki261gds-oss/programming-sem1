#include <stdio.h>


void reverse_word(char str[], int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[101];

    printf("write a string:\n");
    fgets(str, sizeof(str), stdin);

    
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }

    
    i = 0;
    int start = -1;

    while (str[i] != '\0') {
        if (str[i] != ' ' && start == -1) {
            start = i; 
        }

        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0')) {
            int end = i; 
            reverse_word(str, start, end); 
            start = -1; 
        }

        i++;
    }

    
    printf("result: %s\n", str);

    return 0;
}