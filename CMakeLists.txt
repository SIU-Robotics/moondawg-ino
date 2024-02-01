cmake_minimum_required(VERSION 3.10)

# set the project name
project(embedded-berm-bot)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)

# find the roboclaw library
find_package(roboclaw REQUIRED)

# find the Servo library
find_package(Servo REQUIRED)


# add the executable
add_executable(embedded-berm-bot MoonDawgEmbedded.cpp setup.cpp)

target_link_libraries(embedded-berm-bot roboclaw::roboclaw Servo::Servo)