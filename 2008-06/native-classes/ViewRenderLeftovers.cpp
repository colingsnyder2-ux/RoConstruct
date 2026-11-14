#include "util/Handle.h"

namespace RBX {
bool InstanceHandle::empty() const
{
	return !target;
}
}
