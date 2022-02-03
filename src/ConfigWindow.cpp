#include "ConfigWindow.h"

#include <imgui.h>
#include <thread>

#include "SortAlgs.h"

void ConfigWindow::showConfigWindow()
{
    ImGuiWindowFlags winFlags;
    winFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize |
               ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar;
    ImGui::Begin("SortingVisualizerConfig", nullptr, winFlags);
    ImGui::InputInt("Elements", &mNumElements);
    ImGui::InputInt("Delay", &mDelay);
    ImGui::Combo("Algorithm", &mSelectedSort, ALGO_NAMES, IM_ARRAYSIZE(ALGO_NAMES));
    mStartSort = ImGui::Button("Start");
    ImGui::End();
}

void ConfigWindow::applyToArrayManager(ArrayManager& arrMan)
{
    if (arrMan.getSize() != mNumElements) arrMan.setSize(mNumElements);

    arrMan.setDelay(mDelay);

    if (mStartSort && !arrMan.isSorting()) {
        std::thread t{ALGO_FUNCS[mSelectedSort], std::ref(arrMan)};
        t.detach();
    }
}