#include "util/Guid.h"

// PORT: donor size annotations are metadata, not 2008 API.
#include "util/Name.h"

#define NOMINMAX

#include <algorithm>
#include <boost/thread/once.hpp>
#include <objbase.h>
#include <stdio.h>
#include <windows.h>

namespace RBX {

// PORT: selective unit; remaining functions use the 2008 object.

bool Guid::Data::operator<(const Data& other) const
{
	const Name* otherScope = other.scope;
	const Name* thisScope = scope;
	int order = 0;

	if (thisScope != otherScope) {
		order = thisScope->name.compare(otherScope->name);

		if (order != -1 && order != 0) {
			return false;
		}
	}

	if (order == 0) {
		return index < other.index;
	}

	return true;
}

} // namespace RBX
