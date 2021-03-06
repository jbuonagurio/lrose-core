cmake_minimum_required(VERSION 2.8.4)

project(Radx)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../../cmake/")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Release' as none was specified.")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()

# -----------------------------------------------------------------------------
# Radx Modules
# -----------------------------------------------------------------------------

option(Module_CfRadial "Cf/Radial netCDF support" ON)
option(Module_CfRadial2 "Cf/Radial 2 netCDF support" ON)
option(Module_D3R "CSU/NASA D3R netCDF support" ON)
option(Module_DOE "DOE netCDF (early) support" ON)
option(Module_DORADE "NCAR/EOL DORADE support" ON)
option(Module_EEC "EDGE netCDF format" ON)
option(Module_FORAY "NCAR/EOL FORAY netCDF support" ON)
option(Module_GAMIC "GAMIC HDF5 support" ON)
option(Module_Gematronik "Gematronik support" ON)
option(Module_HRD "HRD raw support" OFF)
option(Module_Leosphere "Leosphere support" ON)
option(Module_MRD "NSSL MRD support" ON)
option(Module_NEXRAD "NEXRAD level II support" ON)
option(Module_NOXP "OU NOXP support" ON)
option(Module_ODIM "ODIM HDF5 support" ON)
option(Module_RAPIC "RAPIC (BOM) support" ON)
option(Module_SIGMET "SIGMET RAW support" ON)
option(Module_TDWR "TDWR support" ON)
option(Module_TWOLF "TWOLF support" ON)
option(Module_UF "UF support" ON)

# -----------------------------------------------------------------------------
# External Dependencies
# -----------------------------------------------------------------------------

set(NETCDF_CXX True)
find_package(NetCDF REQUIRED)
include_directories(${NETCDF_INCLUDE_DIRS})
# Link: NETCDF_LIBRARIES

set(HDF5_USE_STATIC_LIBRARIES True)
find_package(HDF5 COMPONENTS C CXX REQUIRED)
include_directories(${HDF5_INCLUDE_DIRS})
# Link: HDF5_LIBRARIES

find_package(UDUnits REQUIRED)
include_directories(${UDUNITS_INCLUDE_DIR})
# Link: UDUNITS_LIBRARY

find_package(BZip2 REQUIRED)
include_directories(${BZIP2_INCLUDE_DIR})
# Link: BZIP2_LIBRARIES

find_package(ZLIB REQUIRED)
include_directories(${ZLIB_INCLUDE_DIRS})
# Link: ZLIB_LIBRARIES

if(MSVC)
  include_directories(${CMAKE_SOURCE_DIR}/../../compat/win32)
  
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  
  # Check for pthreads-win32
  set(THREADS_USE_PTHREADS_WIN32 True)
  find_package(Threads)
  if(NOT THREADS_FOUND)
    message(FATAL_ERROR "MSVC build requires pthreads-win32.")
  else()
    include_directories(${THREADS_PTHREADS_INCLUDE_DIR})
	# Avoid redefinition of 'struct timespec' with pthreads-win32
    add_definitions(-DHAVE_STRUCT_TIMESPEC)
  endif()
endif()

# Expose macro definitions for math constants
add_definitions(-D_USE_MATH_DEFINES)

# -----------------------------------------------------------------------------
# Targets
# -----------------------------------------------------------------------------

add_subdirectory("src")
