// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#undef _RELEASEASSERT
// 2008-06 native RBX::TreeStage (inactive); layout evidence in native-headers/AppUnit668/TreeStage.h.
// Verified by tests/record_native_app_unit668.py. Built here: onPrimitiveAdded 00668d30, onPrimitiveRemoving 00668d40,
// getMetric 00669030, dirtyAssemblies 00669240, the destructor 00669390, the scalar deleting destructor 00669760 and
// stepWorld 00669780 (vtable 0084cf94 is emitted here).
// Not built: TreeStage() 00669870 news a 0x50-byte AssemblyStage (0066f800) that no native header declares;
// getStageType 005e2790 (TREE_STAGE 3) is built through the kernel-stages opt-in (donor numbers it 2); process 00669410,
// onEdgeAdded 00669c00, onEdgeRemoving 00669c70 and the other TreeStage rows read the 2008 Edge / Joint / Assembly /
// Clump layouts (see the recorder's unit map).
#include "AppUnit668/TreeStage.h"
#include "v8world/Primitive.h"
#include "v8world/Joint.h"

namespace RBX
{
	// 005e2790 (folded `mov eax, 3`): TREE_STAGE of the 2008 StageType (opt-in native-headers/kernel-stages v8kernel/IStage.h
	// through the native-flags line).
	IStage::StageType TreeStage::getStageType()
	{
		return TREE_STAGE;
	}

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
	if (metricType != MAX_TREE_DEPTH)
		return static_cast<IWorldStage*>(getDownstream())->getMetric(metricType);
	return maxTreeDepth;
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
	void TreeStage::stepWorld(int worldStepId, int uiStepId, bool throttling, bool moveBodiesTest)
	{
		process();
		IStage::stepWorld(worldStepId, uiStepId, throttling, moveBodiesTest);
	}
}
