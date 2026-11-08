#pragma once
// >>> native-status (generated) -- do not edit >>>
// Joints2008 | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src b941dedb | roc native-status --write
// 2008-06 native RBX::Joint family (inactive): Joint, RigidJoint, WeldJoint, SnapJoint, MultiJoint, RotateJoint,
// DynamicRotateJoint, RotatePJoint, RotateVJoint, GlueJoint, MotorJoint. Declared under a non-colliding name: the
// original paths v8world/Joint.h, RigidJoint.h, ... are reached through the donor Primitive.h (which includes
// RigidJoint.h) by every unit that includes Primitive.h / World.h / PartInstance.h / JointInstance.h, so a header at an
// original path would shadow the donor for nearly all recorders (see the proposal in
// tests/record_native_world_joints.py). A unit must not include both this header and a donor joint header (or
// v8world/Primitive.h / World.h, which include them).
// The bases Edge / IPipelined come from the donor v8world/Edge.h (Edge ends at +0x20: Joint::setPrimitive 006456e0
// reads prim0 / prim1 at +0xc / +0x10 and calls Edge::setPrimitive 00659290).
// Every Joint field, slot and size below is read from the 2008-06 binary:
//   RTTI     Joint 0084ad44 -> Edge -> IPipelined; RigidJoint 0083e07c, WeldJoint 0083e0bc, SnapJoint 0083e0fc
//            -> RigidJoint -> Joint; MultiJoint 0084ae14 -> Joint; RotateJoint 0084adc4, GlueJoint 0084ae7c ->
//            MultiJoint; RotatePJoint 0083e13c, RotateVJoint 0083e17c -> DynamicRotateJoint -> RotateJoint (no
//            DynamicRotateJoint vtable exists: __declspec(novtable)); MotorJoint 0083f764 -> Joint. All mdisp 0.
//   slots    15 in every joint vtable: 0 scalar deleting dtor, 1 putInKernel, 2 removeFromKernel, 3 getEdgeType
//            (00416690 `xor eax, eax` = JOINT), 4 Joint::setPrimitive 006456e0, 5 getJointType, 6 isBreakable,
//            7 isBroken, 8 joinsFace (005eed40 `xor al, al; ret 8`), 9 isAligned, 10 align (Joint 005e28c0 returns
//            CoordinateFrame()), 11 / 12 two `bool () const` slots (Joint 0060a2f0 false; RotateP/V 00565950 true
//            for both; MotorJoint false / true), 13 `void ()` (Joint 0047d410 empty; RotateP 00645cb0, RotateV
//            00645d00), 14 `void (int)` (Joint 0070bdf0 `ret 4`; MotorJoint 005e5e70, RotateP/V 006463f0).
//            The donor names 12 / 14 canStepUi / stepUi (MotorJoint::stepUi is 005e5e70); 11 / 13 have no donor
//            declaration: canStepWorld / stepWorld are analog names (RotateP 00645cb0 feeds the kernel input
//            every step, RotateV 00645d00 divides by the world/kernel step counts).
//   sizes    Joint 0x88 (MotorJoint fields start at +0x88, ctor 005e5bf0; MultiJoint::init 006468a0 starts at +0x88);
//            MultiJoint 0xc0 (init writes +0x88..+0xbc); RotateJoint 0xc4 (RotateJoint::surfaceTypeToJoint 00645e40
//            news 0xc4); RotatePJoint / RotateVJoint 0xc8 (same function news 0xc8); GlueJoint 0x120
//            (GlueJoint::canBuildJoint 00646f60 news 0x120); MotorJoint 0x98 (VelocityMotor creator 0060bbb0 news
//            0x98, TANDEM 2026-11-03).
//   ctor     Joint() 006456a0: Edge(NULL, NULL) 00659260, vtable, jointOwner +0x20 = 0, active +0x24 = 0,
//            CoordinateFrame() 004782d0 at +0x28 and +0x58. Joint(p0, p1, c0, c1) 006455c0: the same, then
//            Math::snapToGrid(c, 0.1f) 005deed0 copied into +0x28 / +0x58.
//   dtor     ~Joint 00645490 only restores the vtable (no assertion in 2008).
#include <G3D/CoordinateFrame.h>
#include <G3D/Vector2.h>
#include "v8world/Edge.h"
#include "v8kernel/Link.h"
#include "util/NormalId.h"
#include "util/SurfaceType.h"
#include "util/Face.h"

struct NativeWorldJointsLayout;

namespace RBX
{
	class IJointOwner;
	class Connector;
	class Point;
	class Kernel;
	class RotateConnector;

	class Joint : public Edge
	{
		friend struct ::NativeWorldJointsLayout; // tests/NativeWorldJointsLayout.cpp offset asserts

