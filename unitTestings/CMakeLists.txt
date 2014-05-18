# Francois Keith, JRL, CNRS/AIST
# Creation: 19/08/2010
# History:
#
# Copyright CNRS/AIST

include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
include_directories(${PROJECT_INCLUDE_DIR})

add_custom_command(TARGET test_glut POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/unitTestings/sample_stpbv1.txt
  ${CMAKE_BINARY_DIR}/unitTestings/
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/unitTestings/sample_stpbv2.txt
  ${CMAKE_BINARY_DIR}/unitTestings/
)

include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} ${PROJECT_INCLUDE_DIR})
add_executable(test_glut Test1.cpp common.cpp common.h includes.h)
target_link_libraries(test_glut ${Boost_LIBRARIES})
target_link_libraries(test_glut ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
target_link_libraries(test_glut sch_viewer)
add_dependencies(test_glut sch_viewer)
PKG_CONFIG_USE_DEPENDENCY(test_glut sch)


add_executable(sch_display display.cpp common.cpp common.h includes.h)
target_link_libraries(sch_display ${Boost_LIBRARIES})
target_link_libraries(sch_display ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
target_link_libraries(sch_display sch_viewer)
add_dependencies(sch_display sch_viewer)
PKG_CONFIG_USE_DEPENDENCY(sch_display sch)

install(TARGETS sch_display
        RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

