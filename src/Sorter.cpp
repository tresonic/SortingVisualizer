#include "Sorter.h"

#include "ArrayManager.h"
#include <array>
#include <cstddef>

void Sorter::bubblesort(ArrayManager& arrMan)
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

void Sorter::cocktail_shaker_sort(ArrayManager& arrMan)
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
        for(size_t i = arrMan.getSize() - sortedMargin - 1; i>sortedMargin; i--) {
            if(arrMan.get(i) < arrMan.get(i-1)) {
                arrMan.swap(i, i - 1);
                sorted = false;
            }
        }
        sortedMargin++;
    } while (!sorted);
    arrMan.finish();
}

void Sorter::bozosort(ArrayManager& arrMan)
{
    arrMan.start();
    while (!is_sorted(arrMan)) {
        arrMan.swap(std::rand() % arrMan.getSize(), std::rand() % arrMan.getSize());
    }
    arrMan.finish();
}

bool Sorter::is_sorted(ArrayManager& arrMan)
{
    for (size_t i = 1; i < arrMan.getSize(); i++) {
        if (arrMan.get(i - 1) > arrMan.get(i)) return false;
    }
    return true;
}