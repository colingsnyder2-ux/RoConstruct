// from server: 100% by auto
// roc 2009-06 005d8f90  unit: VAuthoringSettings::?$BoundPropGetSet  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d8f90
//
// 005d8f90  8b442404             mov eax, dword ptr [esp + 4]
// 005d8f94  8b08                 mov ecx, dword ptr [eax]
// 005d8f96  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 005d8f9a  750e                 jne 0x5d8faa
// 005d8f9c  8d642400             lea esp, [esp]
// 005d8fa0  8bc1                 mov eax, ecx
// 005d8fa2  8b08                 mov ecx, dword ptr [eax]
// 005d8fa4  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 005d8fa8  74f6                 je 0x5d8fa0
// 005d8faa  c3                   ret 
// standard library set<pod48> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
