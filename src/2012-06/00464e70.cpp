// from server: 100% by auto
// roc 2012-06 00464e70  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00464e70
//
// 00464e70  8b442404             mov eax, dword ptr [esp + 4]
// 00464e74  8b4808               mov ecx, dword ptr [eax + 8]
// 00464e77  80791500             cmp byte ptr [ecx + 0x15], 0
// 00464e7b  750e                 jne 0x464e8b
// 00464e7d  8d4900               lea ecx, [ecx]
// 00464e80  8bc1                 mov eax, ecx
// 00464e82  8b4808               mov ecx, dword ptr [eax + 8]
// 00464e85  80791500             cmp byte ptr [ecx + 0x15], 0
// 00464e89  74f5                 je 0x464e80
// 00464e8b  c3                   ret 
// standard library set<pod8> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
