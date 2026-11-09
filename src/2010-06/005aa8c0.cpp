// from server: 100% by auto
// roc 2010-06 005aa8c0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005aa8c0
//
// 005aa8c0  8b442404             mov eax, dword ptr [esp + 4]
// 005aa8c4  8b4808               mov ecx, dword ptr [eax + 8]
// 005aa8c7  80791500             cmp byte ptr [ecx + 0x15], 0
// 005aa8cb  750e                 jne 0x5aa8db
// 005aa8cd  8d4900               lea ecx, [ecx]
// 005aa8d0  8bc1                 mov eax, ecx
// 005aa8d2  8b4808               mov ecx, dword ptr [eax + 8]
// 005aa8d5  80791500             cmp byte ptr [ecx + 0x15], 0
// 005aa8d9  74f5                 je 0x5aa8d0
// 005aa8db  c3                   ret 
// standard library set<pod8> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
