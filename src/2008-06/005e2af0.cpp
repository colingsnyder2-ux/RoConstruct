// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_3e5353d5d40b465b.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <G3D/Vector3.h>
#include <G3D/Color3.h>
#include <G3D/Color4.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/LineSegment.h>
namespace RBX {
class Adorn {
public:
	virtual ~Adorn();
	virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5();
	virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10();
	virtual void a11(); virtual void a12(); virtual void a13();
	virtual void setObjectToWorldMatrix(const G3D::CoordinateFrame& c) = 0;
	virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
	virtual void a20(); virtual void a21();
	virtual void lineSegment(const G3D::LineSegment& lineSegment, const G3D::Color4& color, float thick) = 0;
};
class Primitive;
class Edge {
public:
	enum EdgeType { JOINT, CONTACT };
	virtual ~Edge();
	virtual void e1();
	virtual void e2();
	virtual EdgeType getEdgeType() const = 0;
	virtual void setPrimitive(int i, Primitive* p);
};
class IJointOwner;
class Joint : public Edge {
public:
	enum JointType { NO_JOINT, ROTATE_JOINT, ROTATE_P_JOINT, ROTATE_V_JOINT, GLUE_JOINT, ANCHOR_JOINT };
private:
	char pad4[0x20 - 4];
	IJointOwner* jointOwner;
protected:
	bool active;
public:
	virtual JointType getJointType() const;
	bool getActive() const { return active; }
	static JointType getJointType(Edge* e)
	{
		return (e->getEdgeType() == Edge::JOINT) ? static_cast<Joint*>(e)->getJointType() : NO_JOINT;
	}
	static bool isAssemblyJoint(Edge* e)
	{
		return getJointType(e) >= ANCHOR_JOINT;
	}
};
class PartPrimitive {
public:
	const G3D::CoordinateFrame& getCoordinateFrame() const;
};
class PartInstance {
public:
	char pad[0x228];
	PartPrimitive primitive;
	PartPrimitive* getPrimitive() { return &primitive; }
};
class InstanceStub { public: virtual ~InstanceStub(); char pad[0x12c]; };
class __declspec(novtable) IRenderable {
public:
	virtual bool shouldRender3dAdorn() const;
	virtual void render3dAdorn(Adorn* adorn);
	int index2d;
	int index3d;
};
class __declspec(novtable) IJointOwner { public: virtual void jo0(); };
class JointInstance : public InstanceStub, public IRenderable, public IJointOwner {
protected:
	boost::weak_ptr<PartInstance> part[2];
	Joint* joint;
	virtual void render3dAdorn(Adorn* adorn);
public:
	PartInstance* getPart0();
	PartInstance* getPart1();
};
void JointInstance::render3dAdorn(Adorn* adorn)
{
	if (Joint::isAssemblyJoint(joint))
	{
		G3D::Color3 color3;

		PartPrimitive* prim0 = getPart0() ? getPart0()->getPrimitive() : NULL;
		PartPrimitive* prim1 = getPart1() ? getPart1()->getPrimitive() : NULL;

		G3D::Vector3 vec0 = prim0
			? prim0->getCoordinateFrame().translation
			: G3D::Vector3::zero();

		G3D::Vector3 vec1 = prim1
			? prim1->getCoordinateFrame().translation
			: G3D::Vector3::zero();

		if (joint->getActive())
			color3 = G3D::Color3::green();
		else
			color3 = G3D::Color3::red();

		adorn->setObjectToWorldMatrix(G3D::CoordinateFrame());

		G3D::Color4 color4(color3);
		adorn->lineSegment(
			G3D::LineSegment::fromTwoPoints(vec0, vec1),
			color4,
			20.0);
	}
}
}
