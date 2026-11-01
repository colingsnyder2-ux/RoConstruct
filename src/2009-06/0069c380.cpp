// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <set>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
namespace RBX {
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual void o0(); };
class ClassDescriptor;
class DescribedBase { public: virtual ~DescribedBase() {} const ClassDescriptor* descriptor; };
class Debugable { public: virtual void b0(); char pad[8]; };
class Instance : public GuidItemBase, public Object, public DescribedBase, public Debugable {
public:
	virtual ~Instance();
	void setName(const std::string& name);
	char ipad[0x8c - 0x2c];
};
class DescribedFSS : public Instance {
public:
	DescribedFSS();
};
class Mid : public DescribedFSS {
public:
	Mid() {}
	virtual ~Mid() {}
};
extern long counter2009;
class Listener2009 {
public:
	Listener2009() { InterlockedIncrement(&counter2009); a = 0; b = 0; }
	virtual ~Listener2009();
	void* a; void* b;
};
class Notify2009 {
public:
	virtual void f0(); virtual void f1(); virtual void f2();
	virtual void f3(DescribedBase* d, const bool& b);
};
extern Notify2009* notify2009;
class FlagStand;
class FlagSet { public: FlagSet(); ~FlagSet(); char pad[0x1c]; };
class FlagStandService : public Mid, public Listener2009 {
public:
	FlagStandService();
	virtual ~FlagStandService();
	int x98;
	FlagSet flagStands;
};
FlagStandService::FlagStandService()
{
	setName("FlagStandService");
	notify2009->f3(this, false);
}
}
