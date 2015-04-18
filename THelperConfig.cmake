# - Config file for the THelper package
# It defines the following variables
#  THELPER_INCLUDE_DIRS - include directories for THelper
#  THELPER_LIBRARIES    - libraries to link against
#  THELPER_LIBRARIES_DIR- diretory to libraries to link against
#  THELPER_EXECUTABLE   - the bar executable
 
# Compute paths
get_filename_component(THELPER_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(THELPER_INCLUDE_DIRS "THelper/Code/OS/inc
                         THelper/Code/Random/inc")
 
# These are IMPORTED targets created by THelperTargets.cmake
set(THELPER_LIBRARIES_DIR "THelper/${CMAKE_BUILD_TYPE}")
set(THELPER_LIBRARIES "libTHelper.a")
set(THELPER_TARGET "THelper")
