// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct Base { Base(const Base&); virtual ~Base(); char pad[0x54]; };
struct Derived : Base { std::string s; virtual ~Derived(); };
Derived* make(void* p, const Derived& o) { return new (p) Derived(o); }
