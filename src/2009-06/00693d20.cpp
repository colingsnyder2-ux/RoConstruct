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
class Sec1 { public: virtual void s1(); char pad[0x1c]; };
class Sec2 { public: virtual void s2(); char pad[0x74]; };
class Sec3 { public: virtual void s3(); };
class Base2009 : public Instance, public Sec1, public Sec2, public Sec3 {
public:
	Base2009(const char* name);
};
class Mid2009 : public Base2009 {
public:
	Mid2009(const char* name) : Base2009(name) {}
	virtual const char* getClassName() const;
};
extern int counter2009;
class __declspec(novtable) Described2009 : public Mid2009 {
public:
	Described2009(const char* name);
	static ClassDescriptor& classDescriptor();
};
Described2009::Described2009(const char* name) : Mid2009(name) { this->descriptor = &classDescriptor(); ++counter2009; }
}
