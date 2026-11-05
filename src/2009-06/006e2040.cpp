// from server: 100% by auto
// roc 2009-06 006e2040  unit: RBX::ChatOutput  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e2040
//
// 006e2040  8b442404             mov eax, dword ptr [esp + 4]
// 006e2044  8b4808               mov ecx, dword ptr [eax + 8]
// 006e2047  80793100             cmp byte ptr [ecx + 0x31], 0
// 006e204b  750e                 jne 0x6e205b
// 006e204d  8d4900               lea ecx, [ecx]
// 006e2050  8bc1                 mov eax, ecx
// 006e2052  8b4808               mov ecx, dword ptr [eax + 8]
// 006e2055  80793100             cmp byte ptr [ecx + 0x31], 0
// 006e2059  74f5                 je 0x6e2050
// 006e205b  c3                   ret 
// standard library set<pod36> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
