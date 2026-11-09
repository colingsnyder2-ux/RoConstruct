// from server: 100% by auto
// roc 2009-12 00648100  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00648100
//
// 00648100  8b442404             mov eax, dword ptr [esp + 4]
// 00648104  8b08                 mov ecx, dword ptr [eax]
// 00648106  80791500             cmp byte ptr [ecx + 0x15], 0
// 0064810a  750e                 jne 0x64811a
// 0064810c  8d642400             lea esp, [esp]
// 00648110  8bc1                 mov eax, ecx
// 00648112  8b08                 mov ecx, dword ptr [eax]
// 00648114  80791500             cmp byte ptr [ecx + 0x15], 0
// 00648118  74f6                 je 0x648110
// 0064811a  c3                   ret 
// standard library set<pod8> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
