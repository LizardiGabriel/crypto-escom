#include <stdio.h>
#include <stdlib.h>
#include <openssl/rand.h>
#define KEY_SIZE 32
#define FILENAME "key.txt"


void save_key_to_file(unsigned int *key);

int main() {
    unsigned int *key = malloc(4 * sizeof(unsigned int));
    if (!key) {
        fprintf(stderr, "[Error] Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < 4; i++) {
        RAND_bytes((unsigned char *)&key[i], sizeof(unsigned int));
    }




    save_key_to_file(key);

    return 0;
}



void save_key_to_file(unsigned int *key) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        fprintf(stderr, "[Error] The file cannot be open.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 4; i++) {
        fprintf(file, "%08X", key[i]);
    }

    fclose(file);
    printf("Key saved in: %s\n", FILENAME);
}
