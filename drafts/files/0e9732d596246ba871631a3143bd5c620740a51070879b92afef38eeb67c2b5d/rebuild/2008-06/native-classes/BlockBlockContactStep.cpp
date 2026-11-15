// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::BlockBlockContact step path (inactive): computeIsColliding 00607c20, matchContactConnector
// 00607cc0, loadGeoPairEdgeEdge 00607ea0 and stepContact 00608830 (the Contact unit 00606b00..00608950).
// Field evidence: native-headers/leaves2008/BlockBlockContact2008.h (vtable 00843714, size 0x7c). Donor bodies:
// tools/rbxgs v8world/Contact.cpp (BlockBlockContact::matchContactConnector / loadGeoPairEdgeEdge).
//
// Declarations (batch 16): the shared headers, included on the 2008 Body path (NATIVE_PRIMITIVE_NATIVE_BODY):
// v8kernel/Connector2008.h, v8world/GeoPair2008.h, v8world/Contact2008.h, v8world/Block2008.h and
// leaves2008/BlockBlockContact2008.h (see the include block below). The only unit-local redeclaration left (pattern of
// BallBlockContactStep.cpp / ContactUnit2008ConnectorBody.cpp) is RBX::Primitive, copied from
// native-headers/v8world/Primitive2008.h (same bases, fields, offsets, slots), plus the inline static aaBoxCollide
// (fuzzyExtents +0x80 is private and is read directly by 00607c20 / 00608830; Primitive2008.h declares it out of line).
// The bases IPipelined / Edge are the native 2008 ones (AppUnit658/Edge.h -> v8kernel/IPipelined2008.h).
// deleteUnmatchedConnectors 00607e00 is in Leaves2008BlockBlockContact.cpp (beside deleteAllConnectors 00607c60).
// Parked: computePlaneContact 00608580 needs Body pv +0x94 without updatePV, the Block face-vertex table 0084aec8 and
// intersectRectQuad 00608160.
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include <G3D/Array.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Vector2.h>
#include <G3D/Vector3int16.h>
#include "AppUnit658/Edge.h"
#include "v8kernel/KernelIndex.h"
#include "v8world/Geometry2008.h"
#include "util/Guid.h"
#include "util/Vector3int32.h"
#include "util/Extents.h"
#include "util/SurfaceType.h"
#include "util/ComputeProp.h"
#include "util/NormalId.h"

struct NativeBodyPrimitive2008Layout;
struct NativeWorldJointsConnectorLayout;
struct NativeWorldShapesLayout;

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

		// Not in Primitive2008.h (proposal): inline in the 2008 binary. BlockBlockContact::computeIsColliding 00607c20
		// and stepContact 00608830 read fuzzyExtents (+0x80) of both primitives directly (`sub reg, -0x80`) and call
		// Extents::overlapsOrTouches 00606b60 (?overlapsOrTouches@Extents@RBX@@QBE_NABV12@@Z), with no state check.
		// Name and parameters: the donor Primitive.h (static bool aaBoxCollide(const Primitive&, const Primitive&)).
		static bool aaBoxCollide(const Primitive& p0, const Primitive& p1)
		{
			return p0.fuzzyExtents.overlapsOrTouches(p1.fuzzyExtents);
		}
	};

}

// The shared 2008 declarations (batch 16): v8kernel/Connector2008.h on the 2008 Body path (Body2008.h / GeoPair2008.h
// / Point2008.h, with the match / setEdgeEdge / setBody forwarders), v8world/Contact2008.h (createConnector 00606e00,
// contactPairMatches / contactPairMisses), v8world/Block2008.h (getEdgeNormal, getEdgeVertex 00606b00; now on
// GeoPair2008.h) and leaves2008/BlockBlockContact2008.h (matchContactConnector 00607cc0, getBestPlaneEdge 00607280,
// block(int)). They replace the former unit-local GeoPair / Connector / ContactConnector / Contact / Block /
// BlockBlockContact copies; the local Primitive above stays (Primitive2008.h declares aaBoxCollide out of line).
#include "v8kernel/Connector2008.h"
#include "v8world/Contact2008.h"
#include "v8world/Block2008.h"
#include "leaves2008/BlockBlockContact2008.h"

