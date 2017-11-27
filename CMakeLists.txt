cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

include(cmake/HunterGate.cmake)

HunterGate(
    URL "https://github.com/sergeyborov8/hunter/archive/v0.19.137.1.tar.gz"
    SHA1 "c712822281d4f9f76ea6a9c982b776578707d9d0"
)

project(pugixml)
hunter_add_package(pugixml)
find_package(pugixml CONFIG REQUIRED)

set(PACK_SOURCE_FILES sources/pack.cpp)
set(UNPACK_SOURCE_FILES sources/unpack.cpp)


add_executable(pack ${PACK_SOURCE_FILES})
target_link_libraries(pack pugixml)
add_executable(unpack ${UNPACK_SOURCE_FILES})
target_link_libraries(unpack pugixml)
