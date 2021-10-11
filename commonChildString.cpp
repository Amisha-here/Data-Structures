// Link to the question on hackerrank: https://www.hackerrank.com/challenges/common-child/problem

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Complete the commonChild function below.
int commonChild(char* s1, char* s2) {

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int** lcs = (int **)malloc(sizeof(int*) * (len1+1));
    for(int i = 0; i <= len1; i ++)
        lcs[i] = (int *)malloc(sizeof(int) * (len2 + 1));


    for(int i = 0; i <= len1; i++)
    {
        for(int j = 0; j <= len2; j++)
        {
            if(i == 0 || j == 0)
                lcs[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                lcs[i][j] = 1 + lcs[i-1][j-1];
            else
                lcs[i][j] = max(lcs[i-1][j] , lcs[i][j-1] );
        }
    }
    return lcs[len1][len2];

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s1 = readline();

    char* s2 = readline();

    int result = commonChild(s1, s2);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
