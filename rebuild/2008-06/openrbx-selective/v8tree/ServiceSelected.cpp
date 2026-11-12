#include "v8tree/Service.h"

#include <windows.h>

namespace RBX {
// PORT: donor relied on boost type imports.
using boost::shared_ptr;

// PORT: selective unit; remaining functions use the 2008 object.

void ServiceProvider::clearServices()
{
	serviceArray.clear();
	serviceMap.clear();
}

} // namespace RBX
