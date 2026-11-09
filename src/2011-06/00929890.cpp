// from server: 100% by auto
// roc 2011-06 00929890  unit: std::D::DU?$char_traits::V?$basic_string::?$STLAllocator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00929890
//
// 00929890  8b442404             mov eax, dword ptr [esp + 4]
// 00929894  8b4808               mov ecx, dword ptr [eax + 8]
// 00929897  80793900             cmp byte ptr [ecx + 0x39], 0
// 0092989b  750e                 jne 0x9298ab
// 0092989d  8d4900               lea ecx, [ecx]
// 009298a0  8bc1                 mov eax, ecx
// 009298a2  8b4808               mov ecx, dword ptr [eax + 8]
// 009298a5  80793900             cmp byte ptr [ecx + 0x39], 0
// 009298a9  74f5                 je 0x9298a0
// 009298ab  c3                   ret 
// standard library map_int<pod40> (function ?_Max@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
