// from server: 100% by auto
// roc 2011-06 007c83a0  unit: RBX::AdornBillboarder  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007c83a0
//
// 007c83a0  8b442404             mov eax, dword ptr [esp + 4]
// 007c83a4  8b4808               mov ecx, dword ptr [eax + 8]
// 007c83a7  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 007c83ab  750e                 jne 0x7c83bb
// 007c83ad  8d4900               lea ecx, [ecx]
// 007c83b0  8bc1                 mov eax, ecx
// 007c83b2  8b4808               mov ecx, dword ptr [eax + 8]
// 007c83b5  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 007c83b9  74f5                 je 0x7c83b0
// 007c83bb  c3                   ret 
// standard library set<pod48> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
