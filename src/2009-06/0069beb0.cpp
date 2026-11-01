// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <list>
namespace RBX {
class A0 { public: virtual void a0(); char pad[0x10]; };
class A1 { public: virtual void a1(); };
class A2 { public: virtual ~A2(); void* d; };
class A3 { public: virtual void a3(); char pad[8]; };
class Instance : public A0, public A1, public A2, public A3 {
public:
	virtual ~Instance();
	char ipad[0x8c - 0x2c];
};
class FactoryProduct : public Instance {
public:
	virtual ~FactoryProduct() {}
};
class __declspec(novtable) Described : public FactoryProduct {};
class __declspec(novtable) DescribedCreatable : public Described {};
class Listener {
public:
	virtual ~Listener();
	char lpad[0xc];
};
class FlagStand;
class FlagStandService : public DescribedCreatable, public Listener {
	std::list<FlagStand*> flagStands;
public:
	~FlagStandService();
};
FlagStandService::~FlagStandService()
{
}
}
