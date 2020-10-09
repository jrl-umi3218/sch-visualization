#ifndef _S_SUPERELLIPSOID_GL
#define _S_SUPERELLIPSOID_GL

#include "sch/view/S_Object_gl.h"
#include <sch/S_Object/S_Superellipsoid.h>

namespace sch
{
class S_Superellipsoid_GL : public S_Object_GL
{
public:
  S_Superellipsoid_GL(S_Superellipsoid * obj);
  ~S_Superellipsoid_GL();

  virtual void drawGLInLocalCordinates() const;

private:
  void createDispList();

  S_Superellipsoid * ellipse_;
  int displist_;
};
} // namespace sch

#endif // _S_SUPERELLIPSOID_GL
