cmake_minimum_required(VERSION 3.10)

project(MBTATracker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")

include(FetchContent)

FetchContent_Declare(
    cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 871ed52d350214a034f6ef8a3b8f51c5ce1bd400
)
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(
  jsoncpp
  GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
  GIT_TAG master
)
FetchContent_MakeAvailable(jsoncpp)

include_directories(include)

add_executable(MBTATracker ${SOURCES})

target_link_libraries(MBTATracker PRIVATE cpr::cpr)
target_link_libraries(MBTATracker PRIVATE jsoncpp_lib)
