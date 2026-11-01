// from server: 100% by auto
// roc 2009-12 005cc680  unit: RBX::MeshRefPartAdapter  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cc680
//
// 005cc680  8b442404             mov eax, dword ptr [esp + 4]
// 005cc684  8b08                 mov ecx, dword ptr [eax]
// 005cc686  80792900             cmp byte ptr [ecx + 0x29], 0
// 005cc68a  750e                 jne 0x5cc69a
// 005cc68c  8d642400             lea esp, [esp]
// 005cc690  8bc1                 mov eax, ecx
// 005cc692  8b08                 mov ecx, dword ptr [eax]
// 005cc694  80792900             cmp byte ptr [ecx + 0x29], 0
// 005cc698  74f6                 je 0x5cc690
// 005cc69a  c3                   ret 
// standard library set<string> (function ?_Min@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
