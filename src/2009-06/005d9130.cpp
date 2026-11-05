// from server: 100% by auto
// roc 2009-06 005d9130  unit: VAuthoringSettings::?$BoundPropGetSet  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d9130
//
// 005d9130  8b442404             mov eax, dword ptr [esp + 4]
// 005d9134  8b08                 mov ecx, dword ptr [eax]
// 005d9136  80793100             cmp byte ptr [ecx + 0x31], 0
// 005d913a  750e                 jne 0x5d914a
// 005d913c  8d642400             lea esp, [esp]
// 005d9140  8bc1                 mov eax, ecx
// 005d9142  8b08                 mov ecx, dword ptr [eax]
// 005d9144  80793100             cmp byte ptr [ecx + 0x31], 0
// 005d9148  74f6                 je 0x5d9140
// 005d914a  c3                   ret 
// standard library set<pod36> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
