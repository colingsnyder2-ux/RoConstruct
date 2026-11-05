// from server: 100% by auto
// roc 2010-06 0060b620  unit: RBX::ScriptContext  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0060b620
//
// 0060b620  8b442404             mov eax, dword ptr [esp + 4]
// 0060b624  8b4808               mov ecx, dword ptr [eax + 8]
// 0060b627  80794900             cmp byte ptr [ecx + 0x49], 0
// 0060b62b  750e                 jne 0x60b63b
// 0060b62d  8d4900               lea ecx, [ecx]
// 0060b630  8bc1                 mov eax, ecx
// 0060b632  8b4808               mov ecx, dword ptr [eax + 8]
// 0060b635  80794900             cmp byte ptr [ecx + 0x49], 0
// 0060b639  74f5                 je 0x60b630
// 0060b63b  c3                   ret 
// standard library map_str<pod32> (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
