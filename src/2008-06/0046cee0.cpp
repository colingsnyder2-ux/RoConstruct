// from server: 100% by auto
// roc 2008-06 0046cee0  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046cee0
//
// 0046cee0  8b442404             mov eax, dword ptr [esp + 4]
// 0046cee4  8b08                 mov ecx, dword ptr [eax]
// 0046cee6  80791500             cmp byte ptr [ecx + 0x15], 0
// 0046ceea  750e                 jne 0x46cefa
// 0046ceec  8d642400             lea esp, [esp]
// 0046cef0  8bc1                 mov eax, ecx
// 0046cef2  8b08                 mov ecx, dword ptr [eax]
// 0046cef4  80791500             cmp byte ptr [ecx + 0x15], 0
// 0046cef8  74f6                 je 0x46cef0
// 0046cefa  c3                   ret 
// standard library set<pod8> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
