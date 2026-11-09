// from server: 100% by auto
// roc 2009-06 0044d440  unit: CRobloxDoc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044d440
//
// 0044d440  8b442404             mov eax, dword ptr [esp + 4]
// 0044d444  8b08                 mov ecx, dword ptr [eax]
// 0044d446  80791500             cmp byte ptr [ecx + 0x15], 0
// 0044d44a  750e                 jne 0x44d45a
// 0044d44c  8d642400             lea esp, [esp]
// 0044d450  8bc1                 mov eax, ecx
// 0044d452  8b08                 mov ecx, dword ptr [eax]
// 0044d454  80791500             cmp byte ptr [ecx + 0x15], 0
// 0044d458  74f6                 je 0x44d450
// 0044d45a  c3                   ret 
// standard library set<pod8> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
