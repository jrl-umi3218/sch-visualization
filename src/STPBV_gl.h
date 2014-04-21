#include <sch/S_Polyhedron/Polyhedron_algorithms.h>
#include <sch/STP-BV/STP_BV.h>
#include "sch/view/S_Object_gl.h"

namespace sch
{
	class STP_BV_GL: public S_Object_GL
	{
	public:
		STP_BV_GL(STP_BV *);

		virtual void drawGLInLocalCordinates() const;

	private:
		STP_BV * stpbv_;
		std::vector<int> displayList_;

		void computeDisplayList();
	};
}
