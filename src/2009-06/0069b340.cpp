// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
class GuiTarget { public: virtual void t0(); char pad[0xfc - 0x90]; };
class IEquipable { public: virtual void e0(); char pad[0xc]; };
class IRenderable { public: virtual void r0(); char pad[0xc]; };
class IHasLocation { public: virtual void h0(); };
class ISelectable3D { public: int x; };
class Tool : public Instance, public GuiTarget, public IEquipable, public IRenderable, public IHasLocation, public ISelectable3D {
public:
	Tool();
};
extern int counter2009;
class __declspec(novtable) DescribedFlag : public Tool {
public:
	DescribedFlag() { this->descriptor = &classDescriptor(); ++counter2009; }
	static ClassDescriptor& classDescriptor();
};
class DescribedCreatableFlag : public DescribedFlag {
public:
	DescribedCreatableFlag();
	virtual void h0();
};
DescribedCreatableFlag::DescribedCreatableFlag() {}
}
