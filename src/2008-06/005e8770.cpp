// from server: 100% by EspClaude
// from server: 84% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_espclaude_34ee53b85132d5c0.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#undef _RELEASEASSERT
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Plane.h>
#include <G3D/GCamera.h>
#include "util/NormalId.h"
#include "util/Vector3int32.h"

namespace RBX
{
	class Extents
	{
	private:
		G3D::Vector3 low;
		G3D::Vector3 high;

	public:
		Extents(const Vector3int32& low, const Vector3int32& high) : low(low.toVector3()), high(high.toVector3()) {}
		Extents(const G3D::Vector3& low, const G3D::Vector3& high) : low(low), high(high) {}
		__forceinline Extents() : low(G3D::Vector3::inf()), high(-G3D::Vector3::inf()) {}

	public:
		bool operator==(const Extents&) const;
		bool operator!=(const Extents&) const;
		Extents& operator=(const Extents& other)
		{
			this->low = other.low;
			this->high = other.high;

			return *this;
		}
		const G3D::Vector3& min() const {return this->low;}
		const G3D::Vector3& max() const {return this->high;}
		G3D::Vector3 getCorner(int i) const;
		G3D::Vector3 size() const { return this->high - this->low; }
		G3D::Vector3 center() const { return (this->high + this->low) * 0.5f; }
		G3D::Vector3 bottomCenter() const
		{
			G3D::Vector3 v = (this->low + this->high) * 0.5f;
			v.y = low.y;

			return v;
		}
		G3D::Vector3 topCenter() const
		{
			G3D::Vector3 v = (this->low + this->high) * 0.5f;
			v.y = high.y;

			return v;
		}
		float longestSide() const;
		float volume() const;
		float areaXZ() const;
		Extents toWorldSpace(const G3D::CoordinateFrame& localCoord);
		Extents express(const G3D::CoordinateFrame& myFrame, const G3D::CoordinateFrame& expressInFrame);
		G3D::Vector3 faceCenter(NormalId faceId) const;
		void getFaceCorners(NormalId faceId, G3D::Vector3& v0, G3D::Vector3& v1, G3D::Vector3& v2, G3D::Vector3& v3) const;
		G3D::Plane getPlane(NormalId normalId) const;
		G3D::Vector3 clip(const G3D::Vector3& v) const
		{
			return v.clamp(this->low, this->high);
		}
		G3D::Vector3 clamp(const Extents& extents) const;
		NormalId closestFace(const G3D::Vector3& point);
		void unionWith(const Extents& other);
		void shift(const G3D::Vector3&);
		void scale(float scale)
		{
			this->low *= scale;
			this->high *= scale;
		}
		void expand(float f)
		{
			this->low -= G3D::Vector3(f, f, f);
			this->high += G3D::Vector3(f, f, f);
		}
		G3D::Vector3& operator[](int);
		const G3D::Vector3& operator[](int) const;
		operator G3D::Vector3 *();
		operator const G3D::Vector3 *() const;
		bool contains(const G3D::Vector3& point) const;
		bool overlapsOrTouches(const Extents& other) const;
		bool fuzzyContains(const G3D::Vector3& point, float slop) const;
		bool containedByFrustum(const G3D::GCamera::Frustum& frustum) const;
		bool partiallyContainedByFrustum(const G3D::GCamera::Frustum&) const;
		bool separatedByMoreThan(const Extents& other, float distance) const;

	private:
		static float epsilon();
	public:
		static Extents fromCenterCorner(const G3D::Vector3& center, const G3D::Vector3& corner)
		{
			return Extents(center - corner, center + corner);
		}
		static Extents fromCenterRadius(const G3D::Vector3&, float);
		static Extents vv(const G3D::Vector3& v0, const G3D::Vector3& v1);
		static bool overlapsOrTouches(const Extents&, const Extents&);
		static const Extents& zero();
		static const Extents& unit();
		static const Extents& infiniteExtents();
		static const Extents& negativeInfiniteExtents();
	};
}

#pragma include_alias("util/Extents.h", "G3D/Vector3.h")
#pragma include_alias("v8world/Primitive.h", "util/Guid.h")
#include "G3D/Array.h"
#include "v8world/Anchor.h"
#include "v8world/Clump.h"
#include "v8world/Contact.h"
#include "v8world/Edge.h"
#include "v8world/Geometry.h"
#include "v8world/IMoving.h"
#include "v8world/IPipelined.h"
#include "v8world/SurfaceData.h"
#include "v8world/RigidJoint.h"
#include "util/Guid.h"
#include "util/Vector3int32.h"
#include "util/Extents.h"
#include "util/SurfaceType.h"
#include "util/ComputeProp.h"
#include "util/Face.h"
#include "util/Velocity.h"

