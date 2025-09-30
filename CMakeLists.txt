cmake_minimum_required(VERSION 4.0)
project(TodoList VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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



list(APPEND CMAKE_PREFIX_PATH /usr/local)
find_package(SDL3 REQUIRED)

set(IMGUI_PATH /home/lfs/Downloads/dearImgui)
file(GLOB IMGUI_GLOB 
  ${IMGUI_PATH}/*.cpp
  ${IMGUI_PATH}/backends/imgui_impl_sdl3.cpp
  ${IMGUI_PATH}/backends/imgui_impl_sdlrenderer3.cpp
  )

message(${IMGUI_PATH})
message(${IMGUI_GLOB})

add_library(imgui STATIC ${IMGUI_GLOB} )
target_include_directories(imgui PUBLIC ${IMGUI_PATH} ${IMGUI_PATH}/backends)


add_executable(gui gui_init.cpp gui.cpp)

target_link_libraries(gui PRIVATE SDL3::SDL3 imgui)