#pragma once

#include <functional>

class ArrayManager;

class SortAlgs {
public:
    static void bubblesort(ArrayManager& arrMan);
    static void cocktail_shaker_sort(ArrayManager& arrMan);
    static void quicksort(ArrayManager& arrMan);
    static void bozosort(ArrayManager& arrMan);

    static bool is_sorted(ArrayManager& arrMan);
private:
    static void quicksort_recursive(ArrayManager& arrMan, size_t lo, size_t hi);
    static size_t quicksort_partition(ArrayManager& arrMan, size_t lo, size_t hi);
};

static const char* ALGO_NAMES[] = {"Bubblesort", "Cocktail shaker sort", "Quicksort", "Bozosort"};

static const std::function<void(ArrayManager&)> ALGO_FUNCS[] = {
    SortAlgs::bubblesort,
    SortAlgs::cocktail_shaker_sort,
    SortAlgs::quicksort,
    SortAlgs::bozosort,
};