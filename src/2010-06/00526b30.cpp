// from server: 100% by auto
// roc 2010-06 00526b30  unit: RBX::ViewG3D  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00526b30
//
// 00526b30  8b442404             mov eax, dword ptr [esp + 4]
// 00526b34  8b08                 mov ecx, dword ptr [eax]
// 00526b36  80792900             cmp byte ptr [ecx + 0x29], 0
// 00526b3a  750e                 jne 0x526b4a
// 00526b3c  8d642400             lea esp, [esp]
// 00526b40  8bc1                 mov eax, ecx
// 00526b42  8b08                 mov ecx, dword ptr [eax]
// 00526b44  80792900             cmp byte ptr [ecx + 0x29], 0
// 00526b48  74f6                 je 0x526b40
// 00526b4a  c3                   ret 
// standard library set<string> (function ?_Min@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
