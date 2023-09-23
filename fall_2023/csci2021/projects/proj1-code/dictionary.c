#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

dictionary_t *create_dictionary() {
    dictionary_t *dict = malloc(sizeof(dictionary_t));
    if (dict == NULL) {
        return NULL;
    }
    dict->root = NULL;
    dict->size = 0;
    return dict;
}



int dict_insert(dictionary_t *dict, const char *word) {
    // TODO Not yet implemented
    if (dict == NULL){
        *dict = ()
    }
    return 0;
}

int dict_find(const dictionary_t *dict, const char *query) {
    // TODO Not yet implemented
    return 0;
}

void dict_print(const dictionary_t *dict) {
    // TODO Not yet implemented
}

void dict_free(dictionary_t *dict) {
    // TODO Not yet implemented
}

dictionary_t *read_dict_from_text_file(const char *file_name) {
    // TODO Not yet implemented
    return NULL;
}

int write_dict_to_text_file(const dictionary_t *dict, const char *file_name) {
    // TODO Not yet implemented
    return 0;
}
