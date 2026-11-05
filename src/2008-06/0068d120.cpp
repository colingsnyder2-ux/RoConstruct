// from server: 100% by auto
// roc 2008-06 0068d120  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d120
//
// 0068d120  8b442404             mov eax, dword ptr [esp + 4]
// 0068d124  8b08                 mov ecx, dword ptr [eax]
// 0068d126  80793900             cmp byte ptr [ecx + 0x39], 0
// 0068d12a  750e                 jne 0x68d13a
// 0068d12c  8d642400             lea esp, [esp]
// 0068d130  8bc1                 mov eax, ecx
// 0068d132  8b08                 mov ecx, dword ptr [eax]
// 0068d134  80793900             cmp byte ptr [ecx + 0x39], 0
// 0068d138  74f6                 je 0x68d130
// 0068d13a  c3                   ret 
// standard library map_int<pod40> (function ?_Min@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
