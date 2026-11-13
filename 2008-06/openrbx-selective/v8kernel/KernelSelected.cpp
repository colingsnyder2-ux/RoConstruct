#include "v8kernel/Kernel.h"

#include "util/Profiling.h"
#include "v8kernel/Body.h"
#include "v8kernel/Connector.h"
#include "v8kernel/Constants.h"
#include "v8kernel/KernelData.h"
#include "v8kernel/Point.h"

#include <cstddef>

namespace RBX {
// PORT: donor relied on G3D type imports.
using namespace G3D;

// PORT: selective unit; remaining functions use the 2008 object.

void Kernel::deletePoint(Point* _point)
{
	if (_point != NULL) {

		if (--_point->numOwners == 0) {
			removePoint(_point);
			delete _point;
		}
	}
}

} // namespace RBX
