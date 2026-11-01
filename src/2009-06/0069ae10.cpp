// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual void o0(); };
class DescribedBase { public: virtual void d0(); int descriptor; };
class Debugable { public: virtual void b0(); char pad[8]; };
class Instance : public GuidItemBase, public Object, public DescribedBase, public Debugable {
public:
	Instance();
	virtual ~Instance();
	char ipad[0x8c - 0x2c];
};
class GuiTarget { public: virtual void t0(); char pad[0x6c]; };
class IEquipable { public: virtual void e0(); char pad[0xc]; };
class IRenderable { public: virtual void r0(); char pad[0xc]; };
class IHasLocation { public: virtual void h0(); };
class Tool : public Instance, public GuiTarget, public IEquipable, public IRenderable, public IHasLocation {
public:
	Tool();
	virtual ~Tool();
};
class Flag : public Tool {
public:
	Flag();
	virtual ~Flag();
};
Flag::~Flag() {}
}
