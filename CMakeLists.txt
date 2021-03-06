cmake_minimum_required(VERSION 3.5)

project(FunctionImage LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports tFunctionImage following variables for Android, which are identical to qmake Android variables.
# CFunctionImageck http://doc.qt.io/qt-5/deployment-android.html for more information.
# TFunctionImagey need to be set before tFunctionImage find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

set(CMAKE_PREFIX_PATH $ENV{QT_DIR})

find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(FunctionImage SHARED
      Equals.h
      Equals.cpp
      Expression.h
      Expression.cpp
      Utils.h
      main.cpp
      mainwindow.cpp
      mainwindow.h
      mainwindow.ui
      dialog.h
      dialog.cpp
      dialog.ui
  )
else()
  add_executable(FunctionImage
      Equals.h
      Equals.cpp
      Expression.h
      Expression.cpp
      Utils.h
      main.cpp
      mainwindow.cpp
      mainwindow.h
      mainwindow.ui
      dialog.h
      dialog.cpp
      dialog.ui
  )
endif()

target_link_libraries(FunctionImage PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
