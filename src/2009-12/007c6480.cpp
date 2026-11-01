// from server: 100% by auto
// roc 2009-12 007c6480  unit: RBX::ChatOutput  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c6480
//
// 007c6480  8b442404             mov eax, dword ptr [esp + 4]
// 007c6484  8b4808               mov ecx, dword ptr [eax + 8]
// 007c6487  80794900             cmp byte ptr [ecx + 0x49], 0
// 007c648b  750e                 jne 0x7c649b
// 007c648d  8d4900               lea ecx, [ecx]
// 007c6490  8bc1                 mov eax, ecx
// 007c6492  8b4808               mov ecx, dword ptr [eax + 8]
// 007c6495  80794900             cmp byte ptr [ecx + 0x49], 0
// 007c6499  74f5                 je 0x7c6490
// 007c649b  c3                   ret 
// standard library map_str<pod32> (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
