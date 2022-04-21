#ifndef _S_SPHERE_GL_H
#define _S_SPHERE_GL_H

#include "sch/view/S_Object_gl.h"
#include <sch/S_Object/S_Sphere.h>

namespace sch
{
class S_Sphere_GL : public S_Object_GL
{
public:
  S_Sphere_GL(S_Sphere * obj);

  virtual void drawGLInLocalCordinates() const;

private:
  void createDispList();

  S_Sphere * sphere_;
  int displist_;
};
} // namespace sch

#endif // _S_SPHERE_GL_H
