// from server: 100% by auto
// roc 2007-08 00545380  unit: RBX::VDebugSettings::?$GlobalSettingsItem  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00545380
//
// 00545380  8b442404             mov eax, dword ptr [esp + 4]
// 00545384  8b08                 mov ecx, dword ptr [eax]
// 00545386  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 0054538a  750e                 jne 0x54539a
// 0054538c  8d642400             lea esp, [esp]
// 00545390  8bc1                 mov eax, ecx
// 00545392  8b08                 mov ecx, dword ptr [eax]
// 00545394  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 00545398  74f6                 je 0x545390
// 0054539a  c3                   ret 
// standard library set<pod48> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
