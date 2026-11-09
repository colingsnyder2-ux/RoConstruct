// from server: 100% by auto
// roc 2010-06 008c62b0  unit: RBX::AdornRbxGfx  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c62b0
//
// 008c62b0  8b442404             mov eax, dword ptr [esp + 4]
// 008c62b4  8b4808               mov ecx, dword ptr [eax + 8]
// 008c62b7  80793900             cmp byte ptr [ecx + 0x39], 0
// 008c62bb  750e                 jne 0x8c62cb
// 008c62bd  8d4900               lea ecx, [ecx]
// 008c62c0  8bc1                 mov eax, ecx
// 008c62c2  8b4808               mov ecx, dword ptr [eax + 8]
// 008c62c5  80793900             cmp byte ptr [ecx + 0x39], 0
// 008c62c9  74f5                 je 0x8c62c0
// 008c62cb  c3                   ret 
// standard library map_int<pod40> (function ?_Max@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
