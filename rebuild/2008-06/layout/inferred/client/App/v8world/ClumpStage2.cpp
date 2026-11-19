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
