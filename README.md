[![Build Status](https://travis-ci.org/KadrusBAG/tree-0.0.1.svg?branch=master)](https://travis-ci.org/KadrusBAG/tree-0.0.1)
```
cmake -H. -B_builds -DBUILD_TESTS=ON
cmake --build _builds
cmake --build _builds --target test -- ARGS=--verbose
```
