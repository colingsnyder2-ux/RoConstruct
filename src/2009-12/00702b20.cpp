// from server: 100% by auto
// roc 2009-12 00702b20  unit: RBX::Assembly  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00702b20
//
// 00702b20  8b442404             mov eax, dword ptr [esp + 4]
// 00702b24  8b4808               mov ecx, dword ptr [eax + 8]
// 00702b27  80795100             cmp byte ptr [ecx + 0x51], 0
// 00702b2b  750e                 jne 0x702b3b
// 00702b2d  8d4900               lea ecx, [ecx]
// 00702b30  8bc1                 mov eax, ecx
// 00702b32  8b4808               mov ecx, dword ptr [eax + 8]
// 00702b35  80795100             cmp byte ptr [ecx + 0x51], 0
// 00702b39  74f5                 je 0x702b30
// 00702b3b  c3                   ret 
// standard library map_int<pod64> (function ?_Max@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: map_int<pod64>
struct E { int v[16]; };
#include <map>
template class std::map<int, E>;
