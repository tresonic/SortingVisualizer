#include "ConfigWindow.h"

#include <imgui.h>
#include <thread>

#include "SortAlgs.h"

void ConfigWindow::showConfigWindow(bool isSorting)
{
    ImGuiWindowFlags winFlags;
    winFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize |
               ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar;
    ImGui::Begin("SortingVisualizerConfig", nullptr, winFlags);
    if (!isSorting) {
        ImGui::InputInt("Elements", &mNumElements);
        ImGui::InputInt("Delay", &mDelay);
        ImGui::Combo("Algorithm", &mSelectedSort, ALGO_NAMES, IM_ARRAYSIZE(ALGO_NAMES));
        mStartSort = ImGui::Button("Start");
    } else {
        mShouldStop = ImGui::Button("Skip");
    }
    ImGui::End();
}

void ConfigWindow::applyToArrayManager(ArrayManager& arrMan)
{
    if (arrMan.getSize() != mNumElements) arrMan.setSize(mNumElements);

    if (!arrMan.isSorting()) arrMan.setDelay(mDelay);

    if (mStartSort && !arrMan.isSorting()) {
        std::thread t{ALGO_FUNCS[mSelectedSort], std::ref(arrMan)};
        t.detach();
    }

    if (mShouldStop) {
        arrMan.setDelay(0);
    }
}