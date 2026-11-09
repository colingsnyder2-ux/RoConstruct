// from server: 100% by auto
// roc 2008-06 005870c0  unit: RBX::LocalScript  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005870c0
//
// 005870c0  8b442404             mov eax, dword ptr [esp + 4]
// 005870c4  8b08                 mov ecx, dword ptr [eax]
// 005870c6  80794900             cmp byte ptr [ecx + 0x49], 0
// 005870ca  750e                 jne 0x5870da
// 005870cc  8d642400             lea esp, [esp]
// 005870d0  8bc1                 mov eax, ecx
// 005870d2  8b08                 mov ecx, dword ptr [eax]
// 005870d4  80794900             cmp byte ptr [ecx + 0x49], 0
// 005870d8  74f6                 je 0x5870d0
// 005870da  c3                   ret 
// standard library map_str<pod32> (function ?_Min@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
