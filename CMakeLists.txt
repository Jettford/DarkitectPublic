cmake_minimum_required(VERSION 3.8)
project(Darkitect LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(External)
include_directories(Internal)
include_directories(External/PhysX/physx/include)
include_directories(External/PhysX/pxshared/include)

add_subdirectory(Internal)
add_subdirectory(External)

IF (!WIN32)
	add_definitions(-IExternal)
	add_definitions(-IInternal)
	add_definitions(-IExternal/PhysX/physx/include)
	add_definitions(-IExternal/PhysX/pxshared/include)
endif()

add_executable(GameServer Servers/GameServer/Main.cpp)
add_executable(MasterServer Servers/MasterServer/Main.cpp)
add_executable(TestingExecutable Servers/TestingExecutable/Main.cpp)

set_target_properties(GameServer PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(MasterServer PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(TestingExecutable PROPERTIES LINKER_LANGUAGE CXX)

set(SharedLibs RakNet odbccpp_static CppSQLite Net Common Game Files tinyxml2)

set(PHYSX_BIN_PATH "")

if (WIN32)
set(PHYSX_BIN_PATH External/PhysX/physx/bin/win.x86_64.vc142.mt/debug)
set(SharedLibs ${SharedLibs} odbc32)
elseif (UNIX)
set(SharedLibs ${SharedLibs} odbc pthread dl)
endif()

find_library(PhysX PhysX_64 PATHS External/PhysX/physx/bin/win.x86_64.vc142.mt/debug)
find_library(PhysXCommon PhysXCommon_64 PATHS External/PhysX/physx/bin/win.x86_64.vc142.mt/debug)
find_library(PhysXFoundation PhysXFoundation_64 PATHS External/PhysX/physx/bin/win.x86_64.vc142.mt/debug)

message(${PhysX})
message(${PhysXCommon})
message(${PhysXFoundation})

set(SharedLibs ${SharedLibs} F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysX_64.lib F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXCommon_64.lib F:/Darkitect/External/PhysX/physx/bin/win.x86_64.vc142.mt/debug/PhysXFoundation_64.lib)

target_link_libraries(MasterServer ${SharedLibs})
target_link_libraries(GameServer ${SharedLibs})
target_link_libraries(TestingExecutable ${SharedLibs})

add_dependencies(MasterServer GameServer)