namespace RBX
{
	class Edge;
	class Clump;
	class World;
	class SpatialNode;
	class Controller;
	class Assembly;
	class IMoving;
	class Anchor;
	class Joint;
	class RigidJoint;
	class Contact;
	class Primitive;

	class EdgeList
	{
	public:
		Primitive* owner;
		G3D::Array<Edge*> edges;
		G3D::Array<Edge*> pending;
	public:
		EdgeList(Primitive* owner) : owner(owner) {}
	public:
		bool hasEdge();
	public:
		static void insertEdge(Primitive*, Edge*, EdgeList&);
		static void removeEdge(Primitive*, Edge*, EdgeList&);
	};

	class Primitive : public IPipelined
	{
		friend class SpatialHash;

	private:
		Guid guid;
		bool guidSetExternally;
		int edgeVersion;
		EdgeList contacts;
		EdgeList joints;
		int worldIndex;
		int traverseId;
		World* world;
		Clump* clump;
		int clumpDepth;
		SpatialNode* spatialNodes;
		Vector3int32 oldSpatialMin;
		Vector3int32 oldSpatialMax;
		mutable Extents fuzzyExtents;
		mutable int fuzzyExtentsStateId;
	protected:
		Geometry* geometry;
		Body* body;
		IMoving* myOwner;
		bool dragging;
		bool anchored;
		bool flagA;
		bool flagB;
		bool canCollide;
		float friction;
		float elasticity;
		SurfaceType surfaceType[6];
		SurfaceData* surfaceData[6];
		Controller* controller;
		ComputeProp<float, Primitive> JointK;
	public:
		static bool disableSleep;
	private:
		static bool ignoreBool;
  
