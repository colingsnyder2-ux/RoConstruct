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
class Base2009 : public Instance {
public:
	Base2009();
};
class __declspec(novtable) Second2009 { public: virtual void s0(); };
class Mid2009 : public Base2009, public Second2009 {
public:
	Mid2009() {}
	virtual const char* getClassName() const;
};
extern int counter2009;
class __declspec(novtable) Described2009 : public Mid2009 {
public:
	Described2009();
	static ClassDescriptor& classDescriptor();
};
Described2009::Described2009() { this->descriptor = &classDescriptor(); ++counter2009; }
}
