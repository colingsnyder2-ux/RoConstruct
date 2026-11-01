// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct A;
struct Str { std::string s; };
class B {
public:
	B(A* a, Str s);
	char pad[0x1c];
};
class D : public B {
public:
	D(A* a, Str s, bool f);
	bool flag;
};
D::D(A* a, Str s, bool f) : B(a, s), flag(f) {}
