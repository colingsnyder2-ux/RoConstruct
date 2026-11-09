// from server: 100% by auto
// roc 2009-06 006e2000  unit: RBX::ChatOutput  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e2000
//
// 006e2000  8b442404             mov eax, dword ptr [esp + 4]
// 006e2004  8b4808               mov ecx, dword ptr [eax + 8]
// 006e2007  80792900             cmp byte ptr [ecx + 0x29], 0
// 006e200b  750e                 jne 0x6e201b
// 006e200d  8d4900               lea ecx, [ecx]
// 006e2010  8bc1                 mov eax, ecx
// 006e2012  8b4808               mov ecx, dword ptr [eax + 8]
// 006e2015  80792900             cmp byte ptr [ecx + 0x29], 0
// 006e2019  74f5                 je 0x6e2010
// 006e201b  c3                   ret 
// standard library set<string> (function ?_Max@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