	public:
		enum JointType
		{
			NO_JOINT,          // 00416690 (Joint / RigidJoint / MultiJoint slot 5)
			ROTATE_JOINT,      // RotateJoint slot 5 007286a0 `mov eax, 1`
			ROTATE_P_JOINT,    // RotatePJoint slot 5 0077d810 `mov eax, 2`
			ROTATE_V_JOINT,    // RotateVJoint slot 5 005e2790 `mov eax, 3`
			GLUE_JOINT,        // GlueJoint slot 5 006fa3f0 `mov eax, 4`
			ANCHOR_JOINT,
			WELD_JOINT,        // WeldJoint slot 5 005cb9d0 `mov eax, 6`
			SNAP_JOINT,        // SnapJoint slot 5 0077d800 `mov eax, 7`
			MOTOR_JOINT,       // MotorJoint slot 5 0063e420 `mov eax, 8`
			FREE_JOINT
		};

	private:
		IJointOwner* jointOwner;              // +0x20
	protected:
		bool active;                          // +0x24
		G3D::CoordinateFrame jointCoord0;     // +0x28
		G3D::CoordinateFrame jointCoord1;     // +0x58

	protected:
		virtual Edge::EdgeType getEdgeType() const         // slot 3
		{
			return JOINT;
		}

	protected:
		Joint(Primitive* prim0, Primitive* prim1, const G3D::CoordinateFrame& _jointCoord0,
		      const G3D::CoordinateFrame& _jointCoord1);   // 006455c0
		Joint();                                           // 006456a0
	public:
		virtual ~Joint();                                  // 00645490 (slot 0 ??_G 00645680)

	public:
		virtual void setPrimitive(int i, Primitive* p);    // slot 4 (006456e0)
		virtual JointType getJointType() const             // slot 5
		{
			return NO_JOINT;
		}
		virtual bool isBreakable() const                   // slot 6
		{
			return false;
		}
		virtual bool isBroken() const                      // slot 7
		{
			return false;
		}
		virtual bool joinsFace(Primitive* p, NormalId face) const   // slot 8
		{
			return false;
		}
		virtual bool isAligned()                           // slot 9
		{
			return true;
		}
		virtual G3D::CoordinateFrame align(Primitive* pMove, Primitive* pStay)   // slot 10 (005e28c0)
		{
			return G3D::CoordinateFrame();
		}
		virtual bool canStepWorld() const                  // slot 11 (analog name)
		{
			return false;
		}
		virtual bool canStepUi() const                     // slot 12
		{
			return false;
		}
		virtual void stepWorld()                           // slot 13 (analog name)
		{
		}
		virtual void stepUi(int uiStepId)                  // slot 14
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
		void setJointCoord(int i, const G3D::CoordinateFrame& c);   // 00645750
		const G3D::CoordinateFrame& getJointCoord(int i) const
		{
			return i == 0 ? jointCoord0 : jointCoord1;
		}

