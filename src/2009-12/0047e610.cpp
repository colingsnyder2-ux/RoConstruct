// from server: 100% by auto
// roc 2009-12 0047e610  unit: Ogre::VResource::?$SharedPtr  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047e610
//
// 0047e610  8b442404             mov eax, dword ptr [esp + 4]
// 0047e614  8b4808               mov ecx, dword ptr [eax + 8]
// 0047e617  80793900             cmp byte ptr [ecx + 0x39], 0
// 0047e61b  750e                 jne 0x47e62b
// 0047e61d  8d4900               lea ecx, [ecx]
// 0047e620  8bc1                 mov eax, ecx
// 0047e622  8b4808               mov ecx, dword ptr [eax + 8]
// 0047e625  80793900             cmp byte ptr [ecx + 0x39], 0
// 0047e629  74f5                 je 0x47e620
// 0047e62b  c3                   ret 
// standard library map_int<pod40> (function ?_Max@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
