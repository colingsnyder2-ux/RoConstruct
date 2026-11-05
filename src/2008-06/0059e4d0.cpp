// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_unit_1d9b5609956f3c96.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Extents.h"
#pragma include_alias("v8world/Primitive.h", "G3D/Array.h")
#undef _RELEASEASSERT
#undef _DEBUG
#define _DLL
#define private public
#include "util/IRenderable.h"
#undef private
#include "util/Object.h"
#define hasListeners() hasListeners() const { return listeners.size() > 0; } bool hasListenersEmpty()
#include "util/Events.h"
#undef hasListeners
namespace RBX { template<class T> class GuidItem { public: virtual ~GuidItem() {} char guidPad[0xc]; }; }
namespace RBX { template<class T> class GuidAFP : public AbstractFactoryProduct<T> { protected: virtual void onGuidChanged() {} }; }
#define AbstractFactoryProduct GuidItem<Instance>, public GuidAFP
#include "util/Guid.h"
namespace RBX { class GuidStub { public: typedef Guid::Data Data; void assign(const Data&) {} operator const Guid&() const { return *(const Guid*)0; } }; }
#define Guid GuidStub
#include "v8tree/Instance.h"
#undef Guid
#undef AbstractFactoryProduct
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

namespace boost { template<> class scoped_ptr<RBX::Primitive> { RBX::Primitive p; public: RBX::Primitive* operator->() const { return const_cast<RBX::Primitive*>(&p); } RBX::Primitive* get() const { return const_cast<RBX::Primitive*>(&p); } RBX::Primitive& operator*() const { return const_cast<RBX::Primitive&>(p); } }; }
#define SurfacesNeedAdorn SurfacesNeedAdorn; std::string exeStr; char exePartPad2[4]
#define private public
#include "v8datamodel/PartInstance.h"
#undef private
#undef SurfacesNeedAdorn
#include "v8world/Assembly.h"
#include "v8world/Controller.h"
#include "v8world/Clump.h"
#include "v8world/Primitive.h"
#include "AppDraw/Draw.h"
#include "AppDraw/DrawAdorn.h"
#include "util/Math.h"
namespace RBX
{
	// exe Assembly keeps a SleepInfo* at +0x18 (state first); see SleepStage 0064c470
	static inline Sim::AssemblyState exeSleepStatus(Assembly* a)
	{
		Sim::AssemblyState* info = *reinterpret_cast<Sim::AssemblyState**>(reinterpret_cast<char*>(a) + 0x18);
		return info ? *info : Sim::ANCHORED;
	}

	// exe Assembly: rootClump at +0x24, Clump::rootPrimitive at +0x1c (see SleepStage 0064c470)
	struct ExeClump { char pad[0x1c]; Primitive* rootPrimitive; Primitive* getRootPrimitive() const { return rootPrimitive; } };
	struct ExeAssembly { char pad[0x24]; ExeClump* rootClump; ExeClump* getRootClump() const { return rootClump; } Primitive* getMainPrimitive() const; };
	Primitive* ExeAssembly::getMainPrimitive() const { return rootClump->getRootPrimitive(); }
	static inline Primitive* exeMainPrimitive(Assembly* a)
	{
		return reinterpret_cast<ExeAssembly*>(a)->getMainPrimitive();
	}

	class ExeGeoPair { public: G3D::Vector3 computePosition(); };
	class ExeConnector { public: char pad[8]; ExeGeoPair geoPair; };
	class ExeContact : public Edge
	{
		virtual void deleteAllConnectors() = 0;
		virtual bool stepContact() = 0;
		virtual bool computeIsColliding(float) = 0;
	public:
		virtual int numConnectors() const = 0;
		virtual ExeConnector* getConnector(int) const = 0;
	};
	class ExePrimitiveContacts { public: ExeContact* getContact(int); };
	extern bool showContactPoints;

	static __forceinline G3D::Color3 exeSleepColor(Sim::AssemblyState sleepStatus)
	{
		G3D::Color3 sleepColor;
		switch (sleepStatus)
		{
		case Sim::RECURSIVE_WAKE_PENDING:
		case Sim::WAKE_PENDING:
			sleepColor = G3D::Color3::purple();
			break;
		case Sim::SLEEPING_CHECKING:
			sleepColor = G3D::Color3::orange();
			break;
		case Sim::SLEEPING_DEEPLY:
			sleepColor = G3D::Color3::yellow();
			break;
		default:
			sleepColor = sleepColor;
			break;
		}
		return sleepColor;
	}

