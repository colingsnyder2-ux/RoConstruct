// from server: 100% by king_originala_sol_native
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_sol_gluetransform_ed1d80f4471ae699.cpp

// Candidate translation unit (score above; library headers required).
#include "util/PV.h"
#include "util/Face.h"
#include "util/NormalId.h"
#include "v8kernel/IStage.h"
#include "v8world/IWorldStage.h"
// Native Connector has five typed virtual APIs: dt/throttle force, throttle flag,
// broken flag and an indexed Body getter after its destructor. The older SDK
// potentialEnergy declaration does not describe this binary.
namespace RBX {
class Body;
class KernelIndex { public: int kernelIndex; KernelIndex():kernelIndex(-1){} };
// Borrowed Point view: native getBody(int) dereferences point+0xc.
class Point { char nativePrefix[0xc]; Body* body; public: Body* getBody(){return body;} };
class Kernel { public: Point* newPoint(Body*,const G3D::Vector3&); };
	class Connector : public RBX::KernelIndex
	{
	public: // this is meant to be private
		__declspec(noinline) int& getKernelIndex() {return kernelIndex;}
	public:
		Connector(const Connector&);
		Connector() {};
		virtual ~Connector() {}
		virtual void computeForce(const float dt, bool throttling) = 0;
		virtual bool canThrottle() const {return true;}
		virtual bool getBroken() {return false;}
		virtual Body* getBody(int) = 0;
		//RBX::Connector& operator=(const RBX::Connector&);
	};

	class PointToPointBreakConnector : public Connector
	{
	protected:
		Point* point0;
		Point* point1;
		float k;
		float breakForce;
		bool broken;
	protected:
		void forceToPoints(const G3D::Vector3&);
	public:
		//PointToPointBreakConnector(const PointToPointBreakConnector&);
		// TODO:: check if the ctor matches
		PointToPointBreakConnector(Point* _point0, Point* _point1, float _k, float _breakForce)
			: point0(_point0),
			  point1(_point1),
			  k(_k),
			  breakForce(_breakForce),
			  broken(false)
		{}

		virtual void computeForce(const float dt, bool throttling);
		virtual bool getBroken() {return this->broken;}
		virtual Body* getBody(int i) { if (i == 0) return point0->getBody(); return point1->getBody(); }
		void setBroken() {this->broken = true;}
		virtual ~PointToPointBreakConnector() {};
		//PointToPointBreakConnector& operator=(const PointToPointBreakConnector&);
	};

	class NormalBreakConnector : public PointToPointBreakConnector
	{
	private:
		NormalId normalIdBody0;

	public:
		//NormalBreakConnector(const NormalBreakConnector&);
		NormalBreakConnector(Point* _point0, Point* _point1, float _k, float _breakForce, NormalId _normalIdBody0)
			: PointToPointBreakConnector(_point0, _point1, _k, _breakForce),
			  normalIdBody0(_normalIdBody0)
		{
		}
		virtual ~NormalBreakConnector() {}
	public:
		virtual void computeForce(const float dt, bool throttling);
		//NormalBreakConnector& operator=(const NormalBreakConnector&);
	};

}


namespace RBX
{
	class World;

	class __declspec(novtable) IPipelined
	{
	private:
		RBX::IStage* currentStage;
  
	public:
		void removeFromStage(IStage* stage);
	private:
		void removeFromStage(IStage::StageType);
		IStage* getStage(IStage::StageType stageType) const;
	public:
		//IPipelined(const IPipelined&);
		IPipelined() : currentStage(NULL) {}
		virtual ~IPipelined()
		{
			RBXASSERT(currentStage == NULL);
		}
		void putInPipeline(IStage* stage);
		void removeFromPipeline(IStage* stage);
		void putInStage(IStage* stage);
		bool inPipeline() const
		{
			return currentStage != NULL;
		}
		bool inStage(IStage* iStage) const
		{
			RBXASSERT(iStage);
			RBXASSERT(currentStage);

			return currentStage == iStage;
		}
		bool inStage(IStage::StageType stageType) const
		{
			RBXASSERT(currentStage);

			return currentStage->getStageType() == stageType;
		}
		bool inOrDownstreamOfStage(IStage* iStage) const
		{
			RBXASSERT(iStage);
			RBXASSERT(currentStage);

			return (int)currentStage->getStageType() >= (int)iStage->getStageType();
		}
		bool downstreamOfStage(IStage* iStage) const
		{
			RBXASSERT(iStage);
			RBXASSERT(currentStage);

			return (int)currentStage->getStageType() > (int)iStage->getStageType();
		}
		bool inKernel() const
		{
			return this->inStage(IStage::KERNEL_STAGE);
		}
		Kernel* getKernel() const;
		virtual void putInKernel(Kernel* kernel);
		virtual void removeFromKernel();
		World* getWorld()
		{
			if (!currentStage)
				return NULL;

			IStage* upstream;
			if (currentStage->getStageType() != IStage::KERNEL_STAGE)
				upstream = currentStage;
			else
				upstream = currentStage->getUpstream();

			return rbx_static_cast<IWorldStage*>(upstream)->getWorld();
		}
		//IPipelined& operator=(const IPipelined&);
	};
}

