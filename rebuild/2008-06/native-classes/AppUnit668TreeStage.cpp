// 2008-06 native RBX::TreeStage (inactive); layout evidence in native-headers/AppUnit668/TreeStage.h.
// Verified by tests/record_native_app_unit668.py. Built here: onPrimitiveAdded 00668d30, onPrimitiveRemoving 00668d40,
// getMetric 00669030, dirtyAssemblies 00669240, the destructor 00669390, the scalar deleting destructor 00669760 and
// stepWorld 00669780 (vtable 0084cf94 is emitted here).
// Not built: TreeStage() 00669870 news a 0x50-byte AssemblyStage (0066f800) that no native header declares;
// getStageType 005e2790 returns the 2008 TREE_STAGE 3 (the donor IStage.h numbers it 2); process 00669410,
// onEdgeAdded 00669c00, onEdgeRemoving 00669c70 and the other TreeStage rows read the 2008 Edge / Joint / Assembly /
// Clump layouts (see the recorder's unit map).
#include "AppUnit668/TreeStage.h"
#include "v8world/Primitive.h"
#include "v8world/Joint.h"

namespace RBX
{
	// 00668d30
	void TreeStage::onPrimitiveAdded(Primitive* p)
	{
		p->putInStage(this);
	}

	// 00668d40
	void TreeStage::onPrimitiveRemoving(Primitive* p)
	{
		p->removeFromStage(this);
	}

	// 00669030
	int TreeStage::getMetric(MetricType metricType)
	{
		switch (metricType)
		{
		case MAX_TREE_DEPTH:
			return maxTreeDepth;
		default:
			return getDownstreamWS()->getMetric(metricType);
		}
	}

	// 00669240
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

	// 00669390
	TreeStage::~TreeStage()
	{
	}

	// 00669780
	void TreeStage::stepWorld(int worldStepId, int uiStepId, bool throttling)
	{
		process();
		IStage::stepWorld(worldStepId, uiStepId, throttling);
	}
}
