// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <queue>
namespace RBX {
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual void o0(); };
class ClassDescriptor;
class DescribedBase { public: virtual ~DescribedBase() {} const ClassDescriptor* descriptor; };
class Debugable { public: virtual void b0(); char pad[8]; };
class Instance : public GuidItemBase, public Object, public DescribedBase, public Debugable {
public:
	Instance(const char* name);
	virtual ~Instance();
	char ipad[0x8c - 0x2c];
};
class NonFactoryProduct2009 : public Instance {
public:
	NonFactoryProduct2009(const char* name) : Instance(name) {}
	virtual const char* getClassName() const;
};
class __declspec(novtable) Described2009 : public NonFactoryProduct2009 {
public:
	Described2009(const char* name);
};
struct WeakInst { void* px; void* pn; ~WeakInst(); };
class TimerService;
extern const char sDebris[];
class DebrisService : public Described2009 {
	std::queue<WeakInst> queue;
	int maxItems;
	TimerService* timer;
public:
	DebrisService();
	virtual ~DebrisService();
};
DebrisService::DebrisService() : Described2009("Debris"), maxItems(300), timer(0)
{
}
}
