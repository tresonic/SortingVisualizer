find_package(Threads REQUIRED)


add_executable(sortviz
    main.cpp
    ArrayManager.cpp
    SortAlgs.cpp
    Sine.cpp
    ConfigWindow.cpp
)

target_link_libraries(sortviz
    PUBLIC
    ImGui-SFML::ImGui-SFML
    rtaudio
    Threads::Threads
)

target_compile_options(sortviz PRIVATE
     $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
          -Wall>
     $<$<CXX_COMPILER_ID:MSVC>:
          /W4>)
