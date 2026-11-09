// from server: 100% by auto
// roc 2009-12 007c1df0  unit: RBX::ImageButton  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c1df0
//
// 007c1df0  8b442404             mov eax, dword ptr [esp + 4]
// 007c1df4  8b08                 mov ecx, dword ptr [eax]
// 007c1df6  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 007c1dfa  750e                 jne 0x7c1e0a
// 007c1dfc  8d642400             lea esp, [esp]
// 007c1e00  8bc1                 mov eax, ecx
// 007c1e02  8b08                 mov ecx, dword ptr [eax]
// 007c1e04  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 007c1e08  74f6                 je 0x7c1e00
// 007c1e0a  c3                   ret 
// standard library set<pod64> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
