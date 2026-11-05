// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_workspacedtornovtabledc74c025d673033c.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <set>
#include <boost/scoped_ptr.hpp>
#include <G3D/Array.h>
#define _DLL
#include <stddef.h>
#include <windows.h>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <memory>
#include <G3D/Vector3.h>
#include <G3D/Vector2.h>
#include <G3D/Rect2D.h>
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
namespace Reflection { class ClassDescriptor; }
class DescribedBase0 { public: virtual ~DescribedBase0(); int a; Reflection::ClassDescriptor* descriptor; };
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

namespace Reflection {
template<typename Class, const char* const* ClassName, typename DerivedClass>
class __declspec(novtable) Described : public DerivedClass
{
public:
	typedef Described<Class, ClassName, DerivedClass> Base;
	Described()
		: DerivedClass()
	{
		this->descriptor = &classDescriptor();
	}
	static ClassDescriptor& classDescriptor();
};
}
class __declspec(novtable) IPrimaryPart { public: virtual ~IPrimaryPart() {} virtual void ipp0() = 0; };
class __declspec(novtable) IHasCamera { public: virtual void ihc0() = 0; };
class __declspec(novtable) ICameraSubject : public virtual IHasCamera { public: virtual void ics0() = 0; };
class ISelectable3d { };
class __declspec(novtable) PVBase { public: virtual void pv0() = 0; };
class PVInstance : public Instance, public PVBase,
                   public virtual IPrimaryPart, public virtual ICameraSubject, public virtual ISelectable3d
{
	char pvpad[0x1a0 - 0x138];
};
class __declspec(novtable) IRenderable { public: virtual void r0(); int index2d; int index3d; };
class ModelInstance : public PVInstance, public IRenderable
{
	char mpad[0x288 - 0x1ac];
protected:
	ModelInstance();
	virtual ~ModelInstance();
};
class Camera;
class CameraEntry { public: CameraEntry(const CameraEntry&); ~CameraEntry(); int a; };
class __declspec(novtable) ICameraOwner {
public:
	ICameraOwner();
	virtual ~ICameraOwner() {}
	virtual Camera* getCamera() = 0;
	std::vector<boost::weak_ptr<Camera> > cameras;
	int unk;
};
class ControllerTypeArray {
	bool values[8];
public:
	void clear() { for (int i = 0; i < 8; ++i) values[i] = false; }
	ControllerTypeArray() { clear(); }
};
template<typename T, typename U>
class ComputeProp {
	mutable T val;
	mutable bool dirty;
	U* object;
	T(U::* getFunc)() const;
public:
	ComputeProp(U* object, T(U::* getFunc)() const)
		: dirty(true), object(object), getFunc(getFunc) {}
};
class World { public: World(); virtual ~World(); char pad[0x110]; };
extern char* sRootInstance;
class RootInstance : public Reflection::Described<RootInstance, &sRootInstance, ModelInstance>,
                     public ICameraOwner
{
	ComputeProp<ControllerTypeArray, RootInstance> ControllersUsed;
	mutable G3D::Vector3 insertPoint;
protected:
	G3D::Rect2D viewPort;
	std::auto_ptr<World> world;
	ControllerTypeArray computeControllersUsed() const;
	virtual void ipp0();
	virtual void ihc0();
	virtual void ics0();
	RootInstance();
	virtual ~RootInstance();
	friend struct Check;
};


class GuiTarget { public: virtual void process(); };
class Verb;
class VerbContainer { std::map<const Name*,Verb*> verbs; VerbContainer* parent; public: virtual ~VerbContainer(); };
class IMoving;
class IMovingManager { std::set<IMoving*> moving; std::set<IMoving*>::iterator current; public: virtual ~IMovingManager(); };
class IScriptOwner { public: virtual void scriptShouldRun(); virtual void runScript(); virtual void releaseScript(); };
template<int N> class __declspec(novtable) WorkspaceNotifier { std::vector<void*> listeners; void* raiseRange; public: virtual ~WorkspaceNotifier() {} virtual void added(); virtual void removed(); };
class __declspec(novtable) HeartbeatListener { public: virtual void onEvent(); virtual ~HeartbeatListener() {} };
class IRenderableBucket { G3D::Array<IRenderable*> render2d,render3d; public: ~IRenderableBucket(); };
class MouseCommand { public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual ~MouseCommand();
};
class Profiler { public: virtual ~Profiler(); };
class Script;
class Workspace : public RootInstance, public GuiTarget, public VerbContainer,
 public IRenderableBucket, public IMovingManager, public IScriptOwner,
 public WorkspaceNotifier<0>, public WorkspaceNotifier<1>, public HeartbeatListener {
 boost::shared_ptr<Instance> stats;
 void* dataState;
 bool arrowControls;
 std::auto_ptr<MouseCommand> currentCommand,stickyCommand;
 char idleEvent[0x1c]; // observed interval 3b8..3d4
 std::set<Script*> pendingScripts;
 void* scriptContext;
 bool inMouselookMode;
 boost::shared_ptr<Camera> currentCamera;
 boost::shared_ptr<Instance> observedShared404;
 char reserved40c[0x1c]; // observed interval between shared ownership and profilers
 boost::scoped_ptr<Profiler> profile0,profile1,profile2,profile3,profile4;
 int imageServerViewHack;
 public: virtual ~Workspace();
};
Workspace::~Workspace() {}
}
