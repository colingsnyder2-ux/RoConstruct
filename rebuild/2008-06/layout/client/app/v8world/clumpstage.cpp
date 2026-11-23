#include "v8world/ClumpStage2008.h"
#include "v8world/Joints2008.h"
#include "v8world/Primitive2008.h"

namespace RBX
{

	Joint* getJoint(Primitive* p, Joint::JointType jointType);

	void ClumpStage::onPrimitiveRemoving(Primitive* p)
	{
		Joint* j = p->getFirstJoint();
		static_cast<IWorldStage*>(getDownstream())->onEdgeRemoving(j);
		static_cast<TreeStage*>(getDownstream())->onPrimitiveRemoving(p);
		j->removeFromPipeline(this);
		delete j;
		p->removeFromStage(this);
	}

	void ClumpStage::onPrimitiveAddedAnchor(Primitive* p)
	{
		Joint* freeJoint = getJoint(p, Joint::FREE_JOINT);
		Joint* anchorJoint = new AnchorJoint(p);
		anchorJoint->putInStage(this);
		static_cast<IWorldStage*>(getDownstream())->onEdgeAdded(anchorJoint);   // plain cast: no rbx_static_cast check in 2008
		onEdgeRemoving(freeJoint);
	}

	void ClumpStage::onPrimitiveRemovedAnchor(Primitive* p)
	{
		Joint* anchorJoint = getJoint(p, Joint::ANCHOR_JOINT);
		Joint* freeJoint = new FreeJoint(p);
		freeJoint->putInStage(this);
		static_cast<IWorldStage*>(getDownstream())->onEdgeAdded(freeJoint);
		onEdgeRemoving(anchorJoint);
	}

	ClumpStage::ClumpStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new TreeStage(this, world), world)
	{
	}

	ClumpStage::~ClumpStage()
	{
	}
}
