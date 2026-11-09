// from server: 100% by EspClaude
// from server: 61% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_05e12309f655b19f.cpp

// Candidate translation unit (score above; library headers required).
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
	std::vector<CameraEntry> cameras;
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
class World { public: World(); ~World(); char pad[0x114]; };
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

#pragma warning (push)
#pragma warning (disable : 4355)
RootInstance::RootInstance()
	: Base(),
	  ControllersUsed(this, &RootInstance::computeControllersUsed),
	  insertPoint(G3D::Vector3::zero()),
	  viewPort(G3D::Vector2(800.0f, 600.0f)),
	  world(new World())
{
}
#pragma warning (pop)
}
