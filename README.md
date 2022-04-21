sch-visualization
=================

![CI of sch-visualization](https://github.com/jrl-umi3218/sch-visualization/workflows/CI%20of%20sch-visualization/badge.svg)


Documentation
-------------

Library for vizualization of the the sch volumes.
This package provides the routines allowing to display a sch volumes, and an 
executable allowing you to display the volumes you've created 

Dependency
----------

* sch-core
* glut 
* opengl

Installation
------------

Building using cmake:
- create a new build directory
- run `cmake ..` in this directory 
  (you probably want to define `CMAKE_INSTALL_PREFIX`)
- `make`
- `make install`

Indentation
-----------

    astyle --style=allman --lineend=linux --indent=spaces=2
