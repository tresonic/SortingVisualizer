SortingVisualizer
==========================

Building
--------

```sh
mkdir build
cd build
cmake <path-to-cloned-repo>
cmake --build .
./src/imgui-sfml-example # or .\src\Debug\imgui-sfml-example.exe if you're on Windows
```

Options
-------

You can also set the following options when building:

* `USE_SYSTEM_DEPS` (`OFF` by default) - search for SFML installed on system instead of fetching it
* `LINK_DEPS_STATIC` (`ON` by default) - link dependencies statically

Dependencies
---

CMake >= 3.12

Also, if you're on Linux, you'll need to install dependencies for building SFML
specified
[here](https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php#installing-dependencies).

sfml-imgui-template from [here](https://github.com/eliasdaler/imgui-sfml-fetchcontent/tree/dev)
