// from server: 100% by auto
// roc 2010-06 00480cf0  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00480cf0
//
// 00480cf0  8b442404             mov eax, dword ptr [esp + 4]
// 00480cf4  8b08                 mov ecx, dword ptr [eax]
// 00480cf6  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00480cfa  750e                 jne 0x480d0a
// 00480cfc  8d642400             lea esp, [esp]
// 00480d00  8bc1                 mov eax, ecx
// 00480d02  8b08                 mov ecx, dword ptr [eax]
// 00480d04  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00480d08  74f6                 je 0x480d00
// 00480d0a  c3                   ret 
// standard library set<pod32> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
