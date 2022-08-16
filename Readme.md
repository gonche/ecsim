# ECSim

## How to build and run the application

## Build instructions

The build system uses CMake.

## Configuring and Building ECSim with CMake using commandline

```

cd ecsim/build/
cmake ..
make

```

## Running the application and writing to stdin using pipe

```

cd ecsim/build/
cat ../file | ./ecsim 

```

### This program has been tested on Macos.

### Citations

Research - Robert Penner's Easing Functions

```

jesús gollonet
https://github.com/jesusgollonet/ofpennereasing
a port of penner's easing equations to c++

```