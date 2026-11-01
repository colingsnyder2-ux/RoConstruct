// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Name { std::string s; int id; };
class Thing { public: virtual ~Thing(); char pad[0x94]; Name name; Name getName() const; };
Name Thing::getName() const { return name; }
