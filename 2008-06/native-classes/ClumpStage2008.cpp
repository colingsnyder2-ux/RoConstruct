// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::ClumpStage (inactive); evidence in native-headers/v8world/ClumpStage2008.h.
// Rows: constructor 0064cfd0, destructor 0064cf50, onPrimitiveAddedAnchor 0064cc40, onPrimitiveRemovedAnchor 0064ccf0.
#include "v8world/ClumpStage2008.h"
#include "v8world/Joints2008.h"
<<<<<<< HEAD
#include "v8world/Primitive2008.h"

namespace RBX
{
	// 0064cbf0: remove the primitive's first joint from the downstream TreeStage,
	// then remove that joint and the primitive from this stage (donor ClumpStage name).
	void ClumpStage::onPrimitiveRemoving(Primitive* p)
	{
		Joint* j = p->getFirstJoint();
		static_cast<IWorldStage*>(getDownstream())->onEdgeRemoving(j);
		static_cast<TreeStage*>(getDownstream())->onPrimitiveRemoving(p);
		j->removeFromPipeline(this);
		delete j;
		p->removeFromStage(this);
=======

namespace RBX
{
	// Unit-local declarations as native-world/App/include/v8world/Joint.h declares them (AnchorJoint / FreeJoint, size
	// 0x88, inline ctor Joint(p, NULL, CoordinateFrame(), CoordinateFrame()) 006455c0 then the vtable store: AnchorJoint
	// ??_7 0084b0cc, FreeJoint ??_7 0084b10c). The native v8world/Joints2008.h does not declare them yet (proposal).
	class AnchorJoint : public Joint
	{
	public:
		AnchorJoint(Primitive* p) : Joint(p, NULL, G3D::CoordinateFrame(), G3D::CoordinateFrame()) {}

	private:
		virtual JointType getJointType() const { return ANCHOR_JOINT; } // slot 5
	};

	class FreeJoint : public Joint
	{
	public:
		FreeJoint(Primitive* p) : Joint(p, NULL, G3D::CoordinateFrame(), G3D::CoordinateFrame()) {}

	private:
		virtual JointType getJointType() const { return FREE_JOINT; } // slot 5
	};

	// 0064ca60 ?getJoint@RBX@@YAPAVJoint@1@PAVPrimitive@1@W4JointType@21@@Z (body in native-classes/Inferred_0064ca60.cpp).
	Joint* getJoint(Primitive* p, Joint::JointType jointType);

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
>>>>>>> mew/claude/optimistic-shannon-0xccuy
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
