// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_e4de95bcbafa2a17.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <stddef.h>
#include <windows.h>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/scoped_ptr.hpp>
#include "G3D/Array.h"
#include <stddef.h>
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
	void setName(const std::string& value);
};
class Service {};
template<class Class, class Event> class __declspec(novtable) Listener {
protected:
	virtual void onEvent(const Class*, Event) = 0;
	virtual ~Listener() {}
};
template<class Base, int N> class NonFactoryProduct : public Base {
protected:
	NonFactoryProduct();
};
class World;
class AutoJoin {};
class AutoDestroy {};
class IRenderable;
template<class T> class IndexArray {
	G3D::Array<T*> array;
};
class IRenderableBucket {
	IndexArray<IRenderable> renderable2ds;
	IndexArray<IRenderable> renderable3ds;
public:
	~IRenderableBucket();
};
class JointsService : public NonFactoryProduct<Instance, 0>,
                      public Service,
                      public IRenderableBucket,
                      public Listener<World, AutoJoin>,
                      public Listener<World, AutoDestroy>
{
public:
	World* world;
	virtual void onEvent(const World* source, AutoDestroy event);
	virtual void onEvent(const World* source, AutoJoin event);
	JointsService();
	friend struct Check;
};
struct Check {
	typedef char c1[(offsetof(JointsService, world) == 0x150) ? 1 : -1];
};
JointsService::JointsService()
	: world(NULL)
{
	setName("JointsService");
}
}
