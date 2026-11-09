// from server: 100% by auto
// roc 2007-08 004d95d0  unit: RBX::View::MegaTextureProxy  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d95d0
//
// 004d95d0  8b442404             mov eax, dword ptr [esp + 4]
// 004d95d4  8b4808               mov ecx, dword ptr [eax + 8]
// 004d95d7  80793500             cmp byte ptr [ecx + 0x35], 0
// 004d95db  750e                 jne 0x4d95eb
// 004d95dd  8d4900               lea ecx, [ecx]
// 004d95e0  8bc1                 mov eax, ecx
// 004d95e2  8b4808               mov ecx, dword ptr [eax + 8]
// 004d95e5  80793500             cmp byte ptr [ecx + 0x35], 0
// 004d95e9  74f5                 je 0x4d95e0
// 004d95eb  c3                   ret 
// standard library set<pod40> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
