#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

typedef struct {
    unsigned long long key;
    unsigned long long numbers[500];
    int num_count;
} KeyData;

unsigned long long concat(unsigned long long num1, unsigned long long num2) {
    unsigned long long temp = num2;
    int digits = 0;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    unsigned long long power_of_ten = 1;
    for (int i = 0; i < digits; i++) {
        power_of_ten *= 10;
    }

    unsigned long long result = num1 * power_of_ten + num2;

    return result;
}


int parse_line(const char *line, KeyData *data) {
    char *token;
    char *endptr;
    char line_copy[1000];
    strcpy(line_copy, line);

    token = strtok(line_copy, ":");
    if (token == NULL) {
        return 0;
    }
    data->key = strtol(token, &endptr, 10);

    token = strtok(NULL, " ");
    data->num_count = 0;
    while (token != NULL && data->num_count < 500) {
        data->numbers[data->num_count] = strtol(token, &endptr, 10);
        data->num_count++;
        token = strtok(NULL, " ");
    }

    return 1;
}
bool ruleCheck(KeyData data, int size, unsigned long long  currentvalue, int index) {
    // printf("%lld\n", currentvalue);
    if (index == size) {
        return currentvalue == data.key;
    }
        
    unsigned long long  nextvalue = data.numbers[index];

    if (ruleCheck(data, size, currentvalue + nextvalue, index + 1)){
        return true;
    }
    if (ruleCheck(data, size, currentvalue * nextvalue, index + 1)){
        return true;
    }
    if (ruleCheck(data, size, concat(currentvalue, nextvalue), index + 1)) {
        return true;
    }
    return false;
}

void printNumb(KeyData data) {
    int i = 0;
    while (i < data.num_count) {
        printf(" %lld", data.numbers[i]);
        i++;
    }
    printf("\n");
}

int main() {
    FILE *file = fopen("day7.txt", "r");
    if (file == NULL) {
        return 1;
    }

    char *line = calloc(1, 1);
    size_t len = 0;     
    size_t read; 
    KeyData data;
    KeyData *de = malloc(1200 * sizeof(KeyData));
    int line_count = 0;


    while ((read = getline(&line, &len, file)) != -1) {
        if (parse_line(line, &data)) {
            if (line_count < 1200) {
                de[line_count] = data;
                line_count++;
            }
        }
    }
    
    free(line); 
    fclose(file);
    unsigned long long count = 0;
    int i = 0;
    while(i < line_count) {
        if (ruleCheck(de[i], de[i].num_count, de[i].numbers[0], 1)) {
            count += de[i].key;
        }
        i++;
    }
    printf("%lld\n", count);

    return 0;
}

