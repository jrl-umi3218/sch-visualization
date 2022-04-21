#ifndef _S_BOX_GL_H
#define _S_BOX_GL_H

#include "sch/view/S_Object_gl.h"
#include <sch/S_Object/S_Box.h>

namespace sch
{
class S_Box_GL : public S_Object_GL
{
public:
  S_Box_GL(S_Box * obj);
  ~S_Box_GL();

  virtual void drawGLInLocalCordinates() const;

private:
  void createDispList();

  S_Box * box_;
  int displist_;
};
} // namespace sch

#endif // _S_BOX_GL_H