namespace RBX
{
	class Primitive;

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

	class __declspec(novtable) Edge : public IPipelined
	{
	public:
		enum EdgeType
		{
			JOINT,
			CONTACT
		};

	private:
		Sim::EdgeState edgeState;
		Primitive* prim0;
		Primitive* prim1;
		Edge* next0;
		Edge* next1;
		bool inEdgeList;
  
	public:
		Edge(Primitive* prim0, Primitive* prim1);
		virtual ~Edge() 
		{
		}

		bool getInEdgeList() const;
		void setInEdgeList(bool);
		virtual EdgeType getEdgeType() const = 0;
		Sim::EdgeState getEdgeState() const;
		void setEdgeState(Sim::EdgeState);
		Primitive* getPrimitive(int i) const
		{
			return *(&this->prim0 + i);
		}
		Primitive* otherPrimitive(int) const;
		Primitive* otherPrimitive(const Primitive* p) const
		{
			return p == prim0 ? prim1 : prim0;
		}
		int getPrimitiveId(const Primitive*) const;
		Edge* getNext(const Primitive* p) const
		{
			return p == prim0 ? next0 : next1;
		}
		void setNext(Primitive* p, Edge* e)
		{
			if (p == prim0)
				next0 = e;
			else
				next1 = e;
		}
		bool links(Primitive*, Primitive*) const;
		bool links(const Primitive* p) const
		{
			return p == prim0 || p == prim1;
		}
		virtual void setPrimitive(int i, Primitive* p);
	};
}

namespace RBX
{
	class IJointOwner
	{
	};

	class Joint : public Edge
	{
	public:
		enum JointType
		{
			NO_JOINT,
			ROTATE_JOINT,
			ROTATE_P_JOINT,
			ROTATE_V_JOINT,
			GLUE_JOINT,
			ANCHOR_JOINT,
			WELD_JOINT,
			SNAP_JOINT,
			MOTOR_JOINT,
			FREE_JOINT
		};

	private:
		IJointOwner* jointOwner;
	protected:
		bool active;
		G3D::CoordinateFrame jointCoord0;
		G3D::CoordinateFrame jointCoord1;

	protected:
		virtual Edge::EdgeType getEdgeType() const
		{
			return JOINT;
		}
	public:
		//Joint(const Joint&);
	protected:
		Joint(Primitive* prim0, Primitive* prim1, const G3D::CoordinateFrame& _jointCoord0, const G3D::CoordinateFrame& _jointCoord1);
		Joint();
	public:
		virtual ~Joint();
	public:
		void setJointOwner(IJointOwner* value);
		IJointOwner* getJointOwner() const;
		virtual void setPrimitive(int i, Primitive* p);
		virtual JointType getJointType() const
		{
			RBXASSERT(0);
			return NO_JOINT;
		}
		virtual bool isBreakable() const
		{
			return false;
		}
		virtual bool isBroken() const
		{
			return false;
		}
		virtual bool joinsFace(Primitive* p, NormalId face) const
		{
			return false;
		}
		virtual bool isAligned()
		{
			return true;
		}
		virtual G3D::CoordinateFrame align(Primitive* pMove, Primitive* pStay)
		{
			RBXASSERT(0);
			return G3D::CoordinateFrame();
		}
		virtual bool canStepUi() const
		{
			return false;
		}
		virtual void stepUi(int uiStepId)
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
		void setJointCoord(int i, const G3D::CoordinateFrame& c);
		const G3D::CoordinateFrame& getJointCoord(int i) const
		{
			return i == 0 ? jointCoord0 : jointCoord1;
		}
		NormalId getNormalId(int) const;
		//Joint& operator=(const Joint&);
  
