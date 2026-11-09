// from server: 100% by auto
// roc 2007-08 00545360  unit: RBX::VDebugSettings::?$GlobalSettingsItem  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00545360
//
// 00545360  8b442404             mov eax, dword ptr [esp + 4]
// 00545364  8b4808               mov ecx, dword ptr [eax + 8]
// 00545367  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 0054536b  750e                 jne 0x54537b
// 0054536d  8d4900               lea ecx, [ecx]
// 00545370  8bc1                 mov eax, ecx
// 00545372  8b4808               mov ecx, dword ptr [eax + 8]
// 00545375  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 00545379  74f5                 je 0x545370
// 0054537b  c3                   ret 
// standard library set<pod48> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
