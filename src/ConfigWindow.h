#pragma once

#include "ArrayManager.h"

class ConfigWindow {
public:
    void showConfigWindow();
    void applyToArrayManager(ArrayManager& arrMan);

private:
    bool mStartSort;
    int mSelectedSort;
    int mDelay;
    int mNumElements;
};