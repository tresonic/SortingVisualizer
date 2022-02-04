include(FetchContent)

set(SFML_VERSION 2.5.1)
set(IMGUI_VERSION 1.86)
set(IMGUI_SFML_VERSION 2.5)
set(BUILD_SHARED_LIBS OFF)
set(BUILD_STATIC_LIBS ON)

if(MSVC)
    execute_process(
        COMMAND ping www.google.com -n 2
        ERROR_QUIET
        RESULT_VARIABLE NO_CONNECTION
    )
else()
    execute_process(
        COMMAND ping www.google.com -c 2
        ERROR_QUIET
        RESULT_VARIABLE NO_CONNECTION
    )
endif()

if(NOT NO_CONNECTION EQUAL 0)
    set(FETCHCONTENT_FULLY_DISCONNECTED ON)
    message(STATUS "Fetch offline mode: requires already populated _deps")
else()
    set(FETCHCONTENT_FULLY_DISCONNECTED OFF)
    message(STATUS "Fetching third party libraries")
endif()


FetchContent_Declare(
  SFML
  GIT_REPOSITORY "https://github.com/SFML/SFML.git"
)

FetchContent_Declare(
  imgui
  URL "https://github.com/ocornut/imgui/archive/v${IMGUI_VERSION}.zip"
)

# Or by tag...
FetchContent_Declare(
  imgui-sfml
  GIT_REPOSITORY https://github.com/eliasdaler/imgui-sfml.git
  # GIT_COMMIT 5f54b69b6aee18db846c81633f86f78c2586dded
  # ^ or like this - sometimes it's better because FetchContent won't look
  # into remote to see if branch head was updated or not - good for stable
  # tags like 'vX.X' corresponding to releases
)

FetchContent_Declare(
    rtaudio
    GIT_REPOSITORY https://github.com/thestk/rtaudio.git
)

## finally, let's build

# SFML
option(SFML_BUILD_AUDIO "Build audio" OFF)
option(SFML_BUILD_NETWORK "Build network" OFF)
FetchContent_MakeAvailable(sfml)

# Dear ImGui
FetchContent_MakeAvailable(imgui)

# ImGui-SFML
set(IMGUI_DIR ${imgui_SOURCE_DIR})
option(IMGUI_SFML_FIND_SFML "Use find_package to find SFML" OFF)
option(IMGUI_SFML_IMGUI_DEMO "Build imgui_demo.cpp" OFF)

FetchContent_MakeAvailable(imgui-sfml)

option(RTAUDIO_STATIC_MSVCRT OFF)
FetchContent_MakeAvailable(rtaudio)