	private:
		static bool canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1, float angleMax, float planarMax);
	protected:
		static bool canBuildJointLoose(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1);
		static bool canBuildJointTight(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1);
	public:
		static JointType getJointType(Edge* e)
		{
			if (e->getEdgeType() == Edge::JOINT)
			{
				return rbx_static_cast<Joint*>(e)->getJointType();
			}
			else
			{
				return NO_JOINT;
			}
		}
		static bool isJoint(Edge* e)
		{
			return e->getEdgeType() == Edge::JOINT;
		}
		static bool isAssemblyJoint(Edge* e);
		static bool isGroundJoint(Joint*);
		static bool isAutoJoinJoint(Joint*);
	};
}
namespace RBX
{
	class MultiJoint : public Joint
	{
	private:
		int numConnector;
		Point* point[8];
		Connector* connector[4];
		int numBreakingConnectors;
	  
	private:
		bool pointsAligned() const;
		void init(int);
	protected:
		virtual void putInKernel(Kernel*);
		virtual void removeFromKernel();
		virtual bool isBroken() const;
		void addToMultiJoint(Point*, Point*, Connector*);
		Point* getPoint(int);
		Connector* getConnector(int);
		float getJointK();
	public:
		//MultiJoint(const MultiJoint&);
	protected:
		MultiJoint(Primitive* p0, Primitive* p1, const G3D::CoordinateFrame& jointCoord0, const G3D::CoordinateFrame& jointCoord1, int numBreaking);
		MultiJoint(int numBreaking);
		virtual ~MultiJoint();
	public:
		//MultiJoint& operator=(const MultiJoint&);
	};
}

namespace RBX
{
	class Primitive;
	class Kernel;

	class GlueJoint : public MultiJoint
	{
	private:
		Face overlapInP0;
		Face overlapInP1;
  
	private:
		float getMaxForce();
		virtual void putInKernel(Kernel*);
		virtual Joint::JointType getJointType() const
		{
			return GLUE_JOINT;
		}
		virtual bool isBreakable() const
		{
			return true;
		}
	public:
		//GlueJoint(const GlueJoint&);
		GlueJoint(Primitive*, Primitive*, const G3D::CoordinateFrame&, const G3D::CoordinateFrame&);
		GlueJoint();
		virtual ~GlueJoint() {}
  
	private:
		static bool compatibleSurfaces(Primitive*, Primitive*, NormalId, NormalId);
	public:
		static GlueJoint* canBuildJoint(Primitive*, Primitive*, NormalId, NormalId);
	};
}
namespace RBX {
// Borrowed native views: observed primitive body pointer at a0 and Body PV at 94.
struct NativePrimitiveBodyView { char prefix[0xa0]; Body* body; };
struct NativeBodyPVView {
 char prefix[0x94]; PV pv;
 void updatePV() const;
 const PV& getPV() const { updatePV(); return pv; }
};
__forceinline G3D::Vector3 gluePointWorld(const G3D::CoordinateFrame& f,const G3D::Vector3& v){return G3D::Vector3(f.rotation[0][0]*v[0] + f.rotation[0][1]*v[1] + f.rotation[0][2]*v[2] + f.translation[0],f.rotation[1][0]*v[0] + f.rotation[1][1]*v[1] + f.rotation[1][2]*v[2] + f.translation[1],f.rotation[2][0]*v[0] + f.rotation[2][1]*v[1] + f.rotation[2][2]*v[2] + f.translation[2]);}
void GlueJoint::putInKernel(Kernel* _kernel)
{
    MultiJoint::putInKernel(_kernel);

    Body* b0 = reinterpret_cast<NativePrimitiveBodyView*>(getPrimitive(0))->body;
    Body* b1 = reinterpret_cast<NativePrimitiveBodyView*>(getPrimitive(1))->body;

    NormalId nId0 = Matrix3ToNormalId(jointCoord0.rotation);

    for (int i = 0; i < 4; ++i)
    {
        G3D::Vector3 p0World = gluePointWorld(reinterpret_cast<const NativeBodyPVView*>(b0)->getPV().position,overlapInP0[i]);
        G3D::Vector3 p1World = reinterpret_cast<const NativeBodyPVView*>(b1)->getPV().position.pointToWorldSpace(overlapInP1[i]);

        Point* p0 = getKernel()->newPoint(b0, p0World);
        Point* p1 = getKernel()->newPoint(b1, p1World);

        NormalBreakConnector* connector = new NormalBreakConnector(p0, p1, getJointK(), getMaxForce(), nId0);
        addToMultiJoint(p0, p1, connector);
    }
}
}
