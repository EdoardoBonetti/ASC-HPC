cmake_minimum_required(VERSION 3.20)
project(ASC_HPC)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -O3 -ffast-math")

include_directories(src concurrentqueue)

add_executable(demo_tasks demos/demo_tasks.cc
    src/taskmanager.cc src/timer.cc)

target_sources(demo_tasks PUBLIC src/taskmanager.h src/timer.h)

add_executable(demo_simd demos/demo_simd.cc
    src/timer.cc)

target_sources(demo_simd PUBLIC src/simd.h src/timer.h)

add_executable(simd_timings demos/simd_timings.cc)
target_sources(simd_timings PUBLIC src/simd.h)

add_executable(timing_mem demos/timing_mem.cc)
target_sources(timing_mem PUBLIC src/simd.h)