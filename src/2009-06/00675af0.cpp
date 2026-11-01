// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
	char ipad[0x8c - 0x2c];
};
class DescribedTS : public Instance {
public:
	DescribedTS();
};
class Mid : public DescribedTS {
public:
	Mid() {}
	virtual const char* getClassName() const;
};
extern long counter;
class Second {
public:
	Second() { InterlockedIncrement(&counter); a = 0; b = 0; }
	virtual ~Second();
	void* a; void* b;
};
class Item { public: Item(); void* a; int b; int c; };
class TimerService : public Mid, public Second {
public:
	TimerService();
	virtual void t0();
	int r;
	Item items;
};
TimerService::TimerService() {}
}
