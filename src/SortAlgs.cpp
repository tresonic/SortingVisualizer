#include "SortAlgs.h"

#include <array>
#include <cstddef>

#include "ArrayManager.h"

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

void SortAlgs::insertion_sort(ArrayManager& arrMan)
{
    arrMan.start();
    for (size_t i = 1; i < arrMan.getSize(); i++) {
        for (size_t j = i; j > 0; j--) {
            if (arrMan.get(j - 1) > arrMan.get(j))
                arrMan.swap(j - 1, j);
            else
                break;
        }
    }
    arrMan.finish();
}

void SortAlgs::heapsort(ArrayManager& arrMan)
{
    arrMan.start();
    heapsort_heapify(arrMan);

    size_t end = arrMan.getSize() - 1;
    while (end > 0) {
        arrMan.swap(end, 0);
        end--;
        heapsort_sift_down(arrMan, 0, end);
    }
    arrMan.finish();
}

void SortAlgs::inplace_merge_sort(ArrayManager& arrMan)
{
    arrMan.start();
    inplace_merge_sort_recursive(arrMan, 0, arrMan.getSize() - 1);
    arrMan.finish();
}

void SortAlgs::merge_sort(ArrayManager& arrMan)
{
    arrMan.start();
    merge_sort_recursive(arrMan, 0, arrMan.getSize() - 1);
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

void SortAlgs::heapsort_heapify(ArrayManager& arrMan)
{
    auto i_parent = [](size_t i) { return (i - 1) / 2; };

    size_t start = i_parent(arrMan.getSize() - 1);
    while (start < arrMan.getSize()) {
        heapsort_sift_down(arrMan, start, arrMan.getSize() - 1);
        start--;
    }
}

void SortAlgs::heapsort_sift_down(ArrayManager& arrMan, size_t start, size_t end)
{
    auto i_left_child = [](size_t i) { return 2 * i + 1; };
    //auto i_right_child = [](size_t i) { return 2 * i + 2; };

    size_t root = start;

    while (i_left_child(root) <= end) {
        size_t child = i_left_child(root);
        size_t swap = root;

        if (arrMan.get(swap) < arrMan.get(child)) swap = child;
        if (child + 1 <= end && arrMan.get(swap) < arrMan.get(child + 1)) swap = child + 1;
        if(swap == root) {
            return;
        } else {
            arrMan.swap(root, swap);
            root = swap;
        }
    }
}

void SortAlgs::inplace_merge_sort_recursive(ArrayManager& arrMan, size_t lo, size_t hi)
{
    if (hi > lo) {
        size_t mid = lo + (hi - lo) / 2;
        inplace_merge_sort_recursive(arrMan, lo, mid);
        inplace_merge_sort_recursive(arrMan, mid + 1, hi);
        inplace_merge_sort_merge(arrMan, lo, mid, hi);
    }
}

void SortAlgs::inplace_merge_sort_merge(ArrayManager& arrMan, size_t lo, size_t mid, size_t hi)
{
    size_t mid2 = mid + 1;

    if (arrMan.get(mid) <= arrMan.get(mid2)) return;

    while (lo <= mid && mid2 <= hi) {
        if (arrMan.get(lo) <= arrMan.get(mid2)) {
            lo++;
        } else {
            arr_type val = arrMan.get(mid2);
            size_t idx = mid2;

            while (idx != lo) {
                arrMan.set(idx, arrMan.get(idx - 1));
                idx--;
            }
            arrMan.set(lo, val);

            lo++;
            mid++;
            mid2++;
        }
    }
}

void SortAlgs::merge_sort_recursive(ArrayManager& arrMan, size_t lo, size_t hi)
{
    if (hi > lo) {
        size_t mid = lo + (hi - lo) / 2;
        merge_sort_recursive(arrMan, lo, mid);
        merge_sort_recursive(arrMan, mid + 1, hi);
        merge_sort_merge(arrMan, lo, mid, hi);
    }
}

void SortAlgs::merge_sort_merge(ArrayManager& arrMan, size_t left, size_t mid, size_t right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    std::vector<arr_type> leftArray;
    std::vector<arr_type> rightArray;
    leftArray.resize(subArrayOne);
    rightArray.resize(subArrayTwo);

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (size_t i = 0; i < subArrayOne; i++)
        leftArray[i] = arrMan.get(left + i);
    for (size_t j = 0; j < subArrayTwo; j++)
        rightArray[j] = arrMan.get(mid + 1 + j);

    size_t indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    size_t indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arrMan.set(indexOfMergedArray, leftArray[indexOfSubArrayOne]);
            indexOfSubArrayOne++;
        } else {
            arrMan.set(indexOfMergedArray, rightArray[indexOfSubArrayTwo]);
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        arrMan.set(indexOfMergedArray, leftArray[indexOfSubArrayOne]);
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        arrMan.set(indexOfMergedArray, rightArray[indexOfSubArrayTwo]);
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void SortAlgs::quicksort_recursive(ArrayManager& arrMan, size_t lo, size_t hi)
{
    if (lo < hi) {
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
