// from server: 99% by EspClaude
// from server: 74% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_claude_94f14001488898df.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8kernel/Body.h", "v8kernel/KernelIndex.h")
#pragma include_alias(<v8kernel/Body.h>, <v8kernel/KernelIndex.h>)
// v8kernel/Body.h (2007-08: no Link* member; body->pv at +0x84 not +0x88 in target)
#include <G3D/Vector3.h>
#include <G3D/Matrix3.h>
#include <G3D/CoordinateFrame.h>
#include "util/indexarray.h"
#include "v8kernel/SimBody.h"
#include "v8kernel/Link.h"
#include "util/PV.h"
#include "v8kernel/KernelIndex.h"
#include "v8kernel/Cofm.h"
#include "util/math.h"

namespace RBX {
	//class SimBody;
	class Body : KernelIndex
	{
		private:
			int& getIndex() {return index;};
			Body *root;
			Body *parent;
			int index;
			IndexArray<RBX::Body, &getIndex> children;
			Cofm *cofm;
			SimBody *simBody;
			bool canThrottle;
			G3D::CoordinateFrame meInParent;
			G3D::Matrix3 moment;
			float mass;
			mutable int stateIndex;
			mutable PV pv;
			//int& getKernelIndex();
			const RBX::SimBody* getRootSimBody() {return getRoot()->simBody;};
			void resetRoot(RBX::Body* newRoot);
			bool validateParentCofmDirty();
			const G3D::CoordinateFrame& getMeInParent() const
			{
				RBXASSERT(getParent());
				return meInParent;
			}
			void updatePV() const;
			void onChildAdded(RBX::Body* child);
			void onChildRemoved(RBX::Body* child);
			const RBX::Body* calcRootConst() const;
			__declspec(noinline) Body* Body::calcRoot()
			{
				return (getParent() ? getParent()->calcRoot() : this);
			}
			void matchDummy();
		public:
			int& getKernelIndex() {return kernelIndex;}
			Body();
			~Body();
			void step(float, bool);
			bool cofmIsClean();
			void makeCofmDirty();
			void advanceStateIndex();
			void makeStateDirty();
			int getStateIndex() const
			{
				updatePV();
				return stateIndex;
			}
			int numChildren() const {return children.size();}
			RBX::Body* getChild(int index) {return children[index];} //suppose to be const
			inline RBX::Body* getParent() const
			{
				return parent;
			}
			const RBX::Body* getRootConst() const {return root;}
			RBX::Body* getRoot() {return root;}
			const G3D::Vector3& getCofmOffset() const
			{
				if (cofm)
				{
					return cofm->getCofmInBody();
				}
				else
				{
					return G3D::Vector3::zero();
				}
			}

