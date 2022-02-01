#pragma once

class ArrayManager;
class Sorter {
public:
    static void bubblesort(ArrayManager& arrMan);
    static void cocktail_shaker_sort(ArrayManager& arrMan);
    static void quicksort(ArrayManager& arrMan);
    static void bozosort(ArrayManager& arrMan);

    static bool is_sorted(ArrayManager& arrMan);
};