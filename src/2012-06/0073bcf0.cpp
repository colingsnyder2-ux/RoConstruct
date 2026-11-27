// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <map>
struct V { char pad[0x18]; int x; char pad2[4]; };
struct S { char pad[0xac]; std::map<unsigned, V> m; int f(unsigned key); };
int S::f(unsigned key) { std::map<unsigned, V>::iterator it = m.find(key); return it != m.end() ? it->second.x : 0; }