	public:
		int& worldIndexFunc() 
		{
			return worldIndex;
		}
	private:
		void onChangedInKernel();
		G3D::Vector3 clipToSafeSize(const G3D::Vector3& newSize);
		Extents computeFuzzyExtents() const;
	protected:
		float computeJointK() const;
	public:
		//Primitive(const Primitive&);
		Primitive(Geometry::GeometryType);
		virtual ~Primitive();
	public:
		const Guid& getGuid() const 
		{
			return guid;
		}
		void setGuid(const Guid&);
		World* getWorld() const 
		{
			return world;
		}
		void setWorld(World* world)
		{
			this->world = world;
		}
		Clump* getClump() const
		{
			return clump;
		}
		void setClump(Clump* set);
		int getClumpDepth() const
		{
			return clumpDepth;
		}
		void setClumpDepth(int value)
		{
			clumpDepth = value;
		}
		int getTraverseId() const;
		void setTraverseId(int);
		Assembly* getAssembly() const;
		const Geometry* getGeometry() const
		{
			return geometry;
		}
		Geometry* getGeometry()
		{
			return geometry;
		}
		void setPrimitiveType(Geometry::GeometryType geometryType);
		Geometry::GeometryType getPrimitiveType() const;
		const Body* getBody() const
		{
			return body;
		}
		Body* getBody()
		{
			return body;
		}
		void setOwner(IMoving* owner)
		{
			myOwner = owner;
		}
		IMoving* getOwner() const
		{
			return myOwner;
		}
		__declspec(noinline) const G3D::CoordinateFrame& getCoordinateFrame() const;
		G3D::CoordinateFrame getGridCorner() const;
		void setCoordinateFrame(const G3D::CoordinateFrame& value);
		void setGridCorner(const G3D::CoordinateFrame& gridCorner);
		void setPV(const PV&);
		void setVelocity(const Velocity& vel);
		void setMassInertia(float);
		void setDragging(bool _dragging);
		bool getDragging() const
		{
			return dragging;
		}
		void setAnchor(bool _anchored);
		bool getAnchor() const
		{
			return anchored;
		}
		void setCanCollide(bool value);
		const bool getCanCollide() const
		{
			return canCollide;
		}
		void setCanSleep(bool _canSleep);
		const bool getCanSleep() const
		{
			return flagB;
		}
		void setFriction(float _friction);
		float getFriction() const
		{
			return this->friction;
		}
		void setElasticity(float _elasticity);
		float getElasticity() const
		{
			return this->elasticity;
		}
		void setGridSize(const G3D::Vector3& gridSize);
		const G3D::Vector3& getGridSize() const
		{
			return geometry->getGridSize();
		}
		virtual float getRadius() const 
		{
			return geometry->getRadius();
		}
		float getPlanarSize() const;
		Extents getExtentsLocal() const
		{
			G3D::Vector3 hVec = geometry->getGridSize() * 0.5f;
			return Extents(-hVec, hVec);
		}
		Extents getExtentsWorld() const
		{
			return getExtentsLocal().toWorldSpace(getCoordinateFrame());
		}
		const Extents& getFastFuzzyExtents() const;
		bool hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint, bool& inside);
		Face getFaceInObject(NormalId objectFace);
		Face getFaceInWorld(NormalId objectFace);
		G3D::CoordinateFrame getFaceCoordInObject(NormalId objectFace);
		void setSurfaceType(NormalId id, SurfaceType newSurfaceType);
		SurfaceType getSurfaceType(NormalId id) const
		{
			return surfaceType[id];
		}
		void setSurfaceData(NormalId id, const SurfaceData& newSurfaceData);
		const SurfaceData& getSurfaceData(NormalId id) const
		{
			if (!surfaceData[id])
			{
				return SurfaceData::empty();
			}
			else
			{
				return *surfaceData[id];
			}
		}
		void setController(Controller* _controller);
		Controller* getController()
		{
			return controller;
		}
		float getJointK() const
		{
			return JointK;
		}
	private:
		RigidJoint* getFirstRigidAt(Edge* start);
	public:
		int getNumJoints2() const
		{
			return joints.edges.size();
		}
		int countNumJoints() const;
		int getNumContacts() const
		{
			return contacts.edges.size();
		}
		int getNumEdges() const;
		bool hasEdge();
		Edge* getFirstEdge() const;
		Edge* getNextEdge(Edge* e) const;
		Joint* getFirstJoint() const;
		Joint* getNextJoint(Joint* prev) const;
		Contact* getFirstContact();
		Contact* getNextContact(Contact* prev);
		RigidJoint* getFirstRigid();
		RigidJoint* getNextRigid(RigidJoint* prev);
		//Primitive& operator=(const Primitive&);
  
	private:
		static const int fuzzyExtentsReset();
	protected:
		static Geometry* newGeometry(Geometry::GeometryType geometryType);
	public:
		static void onNewTouch(Primitive* p0, Primitive* p1);
		static float squaredDistance(const Primitive&, const Primitive&);
		static bool aaBoxCollide(const Primitive& p0, const Primitive& p1);
		static float defaultElasticity();
		static float defaultFriction();
		static void insertEdge(Edge*);
		static void removeEdge(Edge*);
		static Joint* getJoint(Primitive* p0, Primitive* p1);
		static Contact* getContact(Primitive* p0, Primitive* p1);
		static Primitive* downstreamPrimitive(Joint*);
	};
}

#include "v8world/Geometry.h"
#include "v8world/Assembly.h"
#include "v8world/Ball.h"
#include "v8world/Block.h"
#include "v8world/World.h"
#include <cmath>

namespace RBX
{
	struct BodyExe : public Body { BodyExe(); char exePad[0xc]; };

	#pragma warning (push)
	#pragma warning (disable : 4355)
	Primitive::Primitive(Geometry::GeometryType geometryType) :
		guidSetExternally(false),
		edgeVersion(1),
		contacts(this),
		joints(this),
		worldIndex(-1),
		traverseId(-1),
		world(NULL),
		clump(NULL),
		clumpDepth(-1),
		spatialNodes(NULL),
		fuzzyExtentsStateId(-2),
		geometry(newGeometry(geometryType)),
		body(new BodyExe),
		myOwner(NULL),
		dragging(false),
		anchored(false),
		flagA(false),
		flagB(false),
		canCollide(true),
		friction(0.0f),
		elasticity(0.75f),
		controller(NullController::getStaticNullController()),
		JointK(this, &Primitive::computeJointK)
	{
		for (int i = 0; i < 6; i++)
		{
			surfaceType[i] = NO_SURFACE;
			surfaceData[i] = NULL;
		}
	}
	#pragma warning (pop)
}

