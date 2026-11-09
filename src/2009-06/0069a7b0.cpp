// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
struct A0 { virtual ~A0(); int pad[4]; };
struct A1 { virtual void a1(); };
struct A2 { virtual void a2(); void* descriptor; };
struct A3 { virtual void a3(); char pad[0x68]; };
struct A4 { virtual void a4(); };
class Feature : public A0, public A1, public A2, public A3, public A4 {
public:
	Feature();
	void setName(const std::string& name);
};
class Hole : public Feature {
public:
	Hole();
	virtual ~Hole();
};
Hole::Hole()
{
	setName("Hole");
}
}