	private:
		static bool canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1, float angleMax,
		                          float planarMax);                                     // 006454b0
	protected:
		static bool canBuildJointLoose(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1);   // 00645590
		static bool canBuildJointTight(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1);   // 00645560
	};

	class RigidJoint : public Joint
	{
		friend struct ::NativeWorldJointsLayout;

	public:
		RigidJoint(Primitive* prim0, Primitive* prim1, const G3D::CoordinateFrame& _jointCoord0,
		           const G3D::CoordinateFrame& _jointCoord1)
			: Joint(prim0, prim1, _jointCoord0, _jointCoord1)
		{
		}
		RigidJoint()
			: Joint()
		{
		}
		virtual ~RigidJoint() {}                           // ??_G 005e2760 (calls ~Joint 00645490)

	public:
		virtual bool isAligned();                                                  // slot 9 (00645870)
		virtual G3D::CoordinateFrame align(Primitive* pMove, Primitive* pStay);   // slot 10 (006458d0)
		G3D::CoordinateFrame getChildInParent(Primitive* parent, Primitive* child);   // 00645930

	protected:
		static void faceIdToCoords(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1,
		                           G3D::CoordinateFrame& c0, G3D::CoordinateFrame& c1);   // 00645980
	};

	class WeldJoint : public RigidJoint
	{
	private:
		virtual Joint::JointType getJointType() const      // slot 5 (005cb9d0)
		{
			return WELD_JOINT;
		}

	public:
		WeldJoint(Primitive* prim0, Primitive* prim1, const G3D::CoordinateFrame& _jointCoord0,
		          const G3D::CoordinateFrame& _jointCoord1)
			: RigidJoint(prim0, prim1, _jointCoord0, _jointCoord1)
		{
		}
		WeldJoint()
			: RigidJoint()
		{
		}
		virtual ~WeldJoint() {}                            // ??_G folds with RigidJoint's 005e2760
	};

	class SnapJoint : public RigidJoint
	{
	private:
		virtual Joint::JointType getJointType() const      // slot 5 (0077d800)
		{
			return SNAP_JOINT;
		}

	public:
		SnapJoint(Primitive* prim0, Primitive* prim1, const G3D::CoordinateFrame& _jointCoord0,
		          const G3D::CoordinateFrame& _jointCoord1)
			: RigidJoint(prim0, prim1, _jointCoord0, _jointCoord1)
		{
		}
		SnapJoint()
			: RigidJoint()
		{
		}
		virtual ~SnapJoint() {}                            // ??_G folds with RigidJoint's 005e2760
	};

	// MultiJoint::init 006468a0 writes numBreakingConnectors +0xbc, numConnector +0x88, then point[2i] +0x8c,
	// point[2i+1] +0x90, connector[i] +0xac for i < 4; addToMultiJoint 00646980 indexes +0x8c / +0x90 by 8 and +0xac
	// by 4; isBroken 00646a80 walks connector[] up to numBreakingConnectors.
	class MultiJoint : public Joint
	{
		friend struct ::NativeWorldJointsLayout;

	private:
		int numConnector;                 // +0x88
		Point* point[8];                  // +0x8c
		Connector* connector[4];          // +0xac
		int numBreakingConnectors;        // +0xbc

	private:
		void init(int numBreaking);                                      // 006468a0
	protected:
		virtual void putInKernel(Kernel* _kernel);                      // slot 1 (00646970)
		virtual void removeFromKernel();                                // slot 2 (006469e0)
		virtual bool isBroken() const;                                  // slot 7 (00646a80)
		void addToMultiJoint(Point* point0, Point* point1, Connector* _connector);   // 00646980
		Point* getPoint(int id);                                        // 006469d0
		float getJointK();                                              // 00646af0

	protected:
		MultiJoint(Primitive* p0, Primitive* p1, const G3D::CoordinateFrame& jointCoord0,
		           const G3D::CoordinateFrame& jointCoord1, int numBreaking);   // 00646920
		MultiJoint(int numBreaking);                                    // 00646900
		virtual ~MultiJoint();                                          // 00646960 (??_G 00646ac0)
	};

	class RotateJoint : public MultiJoint
	{
		friend struct ::NativeWorldJointsLayout;

	protected:
		RotateConnector* rotateConnector; // +0xc0 (ctors 00645a70 / 00645a90 clear it)

	private:
		virtual void putInKernel(Kernel* _kernel);                      // slot 1 (00646550)
		virtual void removeFromKernel();                                // slot 2 (00645ae0)
		virtual Joint::JointType getJointType() const                   // slot 5 (007286a0)
		{
			return ROTATE_JOINT;
		}
	protected:
		float getTorqueArmLength();
		float getChannelValue(int uiStepId);                            // 00645af0

	public:
		RotateJoint(Primitive* axlePrim, Primitive* holePrim, const G3D::CoordinateFrame& c0,
		            const G3D::CoordinateFrame& c1);                    // 00645a90
		RotateJoint();                                                  // 00645a70
		virtual ~RotateJoint();                                         // 00645ad0 (??_G 00645e10)

	private:
		static RotateJoint* surfaceTypeToJoint(SurfaceType surfaceType, Primitive* axlePrim, Primitive* holePrim,
		                                       const G3D::CoordinateFrame& c0, const G3D::CoordinateFrame& c1);   // 00645e40
	public:
		static RotateJoint* canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1);   // 00645f60
	};

	// No vtable of its own (RTTI-only base of RotatePJoint / RotateVJoint). The float at +0xc4 is cleared by the
	// RotateP / RotateV constructors (00645d90, 00645dd0, the inline default constructor in 005e4c60) and set from
	// getChannelValue 00645af0 by the shared stepUi 006463f0; both stepWorld bodies read it.
	class __declspec(novtable) DynamicRotateJoint : public RotateJoint
	{
		friend struct ::NativeWorldJointsLayout;

	protected:
		float channelValue;               // +0xc4 (analog name)

	private:
		virtual bool canStepWorld() const                               // slot 11 (00565950)
		{
			return true;
		}
		virtual bool canStepUi() const                                  // slot 12 (00565950)
		{
			return true;
		}
		virtual void stepUi(int uiStepId);                              // slot 14 (006463f0)

	protected:
		DynamicRotateJoint(Primitive* axlePrim, Primitive* holePrim, const G3D::CoordinateFrame& c0,
		                   const G3D::CoordinateFrame& c1)
			: RotateJoint(axlePrim, holePrim, c0, c1),
			  channelValue(0.0f)
		{
		}
		DynamicRotateJoint()
			: RotateJoint(),
			  channelValue(0.0f)
		{
		}
	};

	class RotatePJoint : public DynamicRotateJoint
	{
	private:
		virtual Joint::JointType getJointType() const                   // slot 5 (0077d810)
		{
			return ROTATE_P_JOINT;
		}
		virtual void stepWorld();                                       // slot 13 (00645cb0)

	public:
		RotatePJoint(Primitive* axlePrim, Primitive* holePrim, const G3D::CoordinateFrame& c0,
		             const G3D::CoordinateFrame& c1);                   // 00645d90
		RotatePJoint()
			: DynamicRotateJoint()
		{
		}
		// No user-declared destructor: the scalar deleting destructor 005e28e0 calls ~RotateJoint 00645ad0 without
		// storing the RotatePJoint vtable first (an implicit destructor).
	};

	class RotateVJoint : public DynamicRotateJoint
	{
	private:
		virtual Joint::JointType getJointType() const                   // slot 5 (005e2790)
		{
			return ROTATE_V_JOINT;
		}
		virtual void stepWorld();                                       // slot 13 (00645d00)

	public:
		RotateVJoint(Primitive* axlePrim, Primitive* holePrim, const G3D::CoordinateFrame& c0,
		             const G3D::CoordinateFrame& c1);                   // 00645dd0
		RotateVJoint()
			: DynamicRotateJoint()
		{
		}
		// No user-declared destructor (??_G folds with RotatePJoint's 005e28e0).
	};

	// GlueJoint() 00646b60 zeroes +0xc0..+0x11c (two Faces of four Vector3s); getMaxForce 00646c10 reads
	// overlapInP0 corners c0 +0xc0, c1 +0xcc, c3 +0xe4 (Face::size).
	class GlueJoint : public MultiJoint
	{
		friend struct ::NativeWorldJointsLayout;

	private:
		Face overlapInP0;                 // +0xc0
		Face overlapInP1;                 // +0xf0

	private:
		float getMaxForce();                                            // 00646c10
		virtual void putInKernel(Kernel* _kernel);                      // slot 1 (00647190)
		virtual Joint::JointType getJointType() const                   // slot 5 (006fa3f0)
		{
			return GLUE_JOINT;
		}
		virtual bool isBreakable() const                                // slot 6 (00565950)
		{
			return true;
		}

	public:
		GlueJoint(Primitive* p0, Primitive* p1, const G3D::CoordinateFrame& jointCoord0,
		          const G3D::CoordinateFrame& jointCoord1);             // 00646cc0
		GlueJoint();                                                    // 00646b60
		// No user-declared destructor: the scalar deleting destructor 00646ca0 calls ~MultiJoint 00646960 without
		// storing the GlueJoint vtable first (an implicit destructor).

	public:
		static GlueJoint* canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1);   // 00646f60
	};

	// MotorJoint() 005e5bf0: Joint(), vtable, link +0x88 = new RevoluteLink (0xd0: Link() 00613d20, jointAngle +0xcc,
	// vtable 0083f75c), currentAngle +0x8c, maxVelocity +0x90, desiredAngle +0x94 = 0. No polarity field in 2008.
	// ~MotorJoint 005e5e00 deletes the link (non-virtual ~Link 0047d410) before ~Joint.
	class MotorJoint : public Joint
	{
		friend struct ::NativeWorldJointsLayout;

	private:
		RevoluteLink* link;               // +0x88
		float currentAngle;               // +0x8c
	public:
		float maxVelocity;                // +0x90
		float desiredAngle;               // +0x94

	private:
		virtual Joint::JointType getJointType() const                   // slot 5 (0063e420)
		{
			return MOTOR_JOINT;
		}
		virtual bool isBroken() const                                   // slot 7 (0060a2f0)
		{
			return false;
		}
		virtual bool isAligned();                                       // slot 9 (005e5d00)
		virtual bool canStepUi() const                                  // slot 12 (00565950)
		{
			return true;
		}

	public:
		float getCurrentAngle() const
		{
			return currentAngle;
		}
		void setCurrentAngle(float value);                              // 005e5da0
		virtual void stepUi(int uiStepId);                              // slot 14 (005e5e70)

	public:
		MotorJoint();                                                   // 005e5bf0
		virtual ~MotorJoint();                                          // 005e5e00 (??_G 005e5ee0)

	public:
		RevoluteLink* resetLink();                                      // 005e5c90
	};
}
