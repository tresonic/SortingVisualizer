include(FetchContent)

set(SFML_VERSION 2.5.1)
set(IMGUI_VERSION 1.87)
set(BUILD_SHARED_LIBS OFF)
set(BUILD_STATIC_LIBS ON)

set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 5fde1ca613b7c308b6155594e5d067b1a02f5179
)

FetchContent_Declare(
    imgui
    URL "https://github.com/ocornut/imgui/archive/v${IMGUI_VERSION}.zip"
)

FetchContent_Declare(
    imgui-sfml
    GIT_REPOSITORY https://github.com/eliasdaler/imgui-sfml.git
    GIT_TAG 29dbc25b5a4f3e7bde4a07472395071457a7d2ee
)

FetchContent_Declare(
    rtaudio
    GIT_REPOSITORY https://github.com/thestk/rtaudio.git
    GIT_TAG ac73fc8aad831cc4e5a91c12db77f884af3f6c61
)

# if(MSVC)
#     execute_process(
#         COMMAND ping www.google.com -n 2
#         ERROR_QUIET
#         RESULT_VARIABLE NO_CONNECTION
#     )
# else()
#     execute_process(
#         COMMAND ping www.google.com -c 2
#         ERROR_QUIET
#         RESULT_VARIABLE NO_CONNECTION
#     )
# endif()

# if(NOT NO_CONNECTION EQUAL 0)
#     set(FETCHCONTENT_FULLY_DISCONNECTED ON)
#     message(STATUS "Fetch offline mode: requires already populated _deps")
# else()
#     set(FETCHCONTENT_FULLY_DISCONNECTED OFF)
#     message(STATUS "Fetching third party libraries")
# endif()

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
