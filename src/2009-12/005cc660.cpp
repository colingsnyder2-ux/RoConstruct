// from server: 100% by auto
// roc 2009-12 005cc660  unit: RBX::MeshRefPartAdapter  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cc660
//
// 005cc660  8b442404             mov eax, dword ptr [esp + 4]
// 005cc664  8b4808               mov ecx, dword ptr [eax + 8]
// 005cc667  80792900             cmp byte ptr [ecx + 0x29], 0
// 005cc66b  750e                 jne 0x5cc67b
// 005cc66d  8d4900               lea ecx, [ecx]
// 005cc670  8bc1                 mov eax, ecx
// 005cc672  8b4808               mov ecx, dword ptr [eax + 8]
// 005cc675  80792900             cmp byte ptr [ecx + 0x29], 0
// 005cc679  74f5                 je 0x5cc670
// 005cc67b  c3                   ret 
// standard library set<string> (function ?_Max@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
