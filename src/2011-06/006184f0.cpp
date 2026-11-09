// from server: 100% by auto
// roc 2011-06 006184f0  unit: RBX::ScriptContext  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006184f0
//
// 006184f0  8b442404             mov eax, dword ptr [esp + 4]
// 006184f4  8b08                 mov ecx, dword ptr [eax]
// 006184f6  80793900             cmp byte ptr [ecx + 0x39], 0
// 006184fa  750e                 jne 0x61850a
// 006184fc  8d642400             lea esp, [esp]
// 00618500  8bc1                 mov eax, ecx
// 00618502  8b08                 mov ecx, dword ptr [eax]
// 00618504  80793900             cmp byte ptr [ecx + 0x39], 0
// 00618508  74f6                 je 0x618500
// 0061850a  c3                   ret 
// standard library map_int<pod40> (function ?_Min@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
