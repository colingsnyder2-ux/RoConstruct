// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual void o0(); };
class ClassDescriptor;
class DescribedBase { public: virtual ~DescribedBase() {} const ClassDescriptor* descriptor; };
class Debugable { public: virtual void b0(); char pad[8]; };
class Instance : public GuidItemBase, public Object, public DescribedBase, public Debugable {
public:
	virtual ~Instance();
	void setName(const std::string& value);
	char ipad[0x8c - 0x2c];
};
class DescribedCreatable2009 : public Instance {
public:
	DescribedCreatable2009();
};
class PhysicsSettings2009 : public DescribedCreatable2009 {
public:
	PhysicsSettings2009();
	virtual const char* getClassName() const;
};
PhysicsSettings2009::PhysicsSettings2009() { setName("Physics"); }
}
