// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Primitive state setters of v8world/Primitive.cpp, application range 005e8000.. (inactive):
// getNextJoint 005e7ba0, getNextContact 005e7be0, setDragging 005e8050, setAnchor 005e80d0, clipToSafeSize 005e83c0,
// setGridSize 005e8470 and setPV 005e85b0.
// Flags: the sibling rows of native-classes/AppUnit5E4Primitive.cpp (/fp:fast).
//
// Unit-local redeclarations (pattern of ContactUnit2008ConnectorBody.cpp / BlockBlockContactStep.cpp), because the
// shared headers lack members this unit defines or calls; proposals are in the batch result:
//   - RBX::EdgeList / RBX::Primitive, copied from native-headers/v8world/Primitive2008.h (same bases, fields, offsets,
//     slots), plus the out-of-line members named by the identity registry (decorated signatures): setAnchor,
//     setCoordinateFrame, setPV, setGridSize, clipToSafeSize, and setMassInertia 005e8000 (called by setGridSize).
//   - RBX::World, copied from native-headers/v8world/World2008.h (no fields), plus the four notifications these
//     bodies call (005e91c0, 005e94a0, 005e94e0; names from the donor v8world/World.h by call site and order).
//   - RBX::Edge copied from native-classes/EdgeListInsert.cpp (native-headers/AppUnit658/Edge.h plus the inline
//     getIndex accessor that header lacks), RBX::Joint copied from native-headers/v8world/Joints2008.h and RBX::Contact
//     copied from native-headers/v8world/Contact2008.h (both headers include the donor v8world/Edge.h, which cannot sit
//     next to v8kernel/IPipelined2008.h), for getNextJoint 005e7ba0 / getNextContact 005e7be0.
// Parked (declarations missing from read-only headers, see the batch result): getAssembly 005e7570 and
// setCoordinateFrame 005e8200 read the 2008 Clump (+0x24 assembly) and Assembly (+0x24 -> +0x1c root primitive,
// notifyMoved 005e6170), which no native header declares (the donor Clump.h puts assembly at +0x20; the native-world
// openrbx port Clump.h / Assembly.h carries the WEBSERVICE layout). RBX::getJoint 0064ca60 belongs to the ClumpStage unit
// (next to 0064cc40 / 0064ccf0) and already has a body in native-world/App/v8world/ClumpStage.cpp: not duplicated.
// Primitive2008.h and World2008.h are therefore not included here. The Body is the native 2008 Body
// (native-headers/v8kernel/Body2008.h): setVelocity 00614040.
#include <math.h>
#include <G3D/Array.h>
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>
#include "v8kernel/IPipelined2008.h"
#include "v8kernel/Body2008.h"
#include "v8world/Geometry2008.h"
#include "util/Guid.h"
#include "util/Vector3int32.h"
#include "util/Extents.h"
#include "util/SurfaceType.h"
#include "util/ComputeProp.h"
#include "util/NormalId.h"
#include "util/PV.h"

struct NativeWorldJointsLayout;
struct NativeWorldShapesLayout;

namespace RBX
{
	class Assembly;
	class Body;
	class Clump;
	class Contact;
	class ContactConnector;
	class Controller;
	class IJointOwner;
	class Kernel;
	class Edge;
	class IMoving;
	class Joint;
	class Primitive;
	class SpatialNode;
	class SurfaceData;

	class World
	{
	public:
		void onJointPrimitiveNulling(Joint* j, Primitive* p);
		void onJointPrimitiveSet(Joint* j, Primitive* p);
		void insertJoint(Joint* j);
		void removeJoint(Joint* j);
		void ticklePrimitive(Primitive* p, int value);

		// Not in World2008.h (proposal). 005e91c0: contactManager (+0x84) -> 0060cc50 (tail jump).
		void onPrimitiveExtentsChanged(Primitive* p);
		// Not in World2008.h (proposal). 005e94a0 / 005e94e0: walk the stage chain from +0x88 to stage type 2 and
		// call 0064cc40 / 0064ccf0 (the "June anchor swap" pair of native-world ClumpStage).
		void onPrimitiveAddedAnchor(Primitive* p);
		void onPrimitiveRemovingAnchor(Primitive* p);
	};

