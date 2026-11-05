// from server: 100% by auto
// roc 2009-06 006d2bf0  unit: RBX::Block  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d2bf0
//
// 006d2bf0  8b442404             mov eax, dword ptr [esp + 4]
// 006d2bf4  8b08                 mov ecx, dword ptr [eax]
// 006d2bf6  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 006d2bfa  750e                 jne 0x6d2c0a
// 006d2bfc  8d642400             lea esp, [esp]
// 006d2c00  8bc1                 mov eax, ecx
// 006d2c02  8b08                 mov ecx, dword ptr [eax]
// 006d2c04  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 006d2c08  74f6                 je 0x6d2c00
// 006d2c0a  c3                   ret 
// standard library set<pod16> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
