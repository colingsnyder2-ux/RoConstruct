// from server: 96% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct Link { Link* next; };
struct Entry { std::string key; int pad; Link link; };
Link* __stdcall find(Link** head, const std::string& key) { Link* p = *head; while (p && !(key == ((Entry*)((char*)p - 0x20))->key)) p = p->next; return p; }
