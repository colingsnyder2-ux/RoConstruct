// from server: 100% by auto
// roc 2011-06 005bf630  unit: RBX::VRbxRay::?$TypedPropertyDescriptor  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005bf630
//
// 005bf630  8b442404             mov eax, dword ptr [esp + 4]
// 005bf634  8b4808               mov ecx, dword ptr [eax + 8]
// 005bf637  80791500             cmp byte ptr [ecx + 0x15], 0
// 005bf63b  750e                 jne 0x5bf64b
// 005bf63d  8d4900               lea ecx, [ecx]
// 005bf640  8bc1                 mov eax, ecx
// 005bf642  8b4808               mov ecx, dword ptr [eax + 8]
// 005bf645  80791500             cmp byte ptr [ecx + 0x15], 0
// 005bf649  74f5                 je 0x5bf640
// 005bf64b  c3                   ret 
// standard library set<pod8> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