	class EdgeList
	{
	public:
		Primitive* owner;                                // +0x0
		G3D::Array<Edge*> edges;                         // +0x4
		G3D::Array<Primitive*> otherPrimitives;          // +0x10

	public:
		EdgeList(Primitive* owner) : owner(owner) {}
		~EdgeList();                                     // 005e7910

		void insertEdge(Edge* e);                        // 005e8990
		void removeEdge(Edge* e);                        // 005e8610
	};

	class Primitive : public IPipelined
	{
	private:
		Guid guid;                                       // +0x8
		bool guidSetExternally;                          // +0x10
		int unknown0x14;                                 // +0x14 (setUnknown0x14 005e7420)
		EdgeList contacts;                               // +0x18
		EdgeList joints;                                 // +0x34
		int worldIndex;                                  // +0x50
		int traverseId;                                  // +0x54
		World* world;                                    // +0x58
		Clump* clump;                                    // +0x5c
		int clumpDepth;                                  // +0x60
		SpatialNode* spatialNodes;                       // +0x64
		Vector3int32 oldSpatialMin;                      // +0x68
		Vector3int32 oldSpatialMax;                      // +0x74
		mutable Extents fuzzyExtents;                    // +0x80
		mutable int fuzzyExtentsStateId;                 // +0x98
	protected:
		Geometry* geometry;                              // +0x9c
		Body* body;                                      // +0xa0
		IMoving* myOwner;                                // +0xa4
		bool dragging;                                   // +0xa8
		bool anchored;                                   // +0xa9
		bool jointAnchored;                              // +0xaa
		bool canSleep;                                   // +0xab
		bool canCollide;                                 // +0xac
		float friction;                                  // +0xb0
		float elasticity;                                // +0xb4
		SurfaceType surfaceType[6];                      // +0xb8
		SurfaceData* surfaceData[6];                     // +0xd0
		Controller* controller;                          // +0xe8
		ComputeProp<float, Primitive> JointK;            // +0xec

	protected:
		float computeJointK() const;                     // 005e7580

	private:
		// Not in Primitive2008.h (proposal): ?clipToSafeSize@Primitive@RBX@@AAE?AVVector3@G3D@@ABV34@@Z (private).
		G3D::Vector3 clipToSafeSize(const G3D::Vector3& newSize);   // 005e83c0

	public:
		Primitive(Geometry::GeometryType geometryType);  // 005e8770
		virtual ~Primitive();                            // 005e7df0 (slot 0 ??_G 005e83a0)
		virtual float getRadius() const;                 // slot 3 (005e7f10)

		void setUnknown0x14(int value);                  // 005e7420 (evidence name)
		World* getWorld() const
		{
			return world;
		}
		Clump* getClump() const
		{
			return clump;
		}
		int getClumpDepth() const
		{
			return clumpDepth;
		}
		const Geometry* getGeometry() const
		{
			return geometry;
		}
		Geometry* getGeometry()
		{
			return geometry;
		}
		Body* getBody()
		{
			return body;
		}
		const Body* getBody() const
		{
			return body;
		}
		IMoving* getOwner() const
		{
			return myOwner;
		}
		bool getDragging() const
		{
			return dragging;
		}
		void setDragging(bool _dragging);                // 005e8050
		const bool getCanCollide() const
		{
			return canCollide;
		}
		float getFriction() const
		{
			return friction;
		}
		float getElasticity() const
		{
			return elasticity;
		}
		float getJointK() const
		{
			return JointK;
		}
		void setSurfaceType(NormalId id, SurfaceType type);   // 005e7850
		void setController(Controller* _controller);     // 005e85e0
		Controller* getController()
		{
			return controller;
		}

		const G3D::CoordinateFrame& getCoordinateFrame() const;   // 005e82c0
		const Extents& getFastFuzzyExtents() const;      // 005e7a50 (00606ce6 / 00606cee)

