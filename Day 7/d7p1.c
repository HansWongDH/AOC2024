// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_LINE_LENGTH 1024
// #define MAX_NUMBERS 100

// typedef struct {
//     long key;
//     long numbers[MAX_NUMBERS];
//     int num_count;
// } KeyData;

// typedef struct Node {
//     KeyData data;
//     struct Node* next;
// } Node;

// int parse_line(const char *line, KeyData *data) {
//     char *token;
//     char *endptr;
//     char line_copy[MAX_LINE_LENGTH];
//     strcpy(line_copy, line);

//     token = strtok(line_copy, ":");
//     if (token == NULL) {
//         return 0;
//     }
//     data->key = strtol(token, &endptr, 10);

//     token = strtok(NULL, " ");
//     data->num_count = 0;
//     while (token != NULL && data->num_count < MAX_NUMBERS) {
//         data->numbers[data->num_count] = strtol(token, &endptr, 10);
//         data->num_count++;
//         token = strtok(NULL, " ");
//     }

//     return 1;
// }

// Node* create_node(KeyData data) {
//     Node* new_node = (Node*)malloc(sizeof(Node));
//     new_node->data = data;
//     new_node->next = NULL;
//     return new_node;
// }

// void insert_node(Node** head, KeyData data) {
//     Node* new_node = create_node(data);
//     new_node->next = *head;
//     *head = new_node;
// }

// void print_list(Node* head) {
//     Node* current = head;
//     while (current != NULL) {
//         printf("Key: %ld\n", current->data.key);
//         printf("Numbers: ");
//         for (int i = 0; i < current->data.num_count; i++) {
//             printf("%ld ", current->data.numbers[i]);
//         }
//         printf("\n");
//         current = current->next;
//     }
// }

// void free_list(Node* head) {
//     Node* current = head;
//     while (current != NULL) {
//         Node* temp = current;
//         current = current->next;
//         free(temp);
//     }
// }

// int main() {
//     FILE *file = fopen("day7.txt", "r");
//     if (file == NULL) {
//         fprintf(stderr, "Error opening file\n");
//         return 1;
//     }

//     char line[MAX_LINE_LENGTH];
//     KeyData data;
//     Node* head = NULL;
//     int line_count = 0;

//     while (fgets(line, sizeof(line), file)) {
//         line[strcspn(line, "\n")] = '\0';

//         if (parse_line(line, &data)) {
//             insert_node(&head, data);
//             line_count++;
//         }
//     }

//     fclose(file);

//     printf("Parsed %d lines:\n", line_count);
//     print_list(head);

//     free_list(head);

//     return 0;
// }
