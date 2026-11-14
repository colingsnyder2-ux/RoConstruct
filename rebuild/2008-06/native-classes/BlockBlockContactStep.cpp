// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::BlockBlockContact step path (inactive): computeIsColliding 00607c20, matchContactConnector
// 00607cc0, loadGeoPairEdgeEdge 00607ea0 and stepContact 00608830 (the Contact unit 00606b00..00608950).
// Field evidence: native-headers/leaves2008/BlockBlockContact2008.h (vtable 00843714, size 0x7c). Donor bodies:
// tools/rbxgs v8world/Contact.cpp (BlockBlockContact::matchContactConnector / loadGeoPairEdgeEdge).
//
// Unit-local redeclarations (pattern of BallBlockContactStep.cpp / ContactUnit2008ConnectorBody.cpp), because the
// shared headers lack members this unit calls and v8kernel/Connector2008.h / v8world/Block2008.h include the donor
// v8kernel/Pair.h, whose GeoPair::match is inline (the 2008 one is out of line, 00606a50). Proposals are in the batch
// result; each addition is marked "Not in ...":
//   - RBX::Primitive, copied from native-headers/v8world/Primitive2008.h (same bases, fields, offsets, slots), plus
//     the inline static aaBoxCollide (fuzzyExtents +0x80 is private and is read directly by 00607c20 / 00608830).
//   - RBX::GeoPairType / PairParams / GeoPair, copied from native-headers/v8world/GeoPair2008.h, plus the 2008 inline
//     setEdgeEdge (no bodies) and setBody.
//   - RBX::Connector / ContactConnector, copied from native-headers/v8kernel/Connector2008.h, plus the donor match
//     forwarder and the setEdgeEdge / setBody forwarders.
//   - RBX::Contact, copied from native-headers/v8world/Contact2008.h, plus createConnector(Body*, Body*) 00606e00 and
//     the donor statics contactPairMatches / contactPairMisses.
//   - RBX::Block, copied from native-headers/v8world/Block2008.h, plus getEdgeNormal (donor inline) and getEdgeVertex
//     00606b00.
//   - RBX::BlockBlockContact, copied from native-headers/leaves2008/BlockBlockContact2008.h, plus the private
//     getBestPlaneEdge(float) 00607280 (`ret 4`, returns bool in al) that both step bodies call after aaBoxCollide,
//     matchContactConnector 00607cc0 and the donor block(int) accessor.
// The bases IPipelined / Edge are the native 2008 ones (AppUnit658/Edge.h -> v8kernel/IPipelined2008.h).
// Parked (see the batch result): deleteUnmatchedConnectors 00607e00 calls the ContactConnector member 00606770
// (`add ecx, 8; jmp 00606270`, a GeoPair test) that Connector2008.h does not declare (00606270 returns true unless
// geoPairType == POINT_PLANE_PAIR, then PairParams p; computePointPlane 00613560; return p.length < 0.02f (00827488);
// the loop removes connector i when !matched[i] || !connectors[i]->test(), then fastRemoveIndex on both arrays (resize
// 006078f0 / 0047ff20), getKernel()->removeConnector, delete; no name for either member in the donor or registry);
// computePlaneContact 00608580 needs Body pv +0x94 without updatePV, the Block face-vertex table 0084aec8 and
// intersectRectQuad 00608160.
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

	enum GeoPairType
	{
		BALL_BALL_PAIR = 0,
		BALL_POINT_PAIR = 1,
		BALL_EDGE_PAIR = 2,
		BALL_PLANE_PAIR = 3,
		POINT_PLANE_PAIR = 4,
		EDGE_EDGE_PLANE_PAIR = 5,
		EDGE_EDGE_PAIR = 6
	};

	// PairParams (0x20): ContactConnector::computeForce 00606780 zeroes normal +0x0 / position +0x10 of its local (length
	// +0xc and rotVel +0x1c are left unset) before the compute* call, then reads length +0xc, normal and position.
	class PairParams
	{
	public:
		G3D::Vector3 normal;                              // +0x0
		union
		{
			float length;                                 // +0xc
			float rotation;
		};
		G3D::Vector3 position;                            // +0x10
		float rotVel;                                     // +0x1c

	public:
		PairParams()
			: normal(0, 0, 0),
			  position(0, 0, 0)
		{
		}
	};

	class GeoPair
	{
		friend struct ::NativeBodyPrimitive2008Layout;

	private:
		struct GeoPairData
		{
			union
			{
				NormalId normalID0;
				float radius0;
			};
			union
			{
				NormalId normalID1;
				float radiusSum;
			};
			union
			{
				NormalId planeID;
				int point0ID;
			};
		};

	private:
		GeoPairType geoPairType;                          // +0x0
		const G3D::Vector3* offset0;                      // +0x4
		const G3D::Vector3* offset1;                      // +0x8
		Body* body0;                                      // +0xc
		Body* body1;                                      // +0x10
		float edgeLength0;                                // +0x14
		GeoPairData pairData;                             // +0x18

	private:
		// the GeoPair unit 00613060..00613cb0; ContactConnector::computeForce 00606780 dispatches on geoPairType through
		// the jump table 00606a34 (0 -> 00613290, 1 -> 006131e0, 2 -> 00613320, 3 -> 00613440, 4 -> 00613560,
		// 5 -> 006136a0, 6 -> 006139c0) in the case order of computeLengthNormalPosition below.
		void computeBallBall(PairParams& _params);        // 00613290
		void computeBallPoint(PairParams& _params);       // 006131e0
		void computeBallEdge(PairParams& _params);        // 00613320
		void computeBallPlane(PairParams& _params);       // 00613440
		void computePointPlane(PairParams& _params);      // 00613560
		void computeEdgeEdgePlane(PairParams& _params);   // 006136a0
		void computeEdgeEdge(PairParams& _params);        // 006139c0

	public:
		GeoPair();                                        // 00613060

		void computeLengthNormalPosition(PairParams& _params)
		{
			switch (geoPairType)
			{
			case POINT_PLANE_PAIR:
				computePointPlane(_params);
				break;
			case EDGE_EDGE_PLANE_PAIR:
				computeEdgeEdgePlane(_params);
				break;
			case BALL_BALL_PAIR:
				computeBallBall(_params);
				break;
			case BALL_PLANE_PAIR:
				computeBallPlane(_params);
				break;
			case BALL_POINT_PAIR:
				computeBallPoint(_params);
				break;
			case BALL_EDGE_PAIR:
				computeBallEdge(_params);
				break;
			case EDGE_EDGE_PAIR:
				computeEdgeEdge(_params);
				break;
			}
		}
		void computeNormalPerpVel(float& normalVel, G3D::Vector3& perpVel, const PairParams& _params);   // 006130e0
		void forceToBodies(const G3D::Vector3& _force, const G3D::Vector3& _position);                 // 00613080

		Body* getBody(int i)
		{
			return i == 0 ? body0 : body1;
		}
		const Body* getBody(int i) const
		{
			return i == 0 ? body0 : body1;
		}

		bool match(Body* _b0, Body* _b1, GeoPairType _pairType, int param0, int param1);   // 00606a50

		// Not in GeoPair2008.h (proposal): the 2008 inline of loadGeoPairEdgeEdge 00607ea0 (00607f70..00607f81 store
		// offset0 +0x4, normalID0 +0x18, normalID1 +0x1c, offset1 +0x8 and geoPairType +0x0 = EDGE_EDGE_PAIR of the GeoPair
		// at connector +0x8; the bodies are not written there). Donor v8kernel/Pair.h setEdgeEdge without the bodies.
		void setEdgeEdge(const G3D::Vector3* offset0, const G3D::Vector3* offset1, NormalId norm0, NormalId norm1)   // INFERRED: 2008 signature from the stores above
		{
			this->offset0 = offset0;
			pairData.normalID0 = norm0;
			pairData.normalID1 = norm1;
			this->offset1 = offset1;
			geoPairType = EDGE_EDGE_PAIR;
		}

		// Not in GeoPair2008.h (proposal): body0 +0xc / body1 +0x10, written by matchContactConnector 00607cc0
		// (00607d47 / 00607d50, connector +0x14 / +0x18) after a match and by Contact::createConnector 00606e00
		// (00606e5a / 00606e5d) for a new connector.
		void setBody(int i, Body* b)   // INFERRED: analog name; one store per call (00607d41..00607d50 reload connectors[i])
		{
			if (i == 0)
				body0 = b;
			else
				body1 = b;
		}
	};

	class Connector : public KernelIndex
	{
	public:
		Connector() {}
		// KernelData indexes Connector through the proven KernelIndex +0x4
		// field. The donor declaration is noinline; no layout or vtable effect.
		__declspec(noinline) int& getKernelIndex() { return kernelIndex; }
		virtual ~Connector() {}                                         // slot 0 (??_G 006062c0)
		virtual void computeForce(const float dt, bool throttling) = 0; // slot 1
		virtual bool canThrottle() const                                // slot 2 (00565950)
		{
			return true;
		}
		virtual bool getBroken()                                        // slot 3 (0060a2f0)
		{
			return false;
		}
		virtual Body* getBody(int i) = 0;                               // slot 4 (analog name)
		virtual float potentialEnergy()                                 // slot 5 (005e72c0)
		{
			return 0;
		}
	};

	// ContactConnector(k, kNeg, kFriction) 00606d40: GeoPair() 00613060 at +0x8, frictionOffset +0x44 = 0 then
	// Vector3::zero(), k +0x2c, kNeg +0x34, kFriction +0x30, firstApproach +0x38, threshold +0x3c, forceMagLast +0x40.
	class ContactConnector : public Connector
	{
		friend struct ::NativeWorldJointsConnectorLayout;

	protected:
		GeoPair geoPair;                  // +0x8
		float k;                          // +0x2c
		float kFriction;                  // +0x30
		float kNeg;                       // +0x34
		float firstApproach;              // +0x38
		float threshold;                  // +0x3c
		float forceMagLast;               // +0x40
		G3D::Vector3 frictionOffset;      // +0x44

	public:
		ContactConnector(float _k, float _kNeg, float _kFriction)       // 00606d40
			: geoPair()
		{
			k = _k;
			kNeg = _kNeg;
			kFriction = _kFriction;
			frictionOffset = G3D::Vector3::zero();
			firstApproach = 0;
			threshold = 0;
			forceMagLast = 0;
		}

		virtual void computeForce(const float dt, bool throttling);    // slot 1 (00606780)
		virtual bool canThrottle() const;                               // slot 2 (00606250; reads Body +0x30)
		virtual Body* getBody(int i)                                    // slot 4 (00606230)
		{
			return geoPair.getBody(i);
		}

		// Not in Connector2008.h (proposal): the donor v8kernel/Connector.h inline forwarder (matchContactConnector
		// 00607cf5 `add ecx, 8; call 00606a50`).
		bool match(Body* _b0, Body* _b1, GeoPairType _pairType, int param0, int param1)
		{
			return geoPair.match(_b0, _b1, _pairType, param0, param1);
		}

		// Not in Connector2008.h (proposal): forwarders to the GeoPair inlines above.
		void setEdgeEdge(const G3D::Vector3* offset0, const G3D::Vector3* offset1, NormalId norm0, NormalId norm1)   // INFERRED: forwards to geoPair (+0x8)
		{
			geoPair.setEdgeEdge(offset0, offset1, norm0, norm1);
		}
		void setBody(int i, Body* b)   // INFERRED: forwards to geoPair (+0x8)
		{
			geoPair.setBody(i, b);
		}
	};

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
		// Not in Contact2008.h (proposal): 00606e00 (`ret 8`, placeholder func_00606e00 in the identity registry):
		// new ContactConnector(jointK +0x28, elasticJointK +0x2c, kFriction +0x30) 00606d40, stores the two Body
		// arguments at connector +0x14 / +0x18, then getKernel()->insertConnector 005fb160. Donor name
		// Contact::createConnector() (the 2008 one takes the bodies); as BallBlockContactStep.cpp declares it.
		ContactConnector* createConnector(Body* b0, Body* b1);   // 00606e00
		virtual void deleteAllConnectors() = 0;         // slot 5
		virtual bool stepContact() = 0;                 // slot 6

	public:
		// Not in Contact2008.h (proposal): donor v8world/Contact.h statics, defined (pending) by
		// native-classes/ContactUnit2008Contact.cpp: contactPairMatches 0097b880 (++ at 00607d3b), contactPairMisses
		// 0097b884 (++ at 00607d07).
		static int contactPairMatches;
		static int contactPairMisses;

		Contact(Primitive* prim0, Primitive* prim1);    // 00606c20

		virtual bool computeIsColliding(float overlapIgnored) = 0;   // slot 7
		virtual int numConnectors() const = 0;                       // slot 8 (analog name)
		virtual ContactConnector* getConnector(int i) = 0;           // slot 9 (analog name)

		void onPrimitiveContactParametersChanged();     // 00607ad0
	};

	class Block : public Geometry
	{
		friend struct ::NativeWorldShapesLayout;

	private:
		const G3D::Vector3* vertices; // +0x10
		float cornerRadius;           // +0x14

	private:
		// inlined into getBallBlockInfo 00647a20
		const G3D::Vector3* getCornerPoint(const G3D::Vector3int16& clip) const
		{
			return &vertices[((clip.x <= 0) * 2 + (clip.y <= 0)) * 2 + (clip.z <= 0)];
		}
		const G3D::Vector3* getEdgePoint(const G3D::Vector3int16& clip, NormalId& normalID) const;    // 00647900
		const G3D::Vector3* getPlanePoint(const G3D::Vector3int16& clip, NormalId& normalID) const;   // 00647990
		G3D::Matrix3 getMomentHollow(float mass) const;                                              // 006477b0
		virtual void onSetSize();                                                                    // 00648fd0

	public:
		Block() : vertices(NULL), cornerRadius(0.0f) {}

		virtual bool hitTest(const G3D::Ray& rayInMe, G3D::Vector3& localHitPoint, bool& inside);   // 00647f40

		virtual GeometryType getGeometryType() const     // 0077d810 (folded)
		{
			return GEOMETRY_BLOCK;
		}

		virtual float getRadius() const                  // 004e5b70
		{
			return cornerRadius;
		}

		virtual G3D::Vector3 getCenterToCorner(const G3D::Matrix3& rotation) const;   // 00648270

		virtual G3D::Matrix3 getMoment(float mass) const // 005e7390
		{
			return getMomentHollow(mass);
		}

		virtual float getGridVolume() const;             // 006478f0

		void projectToFace(G3D::Vector3& ray, G3D::Vector3int16& clip, int& onBorder);                                   // 00647b90
		GeoPairType getBallInsideInfo(const G3D::Vector3& ray, const G3D::Vector3*& offset, NormalId& normalID);         // 00647ab0
		GeoPairType getBallBlockInfo(int onBorder, G3D::Vector3int16 clip, const G3D::Vector3*& offset, NormalId& normalID); // 00647a20
		int getClosestEdge(const G3D::Matrix3& rotation, NormalId normalID, G3D::Vector3& crossAxis);                   // 00647d10
		G3D::Vector2 getProjectedVertex(const G3D::Vector3& vertex, NormalId normalID);                                  // 00647c70

		const G3D::Vector3& getExtent() const
		{
			return *vertices;
		}

		// Not in Block2008.h (proposal): donor v8world/Block.h inline, read twice by loadGeoPairEdgeEdge 00607ea0
		// (00607ea6..00607ed9 / 00607edb..00607f0f).
		NormalId getEdgeNormal(int edge)
		{
			int answer = edge / 4 + 3 * (edge % 2);
			if (edge > 12)
				answer = (answer + 3) % 6;
			return (NormalId)answer;
		}
		// Not in Block2008.h (proposal): 00606b00 (?getEdgeVertex@Block@RBX@@QBEPBVVector3@G3D@@H@Z, `ret 4`; vertex
		// tables 0084aec8 / 0084aecc, vertices +0x10).
		const G3D::Vector3* getEdgeVertex(int edge) const;   // 00606b00
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
		// Not in BlockBlockContact2008.h (proposal): 00607cc0 (`ret 0x14`; donor v8world/Contact.h signature).
		ContactConnector* matchContactConnector(Body* b0, Body* b1, GeoPairType _pairType, int param0, int param1);   // 00607cc0
		void loadGeoPairEdgeEdge(int b0, int b1, int edge0, int edge1);   // 00607ea0
		// Not in BlockBlockContact2008.h (proposal): donor v8world/Contact.h inline (00607f3e..00607f42 geometry +0x9c).
		Block* block(int i)
		{
			return static_cast<Block*>(getPrimitive(i)->getGeometry());
		}
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

	// 00607cc0: donor v8world/Contact.cpp body; the 2008 one passes the bodies to createConnector 00606e00 and, after
	// a match, writes them into the matched connector (match accepts both body orders). Not exact yet: 316 B, same
	// instructions and stores, but this / i are allocated to esi / edi (original edi / esi) and connectors[i] is loaded
	// before the match arguments are pushed (original after). Rejected: a direct connectors[i]->geoPair.match call
	// (318 B) and a single `!matched[i] && ...` condition (unchanged). The identity registry has only the placeholder
	// func_00607cc0.
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
	// Rejected: direct matched->geoPair.setEdgeEdge (unchanged).
	void BlockBlockContact::loadGeoPairEdgeEdge(int b0, int b1, int edge0, int edge1)
	{
		NormalId edgeNormal0 = block(b0)->getEdgeNormal(edge0);
		NormalId edgeNormal1 = block(b1)->getEdgeNormal(edge1);

		ContactConnector* matched = matchContactConnector(
			getPrimitive(b0)->getBody(),
			getPrimitive(b1)->getBody(),
			EDGE_EDGE_PAIR,
			edgeNormal0,
			edgeNormal1);

		matched->setEdgeEdge(
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
