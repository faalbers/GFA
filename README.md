Graphic Data Library by Frank Aalbers

# GFA

Graphic Data Library by Frank Aalbers

### git clone:

```
git clone -b stable https://github.com/faalbers/GFA.git
```

### adding GFA as submodel:
```
git submodule add -b stable https://github.com/faalbers/FaaRay extern/GFA
git submodule update --init
```

### build

```
cd FaaRay
cmake -B build -D CMAKE_BUILD_TYPE:STRING=Release
cmake --build build --config Release -j 10 --
```
