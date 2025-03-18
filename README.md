# How to build for web

With cmake installed and emscripten installed (and activated) run the following:
```
emcmake cmake -DPLATFORM=Web -S . -B build
```
Then to build the project run the following: (note emscripten does not have to be activated for this step)
```
cmake --build build
```
Now to run the compiled program:
```
emrun ./build/cubeSnake.html
```