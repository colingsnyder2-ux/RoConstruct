// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Primitive state setters of v8world/Primitive.cpp, application range 005e8000.. (inactive):
// setDragging 005e8050, setAnchor 005e80d0, clipToSafeSize 005e83c0, setGridSize 005e8470 and setPV 005e85b0.
// Flags: the sibling rows of native-classes/AppUnit5E4Primitive.cpp (/fp:fast).
//
// Unit-local redeclarations (pattern of ContactUnit2008ConnectorBody.cpp / BlockBlockContactStep.cpp), because the
// shared headers lack members this unit defines or calls; proposals are in the batch result:
//   - RBX::EdgeList / RBX::Primitive, copied from native-headers/v8world/Primitive2008.h (same bases, fields, offsets,
//     slots), plus the out-of-line members named by the identity registry (decorated signatures): setAnchor,
//     setCoordinateFrame, setPV, setGridSize, clipToSafeSize, and setMassInertia 005e8000 (called by setGridSize).
//   - RBX::World, copied from native-headers/v8world/World2008.h (no fields), plus the four notifications these
//     bodies call (005e91c0, 005e94a0, 005e94e0; names from the donor v8world/World.h by call site and order).
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

namespace RBX
{
	class Assembly;
	class Body;
	class Clump;
	class Contact;
	class Controller;
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

	// 005e8050: the anchored state `dragging || anchored || jointAnchored` (+0xa8 / +0xa9 / +0xaa) before and after
	// the store; on a change the world (+0x58) is told 005e94a0 (now anchored) or 005e94e0 (no longer), as tail jumps.
	void Primitive::setDragging(bool _dragging)
	{
		bool oldAnchored = dragging || anchored || jointAnchored;
		if (dragging != _dragging)
		{
			dragging = _dragging;
			bool newAnchored = dragging || anchored || jointAnchored;
			if (oldAnchored != newAnchored && world)
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
			if (oldAnchored != newAnchored && world)
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
		if (geometry->getGridSize() != safe)
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
