// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::ClumpStage (inactive); evidence in native-headers/v8world/ClumpStage2008.h.
// Rows: constructor 0064cfd0, destructor 0064cf50, onPrimitiveAddedAnchor 0064cc40, onPrimitiveRemovedAnchor 0064ccf0.
#include "v8world/ClumpStage2008.h"
#include "v8world/Joints2008.h"
#include "v8world/Primitive2008.h"

namespace RBX
{
	// AnchorJoint / FreeJoint (size 0x88, vtables 0084b0cc / 0084b10c) are declared by v8world/Joints2008.h (batch 28;
	// they were unit-local here).

	// 0064ca60 ?getJoint@RBX@@YAPAVJoint@1@PAVPrimitive@1@W4JointType@21@@Z (body in native-classes/Inferred_0064ca60.cpp).
	Joint* getJoint(Primitive* p, Joint::JointType jointType);

	// 0064cbf0: remove the primitive's first joint from the downstream TreeStage,
	// then remove that joint and the primitive from this stage (donor ClumpStage name).
	// Declared in v8world/ClumpStage2008.h (batch 39; caller JointStage 00668850). Registry row is the placeholder
	// func_0064cbf0.
	void ClumpStage::onPrimitiveRemoving(Primitive* p)
	{
		Joint* j = p->getFirstJoint();
		static_cast<IWorldStage*>(getDownstream())->onEdgeRemoving(j);
		static_cast<TreeStage*>(getDownstream())->onPrimitiveRemoving(p);
		j->removeFromPipeline(this);
		delete j;
		p->removeFromStage(this);
	}

	// 0064cae0 (registry placeholder func_0064cae0; caller JointStage::onPrimitiveAdded 006685e2): native-world
	// ClumpStage.cpp onPrimitiveAdded shape in 2008 form: IPipelined::putInStage 00645830, TreeStage::onPrimitiveAdded
	// 00668d30 on the downstream (+0x8), then new(0x88) AnchorJoint (vtable 0084b0cc) when the anchored state
	// (+0xa8 / +0xa9 / +0xaa) is set, else FreeJoint (0084b10c), putInStage(this) and downstream slot 4 onEdgeAdded.
	void ClumpStage::onPrimitiveAdded(Primitive* p)
	{
		p->putInStage(this);
		static_cast<TreeStage*>(getDownstream())->onPrimitiveAdded(p);

		Joint* joint;

		if (p->getAnchor())
			joint = new AnchorJoint(p);
		else
			joint = new FreeJoint(p);

		joint->putInStage(this);
		static_cast<IWorldStage*>(getDownstream())->onEdgeAdded(joint);
	}

	// 0064ce40 (caller World::step 005ea137): donor ClumpStage::stepUi, Joint slot 14 on every edge of set10 (+0x10).
	void ClumpStage::stepUi(int uiStepId)
	{
		for (std::set<Edge*>::iterator it = set10.begin(); it != set10.end(); ++it)
			static_cast<Joint*>(*it)->stepUi(uiStepId);
	}

	// 0064cc40 (native-world ClumpStage.cpp / openrbx shape): the FREE_JOINT of p (getJoint 0064ca60), new(0x88)
	// AnchorJoint(p), IPipelined::putInStage 00645830, downstream slot 4 onEdgeAdded, then this slot 5 onEdgeRemoving
	// on the free joint.
	void ClumpStage::onPrimitiveAddedAnchor(Primitive* p)
	{
		Joint* freeJoint = getJoint(p, Joint::FREE_JOINT);
		Joint* anchorJoint = new AnchorJoint(p);
		anchorJoint->putInStage(this);
		static_cast<IWorldStage*>(getDownstream())->onEdgeAdded(anchorJoint);   // plain cast: no rbx_static_cast check in 2008
		onEdgeRemoving(freeJoint);
	}

	// 0064ccf0: the same with ANCHOR_JOINT found and a new FreeJoint (vtable 0084b10c).
	void ClumpStage::onPrimitiveRemovedAnchor(Primitive* p)
	{
		Joint* anchorJoint = getJoint(p, Joint::ANCHOR_JOINT);
		Joint* freeJoint = new FreeJoint(p);
		freeJoint->putInStage(this);
		static_cast<IWorldStage*>(getDownstream())->onEdgeAdded(freeJoint);
		onEdgeRemoving(anchorJoint);
	}

	// 0064cfd0
	ClumpStage::ClumpStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new TreeStage(this, world), world)
	{
	}

	// 0064cf50
	ClumpStage::~ClumpStage()
	{
	}
}
