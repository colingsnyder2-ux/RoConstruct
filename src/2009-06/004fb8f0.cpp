// from server: 100% by auto
// roc 2009-06 004fb8f0  unit: RBX::Network::ServerReplicator  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fb8f0
//
// 004fb8f0  8b442404             mov eax, dword ptr [esp + 4]
// 004fb8f4  8b08                 mov ecx, dword ptr [eax]
// 004fb8f6  80793900             cmp byte ptr [ecx + 0x39], 0
// 004fb8fa  750e                 jne 0x4fb90a
// 004fb8fc  8d642400             lea esp, [esp]
// 004fb900  8bc1                 mov eax, ecx
// 004fb902  8b08                 mov ecx, dword ptr [eax]
// 004fb904  80793900             cmp byte ptr [ecx + 0x39], 0
// 004fb908  74f6                 je 0x4fb900
// 004fb90a  c3                   ret 
// standard library map_int<pod40> (function ?_Min@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
