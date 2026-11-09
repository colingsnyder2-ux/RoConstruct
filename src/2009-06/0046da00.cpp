// from server: 100% by auto
// roc 2009-06 0046da00  unit: PartDataSource  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046da00
//
// 0046da00  8b442404             mov eax, dword ptr [esp + 4]
// 0046da04  8b4808               mov ecx, dword ptr [eax + 8]
// 0046da07  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0046da0b  750e                 jne 0x46da1b
// 0046da0d  8d4900               lea ecx, [ecx]
// 0046da10  8bc1                 mov eax, ecx
// 0046da12  8b4808               mov ecx, dword ptr [eax + 8]
// 0046da15  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0046da19  74f5                 je 0x46da10
// 0046da1b  c3                   ret 
// standard library set<pod32> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
