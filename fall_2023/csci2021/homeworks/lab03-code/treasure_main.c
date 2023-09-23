#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treasure.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage: %s <mode> <treasure_file>\n", argv[0]);
        return 1;
    }

    char *file_mode = argv[1];
    char *file_name = argv[2];
    treasuremap_t *tmap;
    if (strcmp(file_mode, "-txt") == 0) {
        printf("Loading treasure map from text file '%s'\n", file_name);
        tmap = treasuremap_load_text(file_name);
    } else { // Assume binary file mode
        printf("Loading treasure map from binary file '%s'\n", file_name);
        tmap = treasuremap_load_binary(file_name);
    }

    if (tmap == NULL) {
        printf("Loading failed, bailing out\n");
        return 1;
    }

    printf("\n");
    treasuremap_print(tmap);

    printf("\n");
    printf("Deallocating map\n");
    treasuremap_free(tmap);

    return 0;
}

treasuremap_t *treasuremap_load_text(char *file_name) {
    printf("Reading map from text file '%s'\n", file_name);

    FILE *file_handle = fopen(file_name, "r");

    if (file_handle == NULL) {
        printf("Couldn't open file '%s', returning NULL\n", file_name);
        return NULL;
    }

    printf("Allocating map struct\n");

    treasuremap_t *tmap = malloc(sizeof(treasuremap_t)); // Use sizeof(treasuremap_t) here

    fscanf(file_handle, "%d %d", &tmap->height, &tmap->width);
    printf("Map is %d by %d\n", tmap->height, tmap->width);

    fscanf(file_handle, "%d", &tmap->ntreasures); // Fix the fscanf format specifier

    printf("%d treasures on the map\n", tmap->ntreasures);

    printf("Allocating array of treasure locations\n");

    tmap->locations = malloc(tmap->ntreasures * sizeof(treasureloc_t)); // Fix the allocation size

    printf("Reading treasures\n");

    for (int i = 0; i < tmap->ntreasures; i++) {
        fscanf(file_handle, "%d %d", &tmap->locations[i].row, &tmap->locations[i].col); // Read row and col
        char temp_description[100];
        fscanf(file_handle, "%s", temp_description);
        strcpy(tmap->locations[i].description, temp_description); // Copy description
        printf("Treasure at %d %d called '%s'\n",
            tmap->locations[i].row,
            tmap->locations[i].col,
            tmap->locations[i].description);
    }

    printf("Completed file, closing\n");
    fclose(file_handle);

    printf("Returning pointer to heap-allocated treasure_t\n");
    return tmap;
}

treasuremap_t *treasuremap_load_binary(char *file_name) {
    printf("Reading map from binary file '%s'\n", file_name);
    FILE *file_handle = fopen(file_name, "rb"); // Open in binary mode

    if (file_handle == NULL) {
        printf("Couldn't open file '%s', returning NULL\n", file_name);
        return NULL;
    }

    printf("Allocating map struct\n");

    treasuremap_t *tmap = malloc(sizeof(treasuremap_t)); // Use sizeof(treasuremap_t) here

    fread(&tmap->height, sizeof(int), 1, file_handle); // Fix the size and data type
    fread(&tmap->width, sizeof(int), 1, file_handle); // Fix the size and data type
    printf("Map is %d by %d\n", tmap->height, tmap->width);

    fread(&tmap->ntreasures, sizeof(int), 1, file_handle);
    printf("%d treasures on the map\n", tmap->ntreasures);

    printf("Allocating array of treasure locations\n");

    tmap->locations = malloc(tmap->ntreasures * sizeof(treasureloc_t)); // Fix the allocation size

    printf("Reading treasures\n");

    for (int i = 0; i < tmap->ntreasures; i++) {
        fread(&tmap->locations[i].row, sizeof(int), 1, file_handle); // Fix the size and data type
        fread(&tmap->locations[i].col, sizeof(int), 1, file_handle); // Fix the size and data type

        int description_len;
        fread(&description_len, sizeof(int), 1, file_handle); // Fix the size and data type

        fread(tmap->locations[i].description, sizeof(char), description_len, file_handle); // Fix the size
        tmap->locations[i].description[description_len] = '\0';
        printf("Treasure at %d %d called '%s'\n",
            tmap->locations[i].row,
            tmap->locations[i].col,
            tmap->locations[i].description);
    }

    printf("Completed file, closing\n");
    fclose(file_handle);

    printf("Returning pointer to heap-allocated treasure_t\n");
    return tmap;
}

void treasuremap_free(treasuremap_t *tmap) {
    free(tmap->locations);
    free(tmap); // Free the struct itself
    return;
}

void treasuremap_print(treasuremap_t *tm) {
    char printspace[128][128] = {};

    printf("==TREASURE MAP==\n");
    for (int i = 0; i < tm->height; i++) {
        int j;
        for (j = 0; j < tm->width; j++) {
            printspace[i][j] = '.';
        }
        printspace[i][j] = '\0';
    }

    for (int i = 0; i < tm->ntreasures; i++) {
        int row = tm->locations[i].row;
        int col = tm->locations[i].col;
        printspace[row][col] = 'A' + i;
    }

    for (int i = 0; i < tm->height; i++) {
        printf("%s\n", printspace[i]);
    }

    printf("================\n");

    for (int i = 0; i < tm->ntreasures; i++) {
        printf("%c: %s\n", 'A' + i, tm->locations[i].description);
    }

    return;
}
