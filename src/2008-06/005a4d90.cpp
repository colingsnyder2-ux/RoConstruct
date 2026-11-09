// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_164c05053810c4f5.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <stddef.h>
#include <windows.h>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <memory>
#include <set>
#include <boost/scoped_ptr.hpp>
#include <G3D/Vector2int16.h>
#include <G3D/Array.h>
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
template<int N> class InstanceNotifier {
public:
	InstanceNotifier();
	virtual ~InstanceNotifier();
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
                 public InstanceNotifier<0>,
                 public InstanceNotifier<1>,
                 public InstanceNotifier<2>,
                 public InstanceNotifier<3>,
                 public InstanceNotifier<4>,
                 public InstanceNotifier<5>
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
	virtual void setName(const std::string& value);
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
namespace Profiling {
class CodeProfiler {
public:
	CodeProfiler(const char* name);
	char data[0xc040];
	CodeProfiler* parent;
	int pad;
};
}
class World {
public:
	World();
	virtual ~World();
	char pad[0xf8];
	Profiling::CodeProfiler* profileWorldStep;
	Profiling::CodeProfiler& getProfileWorldStep() { return *profileWorldStep; }
};
extern char* sRootInstance;
class RootInstance : public Reflection::Described<RootInstance, &sRootInstance, ModelInstance>,
                     public ICameraOwner
{
	ComputeProp<ControllerTypeArray, RootInstance> ControllersUsed;
	mutable G3D::Vector3 insertPoint;
public:
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

template<class Class, class Base> class DescribedNonCreatable : public Base {
protected:
	DescribedNonCreatable();
};
class VerbContainer {
public:
	VerbContainer(VerbContainer* parent);
	virtual ~VerbContainer();
	char pad[0x24];
};
class GuiTarget {
public:
	virtual void processInput();
};
class IRenderable;
template<class T> class IndexArray {
	G3D::Array<T*> array;
};
class IRenderableBucket {
	IndexArray<IRenderable> renderable2ds;
	IndexArray<IRenderable> renderable3ds;
};
class IMovingManager {
public:
	IMovingManager();
	virtual ~IMovingManager();
	char pad[0x28];
};
class Script;
class ScriptContext;
class __declspec(novtable) IScriptOwner {
public:
	virtual IScriptOwner* scriptShouldRun(Script*) = 0;
};
class DrawChanged {};
class ToolChanged {};
class RunService;
class Heartbeat {};
template<class Class, class Event> class Notifier {
public:
	Notifier();
	virtual ~Notifier();
	char pad[0x1c];
};
template<class Class, class Event> class __declspec(novtable) Listener {
public:
	virtual void onEvent(const Class* source, Event event) = 0;
};
class UserInputBase;
class UIEvent {
public:
	int eventType;
	UserInputBase* userInput;
	G3D::Vector2int16 mousePosition;
	G3D::Vector2int16 mouseDelta;
	G3D::Vector2int16 windowSize;
	UIEvent()
		: userInput(NULL),
		  eventType(0)
	{
	}
};
class IDataState;
class MouseCommand { public: virtual ~MouseCommand(); };
class Camera;
class Hopper;
boost::shared_ptr<Hopper> createHopper();
class Workspace : public DescribedNonCreatable<Workspace, RootInstance>,
                  public GuiTarget,
                  public VerbContainer,
                  public IRenderableBucket,
                  public IMovingManager,
                  public IScriptOwner,
                  public Notifier<Workspace, DrawChanged>,
                  public Notifier<Workspace, ToolChanged>,
                  public Listener<RunService, Heartbeat>
{
private:
	boost::shared_ptr<Instance> statsItem;
	IDataState* dataState;
	bool arrowCameraControls;
	std::auto_ptr<MouseCommand> currentCommand;
	std::auto_ptr<MouseCommand> stickyCommand;
	UIEvent idleMouseEvent;
	MouseCommand* hoverCommand;
	bool isSimulating;
	std::set<Script*> pendingScripts;
	ScriptContext* scriptContext;
	bool inMouselookMode;
	mutable boost::shared_ptr<Camera> currentCamera;
	boost::shared_ptr<Hopper> hopper;
	double time0;
	double time1;
	double time2;
public:
	boost::scoped_ptr<Profiling::CodeProfiler> profileDataModelStep;
	boost::scoped_ptr<Profiling::CodeProfiler> profileWorkspaceStep;
	boost::scoped_ptr<Profiling::CodeProfiler> profileWorkspaceAssemble;
	boost::scoped_ptr<Profiling::CodeProfiler> profileRunServiceStepped;
	boost::scoped_ptr<Profiling::CodeProfiler> profileRunServiceHeartbeat;
	int imageServerViewHack;
private:
	virtual IScriptOwner* scriptShouldRun(Script*);
	virtual void onEvent(const RunService* source, Heartbeat event);
public:
	Workspace(IDataState* dataState);
	virtual ~Workspace();
	friend struct Check2;
};
Workspace::Workspace(IDataState* dataState)
	: VerbContainer(NULL),
	  dataState(dataState),
	  arrowCameraControls(false),
	  hoverCommand(NULL),
	  isSimulating(false),
	  scriptContext(NULL),
	  inMouselookMode(false),
	  hopper(createHopper()),
	  time0(0.0),
	  time1(0.0),
	  time2(0.0),
	  profileDataModelStep(new Profiling::CodeProfiler("DataModel Step")),
	  profileWorkspaceStep(new Profiling::CodeProfiler("Workspace Step")),
	  profileWorkspaceAssemble(new Profiling::CodeProfiler("Workspace Assemble")),
	  profileRunServiceStepped(new Profiling::CodeProfiler("RunService Stepped")),
	  profileRunServiceHeartbeat(new Profiling::CodeProfiler("RunService Heartbeat")),
	  imageServerViewHack(0)
{
	setName("Workspace");

	profileWorkspaceStep->parent = profileDataModelStep.get();
	world->getProfileWorldStep().parent = profileWorkspaceStep.get();
	profileWorkspaceAssemble->parent = profileDataModelStep.get();
	profileRunServiceStepped->parent = profileDataModelStep.get();
	profileRunServiceHeartbeat->parent = profileDataModelStep.get();
}
}
