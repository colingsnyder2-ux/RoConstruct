// from server: 100% by auto
// roc 2009-06 004fb910  unit: RBX::Network::ServerReplicator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fb910
//
// 004fb910  8b442404             mov eax, dword ptr [esp + 4]
// 004fb914  8b4808               mov ecx, dword ptr [eax + 8]
// 004fb917  80793900             cmp byte ptr [ecx + 0x39], 0
// 004fb91b  750e                 jne 0x4fb92b
// 004fb91d  8d4900               lea ecx, [ecx]
// 004fb920  8bc1                 mov eax, ecx
// 004fb922  8b4808               mov ecx, dword ptr [eax + 8]
// 004fb925  80793900             cmp byte ptr [ecx + 0x39], 0
// 004fb929  74f5                 je 0x4fb920
// 004fb92b  c3                   ret 
// standard library map_int<pod40> (function ?_Max@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
