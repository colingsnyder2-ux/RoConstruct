// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Name { std::string s; };
inline bool operator<(const Name& a, const Name& b) { return &a != &b && a.s < b.s; }
struct Item { int a; const Name* name; };
bool lessName(const Item& x, const Item& y)
{
	return *x.name < *y.name;
}
