// from server: 100% by auto
// roc 2010-06 0052c590  unit: RBX::MeshRefPartAdapter  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0052c590
//
// 0052c590  8b442404             mov eax, dword ptr [esp + 4]
// 0052c594  8b4808               mov ecx, dword ptr [eax + 8]
// 0052c597  80792900             cmp byte ptr [ecx + 0x29], 0
// 0052c59b  750e                 jne 0x52c5ab
// 0052c59d  8d4900               lea ecx, [ecx]
// 0052c5a0  8bc1                 mov eax, ecx
// 0052c5a2  8b4808               mov ecx, dword ptr [eax + 8]
// 0052c5a5  80792900             cmp byte ptr [ecx + 0x29], 0
// 0052c5a9  74f5                 je 0x52c5a0
// 0052c5ab  c3                   ret 
// standard library set<string> (function ?_Max@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
