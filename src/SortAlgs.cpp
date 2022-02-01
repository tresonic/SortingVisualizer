#include "SortAlgs.h"

#include "ArrayManager.h"
#include <array>
#include <cstddef>

bool SortAlgs::is_sorted(ArrayManager& arrMan)
{
    for (size_t i = 1; i < arrMan.getSize(); i++) {
        if (arrMan.get(i - 1) > arrMan.get(i)) return false;
    }
    return true;
}

void SortAlgs::bubblesort(ArrayManager& arrMan)
{
    arrMan.start();

    bool sorted;
    size_t maxSortIdx = arrMan.getSize();

    do {
        sorted = true;
        for (size_t i = 1; i < maxSortIdx; i++) {
            if (arrMan.get(i) < arrMan.get(i - 1)) {
                arrMan.swap(i, i - 1);
                sorted = false;
            }
        }
        maxSortIdx--;
    } while (!sorted);
    arrMan.finish();
}

void SortAlgs::cocktail_shaker_sort(ArrayManager& arrMan)
{
    arrMan.start();
    bool sorted;
    size_t sortedMargin = 0;

    do {
        sorted = true;
        for (size_t i = sortedMargin + 1; i < arrMan.getSize() - sortedMargin; i++) {
            if (arrMan.get(i) < arrMan.get(i - 1)) {
                arrMan.swap(i, i - 1);
                sorted = false;
            }
        }
        for (size_t i = arrMan.getSize() - sortedMargin - 1; i > sortedMargin; i--) {
            if (arrMan.get(i) < arrMan.get(i - 1)) {
                arrMan.swap(i, i - 1);
                sorted = false;
            }
        }
        sortedMargin++;
    } while (!sorted);
    arrMan.finish();
}

void SortAlgs::bozosort(ArrayManager& arrMan)
{
    arrMan.start();
    while (!is_sorted(arrMan)) {
        arrMan.swap(std::rand() % arrMan.getSize(), std::rand() % arrMan.getSize());
    }
    arrMan.finish();
}

void SortAlgs::quicksort(ArrayManager& arrMan)
{
    arrMan.start();
    quicksort_recursive(arrMan, 0, arrMan.getSize() - 1);
    arrMan.finish();
}

void SortAlgs::quicksort_recursive(ArrayManager& arrMan, size_t lo, size_t hi)
{
    if (lo >= 0 && hi >= 0 && lo < hi) {
        size_t p = quicksort_partition(arrMan, lo, hi);
        quicksort_recursive(arrMan, lo, p);
        quicksort_recursive(arrMan, p + 1, hi);
    }
}

size_t SortAlgs::quicksort_partition(ArrayManager& arrMan, size_t lo, size_t hi)
{
    arr_type pivot = arrMan.get((lo + hi) / 2);

    size_t i = lo - 1;
    size_t j = hi + 1;

    while (true) {
        do {
            i++;
        } while (arrMan.get(i) < pivot);
        do {
            j--;
        } while (arrMan.get(j) > pivot);

        if (i >= j) return j;

        arrMan.swap(i, j);
    }
}
