// from server: 100% by auto
// roc 2009-06 00445910  unit: CRobloxApp  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00445910
//
// 00445910  8b442404             mov eax, dword ptr [esp + 4]
// 00445914  8b4808               mov ecx, dword ptr [eax + 8]
// 00445917  80792500             cmp byte ptr [ecx + 0x25], 0
// 0044591b  750e                 jne 0x44592b
// 0044591d  8d4900               lea ecx, [ecx]
// 00445920  8bc1                 mov eax, ecx
// 00445922  8b4808               mov ecx, dword ptr [eax + 8]
// 00445925  80792500             cmp byte ptr [ecx + 0x25], 0
// 00445929  74f5                 je 0x445920
// 0044592b  c3                   ret 
// standard library set<pod24> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
