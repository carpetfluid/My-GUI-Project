cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Download SFML via FetchContent
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Your main executable
add_executable(main src/main.cpp)
target_compile_features(main PRIVATE cxx_std_17)

# Link SFML
target_link_libraries(main PRIVATE SFML::Graphics)

# Include GUI_Library headers
target_include_directories(main PRIVATE
    LIBRARY_PATH/GUI_Library/include #PUT THE LIBRARY PATH HERE
)

# Add all .cpp files from GUI_Library
file(GLOB GUI_SRC LIBRARY_PATH/GUI_Library/src/*.cpp) #PUT THE LIBRARY PATH HERE
target_sources(main PRIVATE ${GUI_SRC})

# Group GUI source files in IDEs under "GUI_library"
source_group("GUI_library" FILES ${GUI_SRC})
