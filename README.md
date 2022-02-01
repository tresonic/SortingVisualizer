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