		Contact* getFirstContact();                      // 005e7bd0
		Contact* getNextContact(Contact* prev);          // 005e7be0
		// Not in Primitive2008.h (proposal); decorated signatures from work/2008-06/identity-registry.json.
		Joint* getFirstJoint() const;                    // 005e7b90 ?getFirstJoint@Primitive@RBX@@QBEPAVJoint@2@XZ
		Joint* getNextJoint(Joint* prev) const;          // 005e7ba0 ?getNextJoint@Primitive@RBX@@QBEPAVJoint@2@PAV32@@Z

		static void onNewTouch(Primitive* p0, Primitive* p1);   // 005e7530 (Contact::step 00606c6f)
		void setCanSleep(bool);                          // closure symbol (Primitive2008.h)

		// Not in Primitive2008.h (proposal); decorated signatures from work/2008-06/identity-registry.json.
		void setAnchor(bool _anchored);                  // 005e80d0 ?setAnchor@Primitive@RBX@@QAEX_N@Z
		void setCoordinateFrame(const G3D::CoordinateFrame& value);   // 005e8200
		void setPV(const PV& pv);                        // 005e85b0 ?setPV@Primitive@RBX@@QAEXABVPV@2@@Z
		void setMassInertia(float mass);                 // 005e8000 (donor name; Body::setMass 006140b0 /
		                                                 // setMoment 00614110 of geometry slot 6 getMoment)
		void setGridSize(const G3D::Vector3& gridSize);  // 005e8470 ?setGridSize@Primitive@RBX@@QAEXABVVector3@G3D@@@Z
	};

	namespace Sim
	{
		enum EdgeState
		{
			UNDEFINED,
			STEPPING,
			SLEEPING,
			TOUCHING,
			TOUCHING_SLEEPING
		};
	}

	// Copied from native-classes/EdgeListInsert.cpp (see the header comment of this unit).
	class __declspec(novtable) Edge : public IPipelined
	{
	public:
		enum EdgeType
		{
			JOINT,
			CONTACT
		};

	private:
		Sim::EdgeState edgeState;                      // +0x8
		Primitive* prim0;                              // +0xc
		Primitive* prim1;                              // +0x10
		int index0;                                    // +0x14 (index in prim0's EdgeList, -1 = none)
		int index1;                                    // +0x18 (index in prim1's EdgeList, -1 = none)
		bool inEdgeList;                               // +0x1c

	public:
		Edge(Primitive* prim0, Primitive* prim1);      // 00659260
		virtual ~Edge() {}                             // slot 0

		virtual EdgeType getEdgeType() const = 0;      // slot 3
		virtual void setPrimitive(int i, Primitive* p);   // slot 4 (00659290)

		// Not in AppUnit658/Edge.h (proposal); inlined in 005e7ba0 / 005e7be0 / 005e8610 / 005e8990.
		int getIndex(const Primitive* p) const
		{
			return p == prim0 ? index0 : index1;
		}
	};

	// Copied from native-headers/v8world/Joints2008.h.
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

	// Copied from native-headers/v8world/Contact2008.h.
	class __declspec(novtable) Contact : public Edge
	{
		friend struct ::NativeWorldShapesLayout;

	private:
		int lastContactStep;   // +0x20
		int steppingIndex;     // +0x24
		float jointK;          // +0x28
		float elasticJointK;   // +0x2c
		float kFriction;       // +0x30

	private:
		virtual void putInKernel(Kernel* _kernel)       // slot 1 (0060cb10)
		{
			IPipelined::putInKernel(_kernel);
			onPrimitiveContactParametersChanged();
		}
		virtual void removeFromKernel()                 // slot 2 (0060cb30)
		{
			deleteAllConnectors();
			IPipelined::removeFromKernel();
		}
		virtual Edge::EdgeType getEdgeType() const      // slot 3 (007286a0, folded)
		{
			return CONTACT;
		}

	protected:
		void deleteConnector(ContactConnector*& c);     // 00606d10
		virtual void deleteAllConnectors() = 0;         // slot 5
		virtual bool stepContact() = 0;                 // slot 6

	public:
		Contact(Primitive* prim0, Primitive* prim1);    // 00606c20

