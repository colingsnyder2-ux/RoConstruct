#undef _RELEASEASSERT
#include "v8world/Mechanism.h"
#include "v8world/Primitive.h"
#include "v8world/Assembly.h"

namespace RBX
{
	Mechanism* Mechanism::getMechanismFromPrimitive(const Primitive* primitive)
	{
		Assembly* assembly;
		if (primitive && (assembly = primitive->getAssembly()))
			return assembly->getMechanism();
		return NULL;
	}

	bool MechanismTracker::tracking()
	{
		if (this->mechanism)
		{
			RBXASSERT(this->containedBy(this->mechanism));
			return true;
		}
		return false;
	}
}
