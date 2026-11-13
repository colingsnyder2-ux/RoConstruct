// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::BallBallContact step path (inactive): computeIsColliding 00606e90 and stepContact 00606f80
// (vtable 008436bc slots 7 / 6). Flags: the sibling BlockBlockContactStep.cpp (same Contact unit 00606b00..00608950).
// numConnectors 0060cb60 / getConnector 0060cbc0 are already inline in native-headers/v8world/Contact2008.h (not
// duplicated here). Donor bodies: tools/rbxgs v8world/Contact.cpp BallBallContact::computeIsColliding / stepContact.
//
// Unit-local redeclarations (pattern of ContactUnit2008ConnectorBody.cpp / PrimitiveState.cpp), because the shared
// headers conflict or lack members these bodies call; proposals are in the batch result:
//   - RBX::IPipelined, as native-headers/v8kernel/IPipelined2008.h declares it, plus the donor inline inStage(StageType)
//     (stepContact 00606f93: currentStage +0x4, slot 1 getStageType, `cmp eax, 7`).
//   - RBX::EdgeList / RBX::Primitive, copied from native-headers/v8world/Primitive2008.h (that header includes
//     IPipelined2008.h, which lacks inStage).
//   - RBX::Edge (donor v8world/Edge.h layout: prim0 +0xc / prim1 +0x10), RBX::Contact / BallBallContact copied from
//     native-headers/v8world/Contact2008.h (it reaches the donor Edge.h -> IPipelined.h -> Kernel.h -> Body.h, which
//     cannot sit next to native-headers/v8kernel/Body2008.h), plus Contact::createConnector(Body*, Body*) 00606e00.
//   - RBX::GeoPair (native-headers/v8world/GeoPair2008.h) and Connector / ContactConnector (as
//     ContactUnit2008ConnectorBody.cpp redeclares them) plus the inline setBallBall used by stepContact.
#include <math.h>
#include <G3D/Vector3.h>
#include <G3D/Array.h>
#include <G3D/CoordinateFrame.h>
#include "v8kernel/IStage.h"
#include "v8kernel/KernelIndex.h"
#include "v8kernel/Body2008.h"
#include "v8world/Geometry2008.h"
#include "v8world/Ball2008.h"
#include "util/Guid.h"
#include "util/Vector3int32.h"
#include "util/Extents.h"
#include "util/SurfaceType.h"
#include "util/ComputeProp.h"
#include "util/NormalId.h"
#include "util/Math.h"

struct NativeBodyPrimitive2008Layout;
struct NativeContactUnit2008Layout;
struct NativeWorldShapesLayout;

namespace RBX
{
	class Kernel;

	class __declspec(novtable) IPipelined
	{
		friend struct ::NativeBodyPrimitive2008Layout;

	private:
		IStage* currentStage;                          // +0x4

		IStage* getStage(IStage::StageType stageType) const;   // 006457e0

	public:
		IPipelined() : currentStage(NULL) {}
		virtual ~IPipelined() {}                       // slot 0

		void removeFromPipeline(IStage* stage);        // 00645820
		void removeFromStage(IStage* stage);           // 00645840
		bool inPipeline() const
		{
			return currentStage != NULL;
		}
		// Not in IPipelined2008.h (proposal): the donor v8world/IPipelined.h inline, read by stepContact 00606f93.
		bool inStage(IStage::StageType stageType) const
		{
			return currentStage->getStageType() == stageType;
		}
		Kernel* getKernel() const;                     // 00645850
		virtual void putInKernel(Kernel* kernel);      // slot 1 (00645830)
		virtual void removeFromKernel();               // slot 2 (00645860)
	};

	// 2008 Kernel stage type: Kernel::getStageType 0077d800 returns 7 and IPipelined::getKernel 00645850 pushes 7
	// (native-headers/v8world/CleanStage2008.h); the donor v8kernel/IStage.h numbers KERNEL_STAGE 8.
	static const IStage::StageType kernelStage2008 = static_cast<IStage::StageType>(7);

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

		// Not in GeoPair2008.h (proposal): inline in BallBallContact::stepContact 00606f80 (00606ff4..00607001 store
		// radius0 +0x18, geoPairType +0x0 = BALL_BALL_PAIR and radiusSum +0x1c of the GeoPair at connector +0x8; the
		// bodies +0xc / +0x10 are not written there, Contact::createConnector 00606e00 stores them). Donor v8kernel/
		// Pair.h setBallBall(Body*, Body*, float, float) without the body arguments.
		void setBallBall(float radius0, float radius1)    // INFERRED: 2008 signature from the stores above
		{
			pairData.radius0 = radius0;
			pairData.radiusSum = radius0 + radius1;
			geoPairType = BALL_BALL_PAIR;
		}
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

	// Donor v8world/Edge.h layout (Contact2008.h: Edge fields end at +0x20; Edge(prim0, prim1) 00659260).
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
		Edge* next0;                                   // +0x14
		Edge* next1;                                   // +0x18
		bool inEdgeList;                               // +0x1c

	public:
		Edge(Primitive* prim0, Primitive* prim1);      // 00659260
		virtual ~Edge()
		{
		}

