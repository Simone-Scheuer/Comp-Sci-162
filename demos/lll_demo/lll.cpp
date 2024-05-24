#include "list.h"

int calculate_sum(node * head)
{
    if (!head)
        return 0;

    node * current {head};
    int sum {0};

    while (current != nullptr && sum <= 100)
