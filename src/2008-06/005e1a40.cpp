// from server: 100% by EspClaude
// from server: 61% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_espclaude_1ba6bfc4448832b7.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <stddef.h>
#include <windows.h>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <G3D/Color3.h>
#include <G3D/Color4.h>
#include <G3D/Vector3.h>
#include <GLG3D/LightingParameters.h>
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
	virtual void setName(const std::string& value);
};

class Sky;
template<class Class, class Base> class DescribedCreatable : public Base {
protected:
	DescribedCreatable();
};
class Lighting : public DescribedCreatable<Lighting, Instance> {
private:
	G3D::LightingParameters skyParameters;
	G3D::Color3 ambientTop;
	G3D::Color3 ambientBottom;
	bool hasSky;
	G3D::Color4 clearColor;
	G3D::Color4 shadowColor;
	boost::posix_time::time_duration timeOfDay;
	G3D::Vector3 v0;
	G3D::Vector3 v1;
	float f0;
	G3D::Color3 c0;
	G3D::Color3 c1;
	G3D::Color3 c2;
	G3D::Color3 c3;
	G3D::Vector3 v2;
	G3D::Vector3 v3;
public:
	boost::shared_ptr<Sky> sky;
	Lighting();
	friend struct Check;
};
struct Check {
	typedef char chk1[(offsetof(Lighting, skyParameters) == 0x130) ? 1 : -1];
	typedef char chk2[(offsetof(Lighting, timeOfDay) == 0x268) ? 1 : -1];
	typedef char chk3[(offsetof(Lighting, sky) == 0x2d4) ? 1 : -1];
};
Lighting::Lighting()
	: ambientTop(209/255.0f, 208/255.0f, 217/255.0f),
	  ambientBottom(122/255.0f, 134/255.0f, 120/255.0f),
	  hasSky(true),
	  clearColor(G3D::Color3::white()),
	  shadowColor(0.7f, 0.7f, 0.72f),
	  timeOfDay(boost::posix_time::duration_from_string("14:00:00")),
	  v0(0.0f, 0.0f, 0.0f),
	  v1(0.0f, 0.0f, 0.0f),
	  f0(1.0f),
	  c0(0.5f, 0.5f, 0.5f),
	  c1(1.0f, 1.0f, 1.0f),
	  c2(1.0f, 1.0f, 1.0f),
	  c3(1.0f, 1.0f, 1.0f),
	  v2(0.0f, 0.0f, 0.0f),
	  v3(1.0f, 1.0f, 1.0f)
{
	skyParameters.lightColor = G3D::Color3(152/255.0f, 137/255.0f, 102/255.0f);
	skyParameters.setTime(timeOfDay.total_seconds());
	setName("Lighting");
}
}