namespace RBX
{
	// Donor v8world/Contact.h inline (declared in BlockBlockContact2008.h; loadGeoPairEdgeEdge 00607ea0 reads the
	// geometry +0x9c of the primitive, 00607f3e..00607f42).
	inline Block* BlockBlockContact::block(int i)
	{
		return static_cast<Block*>(getPrimitive(i)->getGeometry());
	}

	// 00607c20
	bool BlockBlockContact::computeIsColliding(float overlapIgnored)
	{
		return Primitive::aaBoxCollide(*getPrimitive(0), *getPrimitive(1)) && getBestPlaneEdge(overlapIgnored);
	}

	// 00607cc0: donor v8world/Contact.cpp body; the 2008 one passes the bodies to createConnector 00606e00 and, after
	// a match, writes them into the matched connector (match accepts both body orders). Not exact yet: 316 B, same
	// instructions and stores, but this / i are allocated to esi / edi (original edi / esi) and connectors[i] is loaded
	// before the match arguments are pushed (original after). Rejected: a direct connectors[i]->geoPair.match call
	// (318 B) and a single `!matched[i] && ...` condition (unchanged). Batch 15 rejected: friend + direct
	// connectors[i]->geoPair.match (318 B: &data[i] early, deref late) and ContactConnector deriving from GeoPair at +0x8
	// (same 318 B). The identity registry has only the placeholder func_00607cc0.
	ContactConnector* BlockBlockContact::matchContactConnector(Body* b0, Body* b1, GeoPairType _pairType, int param0, int param1)
	{
		for (int i = 0; i < matched.size(); i++)
		{
			if (matched[i] == false)
			{
				if (connectors[i]->match(b0, b1, _pairType, param0, param1))
				{
					matched[i] = true;
					Contact::contactPairMatches++;
					connectors[i]->setBody(0, b0);
					connectors[i]->setBody(1, b1);
					return connectors[i];
				}
			}
		}

		Contact::contactPairMisses++;
		ContactConnector* connector = createConnector(b0, b1);
		connectors.append(connector);
		matched.append(true);
		return connector;
	}

	// 00607ea0: donor v8world/Contact.cpp body; the 2008 setEdgeEdge leaves the bodies to matchContactConnector.
	// Not exact yet: 240 B against 238; identical up to the first getEdgeVertex call, then this build loads both
	// Block pointers before it (the original loads block(b0) after it) and stores offset0 after the normals.
	// Rejected: direct matched->geoPair.setEdgeEdge (unchanged); batch 15: donor body arguments passed and ignored
	// (unchanged); block(int) out of line and auto-inlined (unchanged). Closest (238 B, same size, register / spill
	// slot differences only): separate statements offset1 = block(b1)->getEdgeVertex(edge1), then offset0, then
	// setEdgeEdge(offset0, offset1, ...); not kept (no evidence for that source order).
	void BlockBlockContact::loadGeoPairEdgeEdge(int b0, int b1, int edge0, int edge1)
	{
		NormalId edgeNormal0 = block(b0)->getEdgeNormal(edge0);
		NormalId edgeNormal1 = block(b1)->getEdgeNormal(edge1);

		matchContactConnector(
			getPrimitive(b0)->getBody(),
			getPrimitive(b1)->getBody(),
			EDGE_EDGE_PAIR,
			edgeNormal0,
			edgeNormal1)->setEdgeEdge(
			block(b0)->getEdgeVertex(edge0),
			block(b1)->getEdgeVertex(edge1),
			edgeNormal0,
			edgeNormal1);
	}

	// 00608830: separation -1.0f (0081c3b8) when colliding, else 1e9 (0082d030); then updateConnectors 006087a0.
	bool BlockBlockContact::stepContact()
	{
		if (Primitive::aaBoxCollide(*getPrimitive(0), *getPrimitive(1)) && getBestPlaneEdge(0.0f))
			separation = -1.0f;
		else
			separation = 1e9f;
		updateConnectors();
		return separation <= 0.0f;
	}
}
