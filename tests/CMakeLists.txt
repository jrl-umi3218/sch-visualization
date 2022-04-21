# Francois Keith, JRL, CNRS/AIST
# Creation: 19/08/2010
# History:
#
# Copyright CNRS/AIST

include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
link_directories(${Boost_LIBRARY_DIRS})
include_directories(${PROJECT_INCLUDE_DIR})

#### examples
macro(add_example name)
  add_executable(${name}_display shared-tests/examples/${name}.cpp example_displayer.cpp)
  target_link_libraries(${name}_display ${Boost_LIBRARIES})
  target_link_libraries(${name}_display ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
  target_link_libraries(${name}_display sch_viewer)
  add_dependencies(${name}_display sch_viewer)
  PKG_CONFIG_USE_DEPENDENCY(${name}_display sch-core)

  add_executable(${name}_test shared-tests/examples/${name}.cpp example_test.cpp)
  target_link_libraries(${name}_test ${Boost_LIBRARIES})
  target_link_libraries(${name}_test ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
  target_link_libraries(${name}_test sch_viewer)
  add_dependencies(${name}_test sch_viewer)
  PKG_CONFIG_USE_DEPENDENCY(${name}_test sch-core)
endmacro(add_example)

add_example(example1)
add_example(example2)

#### Test
include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} ${PROJECT_INCLUDE_DIR})
add_executable(test_glut Test1.cpp shared-tests/tests/common.cpp shared-tests/tests/common.h shared-tests/tests/includes.h)
target_link_libraries(test_glut ${Boost_LIBRARIES})
target_link_libraries(test_glut ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
target_link_libraries(test_glut sch_viewer)
add_dependencies(test_glut sch_viewer)
PKG_CONFIG_USE_DEPENDENCY(test_glut sch-core)


#### Data
set(DATA_FOLDER ${CMAKE_SOURCE_DIR}/tests/shared-tests/data/)
add_custom_command(TARGET test_glut POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FOLDER}/sample_stpbv1.txt
  ${CMAKE_BINARY_DIR}/tests/
  COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FOLDER}/sample_stpbv2.txt
  ${CMAKE_BINARY_DIR}/tests/
  COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FOLDER}/sample_stp_p.txt
  ${CMAKE_BINARY_DIR}/tests/
  COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FOLDER}/sample_polyhedron.otp
  ${CMAKE_BINARY_DIR}/tests/
)

add_executable(sch_display display.cpp shared-tests/tests/common.cpp shared-tests/tests/common.h shared-tests/tests/includes.h)
target_link_libraries(sch_display ${Boost_LIBRARIES})
target_link_libraries(sch_display ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
target_link_libraries(sch_display sch_viewer)

add_executable(sch_display_stpbvs display-stpbvs.cpp shared-tests/tests/common-stpbvs.cpp shared-tests/tests/common.h shared-tests/tests/includes.h)
target_link_libraries(sch_display_stpbvs ${Boost_LIBRARIES})
target_link_libraries(sch_display_stpbvs ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
target_link_libraries(sch_display_stpbvs sch_viewer)

add_dependencies(sch_display sch_viewer)
PKG_CONFIG_USE_DEPENDENCY(sch_display sch-core)

install(TARGETS sch_display
        RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

