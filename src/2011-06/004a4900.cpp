// from server: 100% by auto
// roc 2011-06 004a4900  unit: RBX::Network::Player  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004a4900
//
// 004a4900  8b442404             mov eax, dword ptr [esp + 4]
// 004a4904  8b08                 mov ecx, dword ptr [eax]
// 004a4906  80793100             cmp byte ptr [ecx + 0x31], 0
// 004a490a  750e                 jne 0x4a491a
// 004a490c  8d642400             lea esp, [esp]
// 004a4910  8bc1                 mov eax, ecx
// 004a4912  8b08                 mov ecx, dword ptr [eax]
// 004a4914  80793100             cmp byte ptr [ecx + 0x31], 0
// 004a4918  74f6                 je 0x4a4910
// 004a491a  c3                   ret 
// standard library set<pod36> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
