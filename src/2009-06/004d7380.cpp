// from server: 100% by EspClaude
// roc 2009-06 004d7380
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
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
template<class C, class B>
class FactoryProduct : public B {
public:
	virtual ~FactoryProduct() {}
};
class Member10 { public: ~Member10(); char pad[0x10]; };
class __declspec(novtable) Message : public FactoryProduct<Message, Instance> {
public:
	virtual ~Message();
	Member10 m;
	std::string text;
};
Message::~Message() {}
}
