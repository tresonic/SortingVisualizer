#pragma once

#include <functional>

class ArrayManager;

class SortAlgs {
public:
    static void bubblesort(ArrayManager& arrMan);
    static void cocktail_shaker_sort(ArrayManager& arrMan);
    static void insertion_sort(ArrayManager& arrMan);
    static void inplace_merge_sort(ArrayManager& arrMan);
    static void merge_sort(ArrayManager& arrMan);
    static void quicksort(ArrayManager& arrMan);
    static void bozosort(ArrayManager& arrMan);

    static bool is_sorted(ArrayManager& arrMan);

private:
    static void inplace_merge_sort_recursive(ArrayManager& arrMan, size_t lo, size_t hi);
    static void inplace_merge_sort_merge(ArrayManager& arrMan, size_t lo, size_t mid, size_t hi);
    static void merge_sort_recursive(ArrayManager& arrMan, size_t lo, size_t hi);
    static void merge_sort_merge(ArrayManager& arrMan, size_t lo, size_t mid, size_t hi);

    static void quicksort_recursive(ArrayManager& arrMan, size_t lo, size_t hi);
    static size_t quicksort_partition(ArrayManager& arrMan, size_t lo, size_t hi);
};

static const char* ALGO_NAMES[] = {"Bubblesort",     "Cocktail shaker sort",
                                   "Insertion sort", "Inplace merge sort",
                                   "Merge sort",     "Quicksort",
                                   "Bozosort"};

static const std::function<void(ArrayManager&)> ALGO_FUNCS[] = {
    SortAlgs::bubblesort,         SortAlgs::cocktail_shaker_sort, SortAlgs::insertion_sort,
    SortAlgs::inplace_merge_sort, SortAlgs::merge_sort,           SortAlgs::quicksort,
    SortAlgs::bozosort,
};