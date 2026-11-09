// from server: 100% by auto
// roc 2011-06 004f0230  unit: RBX::RbxRay  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004f0230
//
// 004f0230  8b442404             mov eax, dword ptr [esp + 4]
// 004f0234  8b08                 mov ecx, dword ptr [eax]
// 004f0236  80792500             cmp byte ptr [ecx + 0x25], 0
// 004f023a  750e                 jne 0x4f024a
// 004f023c  8d642400             lea esp, [esp]
// 004f0240  8bc1                 mov eax, ecx
// 004f0242  8b08                 mov ecx, dword ptr [eax]
// 004f0244  80792500             cmp byte ptr [ecx + 0x25], 0
// 004f0248  74f6                 je 0x4f0240
// 004f024a  c3                   ret 
// standard library set<pod24> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
