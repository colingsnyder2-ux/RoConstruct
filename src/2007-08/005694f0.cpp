// from server: 100% by auto
// roc 2007-08 005694f0  unit: RBX::ModelInstance  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005694f0
//
// 005694f0  8b442404             mov eax, dword ptr [esp + 4]
// 005694f4  8b4808               mov ecx, dword ptr [eax + 8]
// 005694f7  80793100             cmp byte ptr [ecx + 0x31], 0
// 005694fb  750e                 jne 0x56950b
// 005694fd  8d4900               lea ecx, [ecx]
// 00569500  8bc1                 mov eax, ecx
// 00569502  8b4808               mov ecx, dword ptr [eax + 8]
// 00569505  80793100             cmp byte ptr [ecx + 0x31], 0
// 00569509  74f5                 je 0x569500
// 0056950b  c3                   ret 
// standard library set<pod36> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
