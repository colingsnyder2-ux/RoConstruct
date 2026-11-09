#pragma once
#include <set>
#include <boost/scoped_ptr.hpp>
#include <G3D/Array.h>
#include "v8world/IWorldStage.h"
#include "v8world/Primitive.h"
#include "util/IndexArray.h"
#include "util/Events.h"
#include "util/Profiling.h"

namespace RBX
{
	class Assembly;
	class Joint;
	class Contact;
	class MotorJoint;
	class Kernel;
	class ContactManager;
	class SleepStage;
	class JointStage;
	class SimJobStage;
	class ClumpStage;
	class CollisionStage;
	class AutoA;
	class AutoB;

	// is this the right file for AutoJoin and AutoDestroy?
	struct AutoJoin
	{
		Joint* joint;
		AutoJoin(Joint* j) : joint(j) {}
	};

	struct AutoDestroy
	{
		Joint* joint;
		AutoDestroy(Joint* j) : joint(j) {}
	};

	struct AssemblyPhysicsOn
	{
		Primitive* primitive;
	};

	struct AssemblyPhysicsOff
	{
		Primitive* primitive;
	};

	class World : public Notifier<World, AutoJoin>, public Notifier<World, AutoDestroy>,
				  public Notifier<World, AutoA>, public Notifier<World, AutoB>
	{
	private:
		float throttle;
		ContactManager* contactManager;
		JointStage* jointStage;
		G3D::Array<Primitive*> touch;
		G3D::Array<Primitive*> touchOther;
		bool inStepCode;
		bool inJointNotification;
		int worldStepId;
		IndexArray<Primitive, &Primitive::worldIndexFunc> primitives;
		G3D::Array<Primitive*> primitives2;
		std::set<Joint*> breakableJoints;
		int numJoints;
		int numContacts;
		int numLinkCalls;
		G3D::Array<Primitive*> tempPrimitives;
		boost::scoped_ptr<Profiling::CodeProfiler> profilingWorldStep;
		boost::scoped_ptr<Profiling::CodeProfiler> profilingPreStep;
		boost::scoped_ptr<Profiling::CodeProfiler> profilingAssemblyStep;
		boost::scoped_ptr<Profiling::CodeProfiler> profilingUiStep;
		boost::scoped_ptr<Profiling::CodeProfiler> profilingPreStep8Inner;
		boost::scoped_ptr<Profiling::CodeProfiler> profilingBroadphase;
	public:
		static bool disableEnvironmentalThrottle;

		enum EThrottle
		{
			DefaultAuto,
			Disabled,
			Random,
			Always
		};
		static EThrottle environmentalThrottle;
  
	public:
		void createJoints(Primitive* p);
	private:
		void createJoints(Primitive* p, std::set<Primitive*>* ignoreGroup);
	public:
		void destroyJoints(Primitive* p);
	private:
		void destroyJoints(Primitive* p, std::set<Primitive*>* ignoreGroup);
		void destroyJoint(Joint*);
		void removeFromBreakable(Joint* j);
		void doBreakJoints();
	public:
		World();
		virtual ~World();
	public:
		void assertNotInStep()
		{
			RBXASSERT(!inStepCode);
		}
		void assertInStep()
		{
			RBXASSERT(inStepCode);
		}
		void addedBodyForce();
		void setCanThrottle(bool value)
		{
			throttle = value ? 100.0f : 0.0f;
		}
		ContactManager& getContactManager()
		{
			return *contactManager;
		}
		ClumpStage* getClumpStage();


		const SleepStage* getSleepStage() const;
		SleepStage* getSleepStage();
		SimJobStage& getSimJobStage();
		const Kernel& getKernel() const;
		Kernel& getKernel();
		const G3D::Array<Primitive*>& getTouch() const
		{
			return touch;
		}
		const G3D::Array<Primitive*>& getTouchOther() const
		{
			return touchOther;
		}
		void computeFallen(G3D::Array<Primitive*>& fallen) const;
		const G3D::Array<Primitive*>& getPrimitives() const 
		{
			return this->primitives.underlyingArray();
		}
		float step(float desiredInterval);
		void update();
		void reset()
		{
			assertNotInStep();
			worldStepId = 0;
		}
		int getWorldStepId();
		void insertPrimitive(Primitive* p);
		void removePrimitive(Primitive* p);
		void ticklePrimitive(Primitive* p);
		void joinAll();
		void createJointsToWorld(const G3D::Array<Primitive*>&);
		void destroyJointsToWorld(const G3D::Array<Primitive*>&);
		void insertJoint(Joint*);
		void removeJoint(Joint*);
		int getMetric(IWorldStage::MetricType) const;
		int getNumBodies() const;
		int getNumPoints() const;
		int getNumConstraints() const;
		int getNumHashNodes() const;
		int getMaxBucketSize() const;
		int getNumLinkCalls() const
		{
			return numLinkCalls;
		}
		int getNumContacts() const
		{
			return numContacts;
		}
		int getNumJoints() const
		{
			return numJoints;
		}
		int getNumPrimitives() const
		{
			return primitives.size();
		}
		const Profiling::CodeProfiler& getProfileWorldStep() const
		{
			return *profilingWorldStep;
		}
		Profiling::CodeProfiler& getProfileWorldStep()
		{
			return *profilingWorldStep;
		}
		const Profiling::CodeProfiler& getProfileBroadphase() const
		{
			return *profilingBroadphase;
		}
		const Profiling::CodeProfiler& getProfileUiStep() const
		{
			return *profilingUiStep;
		}
		void onPrimitiveAddedAnchor(Primitive* p);
		void onPrimitiveRemovingAnchor(Primitive* p);
		void onPrimitiveExtentsChanged(Primitive* p);
		void onAssemblyExtentsChanged(Assembly* a);
		void onPrimitiveContactParametersChanged(Primitive* p);
		void onPrimitiveCanCollideChanged(Primitive* p);
		void onPrimitiveCanSleepChanged(Primitive* p);
		void onPrimitiveGeometryTypeChanged(Primitive* p);
		void onPrimitiveTouched(Primitive* touchP, Primitive* touchOtherP);
		void onMotorAngleChanged(MotorJoint* m);
		void onJointPrimitiveNulling(Joint* j, Primitive* p);
		void onJointPrimitiveSet(Joint* j, Primitive* p);
		void insertContact(Contact* c);
		void destroyContact(Contact* c);
	};
}
