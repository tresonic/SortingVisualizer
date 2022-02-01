#include "ConfigWindow.h"

#include <thread>
#include <imgui.h>

#include "SortAlgs.h"

void ConfigWindow::showConfigWindow() {
    ImGui::Begin("SortingVisualizerConfig");
    ImGui::SliderInt("Elements", &mNumElements, 5, 500);
    ImGui::SliderInt("Delay", &mDelay, 0, 100);
    ImGui::ListBox("Algorithm", &mSelectedSort, ALGO_NAMES, IM_ARRAYSIZE(ALGO_NAMES));
    mStartSort = ImGui::Button("Start!");
    ImGui::End();
}

void ConfigWindow::applyToArrayManager(ArrayManager &arrMan) {
    if(arrMan.getSize() != mNumElements)
        arrMan.setSize(mNumElements);

    arrMan.setDelay(mDelay);

    if(mStartSort && !arrMan.isSorting()) {
        std::thread t{ALGO_FUNCS[mSelectedSort], std::ref(arrMan)};
        t.detach();
    }
}