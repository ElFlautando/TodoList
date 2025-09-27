cmake_minimum_required(VERSION 4.0)
project(TodoList VERSION 1.0.0 LANGUAGES CXX)


#beginn lib fmt
include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG        e69e5f977d458f2650bb346dadf2ad30c5320281) # 10.2.1
FetchContent_MakeAvailable(fmt)
#end fmt


add_executable(main main.cpp manager.cpp todo_item.cpp utils.cpp)

target_link_libraries(main fmt::fmt)

# SDL inclusion testing
list(APPEND /usr/local)
find_package(SLD3)
add_executable(gui gui_init.cpp gui.cpp)
target_link_libraries(gui PRIVATE SDL3)