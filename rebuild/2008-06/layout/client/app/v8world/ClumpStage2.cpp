// =============================================================================
// ClumpStage2.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8world/ClumpStage2.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#undef _RELEASEASSERT
#include "AppUnit668/TreeStage.h"
#include "v8world/Primitive.h"
#include "v8world/Joint.h"

namespace RBX
{
	IStage::StageType TreeStage::getStageType()
	{
		return TREE_STAGE;
	}

	void TreeStage::onPrimitiveAdded(Primitive* p)
	{
		p->putInStage(this);
	}

	void TreeStage::onPrimitiveRemoving(Primitive* p)
	{
		p->removeFromStage(this);
	}

int TreeStage::getMetric(MetricType metricType)
{
	if (metricType != MAX_TREE_DEPTH)
		return static_cast<IWorldStage*>(getDownstream())->getMetric(metricType);
	return maxTreeDepth;
}

	void TreeStage::dirtyAssemblies(Joint* j)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (Primitive* p = j->getPrimitive(i))
			{
				if (Assembly* a = p->getAssembly())
					dirtyAssembly(a);
			}
		}
	}

	TreeStage::~TreeStage()
	{
	}

	void TreeStage::stepWorld(int worldStepId, int uiStepId, bool throttling, bool moveBodiesTest)
	{
		process();
		IStage::stepWorld(worldStepId, uiStepId, throttling, moveBodiesTest);
	}
}

#include <v8world/Joint.h>
#include <v8world/Primitive.h>
#include "util/Name.h"

namespace RBX
{

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
