// from server: 100% by auto
// roc 2009-12 007af660  unit: RBX::Block  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007af660
//
// 007af660  8b442404             mov eax, dword ptr [esp + 4]
// 007af664  8b4808               mov ecx, dword ptr [eax + 8]
// 007af667  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 007af66b  750e                 jne 0x7af67b
// 007af66d  8d4900               lea ecx, [ecx]
// 007af670  8bc1                 mov eax, ecx
// 007af672  8b4808               mov ecx, dword ptr [eax + 8]
// 007af675  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 007af679  74f5                 je 0x7af670
// 007af67b  c3                   ret 
// standard library set<pod16> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
