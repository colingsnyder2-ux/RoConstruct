#pragma once
#include <boost/noncopyable.hpp>
#include <set>
#include <list>
#include <vector>
#include "util/Debug.h"

namespace RBX
{
	class Primitive;
	class Assembly;
	class MechanismTracker;

	// Native 005e50f0 / 005e53a0: shared tracker ownership, separate from grouping.
	class SimJob : public boost::noncopyable
	{
		friend class MechanismTracker;
		std::vector<MechanismTracker*> trackers;
	public:
		std::list<SimJob*>::iterator jobIterator;
		virtual ~SimJob() { RBXASSERT(trackers.empty()); }
		virtual Assembly* getAssembly() = 0;
		virtual const Assembly* getAssembly() const = 0;
	};
	typedef char SimJobSize[sizeof(SimJob)==36?1:-1];

	// 005e51e0 / 0074eed0: one assembly pointer after the 36-byte base.
	class AssemblyJob : public SimJob
	{
		Assembly* assembly;
	public:
		explicit AssemblyJob(Assembly* value) : assembly(value) {}
		virtual Assembly* getAssembly() { return assembly; }
		virtual const Assembly* getAssembly() const { return assembly; }
	};
	typedef char AssemblyJobSize[sizeof(AssemblyJob)==40?1:-1];

	class Mechanism : public SimJob
	{
	private:
		std::set<Assembly*> assemblies;
	public:
		std::list<Mechanism*>::iterator myIt;

		Mechanism::~Mechanism() 
		{ 
			// SimJob checks tracker lifetime. 
		}

		const std::set<Assembly*>& getAssemblies() const 
		{
			return assemblies;
		}

		std::set<Assembly*>& getAssemblies() 
		{
			return assemblies;
		}

		virtual Assembly* getAssembly() { return assemblies.empty()?NULL:*assemblies.begin(); }
		virtual const Assembly* getAssembly() const { return assemblies.empty()?NULL:*assemblies.begin(); }
		void notifyMovingPrimitives();
		void insertAssembly(Assembly* a);
		void removeAssembly(Assembly* a);
		void absorb(Mechanism* smaller);
		Mechanism::Mechanism() {}
		static Mechanism* getMechanismFromPrimitive(const Primitive* primitive);

		friend class MechanismTracker;
	};

	class MechanismTracker
	{
	private:
		SimJob* mechanism;
		bool containedBy(SimJob*);
		void stopTracking();
	public:
		MechanismTracker()
			: mechanism(NULL)
		{
		}

		~MechanismTracker() 
		{
			this->stopTracking();
		}

		bool tracking();
		void setMechanism(Mechanism* m) { setJob(m); }
		void setJob(SimJob*);
		SimJob* getJob() const { return mechanism; }
		Mechanism* getMechanism();
		static void transferTrackers(SimJob*, SimJob*);
	};
}
