// from server: 100% by auto
// roc 2011-06 006187c0  unit: RBX::ScriptContext  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006187c0
//
// 006187c0  8b442404             mov eax, dword ptr [esp + 4]
// 006187c4  8b4808               mov ecx, dword ptr [eax + 8]
// 006187c7  80794900             cmp byte ptr [ecx + 0x49], 0
// 006187cb  750e                 jne 0x6187db
// 006187cd  8d4900               lea ecx, [ecx]
// 006187d0  8bc1                 mov eax, ecx
// 006187d2  8b4808               mov ecx, dword ptr [eax + 8]
// 006187d5  80794900             cmp byte ptr [ecx + 0x49], 0
// 006187d9  74f5                 je 0x6187d0
// 006187db  c3                   ret 
// standard library map_str<pod32> (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
