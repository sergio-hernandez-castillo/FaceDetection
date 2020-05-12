# Check rob's repo ;)
# https://github.com/robtry/face-alignment/blob/master/CMakeLists.txt
<<<<<<< HEAD
#
# When doing "cmake" command, do: cmake ../ -DCMAKE_CXX_FLAGS="-std=c++11"
=======
>>>>>>> 185114158503d44f6f740a54881cd9b3bb8f0f5e

cmake_minimum_required(VERSION 3.14)
message("Module 1 'FaceDetection' starting ...")
project(FaceDetection)

## OPEN CV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(
FaceDetection
${PROJECT_SOURCE_DIR}/source/FaceDetection.cpp
${PROJECT_SOURCE_DIR}/source/main.cpp
)

<<<<<<< HEAD
target_link_libraries(FaceDetection ${OpenCV_LIBS})
=======
target_link_libraries(FaceDetection ${OpenCV_LIBS} dlib::dlib)
>>>>>>> 185114158503d44f6f740a54881cd9b3bb8f0f5e
