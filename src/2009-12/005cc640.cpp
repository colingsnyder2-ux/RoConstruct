// from server: 100% by auto
// roc 2009-12 005cc640  unit: RBX::MeshRefPartAdapter  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cc640
//
// 005cc640  8b442404             mov eax, dword ptr [esp + 4]
// 005cc644  8b08                 mov ecx, dword ptr [eax]
// 005cc646  80792100             cmp byte ptr [ecx + 0x21], 0
// 005cc64a  750e                 jne 0x5cc65a
// 005cc64c  8d642400             lea esp, [esp]
// 005cc650  8bc1                 mov eax, ecx
// 005cc652  8b08                 mov ecx, dword ptr [eax]
// 005cc654  80792100             cmp byte ptr [ecx + 0x21], 0
// 005cc658  74f6                 je 0x5cc650
// 005cc65a  c3                   ret 
// standard library set<pod20> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
