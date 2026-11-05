// from server: 100% by auto
// roc 2012-06 00766ba0  unit: std::D::DU?$char_traits::$$A6A_NV?$basic_string::?$CallbackDescImpl  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00766ba0
//
// 00766ba0  8b442404             mov eax, dword ptr [esp + 4]
// 00766ba4  8b08                 mov ecx, dword ptr [eax]
// 00766ba6  80791500             cmp byte ptr [ecx + 0x15], 0
// 00766baa  750e                 jne 0x766bba
// 00766bac  8d642400             lea esp, [esp]
// 00766bb0  8bc1                 mov eax, ecx
// 00766bb2  8b08                 mov ecx, dword ptr [eax]
// 00766bb4  80791500             cmp byte ptr [ecx + 0x15], 0
// 00766bb8  74f6                 je 0x766bb0
// 00766bba  c3                   ret 
// standard library set<pod8> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
