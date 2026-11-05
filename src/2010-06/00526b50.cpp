// from server: 100% by auto
// roc 2010-06 00526b50  unit: RBX::ViewG3D  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00526b50
//
// 00526b50  8b442404             mov eax, dword ptr [esp + 4]
// 00526b54  8b08                 mov ecx, dword ptr [eax]
// 00526b56  80792100             cmp byte ptr [ecx + 0x21], 0
// 00526b5a  750e                 jne 0x526b6a
// 00526b5c  8d642400             lea esp, [esp]
// 00526b60  8bc1                 mov eax, ecx
// 00526b62  8b08                 mov ecx, dword ptr [eax]
// 00526b64  80792100             cmp byte ptr [ecx + 0x21], 0
// 00526b68  74f6                 je 0x526b60
// 00526b6a  c3                   ret 
// standard library set<pod20> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