	static __forceinline G3D::Color3 exeWakeColor(Sim::AssemblyState sleepStatus)
	{
		G3D::Color3 wakeColor;
		switch (sleepStatus)
		{
		case Sim::AWAKE:
			wakeColor = G3D::Color3::red();
			break;
		case Sim::SLEEPING_CHECKING:
			wakeColor = G3D::Color3::orange();
			break;
		case Sim::RECURSIVE_WAKE_PENDING:
		case Sim::WAKE_PENDING:
			wakeColor = G3D::Color3::purple();
			break;
		default:
			wakeColor = wakeColor;
			break;
		}
		return wakeColor;
	}

	void PartInstance::setAlphaModifier(float value)
	{
		if (value != alphaModifier)
		{
			alphaModifier = value;
			raisePropertyChanged(prop_Transparency);
		}
	}

	void PartInstance::render3dAdorn(Adorn* adorn)
	{
		if (partType == Part::CYLINDER_PART || SurfacesNeedAdorn)
			Draw::partAdorn(getPart(), adorn, Controller::controllerTypeToColor(getTopPVController()->getControllerType()));

		if (highlightSleepParts && primitive->getAssembly())
		{
			Sim::AssemblyState sleepStatus = exeSleepStatus(primitive->getAssembly());

			if (sleepStatus != Sim::ANCHORED && sleepStatus != Sim::AWAKE)
			{
				G3D::Color3 sleepColor;
				switch (sleepStatus)
				{
				case Sim::RECURSIVE_WAKE_PENDING:
				case Sim::WAKE_PENDING:
					sleepColor = G3D::Color3::purple();
					break;
				case Sim::SLEEPING_CHECKING:
					sleepColor = G3D::Color3::orange();
					break;
				case Sim::SLEEPING_DEEPLY:
					sleepColor = G3D::Color3::yellow();
					break;
				}
				Draw::selectionBox(getPart(), adorn, sleepColor);
			}
		}

		if (highlightAwakeParts && primitive->getAssembly())
		{
			Sim::AssemblyState sleepStatus = exeSleepStatus(primitive->getAssembly());

			if (sleepStatus != Sim::ANCHORED && sleepStatus != Sim::SLEEPING_DEEPLY)
			{
				G3D::Color3 wakeColor;
				switch (sleepStatus)
				{
				case Sim::AWAKE:
					wakeColor = G3D::Color3::red();
					break;
				case Sim::SLEEPING_CHECKING:
					wakeColor = G3D::Color3::orange();
					break;
				case Sim::RECURSIVE_WAKE_PENDING:
				case Sim::WAKE_PENDING:
					wakeColor = G3D::Color3::purple();
					break;
				}
				Draw::selectionBox(getPart(), adorn, wakeColor);
			}
		}

		if (showPartCoord)
			renderCoordinateFrame(adorn);

		if (showAnchoredParts && primitive->getAnchor())
		{
			float transparency = 1.0f - alpha();
			G3D::Color4 color(G3D::Color3::gray(), transparency);
			const G3D::CoordinateFrame& cframe = primitive->getCoordinateFrame();

			DrawAdorn::partSurface(getPart(), Math::getClosestObjectNormalId(G3D::Vector3(0.0f, -1.0f, 0.0f), cframe.rotation), adorn, color);
		}

		if (showUnalignedParts && !aligned())
			Draw::selectionBox(getPart(), adorn, G3D::Color3::yellow());

		if (showSpanningTree)
		{
			setAlphaModifier(0.3f);

			Assembly* assembly = primitive->getAssembly();
			if (assembly && primitive.get() == exeMainPrimitive(assembly))
			{
				adorn->setObjectToWorldMatrix(G3D::CoordinateFrame(primitive->getCoordinateFrame().translation));

				if (primitive->getAnchor())
				{
					adorn->sphere(G3D::Sphere(G3D::Vector3::zero(), 0.5f), G3D::Color3::green(), G3D::Color4::clear());
				}
				else
				{
					G3D::Vector3 boxSize = G3D::Vector3::one() * 0.25f;
					adorn->box(G3D::AABox(-boxSize, boxSize), G3D::Color3::green(), G3D::Color4::clear());
				}
			}
		}

		if (showContactPoints)
		{
			for (int i = 0; i < primitive->getNumContacts(); ++i)
			{
				ExeContact* contact = reinterpret_cast<ExePrimitiveContacts*>(primitive.get())->getContact(i);
				for (int j = 0; j < contact->numConnectors(); ++j)
				{
					{ ExeConnector* connector = contact->getConnector(j); G3D::Vector3 position = connector->geoPair.computePosition(); adorn->setObjectToWorldMatrix(G3D::CoordinateFrame(position)); }
					adorn->sphere(G3D::Sphere(G3D::Vector3::zero(), 0.5f), G3D::Color3::red(), G3D::Color4::clear());
				}
			}
		}
	}

}
