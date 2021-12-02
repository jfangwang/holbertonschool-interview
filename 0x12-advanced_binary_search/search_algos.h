#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H
#include <stdlib.h>

int advanced_binary(int *array, size_t size, int value);
int recurse(int *array, int left, int right, int value);
void print_list(int *array, int left, int right);

#endif /* SEARCH_ALGOS_H */
