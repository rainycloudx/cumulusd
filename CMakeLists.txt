cmake_minimum_required(VERSION 3.27)
project(cumulusd)

set(CMAKE_CXX_STANDARD 17)

find_library(sslsocket
    NAMES sslsocketutil
    PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../cumulus/cmake-build-debug/
)

add_executable(cumulusd main.cpp
        src/App.cpp
        src/CumulusConnection.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../cumulus/src/constants/EnvVars.cpp)

target_include_directories(
        cumulusd PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../cumulus/src/connection
        ${CMAKE_CURRENT_SOURCE_DIR}/../cumulus/src/constants
)

target_link_libraries(cumulusd PUBLIC sslsocket)