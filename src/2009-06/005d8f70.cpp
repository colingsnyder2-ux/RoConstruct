// from server: 100% by auto
// roc 2009-06 005d8f70  unit: VAuthoringSettings::?$BoundPropGetSet  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d8f70
//
// 005d8f70  8b442404             mov eax, dword ptr [esp + 4]
// 005d8f74  8b4808               mov ecx, dword ptr [eax + 8]
// 005d8f77  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 005d8f7b  750e                 jne 0x5d8f8b
// 005d8f7d  8d4900               lea ecx, [ecx]
// 005d8f80  8bc1                 mov eax, ecx
// 005d8f82  8b4808               mov ecx, dword ptr [eax + 8]
// 005d8f85  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 005d8f89  74f5                 je 0x5d8f80
// 005d8f8b  c3                   ret 
// standard library set<pod48> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
