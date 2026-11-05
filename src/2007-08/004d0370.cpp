// from server: 100% by auto
// roc 2007-08 004d0370  unit: RBX::TextureProxyBase  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d0370
//
// 004d0370  8b442404             mov eax, dword ptr [esp + 4]
// 004d0374  8b4808               mov ecx, dword ptr [eax + 8]
// 004d0377  80792900             cmp byte ptr [ecx + 0x29], 0
// 004d037b  750e                 jne 0x4d038b
// 004d037d  8d4900               lea ecx, [ecx]
// 004d0380  8bc1                 mov eax, ecx
// 004d0382  8b4808               mov ecx, dword ptr [eax + 8]
// 004d0385  80792900             cmp byte ptr [ecx + 0x29], 0
// 004d0389  74f5                 je 0x4d0380
// 004d038b  c3                   ret 
// standard library set<string> (function ?_Max@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
