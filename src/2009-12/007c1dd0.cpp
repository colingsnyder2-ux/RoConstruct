// from server: 100% by auto
// roc 2009-12 007c1dd0  unit: RBX::ImageButton  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c1dd0
//
// 007c1dd0  8b442404             mov eax, dword ptr [esp + 4]
// 007c1dd4  8b4808               mov ecx, dword ptr [eax + 8]
// 007c1dd7  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 007c1ddb  750e                 jne 0x7c1deb
// 007c1ddd  8d4900               lea ecx, [ecx]
// 007c1de0  8bc1                 mov eax, ecx
// 007c1de2  8b4808               mov ecx, dword ptr [eax + 8]
// 007c1de5  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 007c1de9  74f5                 je 0x7c1de0
// 007c1deb  c3                   ret 
// standard library set<pod64> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
