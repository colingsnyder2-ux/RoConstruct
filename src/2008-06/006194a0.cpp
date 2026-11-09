// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_8a55bc2c599b69d7.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
namespace RBX
{
	class Instance;
	class ServiceProvider;
	class Flag;
	class ToolVB { public: int vbData; };
	template<class Class> boost::shared_ptr<Class> shared_from(Class* r);
	class Instance : public boost::enable_shared_from_this<Instance>
	{
	public:
		virtual ~Instance();
		char instancePad[0x260 - 8];
	};
	class TimerService { public: void delay(boost::function0<void> func, double seconds); };
	enum RunState { RS_STOPPED, RS_RUNNING };
	class RunService { char pad[0x1b4]; RunState runState; public: RunState getRunState() const { return runState; } };
	class PartInstance;
	class FlagStand { public: void AffixFlag(Flag* flag); };
	class FlagStandService
	{
	public:
		FlagStand* FindStandWithFlag(Flag* flag);
		FlagStand* FindClosestEmptyStandForFlag(Flag* flag);
	};
	class ServiceProvider
	{
	public:
		template<typename Class> Class* create() const;
		template<typename Class>
		static Class* create(const ServiceProvider* serviceProvider)
		{
			if (serviceProvider)
				return serviceProvider->create<Class>();
			return NULL;
		}
		template<typename Class> static Class* create(const Instance* context);
	};
	class Tool : public Instance, public virtual ToolVB
	{
	public:
		PartInstance* getHandle();
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
	};
	class ScopedConnection { public: void disconnect(); char pad[0x14]; };
	class Flag : public Tool
	{
	public:
		boost::shared_ptr<Instance> evilClone;
		int state;
		ScopedConnection flagTouched;
		TimerService* timer;
		void doUglyPeriodicCloneHack();
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
	};

	void Flag::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (!oldProvider)
		{
			timer = ServiceProvider::create<TimerService>(newProvider);
			timer->delay(boost::bind(&Flag::doUglyPeriodicCloneHack, shared_from(this)), 2.0f);
		}

		if (!newProvider)
		{
			flagTouched.disconnect();
			RunService* runService = ServiceProvider::create<RunService>(oldProvider);

			if (runService->getRunState() == RS_RUNNING)
			{
				if (Instance* evilC = evilClone.get())
				{
					Flag* flag = dynamic_cast<Flag*>(evilC);
					PartInstance* handle = flag->getHandle();

					FlagStandService* fss = ServiceProvider::create<FlagStandService>(this);
					if (!fss->FindStandWithFlag(flag))
					{
						if (FlagStand* fs = fss->FindClosestEmptyStandForFlag(flag))
						{
							fs->AffixFlag(flag);
						}
					}
				}
			}
		}
	}
}
