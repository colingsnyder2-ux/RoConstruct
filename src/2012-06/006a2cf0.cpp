// from server: 100% by auto
// roc 2012-06 006a2cf0  unit: std::D::DU?$char_traits::?$basic_istringstream  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006a2cf0
//
// 006a2cf0  8b442404             mov eax, dword ptr [esp + 4]
// 006a2cf4  8b4808               mov ecx, dword ptr [eax + 8]
// 006a2cf7  80793900             cmp byte ptr [ecx + 0x39], 0
// 006a2cfb  750e                 jne 0x6a2d0b
// 006a2cfd  8d4900               lea ecx, [ecx]
// 006a2d00  8bc1                 mov eax, ecx
// 006a2d02  8b4808               mov ecx, dword ptr [eax + 8]
// 006a2d05  80793900             cmp byte ptr [ecx + 0x39], 0
// 006a2d09  74f5                 je 0x6a2d00
// 006a2d0b  c3                   ret 
// standard library map_int<pod40> (function ?_Max@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
