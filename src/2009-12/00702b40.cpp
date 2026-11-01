// from server: 100% by auto
// roc 2009-12 00702b40  unit: RBX::Assembly  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00702b40
//
// 00702b40  8b442404             mov eax, dword ptr [esp + 4]
// 00702b44  8b08                 mov ecx, dword ptr [eax]
// 00702b46  80795100             cmp byte ptr [ecx + 0x51], 0
// 00702b4a  750e                 jne 0x702b5a
// 00702b4c  8d642400             lea esp, [esp]
// 00702b50  8bc1                 mov eax, ecx
// 00702b52  8b08                 mov ecx, dword ptr [eax]
// 00702b54  80795100             cmp byte ptr [ecx + 0x51], 0
// 00702b58  74f6                 je 0x702b50
// 00702b5a  c3                   ret 
// standard library map_int<pod64> (function ?_Min@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: map_int<pod64>
struct E { int v[16]; };
#include <map>
template class std::map<int, E>;
