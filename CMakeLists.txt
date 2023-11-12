cmake_minimum_required(VERSION 3.5)

project(ExtraCreditNitin LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ExtraCreditNitin main.cpp)

cmake_minimum_required(VERSION 3.5)

project(ExtraCreditNitin LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug
    CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

set ( TEMP_CPP_TESTING_SOURCES
  main.cpp
  )

#add_executable(${PROJECT_NAME} ${PROJECT_CPP_SOURCES} ${TEMP_CPP_TESTING_SOURCES})

target_link_libraries(
 ${PROJECT_NAME}
)


