// from server: 100% by auto
// roc 2012-06 00570060  unit: RBX::Network::IdSerializer  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00570060
//
// 00570060  8b442404             mov eax, dword ptr [esp + 4]
// 00570064  8b08                 mov ecx, dword ptr [eax]
// 00570066  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0057006a  750e                 jne 0x57007a
// 0057006c  8d642400             lea esp, [esp]
// 00570070  8bc1                 mov eax, ecx
// 00570072  8b08                 mov ecx, dword ptr [eax]
// 00570074  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00570078  74f6                 je 0x570070
// 0057007a  c3                   ret 
// standard library set<pod32> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
