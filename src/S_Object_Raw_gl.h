#ifndef _S_OBJECT_RAW_GL_H
#define _S_OBJECT_RAW_GL_H

#include "sch/view/S_Object_gl.h"
#include <sch/S_Object/S_Object.h>

namespace sch
{
class S_Object_Raw_GL : public S_Object_GL
{
public:
  S_Object_Raw_GL(S_Object *);
  ~S_Object_Raw_GL();

  virtual void drawGLInLocalCordinates() const;

private:
  void computeDisplayList();
  int displist_;
};
} // namespace sch

#endif //_S_OBJECT_GL_H
