// from server: 100% by auto
// roc 2011-06 005bf650  unit: RBX::VRbxRay::?$TypedPropertyDescriptor  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005bf650
//
// 005bf650  8b442404             mov eax, dword ptr [esp + 4]
// 005bf654  8b08                 mov ecx, dword ptr [eax]
// 005bf656  80791500             cmp byte ptr [ecx + 0x15], 0
// 005bf65a  750e                 jne 0x5bf66a
// 005bf65c  8d642400             lea esp, [esp]
// 005bf660  8bc1                 mov eax, ecx
// 005bf662  8b08                 mov ecx, dword ptr [eax]
// 005bf664  80791500             cmp byte ptr [ecx + 0x15], 0
// 005bf668  74f6                 je 0x5bf660
// 005bf66a  c3                   ret 
// standard library set<pod8> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
