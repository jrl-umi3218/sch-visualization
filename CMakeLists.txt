cmake_minimum_required(VERSION 2.6)

INCLUDE(cmake/base.cmake)
INCLUDE(cmake/eigen.cmake)
INCLUDE(cmake/boost.cmake)
INCLUDE(cmake/cpack.cmake)

set(CXX_DISABLE_WERROR True)
set(CMAKE_VERBOSE_MAKEFILE ON)

# ----------------------------------------------------------------
# --- Project declaration ----------------------------------------
# ----------------------------------------------------------------

SET(PROJECT_NAME scd)
SET(PROJECT_DESCRIPTION "Implementation of the Sphere-Torus Patches Bounding Volumes")
set(PROJECT_CONTACT francois.keith@lirmm.fr)
SET(PROJECT_URL "http://idh.lirmm.fr/projects/sch")
set(PROJECT_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

SETUP_PROJECT()

# Search for dependencies.
# Boost
SEARCH_FOR_BOOST()

find_package(GLUT)
find_package(OpenGL)

# GLUT is a bit tricky, so check the search result.
if(GLUT_FOUND)
	message("-- GLUT found! Libraries: ${GLUT_LIBRARIES}")
else(GLUT_FOUND)
	message("-- GLUT not found! Trying with the alternative FindGLUT")
	include(CMakeModules/FindGLUT_fix1.cmake)
	if(GLUT_FOUND)
		message("-- GLUT found! Libraries: ${GLUT_LIBRARIES}")
	else(GLUT_FOUND)
		message(FATAL_ERROR "-- GLUT not found!")
	endif(GLUT_FOUND)
endif(GLUT_FOUND)

ADD_REQUIRED_DEPENDENCY("sch")

# Optimisation flags when building with RELEASE
#----------------------------------------------
PKG_CONFIG_APPEND_LIBS("sch_viewer")

ADD_SUBDIRECTORY(include)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(unitTestings)

SETUP_PROJECT_FINALIZE()
SETUP_PROJECT_CPACK()
