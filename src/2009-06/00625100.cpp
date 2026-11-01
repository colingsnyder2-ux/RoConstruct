// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Base { ~Base(); char pad[0xa4]; };
struct Member { ~Member(); char pad[0x38]; };
struct X : Base {
	Member m;
	std::string s;
	~X();
};
X::~X() {}
