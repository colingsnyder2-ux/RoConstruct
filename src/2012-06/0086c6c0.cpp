// from server: 100% by auto
// roc 2012-06 0086c6c0  unit: RBX::ContentFilter  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0086c6c0
//
// 0086c6c0  8b442404             mov eax, dword ptr [esp + 4]
// 0086c6c4  8b08                 mov ecx, dword ptr [eax]
// 0086c6c6  80793100             cmp byte ptr [ecx + 0x31], 0
// 0086c6ca  750e                 jne 0x86c6da
// 0086c6cc  8d642400             lea esp, [esp]
// 0086c6d0  8bc1                 mov eax, ecx
// 0086c6d2  8b08                 mov ecx, dword ptr [eax]
// 0086c6d4  80793100             cmp byte ptr [ecx + 0x31], 0
// 0086c6d8  74f6                 je 0x86c6d0
// 0086c6da  c3                   ret 
// standard library set<pod36> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
