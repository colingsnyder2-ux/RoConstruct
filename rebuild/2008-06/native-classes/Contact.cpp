// 2008-06 native RBX::Contact (inactive); evidence in native-headers/v8world/Contact2008.h.
// Verified by tests/record_native_world_shapes.py. Recovered rows of the Contact unit (00606b00..00608950):
// the constructor 00606c20 and deleteConnector 00606d10. The other rows of the unit (step, computeIsAdjacent,
// createConnector, onPrimitiveContactParametersChanged, the ball / block contact geometry) need the native
// Primitive / Body / ContactConnector layouts and are not part of this unit yet.
// >>> native-status (generated) -- do not edit >>>
// Contact | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 4c385f91 | roc native-status --write
#include "v8world/Contact2008.h"
#include "v8kernel/Kernel.h"
#include "v8kernel/Connector.h"

namespace RBX
{
	// 00606c20 (out of line: BallBallContact 0060cae0 / BallBlockContact 0060cb90 / BlockBlockContact 0060d500 call it)
	Contact::Contact(Primitive* prim0, Primitive* prim1)
		: Edge(prim0, prim1),
		  lastContactStep(-1),
		  steppingIndex(-1),
		  jointK(0),
		  elasticJointK(0),
		  kFriction(0)
	{
	}

	// 00606d10: no null test of its own (the callers test, 0060cb50); IPipelined::getKernel 00645850,
	// Kernel::removeConnector 005fb1f0, then the virtual deleting destructor.
	void Contact::deleteConnector(ContactConnector*& c)
	{
		getKernel()->removeConnector(c);
		delete c;
		c = NULL;
	}
}
