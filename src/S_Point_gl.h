#ifndef _S_POINT_GL_H
#define _S_POINT_GL_H

#include "sch/view/S_Object_gl.h"
#include <sch/S_Object/S_Point.h>

namespace sch
{
class S_Point_GL : public S_Object_GL
{
public:
  S_Point_GL(S_Point * obj);

  virtual void drawGLInLocalCordinates() const;

private:
  void createDispList();

  S_Point * point_;
  int displist_;
};
} // namespace sch

#endif // _S_POINT_GL_H