		virtual EdgeType getEdgeType() const = 0;
		Primitive* getPrimitive(int i) const
		{
			return *(&this->prim0 + i);
		}
		virtual void setPrimitive(int i, Primitive* p);   // 00659290
	};

	class Connector : public KernelIndex
	{
	public:
		virtual ~Connector() {}                                         // slot 0
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

	class ContactConnector : public Connector
	{
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
		virtual void computeForce(const float dt, bool throttling);    // slot 1 (00606780)
		virtual bool canThrottle() const;                               // slot 2 (00606250)
		virtual Body* getBody(int i)                                    // slot 4 (00606230)
		{
			return geoPair.getBody(i);
		}

		// Not in Connector2008.h (proposal): inline in stepContact 00606f80, see GeoPair::setBallBall.
		void setBallBall(float radius0, float radius1)                 // INFERRED: forwards to geoPair (+0x8)
		{
			geoPair.setBallBall(radius0, radius1);
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
		virtual void putInKernel(Kernel* _kernel);      // slot 1 (0060cb10; inline in Contact2008.h)
		virtual void removeFromKernel();                // slot 2 (0060cb30; inline in Contact2008.h)
		virtual Edge::EdgeType getEdgeType() const      // slot 3 (007286a0, folded)
		{
			return CONTACT;
		}

	protected:
		void deleteConnector(ContactConnector*& c);     // 00606d10
		// Not in Contact2008.h (proposal): 00606e00 (`ret 8`, placeholder func_00606e00 in the identity registry):
		// new ContactConnector(jointK +0x28, elasticJointK +0x2c, kFriction +0x30) 00606d40, stores the two Body
		// arguments at connector +0x14 / +0x18 (GeoPair body0 / body1), then getKernel()->insertConnector 005fb160.
		// Donor name Contact::createConnector() (the 2008 one takes the bodies).
		ContactConnector* createConnector(Body* b0, Body* b1);   // 00606e00
		virtual void deleteAllConnectors() = 0;         // slot 5
		virtual bool stepContact() = 0;                 // slot 6

	public:
		Contact(Primitive* prim0, Primitive* prim1);    // 00606c20

		virtual bool computeIsColliding(float overlapIgnored) = 0;   // slot 7
		virtual int numConnectors() const = 0;                       // slot 8 (analog name)
		virtual ContactConnector* getConnector(int i) = 0;           // slot 9 (analog name)

		void onPrimitiveContactParametersChanged();     // 00607ad0
	};

	class BallBallContact : public Contact
	{
		friend struct ::NativeWorldShapesLayout;

	private:
		ContactConnector* ballBallConnector;            // +0x34

		// Donor v8world/Contact.h inline (rbx_static_cast of getGeometry; no code of its own).
		Ball* ball(int i)
		{
			return static_cast<Ball*>(getPrimitive(i)->getGeometry());
		}

	private:
		virtual void deleteAllConnectors()              // slot 5 (0060cb50)
		{
			if (ballBallConnector)
				deleteConnector(ballBallConnector);
		}
		virtual bool stepContact();                     // slot 6 (00606f80)
		virtual bool computeIsColliding(float overlapIgnored);   // slot 7 (00606e90)
		virtual int numConnectors() const               // slot 8 (0060cb60)
		{
			return ballBallConnector ? 1 : 0;
		}
		virtual ContactConnector* getConnector(int i)   // slot 9 (0060cbc0)
		{
			return ballBallConnector;
		}

	public:
		BallBallContact(Primitive* p0, Primitive* p1)   // 0060cae0
			: Contact(p0, p1),
			  ballBallConnector(NULL)
		{
		}
	};

	// 00606e90: Geometry slot 4 getRadius of both balls, the Body pv translation +0xb8 read without updatePV
	// (Body2008.h getPVUnsafe), Math::longestVector3Component (std::max of the fabs), then magnitude.
	bool BallBallContact::computeIsColliding(float overlapIgnored)
	{
		float b0Radius = ball(0)->getRadius();
		float b1Radius = ball(1)->getRadius();

		G3D::Vector3 delta = getPrimitive(1)->getBody()->getPVUnsafe().position.translation
			- getPrimitive(0)->getBody()->getPVUnsafe().position.translation;
		float b0b1RadiusSum = b0Radius + b1Radius;

		if (b0b1RadiusSum > Math::longestVector3Component(delta))
			return delta.magnitude() < (b0b1RadiusSum - overlapIgnored);
		else
			return false;
	}

	// 00606f80: computeIsColliding called directly (not through the vtable), createConnector 00606e00, inline
	// setBallBall, else deleteAllConnectors through slot 5.
	bool BallBallContact::stepContact()
	{
		if (BallBallContact::computeIsColliding(0.0f))
		{
			if (inStage(kernelStage2008))
			{
				if (!ballBallConnector)
					ballBallConnector = createConnector(getPrimitive(0)->getBody(), getPrimitive(1)->getBody());

				ballBallConnector->setBallBall(ball(0)->getRadius(), ball(1)->getRadius());
			}
			return true;
		}
		else
		{
			deleteAllConnectors();
		}

		return false;
	}
}
