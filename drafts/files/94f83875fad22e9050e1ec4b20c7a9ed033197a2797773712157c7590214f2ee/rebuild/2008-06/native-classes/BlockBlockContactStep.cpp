// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::BlockBlockContact step path (inactive): computeIsColliding 00607c20 and stepContact 00608830.
// Field evidence: native-headers/leaves2008/BlockBlockContact2008.h (vtable 00843714, size 0x7c).
//
// Unit-local redeclarations (pattern of ContactUnit2008ConnectorBody.cpp), because the shared headers lack members
// this unit calls; proposals are in the batch result:
//   - RBX::Primitive, copied from native-headers/v8world/Primitive2008.h (same bases, fields, offsets, slots), plus
//     the inline static aaBoxCollide (fuzzyExtents +0x80 is private and is read directly by 00607c20 / 00608830).
//   - RBX::BlockBlockContact, copied from native-headers/leaves2008/BlockBlockContact2008.h, plus the private
//     getBestPlaneEdge(float) 00607280 (`ret 4`, returns bool in al) that both bodies call after aaBoxCollide.
// Parked (declarations missing from read-only headers, see the batch result): deleteUnmatchedConnectors 00607e00 calls
// the ContactConnector member 00606770 (`add ecx, 8; jmp 00606270`, a GeoPair test) that Connector2008.h does not
// declare; loadGeoPairEdgeEdge 00607ea0 needs matchContactConnector 00607cc0, Block::getEdgeVertex 00606b00 /
// getEdgeNormal and a 2008 ContactConnector::setEdgeEdge (writes geoPair type / offsets / normals, not the bodies);
// computePlaneContact 00608580 needs Body pv +0x94 without updatePV (the donor Body reached through Connector2008.h
// has none), the Block face-vertex table 0084aec8 and intersectRectQuad 00608160.
// Primitive2008.h and BlockBlockContact2008.h are therefore not included here. The bases come from Contact2008.h
// (donor Edge -> IPipelined), so IPipelined2008.h takes its donor switch, as in ContactUnit2008Contact.cpp.
#define NATIVE_IPIPELINED2008_DONOR
#include "v8world/Contact2008.h"
#include <G3D/Array.h>
#include <G3D/CoordinateFrame.h>
#include "v8kernel/IPipelined2008.h"
#include "v8world/Geometry2008.h"
#include "v8kernel/Connector.h"
#include "util/Guid.h"
#include "util/Vector3int32.h"
#include "util/Extents.h"
#include "util/SurfaceType.h"
#include "util/ComputeProp.h"
#include "util/NormalId.h"

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

	class BlockBlockContact : public Contact
	{
	private:
		G3D::Array<ContactConnector*> connectors;   // +0x34
		G3D::Array<bool> matched;                   // +0x40
		int separatingAxisId;                       // +0x4c (no reader found)
		int separatingBodyId;                       // +0x50 (no reader found)
		float separation;                           // +0x54
		int cachedBody;                             // +0x58
		bool planeContact;                          // +0x5c
		int cachedAxis;                             // +0x60
		int feature[2];                             // +0x64
		int bPlane;                                 // +0x6c
		int bOther;                                 // +0x70
		NormalId planeID;                           // +0x74
		NormalId otherPlaneID;                      // +0x78

		void deleteUnmatchedConnectors();                        // 00607e00
		void loadGeoPairEdgeEdge(int b0, int b1, int edge0, int edge1);   // 00607ea0
		int computePlaneContact();                               // 00608580
		void updateConnectors();                                 // 006087a0 (analog name; called by stepContact)

		// Not in BlockBlockContact2008.h (proposal): 00607280, `ret 4`, one float argument, bool in al; it writes
		// cachedBody +0x58, planeContact +0x5c, cachedAxis +0x60 and feature[] +0x64. Donor name (the donor
		// getBestPlaneEdge(bool& planeContact, float overlapIgnored); in 2008 planeContact is the member +0x5c).
		bool getBestPlaneEdge(float overlapIgnored);             // 00607280

		virtual bool computeIsColliding(float overlapIgnored);   // slot 7 (00607c20)
		virtual void deleteAllConnectors();                      // slot 5 (00607c60)
		virtual bool stepContact();                              // slot 6 (00608830)
		virtual int numConnectors() const;                       // slot 8 (0060d580)
		virtual ContactConnector* getConnector(int i);           // slot 9 (0060d590)

	public:
		BlockBlockContact(Primitive* p0, Primitive* p1);         // 0060d500
	};

	// 00607c20
	bool BlockBlockContact::computeIsColliding(float overlapIgnored)
	{
		return Primitive::aaBoxCollide(*getPrimitive(0), *getPrimitive(1)) && getBestPlaneEdge(overlapIgnored);
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
