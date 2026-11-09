// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Desc;
const Desc* getDesc();
struct Ref {
	std::string name;
	const Desc* desc;
	Ref(const std::string& n) : name(n), desc(getDesc()) {}
};
Ref makeRef(const std::string& n) { return Ref(n); }
