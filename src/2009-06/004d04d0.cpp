// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
struct Str { std::string s; Str(const std::string& x) : s(x) {} };
class Base2009 {
public:
	std::string name;
	Base2009(int a, Str n);
};
class Derived2009 : public Base2009 {
public:
	int value;
	Derived2009(int a, std::string n, int v);
};
Derived2009::Derived2009(int a, std::string n, int v) : Base2009(a, n), value(v) {}
}
