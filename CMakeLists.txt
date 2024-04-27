# CMake References: https://github.com/Lectem/cpp-boilerplate/blob/master/CMakeLists.txt

cmake_minimum_required(VERSION 3.17)
project(eqclassic_project C CXX)

file(GLOB_RECURSE sources_login "./LS/Login/*.cpp")
file(GLOB_RECURSE sources_login_common "./LS/common/*.cpp")
file(GLOB_RECURSE sources_world "./World/*.cpp")
file(GLOB_RECURSE sources_zone "./Zone/*.cpp")
file(GLOB_RECURSE sources_common "./Common/*.cpp")
file(GLOB_RECURSE sources_sharedmemory "./SharedMemory/*.cpp")
file(GLOB_RECURSE sources_eqc "./EQC/Sources/*.cpp")

# MySQL libraries
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
#find_package(MySQL REQUIRED)
execute_process(COMMAND mysql_config --cflags
    OUTPUT_VARIABLE MYSQL_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND mysql_config --libs
    OUTPUT_VARIABLE MYSQL_LIBS OUTPUT_STRIP_TRAILING_WHITESPACE)

foreach(FLAG ${MYSQL_CFLAGS})
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${FLAG}")
endforeach()

#message("Login: ${sources_login}")
add_executable(login ${sources_login} ${sources_login_common} ${sources_eqc} ${sources_sharedmemory}) # ${data}
set_target_properties(login PROPERTIES LINKER_LANGUAGE CXX)

#message("World: ${sources_world}")
add_executable(world ${sources_world} ${sources_common} ${sources_sharedmemory}) # ${data}
set_target_properties(world PROPERTIES LINKER_LANGUAGE CXX)

#message("Zone: ${sources_zone}")
add_executable(zone ${sources_zone} ${sources_common} ${sources_sharedmemory}) # ${data}
set_target_properties(zone PROPERTIES LINKER_LANGUAGE CXX)

target_compile_options(login PUBLIC ${MYSQL_CFLAGS})
target_include_directories(login PUBLIC $ENV{MYSQL}/include ./Common/Include ./EQC/Include ./SharedMemory/Include)
target_link_libraries(login PUBLIC ${MYSQL_LIBS})

target_compile_options(world PUBLIC ${MYSQL_CFLAGS})
target_include_directories(world PUBLIC $ENV{MYSQL}/include ./Common/Include ./EQC/Include ./SharedMemory/Include)
target_link_libraries(world PUBLIC ${MYSQL_LIBS})

target_compile_options(zone PUBLIC ${MYSQL_CFLAGS})
target_include_directories(zone PUBLIC $ENV{MYSQL}/include ./Common/Include ./EQC/Include ./SharedMemory/Include)
target_link_libraries(zone PUBLIC ${MYSQL_LIBS})

#target_compile_options(eqclassic PUBLIC ...)
#target_include_directories(eqclassic PUBLIC ...)
#file(COPY ${data} DESTINATION res_path)

# Dependencies

#find_package(......)
#target_link_libraries(eqclassic PUBLIC ....)

SET( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${MYSQL_CFLAGS} -fpermissive" )
SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MYSQL_CFLAGS} -fpermissive" )
SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} ${MYSQL_LIBS} -lz" )

# all install commands get the same destination. this allows us to use paths
# relative to the executable.
install(TARGETS login DESTINATION eqclassic_destination)
install(TARGETS world DESTINATION eqclassic_destination)
install(TARGETS zone DESTINATION eqclassic_destination)
# this is basically a repeat of the file copy instruction that copies the
# resources in the build directory, but here we tell CMake that we want it
# in the package
#install(DIRECTORY resources DESTINATION eqclassic_destination)

# now comes everything we need, to create a package
# there are a lot more variables you can set, and some
# you need to set for some package types, but we want to
# be minimal here
set(CPACK_PACKAGE_NAME "EQClassic")
set(CPACK_PACKAGE_VERSION "1.0.0")

# we don't want to split our program up into several things
set(CPACK_MONOLITHIC_INSTALL 1)

# This must be last
include(CPack)
