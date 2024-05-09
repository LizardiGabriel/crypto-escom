#include <stdio.h>
#include <stdlib.h>
#include <openssl/rand.h>
#define KEY_SIZE 32
#define FILENAME "key.txt"


void save_key_to_file(char *key);

int main() {
    unsigned char key[KEY_SIZE];

    if (RAND_bytes(key, KEY_SIZE) != 1) {
        perror("Error generating random bytes");
        return 1;
    }

    save_key_to_file(key);

    return 0;
}



void save_key_to_file(char *key) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        fprintf(stderr, "[Error] The file cannot be open.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s", key);
    fclose(file);
    printf("Key saved in: %s\n", FILENAME);
}
