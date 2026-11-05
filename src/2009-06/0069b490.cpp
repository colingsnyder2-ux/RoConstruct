// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
namespace RBX {
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual void o0(); };
class DescribedBase { public: virtual void d0(); int descriptor; };
class Debugable { public: virtual void b0(); char pad[8]; };
class Instance : public GuidItemBase, public Object, public DescribedBase, public Debugable {
public:
	Instance();
	virtual ~Instance();
	void setName(const std::string& name);
	char ipad[0x8c - 0x2c];
};
class GuiTarget { public: virtual void t0(); char pad[0x6c]; };
class IEquipable { public: virtual void e0(); char pad[0xc]; };
class IRenderable { public: virtual void r0(); char pad[0xc]; };
class IHasLocation { public: virtual void h0(); char pad[0x198 - 0x120]; };
class Tool : public Instance, public GuiTarget, public IEquipable, public IRenderable, public IHasLocation {
public:
	Tool();
	virtual ~Tool();
};
extern const char* const sFlag;
template<class Class, class Base, const char* const* name> class DescribedCreatable : public Base {
public:
	DescribedCreatable();
	virtual ~DescribedCreatable();
};
extern long counter2009;
class Conn2009 {
public:
	Conn2009() { InterlockedIncrement(&counter2009); a = 0; b = 0; }
	~Conn2009();
	void* a; void* b;
};
class BrickColor {
public:
	int number;
	BrickColor() : number(194) {}
};
class Flag : public DescribedCreatable<Flag, Tool, &sFlag> {
	Conn2009 flagTouched;
public:
	BrickColor teamColor;
	Flag();
	virtual ~Flag();
};
Flag::Flag()
{
	setName("Flag");
}
}
