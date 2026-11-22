#undef _RELEASEASSERT
#include "../../../../../../tools/rbxgs/Client/App/include/v8world/Mechanism.h" // donor header: native-headers/v8world/Mechanism.h is a global-class stub that shadows it
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
