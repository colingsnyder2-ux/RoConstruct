// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_f661445ef9319a1e.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <stddef.h>
#include <windows.h>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
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
	virtual ~Instance();
public:
	virtual const Name& getClassName() const;
	Instance* getParent() const { return parent; }
};
template<typename Class>
boost::shared_ptr<Class> shared_from(Class* r)
{
	return r ? boost::shared_static_cast<Class>(r->shared_from_this()) : boost::shared_ptr<Class>();
}
boost::function0<void> background_function(const boost::function0<void>& threadfunc, const char* name, int priority = -1);
class DataModel : public Instance { };
class RunService : public Instance {
	char pad130[0x14c];
	boost::scoped_ptr<boost::thread> runThread;
public:
	void start();
	void runProc(boost::shared_ptr<DataModel> dataModel);
	friend struct Check;
};
struct Check { typedef char c[(offsetof(RunService, runThread) == 0x27c) ? 1 : -1]; };
void RunService::start()
{
	boost::shared_ptr<DataModel> dataModel = shared_from(dynamic_cast<DataModel*>(getParent()));
	runThread.reset(new boost::thread(background_function(boost::bind(&RunService::runProc, shared_from(this), dataModel), "rbx_runProc")));
}
}
