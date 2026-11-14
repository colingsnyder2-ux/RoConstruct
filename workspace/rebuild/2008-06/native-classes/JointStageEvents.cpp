// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::JointStage primitive events (inactive).
#undef _RELEASEASSERT
#include "v8world/JointStage2008.h"
#include "v8world/ClumpStage.h"
#include "v8world/Primitive.h"
#include "v8world/Joint.h"
#include <vector>

namespace RBX
{
	void JointStage::onPrimitiveRemoving(Primitive* p)
	{
		std::vector<Joint*> moveJoints;

		for (Joint* j = p->getFirstJoint(); j; j = p->getNextJoint(j))
		{
			if (j->getJointType() != Joint::ANCHOR_JOINT && j->getJointType() != Joint::FREE_JOINT && j->downstreamOfStage(this))
				moveJoints.push_back(j);
		}

		for (size_t i = 0; i < moveJoints.size(); ++i)
		{
			Joint* j = moveJoints[i];
			getDownstreamWS()->onEdgeRemoving(j);
			insertToListAndMap(j);
		}

		rbx_static_cast<ClumpStage*>(getDownstream())->onPrimitiveRemoving(p);
		p->removeFromStage(this);
	}
}
