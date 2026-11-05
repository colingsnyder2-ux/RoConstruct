// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_a3684b884100130e.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <stddef.h>
#include <memory>
#include <windows.h>
#include <string>
#include <vector>
#include <set>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
namespace RBX {
class Name;
class Instance;
struct DebugMember { DebugMember(); ~DebugMember(); int a, b; };
class __declspec(novtable) Debugable {
public:
	virtual void dump();
	bool validating;
	DebugMember member;
	Debugable() : validating(false) {}
};
class Object {
public:
	virtual ~Object() {}
};
template<class T> class Creatable : public Object { };
template<class T> class AbstractFactoryProduct : public Creatable<T> {
protected:
	AbstractFactoryProduct() {}
public:
	virtual const Name& getClassName() const = 0;
};
class DescribedBase0 { public: virtual ~DescribedBase0(); int a, b; };
class DescribedBase1 { public: virtual ~DescribedBase1(); };
class Described : public DescribedBase0, public DescribedBase1 {
public:
	Described();
	virtual ~Described();
};
template<int N> class Notifier {
public:
	Notifier();
	virtual ~Notifier();
	char pad[0x1c];
};
template<class T> class Association {
	std::vector<boost::shared_ptr<T> > v;
};
extern long instanceCount;
class Instance : public boost::enable_shared_from_this<Instance>,
                 public Debugable,
                 public AbstractFactoryProduct<Instance>,
                 public Described,
                 public Notifier<0>,
                 public Notifier<1>,
                 public Notifier<2>,
                 public Notifier<3>,
                 public Notifier<4>,
                 public Notifier<5>
{
private:
	Association<Instance> assoc;
	Instance* parent;
	boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > children;
	std::string name;
	bool archivable;
protected:
	Instance();
public:
	virtual ~Instance();
public:
	virtual const Name& getClassName() const;
};

template<class Class, class Base> class DescribedCreatable : public Base {
protected:
	DescribedCreatable();
	virtual ~DescribedCreatable();
};
class RunService;
class RunTransition;
class Heartbeat;
template<class Class, class Event> class Listener {
public:
	virtual void onEvent(const Class* source, const Event& event) {}
};
class Script;
struct lua_State;
namespace Stats { class Item; }
namespace Lua {
class ThreadRef { public: ~ThreadRef(); char pad[0x20]; };
class YieldEvent { public: ~YieldEvent(); };
class YieldingThreads { public: int a; YieldEvent event; };
}
class LuaAllocator { public: ~LuaAllocator(); };
class Member1D0 { public: ~Member1D0(); int a, b; };
class Member1D8Inner { public: ~Member1D8Inner(); char pad[0x18]; };
class ScriptContext : public DescribedCreatable<ScriptContext, Instance>,
                      public Listener<RunService, RunTransition>,
                      public Listener<RunService, Heartbeat>
{
private:
	lua_State* globalState;
	Lua::ThreadRef commandLineSandbox;
	std::set<Script*> scripts;
	__int64 nextPendingScripts;
	std::vector<boost::shared_ptr<Script> > pendingScripts;
	boost::shared_ptr<RunService> runService;
	std::auto_ptr<Lua::YieldingThreads> yieldEvent;
	bool scriptsDisabled;
	boost::shared_ptr<Stats::Item> statsItem;
	char pad1b8[0x14];
public:
	std::auto_ptr<LuaAllocator> allocator;
	Member1D0 m1d0;
	Member1D8Inner m1d8;
	char* buffer;
	virtual ~ScriptContext();
};
ScriptContext::~ScriptContext()
{
	delete buffer;
}
}
