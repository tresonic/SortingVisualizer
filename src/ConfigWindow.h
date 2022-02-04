#pragma once

#include "ArrayManager.h"

const int MIN_DELAY = 0;
const int MAX_DELAY = 100;
const int MIN_ELEMENTS = 5;
const int MAX_ELEMENTS = 500;

class ConfigWindow {
public:
    void showConfigWindow(bool isSorting);
    void applyToArrayManager(ArrayManager& arrMan);

private:
    bool mStartSort;
    bool mShouldStop = false;
    int mSelectedSort = 0;
    int mDelay = 10;
    int mNumElements = 20;
};