		virtual bool computeIsColliding(float overlapIgnored) = 0;   // slot 7
		virtual int numConnectors() const = 0;                       // slot 8 (analog name)
		virtual ContactConnector* getConnector(int i) = 0;           // slot 9 (analog name)

		void onPrimitiveContactParametersChanged();     // 00607ad0
	};

	// 005e7ba0: the index of prev in this primitive's list (+0x14 when this is prim0 +0xc, else +0x18) plus one, checked
	// against joints.edges.size() (+0x3c), returns joints.edges[i] (+0x38) or NULL. Caller: RBX::getJoint 0064ca60.
	Joint* Primitive::getNextJoint(Joint* prev) const
	{
		int i = prev->getIndex(this) + 1;
		return i < joints.edges.size() ? static_cast<Joint*>(joints.edges[i]) : NULL;
	}

	// 005e7be0: as getNextJoint, on contacts (edges.size() +0x20, data +0x1c).
	Contact* Primitive::getNextContact(Contact* prev)
	{
		int i = prev->getIndex(this) + 1;
		return i < contacts.edges.size() ? static_cast<Contact*>(contacts.edges[i]) : NULL;
	}

	// 005e8050: the anchored state `dragging || anchored || jointAnchored` (+0xa8 / +0xa9 / +0xaa) before and after
	// the store; on a change the world (+0x58) is told 005e94a0 (now anchored) or 005e94e0 (no longer), as tail jumps.
	void Primitive::setDragging(bool _dragging)
	{
		bool oldAnchored = dragging || anchored || jointAnchored;
		if (dragging != _dragging)
		{
			dragging = _dragging;
			bool newAnchored = dragging || anchored || jointAnchored;
			if (newAnchored != oldAnchored && world)
			{
				if (newAnchored)
					world->onPrimitiveAddedAnchor(this);
				else
					world->onPrimitiveRemovingAnchor(this);
			}
		}
	}

	// 005e80d0: as setDragging, on anchored (+0xa9).
	void Primitive::setAnchor(bool _anchored)
	{
		bool oldAnchored = dragging || anchored || jointAnchored;
		if (anchored != _anchored)
		{
			anchored = _anchored;
			bool newAnchored = dragging || anchored || jointAnchored;
			if (newAnchored != oldAnchored && world)
			{
				if (newAnchored)
					world->onPrimitiveAddedAnchor(this);
				else
					world->onPrimitiveRemovingAnchor(this);
			}
		}
	}

	// 005e83c0: each axis clipped to 512 ([00823c70], Vector3::min: z, y, x order of the G3D::min arguments), then a
	// volume above 1e6 ([00823e04]) shrinks y to floor(1e6 / (x * z)) (MSVCR90 floor).
	G3D::Vector3 Primitive::clipToSafeSize(const G3D::Vector3& newSize)
	{
		G3D::Vector3 answer = newSize.min(G3D::Vector3(512.0f, 512.0f, 512.0f));
		const float maxVolume = 1000000.0f;
		if (answer.x * answer.y * answer.z > maxVolume)
			answer.y = floor(maxVolume / (answer.x * answer.z));
		return answer;
	}

	// 005e8470: on a changed clipped size: fuzzyExtentsStateId (+0x98) = -2, geometry (+0x9c) slot 3 setGridSize,
	// setMassInertia 005e8000 of slot 7 getGridVolume, world 005e91c0, JointK dirty (+0xf0).
	void Primitive::setGridSize(const G3D::Vector3& gridSize)
	{
		G3D::Vector3 safe = clipToSafeSize(gridSize);
		if (safe != geometry->getGridSize())
		{
			fuzzyExtentsStateId = -2;
			geometry->setGridSize(safe);
			setMassInertia(geometry->getGridVolume());
			if (world)
				world->onPrimitiveExtentsChanged(this);
			JointK.setDirty();
		}
	}

	// 005e85b0: body (+0xa0) Body::setVelocity 00614040 of pv.velocity (+0x30), then setCoordinateFrame 005e8200 of
	// pv.position.
	void Primitive::setPV(const PV& pv)
	{
		body->setVelocity(pv.velocity);
		setCoordinateFrame(pv.position);
	}
}
