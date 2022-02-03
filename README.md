SortingVisualizer
==========================
![screenshot](https://user-images.githubusercontent.com/37078118/152035644-c0ede538-abcd-4a7a-9637-a35f9c8da874.png)

Building
--------

```sh
mkdir build
cd build
cmake <path-to-cloned-repo>
cmake --build .
./src/sortviz # or .\src\Debug\sortviz.exe if you're on Windows
```

Dependencies
---

CMake >= 3.12

Also, if you're on Linux, you'll need to install dependencies for building SFML
specified
[here](https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php#installing-dependencies).

sfml-imgui-template from [here](https://github.com/eliasdaler/imgui-sfml-fetchcontent/tree/dev)
