#include "shared-tests/examples/example_common.h"
#include "sch/view/S_Object_gl.h"

# if defined __APPLE__
#  include <GLUT/glut.h>
# else
#  include <GL/glut.h>
# endif // __APPLE__

void display() {}

int main (int argc, char *argv[])
{
  Example universe;
  universe.initializeUniverse();

  glutInit (&argc, argv);
  std::vector<sch::S_Object_GL*> sObjGL = createGL(universe.sObj);
  for (size_t i=0; i<sObjGL.size(); ++i)
    sObjGL[i]->drawGL();

  return 0;
}

