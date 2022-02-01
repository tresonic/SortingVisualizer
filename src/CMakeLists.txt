add_executable(sortviz
  main.cpp
  ArrayManager.cpp
)

# Yep, that's it!
target_link_libraries(sortviz
  PUBLIC
    ImGui-SFML::ImGui-SFML
)

#include(Install.cmake)
