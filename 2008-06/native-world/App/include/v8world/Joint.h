#pragma once
#include <G3D/CoordinateFrame.h>
#include "v8world/Edge.h"
#include "util/NormalId.h"

namespace RBX
{
	class IJointOwner
	{
	};

	class Joint : public Edge
	{
	public:
		enum JointType
		{
			NO_JOINT,
			ROTATE_JOINT,
			ROTATE_P_JOINT,
			ROTATE_V_JOINT,
			GLUE_JOINT,
			ANCHOR_JOINT,
			WELD_JOINT,
			SNAP_JOINT,
			MOTOR_JOINT,
			FREE_JOINT
		};

	private:
		IJointOwner* jointOwner;
	protected:
		bool active;
		G3D::CoordinateFrame jointCoord0;
		G3D::CoordinateFrame jointCoord1;

	protected:
		virtual Edge::EdgeType getEdgeType() const
		{
			return JOINT;
		}
	public:
		//Joint(const Joint&);
	protected:
		Joint(Primitive* prim0, Primitive* prim1, const G3D::CoordinateFrame& _jointCoord0, const G3D::CoordinateFrame& _jointCoord1);
		Joint();
	public:
		virtual ~Joint();
	public:
		void setJointOwner(IJointOwner* value);
		IJointOwner* getJointOwner() const;
		virtual void setPrimitive(int i, Primitive* p);
		virtual JointType getJointType() const
		{
			RBXASSERT(0);
			return NO_JOINT;
		}
		virtual bool isBreakable() const
		{
			return false;
		}
		virtual bool isBroken() const
		{
			return false;
		}
		virtual bool joinsFace(Primitive* p, NormalId face) const
		{
			return false;
		}
		virtual bool isAligned()
		{
			return true;
		}
		virtual G3D::CoordinateFrame align(Primitive* pMove, Primitive* pStay)
		{
			RBXASSERT(0);
			return G3D::CoordinateFrame();
		}
		virtual bool canStepUi() const
		{
			return false;
		}
		virtual void stepUi(int uiStepId)
		{
		}
		bool getActive() const
		{
			return active;
		}
		void setActive(bool value)
		{
			active = value;
		}
		void setJointCoord(int i, const G3D::CoordinateFrame& c);
		const G3D::CoordinateFrame& getJointCoord(int i) const
		{
			return i == 0 ? jointCoord0 : jointCoord1;
		}
		NormalId getNormalId(int) const;
		//Joint& operator=(const Joint&);

	private:
		static bool canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1, float angleMax, float planarMax);
	protected:
		static bool canBuildJointLoose(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1);
		static bool canBuildJointTight(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1);
	public:
		static JointType getJointType(Edge* e)
		{
			if (e->getEdgeType() == Edge::JOINT)
			{
				return rbx_static_cast<Joint*>(e)->getJointType();
			}
			else
			{
				return NO_JOINT;
			}
		}
		static bool isJoint(Edge* e)
		{
			return e->getEdgeType() == Edge::JOINT;
		}
		static bool isAssemblyJoint(Edge* e);
		static bool isGroundJoint(Joint*);
		static bool isAutoJoinJoint(Joint*);
	};
class AnchorJoint : public Joint
{
public:
	AnchorJoint(Primitive* p) : Joint(p, NULL, G3D::CoordinateFrame(), G3D::CoordinateFrame()) {}

	static bool isAnchorJoint(const Joint* joint) { return joint->getJointType() == ANCHOR_JOINT; }

private:
	// FUNCTION: WEBSERVICE 0x1011b580 FOLDED
	virtual JointType getJointType() const { return ANCHOR_JOINT; } // vtable+0x14
};


// VTABLE: WEBSERVICE 0x10247ea4
// SIZE 0x88
class FreeJoint : public Joint
{
public:
	FreeJoint(Primitive* p) : Joint(p, NULL, G3D::CoordinateFrame(), G3D::CoordinateFrame()) {}

	// SYNTHETIC: WEBSERVICE 0x1011b590
	// RBX::FreeJoint::`scalar deleting destructor'

	static bool isFreeJoint(const Joint* joint) { return joint->getJointType() == FREE_JOINT; }

private:
	// FUNCTION: WEBSERVICE 0x1011b5b0
	virtual JointType getJointType() const { return FREE_JOINT; } // vtable+0x14
};


}
