#include "v8kernel/Body2008.h"
#include "v8kernel/Link.h"
#include "util/Name.h"

namespace RBX {

void Link::dirty()
{
	if (body) {
		body->getRoot()->advanceStateIndex();
	}
}

}
