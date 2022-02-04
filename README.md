SortingVisualizer [![Build&Release](https://github.com/Tresonic/SortingVisualizer/actions/workflows/build.yml/badge.svg)](https://github.com/Tresonic/SortingVisualizer/actions/workflows/build.yml)
==========================
![screenshot](https://user-images.githubusercontent.com/37078118/152035644-c0ede538-abcd-4a7a-9637-a35f9c8da874.png)
SortingVisualizer is a simple program that allows you to watch and listen to different sorting algorithms doing their thing.
### Currently implemented sorting algorithms:
- bubblesort
- cocktail shaker sort
- insertion sort
- in-place mergesort
- mergesort
- quicksort

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

For Linux:
- [dependencies for building SFML](https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php#installing-dependencies)
- alsa c++ lib: `libclalsadrv-dev` for ubuntu

---
sfml-imgui-template from [here](https://github.com/eliasdaler/imgui-sfml-fetchcontent/tree/dev)
