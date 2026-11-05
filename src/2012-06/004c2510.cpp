// from server: 100% by auto
// roc 2012-06 004c2510  unit: RBX::AdornRbxGfx  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004c2510
//
// 004c2510  8b442404             mov eax, dword ptr [esp + 4]
// 004c2514  8b08                 mov ecx, dword ptr [eax]
// 004c2516  80793900             cmp byte ptr [ecx + 0x39], 0
// 004c251a  750e                 jne 0x4c252a
// 004c251c  8d642400             lea esp, [esp]
// 004c2520  8bc1                 mov eax, ecx
// 004c2522  8b08                 mov ecx, dword ptr [eax]
// 004c2524  80793900             cmp byte ptr [ecx + 0x39], 0
// 004c2528  74f6                 je 0x4c2520
// 004c252a  c3                   ret 
// standard library map_int<pod40> (function ?_Min@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
