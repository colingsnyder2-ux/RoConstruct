// from server: 100% by auto
// roc 2010-06 00756d50  unit: RBX::PrismPoly  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00756d50
//
// 00756d50  8b442404             mov eax, dword ptr [esp + 4]
// 00756d54  8b08                 mov ecx, dword ptr [eax]
// 00756d56  80792500             cmp byte ptr [ecx + 0x25], 0
// 00756d5a  750e                 jne 0x756d6a
// 00756d5c  8d642400             lea esp, [esp]
// 00756d60  8bc1                 mov eax, ecx
// 00756d62  8b08                 mov ecx, dword ptr [eax]
// 00756d64  80792500             cmp byte ptr [ecx + 0x25], 0
// 00756d68  74f6                 je 0x756d60
// 00756d6a  c3                   ret 
// standard library set<pod24> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
