#include <v8world/Joint.h>
#include <v8world/Primitive.h>
#include "util/Name.h"

namespace RBX {

class Joint* __cdecl getJoint(class Primitive* p, enum Joint::JointType jointType)
{
	for (class Joint* j = p->getFirstJoint(); j; j = p->getNextJoint(j))
	{
		if (j->getJointType() == jointType)
			return j;
	}
	return 0;
}

}
