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
	void setName(const std::string& name);
	char ipad[0x8c - 0x2c];
};
class Second2009 { public: virtual void s0(); };
class Joint;
class JointInstance : public Instance, public Second2009 {
public:
	JointInstance(Joint* joint);
};
class Weld : public JointInstance {
public:
	Weld(Joint* joint);
	virtual ~Weld();
};
Weld::Weld(Joint* joint) : JointInstance(joint)
{
	setName("Weld");
}
}
