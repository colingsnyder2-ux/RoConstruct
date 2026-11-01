// from server: 100% by auto
// roc 2009-12 0047e630  unit: Ogre::VResource::?$SharedPtr  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047e630
//
// 0047e630  8b442404             mov eax, dword ptr [esp + 4]
// 0047e634  8b08                 mov ecx, dword ptr [eax]
// 0047e636  80793900             cmp byte ptr [ecx + 0x39], 0
// 0047e63a  750e                 jne 0x47e64a
// 0047e63c  8d642400             lea esp, [esp]
// 0047e640  8bc1                 mov eax, ecx
// 0047e642  8b08                 mov ecx, dword ptr [eax]
// 0047e644  80793900             cmp byte ptr [ecx + 0x39], 0
// 0047e648  74f6                 je 0x47e640
// 0047e64a  c3                   ret 
// standard library map_int<pod40> (function ?_Min@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
