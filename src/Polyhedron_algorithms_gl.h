#include "sch/view/S_Object_gl.h"
#include <sch/S_Polyhedron/S_Polyhedron.h>

namespace sch
{
class Polyhedron_algorithms_GL : public S_Object_GL
{
public:
  Polyhedron_algorithms_GL(S_Polyhedron *);

  virtual void drawGLInLocalCordinates() const;

private:
  Polyhedron_algorithms * pa_;

  void createDispList();
  int displayList_;
};
} // namespace sch
