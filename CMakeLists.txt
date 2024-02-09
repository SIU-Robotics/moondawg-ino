cmake_minimum_required(VERSION 3.10)

# set the project name
project(embedded-berm-bot)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)

# add the library
add_library(berm-bot-lib MoonDawgEmbedded.cpp setup.cpp)

# specify the include directories
target_include_directories(berm-bot-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# specify the libraries that this library depends on
target_link_libraries(berm-bot-lib PUBLIC Arduino Servo RoboClaw)