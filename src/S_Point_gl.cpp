#include "S_Point_gl.h"

#if defined __APPLE__
# include <GLUT/glut.h>
#else
# include <GL/glut.h>
#endif // __APPLE__

using namespace sch;

S_Point_GL::S_Point_GL(S_Point * obj)
  : S_Object_GL(obj)
  , point_(obj)
  , displist_(-1)
{
  createDispList();
}

void S_Point_GL::drawGLInLocalCordinates() const
{
  glCallList(displist_);
}

void S_Point_GL::createDispList()
{
  displist_=glGenLists(1);
  glNewList(displist_,GL_COMPILE);
  glutSolidSphere(point_->getDisplayRadius(),4,3);
  glEndList();
}
