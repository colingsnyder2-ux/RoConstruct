// from server: 100% by auto
// roc 2011-06 004c7120  unit: RBX::MeshAdapter  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004c7120
//
// 004c7120  8b442404             mov eax, dword ptr [esp + 4]
// 004c7124  8b4808               mov ecx, dword ptr [eax + 8]
// 004c7127  80792900             cmp byte ptr [ecx + 0x29], 0
// 004c712b  750e                 jne 0x4c713b
// 004c712d  8d4900               lea ecx, [ecx]
// 004c7130  8bc1                 mov eax, ecx
// 004c7132  8b4808               mov ecx, dword ptr [eax + 8]
// 004c7135  80792900             cmp byte ptr [ecx + 0x29], 0
// 004c7139  74f5                 je 0x4c7130
// 004c713b  c3                   ret 
// standard library set<string> (function ?_Max@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
