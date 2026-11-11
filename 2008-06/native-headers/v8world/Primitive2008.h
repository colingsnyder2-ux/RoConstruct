#pragma once
// 2008-06 native RBX::Primitive and RBX::EdgeList (inactive). Declared under a non-colliding name: the original path
// v8world/Primitive.h is reached by every unit that includes PartInstance.h / World.h, and a unit must not include
// both this header and the donor v8world/Primitive.h. The base IPipelined comes from native-headers/v8kernel/
// IPipelined2008.h (the native 2008 declaration, so this header can be included next to v8kernel/Body2008.h); a unit
// that also includes the donor v8world/Edge.h (for example through v8world/Contact2008.h) defines
// NATIVE_IPIPELINED2008_DONOR and gets the donor IPipelined of the same layout (see IPipelined2008.h).
// Every field, slot and size below is read from the 2008-06 binary:
//   RTTI     vtable 0083f83c .?AVPrimitive@RBX@@ -> IPipelined (mdisp 0); 4 slots: 0 scalar deleting destructor
//            005e83a0 (calls ~Primitive 005e7df0), 1 IPipelined::putInKernel 00645830, 2 IPipelined::removeFromKernel
//            00645860, 3 getRadius 005e7f10 (geometry->getRadius(), Geometry slot 4, as a tail jump).
//   size     0xfc: the PartInstance constructor 0059d4d0 / destructor 0059b970 embed the Primitive at +0x228
//            (part-embedded-primitive-evidence.json); ComputeProp JointK (0x10) ends at +0xfc.
//   ctor     005e8770 (Primitive(Geometry::GeometryType)): currentStage +0x4 = 0, vtable, guid +0x8 (Guid() 005a8300),
//            guidSetExternally +0x10 = false, +0x14 = 1, contacts EdgeList +0x18 (owner +0x18 = this, two Arrays
//            zeroed), joints EdgeList +0x34 (owner = this), +0x50 = -1, +0x54 = -1, world +0x58 = 0, clump +0x5c = 0,
//            clumpDepth +0x60 = -1, spatialNodes +0x64 = 0, oldSpatialMin +0x68 / oldSpatialMax +0x74 = 0, fuzzyExtents
//            +0x80 = (Vector3::inf(), -Vector3::inf()) (G3D::Vector3::inf 00510960), fuzzyExtentsStateId +0x98 = -2,
//            geometry +0x9c = newGeometry(type) 005e7d80, body +0xa0 = new Body (0xdc, Body() 006149c0), myOwner +0xa4
//            = 0, bytes +0xa8..+0xab = false, canCollide +0xac = true, friction +0xb0 = 0, elasticity +0xb4 =
//            [0082f840], controller +0xe8 = NullController::getStaticNullController() (its function-local static
//            00976384 under guard 00976390, inlined), JointK +0xec (dirty +0xf0 = true, object +0xf4 = this, getFunc
//            +0xf8 = computeJointK 005e7580), then surfaceType[i] +0xb8 / surfaceData[i] +0xd0 = 0 for i < 6.
//   fields   setUnknown0x14 005e7420 writes +0x14 (int) only while world +0x58 is NULL (evidence name); setGuid
//            005e7450 copies the Guid (+0x8, Guid::operator= 005a8200) and sets +0x10; setWorld 006fd220 (+0x58);
//            setClump 005e7550 / getClump 00469080 / getAssembly 005e7560 (clump +0x5c, Clump +0x24); getClumpDepth
//            006d45e0 (+0x60); getFastFuzzyExtents 005e7a50 (fuzzyExtents +0x80, fuzzyExtentsStateId +0x98 against
//            Body::stateIndex +0x90); computeJointK 005e7580 / ContactManager::createContact 0060d770 (geometry +0x9c);
//            getCoordinateFrame 005e82c0 (body +0xa0, Body::pv +0x94); PartInstance::fromPrimitiveConst 00599f80
//            (myOwner +0xa4, IMoving at PartInstance +0x1c0); setDragging 005e8050 (+0xa8) and the two setters
//            005e80d0 (+0xa9) / 005e8140 (+0xaa) that recompute `dragging || anchored || jointAnchored` and notify the
//            world (005e94a0 / 005e94e0); 005e75e0 (+0xab, no notification); getCanCollide 0047edc0 (+0xac) and its
//            setter 005e75b0 (notifies World 005e9460); Contact::onPrimitiveContactParametersChanged 00607ad0
//            (friction +0xb0, elasticity +0xb4, JointK +0xec..+0xf8); setSurfaceType 005e7850 (+0xb8 + 4 * face);
//            setController 005e85e0 / getController 00574fb0 (+0xe8).
//   EdgeList 0x1c: owner +0x0, G3D::Array<Edge*> edges +0x4, G3D::Array<Primitive*> otherPrimitives +0x10 (insertEdge
//            005e8990 appends the Edge with Array<Edge*>::append 005e6640 and the edge's other primitive with
//            Array<Primitive*>::append 0059a190; removeEdge 005e8610; ~EdgeList 005e7910 out of line). The Edge keeps
//            its index in each list at +0x14 / +0x18 (getNextContact 005e7be0: `index + 1 < contacts.edges.size()`).
//   Names of +0x14, +0x50, +0x54, +0x64, +0xa9, +0xaa and +0xab are analog names (as in native-headers/
//   part-embedded/v8world/Primitive.h); offsets and types are the binary's.
#include <G3D/Array.h>
#include <G3D/CoordinateFrame.h>
#include "v8kernel/IPipelined2008.h"
#include "v8world/Geometry2008.h"
#include "util/Guid.h"
#include "util/Vector3int32.h"
#include "util/Extents.h"
#include "util/SurfaceType.h"
#include "util/ComputeProp.h"

struct NativeBodyPrimitive2008Layout;
struct NativeContactUnit2008Layout;

namespace RBX
{
	class Body;
	class Clump;
	class Contact;
	class Controller;
	class Edge;
	class IMoving;
	class Primitive;
	class SpatialNode;
	class SurfaceData;
	class World;

	class EdgeList
	{
		friend struct ::NativeBodyPrimitive2008Layout;
		friend struct ::NativeContactUnit2008Layout;

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
		friend struct ::NativeBodyPrimitive2008Layout;   // tests/NativeBodyPrimitive2008Layout.cpp offset asserts
		friend struct ::NativeContactUnit2008Layout;

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
// Declarations proven by closure symbols of byte-exact recovered methods.
public:
    void setCanSleep(bool);
	};
}
