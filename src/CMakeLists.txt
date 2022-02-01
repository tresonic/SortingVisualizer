SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable(sortviz
  main.cpp
  ArrayManager.cpp
  Sorter.cpp
  Sine.cpp
)

target_link_libraries(sortviz
  PUBLIC
    ImGui-SFML::ImGui-SFML
    sfml-graphics
    sfml-audio
)

