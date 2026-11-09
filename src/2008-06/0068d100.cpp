// from server: 100% by auto
// roc 2008-06 0068d100  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d100
//
// 0068d100  8b442404             mov eax, dword ptr [esp + 4]
// 0068d104  8b4808               mov ecx, dword ptr [eax + 8]
// 0068d107  80793900             cmp byte ptr [ecx + 0x39], 0
// 0068d10b  750e                 jne 0x68d11b
// 0068d10d  8d4900               lea ecx, [ecx]
// 0068d110  8bc1                 mov eax, ecx
// 0068d112  8b4808               mov ecx, dword ptr [eax + 8]
// 0068d115  80793900             cmp byte ptr [ecx + 0x39], 0
// 0068d119  74f5                 je 0x68d110
// 0068d11b  c3                   ret 
// standard library map_int<pod40> (function ?_Max@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
