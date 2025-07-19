cmake_minimum_required(VERSION 3.5)
project( colorization )
find_package( OpenCV REQUIRED )
include_directories( include ${OpenCV_INCLUDE_DIRS} )
add_executable( colorization src/colorization.cpp src/main.cpp )
target_link_libraries( colorization ${OpenCV_LIBS} )

find_package(GTest REQUIRED)

add_executable(test_colorization test/test_colorization.cpp src/colorization.cpp)
target_link_libraries(test_colorization
    ${GTEST_LIBRARIES}
    ${OpenCV_LIBS}
)
enable_testing()
add_test(NAME colorization_test COMMAND test_colorization)
