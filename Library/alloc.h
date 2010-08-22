#include <cstdlib.h>
#include <cstdio.h>
#include <ctype.h>

void *emalloc(size_t size) {
    void *ptr= malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void *erealloc(void *ptr, size_t size) {
    ptr = realloc(ptr, size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

