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
	char ipad[0x90 - 0x2c];
};
class Described2009 : public Instance {
public:
	Described2009(const char* name);
};
class Item2009 : public Described2009 {
public:
	Item2009(const char* name);
	virtual const char* getClassName() const;
	double value;
	std::string text;
};
Item2009::Item2009(const char* name) : Described2009(name), value(0) {}
}