			G3D::CoordinateFrame getMeInDescendant(const RBX::Body* descendant) const;
			G3D::CoordinateFrame getMeInRoot() const;
			float getMass() const {return mass;}
			G3D::Matrix3 getIBody() const
			{
				updatePV();
				return moment;
			}
			G3D::Vector3 getIBodyV3() const;
			G3D::Matrix3 getIWorld() const
			{
				return Math::momentToWorldSpace(getIBody(), pv.position.rotation);
			}
			G3D::Matrix3 getIWorldAtPoint(const G3D::Vector3& point) const;
			float getBranchMass() const
			{
				return (cofm ? cofm->getMass() : mass);
			}
			G3D::Matrix3 getBranchIBody() const
			{
				return cofm ? cofm->getMoment() : moment;
			}
			G3D::Vector3 getBranchIBodyV3() const
			{
				return Math::toDiagonal(getBranchIBody());
			}
			G3D::Matrix3 getBranchIWorld() const
			{
				updatePV();
				return Math::momentToWorldSpace(getBranchIBody(), pv.position.rotation);
			}
			G3D::Matrix3 getBranchIWorldAtPoint(const G3D::Vector3& point) const;
			G3D::Vector3 getBranchCofmPos() const;
			G3D::CoordinateFrame getBranchCofmCoordinateFrame() const;
			const G3D::Vector3& getPos() const
			{
				updatePV();
				return cofm->getCofmInBody();
			}
			const G3D::CoordinateFrame& getCoordinateFrame() const
			{
				updatePV();
				return pv.position;
			}
			const RBX::Velocity& getVelocity() const
			{
				updatePV();
				return pv.velocity;
			}
			const RBX::PV& getPV() const
			{
				updatePV();
				return pv;
			}
			const bool getCanThrottle() const {return this->canThrottle;}
			void accumulateForceAtCofm(const G3D::Vector3&);
			void accumulateForceAtBranchCofm(const G3D::Vector3& force)
			{
				RBXASSERT(root == this);

				if (root->simBody)
					root->simBody->accumulateForceCofm(force);
			}
			void accumulateForce(const G3D::Vector3& force, const G3D::Vector3& worldPos)
			{
				SimBody* simBody = root->simBody;
				if (simBody)
					simBody->accumulateForce(force, worldPos);
			}
			void accumulateTorque(const G3D::Vector3& torque)
			{
				if (root->simBody)
					root->simBody->accumulateTorque(torque);
			}
			void resetAccumulators()
			{
				if (root->simBody)
					root->simBody->resetAccumulators();
			}
			const G3D::Vector3& getBranchForce() const
			{
				if (root->simBody)
					return root->simBody->force;
				else
					return G3D::Vector3::zero();
			}
			const G3D::Vector3& getBranchTorque() const
			{
				if (root->simBody)
					return root->simBody->torque;
				else
					return G3D::Vector3::zero();
			}
			void setParent(Body* newParent);
			void setMeInParent(const G3D::CoordinateFrame& _meInParent);
			void setMass(float _mass);
			__declspec(noinline) void setMoment(const G3D::Matrix3& _momentInBody) // noinline for Primitive::setGridSize
			{
				if (moment != _momentInBody)
				{
					makeCofmDirty();
					moment = _momentInBody;
				}
			}
			void setPv(const PV& _pv);
			void setCoordinateFrame(const G3D::CoordinateFrame& worldCord);
			void setVelocity(const RBX::Velocity& worldVelocity);
			void setCanThrottle(bool value)
			{
				canThrottle = value;
			}
			float kineticEnergy() const;
			float potentialEnergy() const;
			static int getNextStateIndex();
			static Body* getWorldBody();
	};
}
#pragma include_alias("v8world/Primitive.h", "v8world/Anchor.h")
#pragma include_alias(<v8world/Primitive.h>, <v8world/Anchor.h>)
// v8world/Primitive.h (2007-08: no guid/traverseId; getCoordinateFrame inline - target reads body at +0x64 and body->pv at +0x84 inline)
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
		RBX::Edge* first;
		int num;
  
	public:
		EdgeList() : num(0), first(NULL) {}
		~EdgeList()
		{
			RBXASSERT(!first);
			RBXASSERT(!num);
		}
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
		EdgeList contacts;
		EdgeList joints;
		int worldIndex;
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
		Anchor* anchorObject;
		bool dragging;
		bool anchored;
		bool canCollide;
		bool canSleep;
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
		const G3D::CoordinateFrame& getCoordinateFrame() const;
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
			return anchorObject != NULL;
		}
		Anchor* getAnchorObject()
		{
			return anchorObject;
		}
		void setCanCollide(bool value);
		const bool getCanCollide() const
		{
			return canCollide;
		}
		void setCanSleep(bool _canSleep);
		const bool getCanSleep() const
		{
			return canSleep;
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
			// TODO: get this fully matching
			// check RotateJoint::getChannelValue
			const SurfaceData* data = surfaceData[id];
			return data ? *data : SurfaceData::empty();
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
			return joints.num;
		}
		int countNumJoints() const;
		int getNumContacts() const
		{
			return contacts.num;
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

#include "v8world/GlueJoint.h"
#include "v8world/Primitive.h"
#include "v8kernel/Kernel.h"
#include "v8kernel/Body.h"
namespace RBX { inline const G3D::CoordinateFrame& Primitive::getCoordinateFrame() const { return body->getPV().position; } }
#include "v8kernel/Connector.h"
#include "v8kernel/Constants.h"
#include "util/Units.h"

namespace RBX
{
	// TODO: check what needs to go into the header file

	GlueJoint::GlueJoint()
		: MultiJoint(4),
		  overlapInP0(),
		  overlapInP1()
	{
	}

	GlueJoint::GlueJoint(Primitive* p0, Primitive* p1, const G3D::CoordinateFrame& jointCoord0, const G3D::CoordinateFrame& jointCoord1)
		: MultiJoint(p0, p1, jointCoord0, jointCoord1, 4),
		  overlapInP0(),
		  overlapInP1()
	{
		NormalId nId0 = Matrix3ToNormalId(this->jointCoord0.rotation);
		Face face0inP0 = p0->getFaceInObject(nId0);

		NormalId nId1 = normalIdOpposite(Matrix3ToNormalId(this->jointCoord1.rotation));
		Face face1inP1 = p1->getFaceInObject(nId1);

		Face face0inJoint0 = face0inP0.toObjectSpace(jointCoord0);
		Face face1inJoint1 = face1inP1.toObjectSpace(jointCoord1);

		Face overlapInJoint0 = face0inJoint0.projectOverlapOnMe(face1inJoint1);
		overlapInJoint0.snapToGrid(0.1f);

		this->overlapInP0 = overlapInJoint0.toWorldSpace(jointCoord0);
		this->overlapInP1 = overlapInJoint0.toWorldSpace(jointCoord1);
	}

	float GlueJoint::getMaxForce()
	{
		G3D::Vector2 size = overlapInP0.size();
		return Units::kmsForceToRbx(Constants::getKmsMaxJointForce(size.x, size.y));
	}

	void GlueJoint::putInKernel(Kernel* _kernel)
	{
		MultiJoint::putInKernel(_kernel);

		Body* b0 = getPrimitive(0)->getBody();
		Body* b1 = getPrimitive(1)->getBody();

		NormalId nId0 = Matrix3ToNormalId(jointCoord0.rotation);

		for (int i = 0; i < 4; ++i)
		{
			G3D::Vector3 p0World = b0->getPV().position.pointToWorldSpace(overlapInP0[i]);
			G3D::Vector3 p1World = b1->getPV().position.pointToWorldSpace(overlapInP1[i]);

			Point* p0 = getKernel()->newPoint(b0, p0World);
			Point* p1 = getKernel()->newPoint(b1, p1World);

			NormalBreakConnector* connector = new NormalBreakConnector(p0, p1, getJointK(), getMaxForce(), nId0);
			addToMultiJoint(p0, p1, connector);
		}
	}

	bool GlueJoint::compatibleSurfaces(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
	{
		SurfaceType s0 = p0->getSurfaceType(nId0);
		SurfaceType s1 = p1->getSurfaceType(nId1);
		return s0 == GLUE || s1 == GLUE;
	}

	GlueJoint* GlueJoint::canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
	{
		if (!compatibleSurfaces(p0, p1, nId0, nId1) || !canBuildJointLoose(p0, p1, nId0, nId1))
			return NULL;

		Face f0 = p0->getFaceInWorld(nId0);
		Face f1 = p1->getFaceInWorld(nId1);

		Face overlapOn0 = f0.projectOverlapOnMe(f1);
		Face overlapOn1 = f1.projectOverlapOnMe(f0);

		Face offsetInP0 = overlapOn0.toObjectSpace(p0->getCoordinateFrame());
		Face offsetInP1 = overlapOn1.toObjectSpace(p1->getCoordinateFrame());

		offsetInP0.snapToGrid(0.1f);
		offsetInP1.snapToGrid(0.1f);

		Face offset0World = offsetInP0.toWorldSpace(p0->getCoordinateFrame());
		Face offset1World = offsetInP1.toWorldSpace(p1->getCoordinateFrame());

		if (!Face::cornersAligned(offset0World, offset1World, 0.05f))
			return NULL;

		G3D::CoordinateFrame jointCoord0 = p0->getFaceCoordInObject(nId0);
		G3D::CoordinateFrame jointCoord0InWorld = p0->getCoordinateFrame() * jointCoord0;
		G3D::CoordinateFrame jc0InP1 = p1->getCoordinateFrame().toObjectSpace(jointCoord0InWorld);
		G3D::CoordinateFrame jointCoord1 = Math::snapToGrid(jc0InP1, 0.1f);

		return new GlueJoint(p0, p1, jointCoord0, jointCoord1);
	}
}
