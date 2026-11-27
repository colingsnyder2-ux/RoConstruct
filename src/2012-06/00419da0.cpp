// from server: 88% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <map>
struct Pad { char pad[8]; };
struct Elems { void* first; char pad2[0x28 - 0xc]; void destroyAll(); ~Elems() { destroyAll(); ::operator delete(first); } };
struct CopyVerb : Pad, Elems { std::map<int,int> m; ~CopyVerb(); };
CopyVerb::~CopyVerb() {}
