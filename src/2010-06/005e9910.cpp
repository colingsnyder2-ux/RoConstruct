// from server: 100% by auto
// roc 2010-06 005e9910  unit: RBX::VModelInstance::?$BoundFuncDesc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005e9910
//
// 005e9910  8b442404             mov eax, dword ptr [esp + 4]
// 005e9914  8b08                 mov ecx, dword ptr [eax]
// 005e9916  80794900             cmp byte ptr [ecx + 0x49], 0
// 005e991a  750e                 jne 0x5e992a
// 005e991c  8d642400             lea esp, [esp]
// 005e9920  8bc1                 mov eax, ecx
// 005e9922  8b08                 mov ecx, dword ptr [eax]
// 005e9924  80794900             cmp byte ptr [ecx + 0x49], 0
// 005e9928  74f6                 je 0x5e9920
// 005e992a  c3                   ret 
// standard library map_str<pod32> (function ?_Min@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
