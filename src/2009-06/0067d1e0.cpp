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
	Instance(const char* name);
	virtual ~Instance();
	char ipad[0x8c - 0x2c];
};
class IExtra { public: virtual void e0(); };
class Base : public Instance, public IExtra {
public:
	Base(const char* name);
};
class Derived : public Base {
public:
	Derived(const char* name);
	virtual void e0();
	virtual void b0();
};
Derived::Derived(const char* name) : Base(name) {}
}
