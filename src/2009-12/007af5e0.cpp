// from server: 100% by auto
// roc 2009-12 007af5e0  unit: RBX::Block  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007af5e0
//
// 007af5e0  8b442404             mov eax, dword ptr [esp + 4]
// 007af5e4  8b08                 mov ecx, dword ptr [eax]
// 007af5e6  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 007af5ea  750e                 jne 0x7af5fa
// 007af5ec  8d642400             lea esp, [esp]
// 007af5f0  8bc1                 mov eax, ecx
// 007af5f2  8b08                 mov ecx, dword ptr [eax]
// 007af5f4  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 007af5f8  74f6                 je 0x7af5f0
// 007af5fa  c3                   ret 
// standard library set<pod16> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
