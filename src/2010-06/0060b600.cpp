// from server: 100% by auto
// roc 2010-06 0060b600  unit: RBX::ScriptContext  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0060b600
//
// 0060b600  8b442404             mov eax, dword ptr [esp + 4]
// 0060b604  8b08                 mov ecx, dword ptr [eax]
// 0060b606  80793900             cmp byte ptr [ecx + 0x39], 0
// 0060b60a  750e                 jne 0x60b61a
// 0060b60c  8d642400             lea esp, [esp]
// 0060b610  8bc1                 mov eax, ecx
// 0060b612  8b08                 mov ecx, dword ptr [eax]
// 0060b614  80793900             cmp byte ptr [ecx + 0x39], 0
// 0060b618  74f6                 je 0x60b610
// 0060b61a  c3                   ret 
// standard library map_int<pod40> (function ?_Min@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
