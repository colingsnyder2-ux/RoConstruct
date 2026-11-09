// 2008-06 native RBX::BlockBlockContact (inactive); evidence in native-headers/leaves2008/BlockBlockContact2008.h.
// Verified by tests/record_native_leaves2008.py: constructor 0060d500, destructor 0060d5a0 (??_G 0060d610),
// deleteAllConnectors 00607c60, numConnectors 0060d580, getConnector 0060d590. stepContact 00608830 and
// computeIsColliding 00607c20 test the primitives' fuzzy extents at Primitive +0x80 (Extents::overlapsOrTouches
// 00606b60), which needs a 2008 Primitive declaration that can share a unit with Contact2008.h; they are not
// defined here (see the recorder's blocked list).
#include "leaves2008/BlockBlockContact2008.h"
#include "v8kernel/Kernel.h"

namespace RBX
{
	BlockBlockContact::BlockBlockContact(Primitive* p0, Primitive* p1)
		: Contact(p0, p1)
	{
		separation = 1e9f;
		feature[0] = -1;
		feature[1] = -1;
		cachedBody = 0;
		cachedAxis = 0;
		separatingAxisId = 0;
		separatingBodyId = 0;
	}

	int BlockBlockContact::numConnectors() const
	{
		return connectors.size();
	}

	ContactConnector* BlockBlockContact::getConnector(int i)
	{
		return connectors[i];
	}

	// 00607c60: Contact::deleteConnector 00606d10 inlined (same original unit), without its own null test.
	void BlockBlockContact::deleteAllConnectors()
	{
		for (int i = 0; i < connectors.size(); ++i)
		{
			ContactConnector*& c = connectors[i];
			getKernel()->removeConnector(c);
			delete c;
			c = NULL;
		}
		connectors.fastClear();
		matched.fastClear();
	}
}

#ifdef NATIVE_BLOCKBLOCKCONTACT_PENDING
// 006087a0 compares IPipelined::currentStage->getStageType() with 7, the 2008 KERNEL_STAGE; the donor IStage.h numbers
// KERNEL_STAGE 8. Built only against the generated IStage.h copy of the recorder (2008 StageType values).
namespace RBX
{
	void BlockBlockContact::updateConnectors()
	{
		if (separation <= 0.0f)
		{
			if (inKernel())
			{
				matched.resize(connectors.size(), false);
				for (int i = 0; i < connectors.size(); ++i)
					matched[i] = false;

				if (planeContact)
					computePlaneContact();
				else
					loadGeoPairEdgeEdge(0, 1, feature[0] - 6, feature[1] - 6);

				deleteUnmatchedConnectors();
			}
		}
		else
		{
			deleteAllConnectors();
			feature[0] = -1;
			feature[1] = -1;
		}
	}
}
#endif
