// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_2442108b456880f1.cpp

// Candidate translation unit (score above; library headers required).
#define Joint Joint_unused_
#define IJointOwner IJointOwner_unused_
#include "v8world/Joint.h"
#undef Joint
#undef IJointOwner

#include <G3D/CoordinateFrame.h>
#include "v8world/Edge.h"
#include "util/NormalId.h"

namespace RBX
{
	class IJointOwner
	{
	};

	class ExeJointBase
	{
	public:
		virtual ~ExeJointBase();
		void* a; void* b; void* c; void* d;
		ExeJointBase() : a(0), b(0), c(0), d(0) {}
	};

	class Joint : public Edge, public ExeJointBase
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
}

#include "v8world/Primitive.h"
#include "v8world/World.h"
#include "util/Face.h"
#include "util/Math.h"

namespace RBX
{
	Joint::Joint(
		Primitive* prim0,
		Primitive* prim1,
		const G3D::CoordinateFrame& _jointCoord0,
		const G3D::CoordinateFrame& _jointCoord1)
		: Edge(prim0, prim1),
		  jointOwner(NULL)
	{
		jointCoord0 = Math::snapToGrid(_jointCoord0, 0.1f);
		jointCoord1 = Math::snapToGrid(_jointCoord1, 0.1f);
	}

}
