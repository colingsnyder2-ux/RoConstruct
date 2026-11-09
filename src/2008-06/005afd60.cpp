// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_scriptserviceoutlinedctor72a8bf579f922a38.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
namespace RBX {
template<class T> class OutOfLineFunction:public boost::function0<T>{
public: template<class F> __declspec(noinline) OutOfLineFunction(F f,int tag=0):boost::function0<T>(f,tag){}
};
template<class Class>
boost::shared_ptr<Class> shared_from(Class* r);
template<class Class, class Event> class Listener {
public:
	virtual ~Listener();
};
template<class Class, class Event> class Notifier {
public:
	char pad[0x40];
	void addListener(Listener<Class, Event>* listener) const;
	void removeListener(Listener<Class, Event>* listener) const;
	template<typename T>
	static void connect(const T& notifier, Listener<Class, Event>* listener)
	{
		if (notifier)
			notifier->Notifier<Class, Event>::addListener(listener);
	}
	template<typename T>
	static void disconnect(const T& notifier, Listener<Class, Event>* listener)
	{
		if (notifier)
			notifier->Notifier<Class, Event>::removeListener(listener);
	}
};
class Instance {
public:
	virtual ~Instance();
	void setParent(Instance* newParent);
};
class RunTransition;
class Heartbeat;
struct RunServicePad { char pad[0x130]; };
class RunService : public RunServicePad, public Notifier<RunService, Heartbeat>, public Notifier<RunService, RunTransition> {
};
namespace Stats {
class StatsService : public Instance { };
class Item : public Instance {
public:
	template<typename T> Item* createBoundChildItem(const char* name, const T& v);
	template<typename T> Item* createChildItem(const char* name, OutOfLineFunction<T> func);
};
}
template<class Base> class Creatable {
public:
	template<class T> static boost::shared_ptr<T> create(const char* name);
};
class ServiceProvider : public Instance {
public:
	template<class T> T* create() const;
};
struct ScriptContextPad { virtual ~ScriptContextPad(); char pad[0x12c]; };
class ScriptContext : public ScriptContextPad,
                      public Listener<RunService, RunTransition>,
                      public Listener<RunService, Heartbeat>
{
	char pad2[0x1a0 - 0x138];
	boost::shared_ptr<RunService> runService;
	int unk1a8;
	bool scriptsDisabled;
	boost::shared_ptr<Stats::Item> statsItem;
public:
	size_t getThreadCount() const;
	void closeState();
protected:
	virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
};
void ScriptContext::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	Notifier<RunService, RunTransition>::disconnect(runService, this);
	Notifier<RunService, Heartbeat>::disconnect(runService, this);

	if (oldProvider && !newProvider)
		closeState();

	if (statsItem)
	{
		statsItem->setParent(NULL);
		statsItem.reset();
	}

	RunService* newRunService;

	if (newProvider)
	{
		Stats::StatsService* statsService = newProvider->create<Stats::StatsService>();
		if (statsService)
		{
			statsItem = Creatable<Instance>::create<Stats::Item>("Lua");
			statsItem->setParent(statsService);
			statsItem->createBoundChildItem("disabled", scriptsDisabled);
			statsItem->createChildItem<int>("threads", boost::bind(&ScriptContext::getThreadCount, this));
		}

		newRunService = newProvider->create<RunService>();
	}
	else
	{
		newRunService = NULL;
	}

	runService = shared_from(newRunService);
	Notifier<RunService, RunTransition>::connect(runService, this);
	Notifier<RunService, Heartbeat>::connect(runService, this);
}
}
