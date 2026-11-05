// from server: 100% by auto
// roc 2009-06 00516ad0  unit: RBX::MeshRefPartAdapter  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00516ad0
//
// 00516ad0  8b442404             mov eax, dword ptr [esp + 4]
// 00516ad4  8b08                 mov ecx, dword ptr [eax]
// 00516ad6  80792900             cmp byte ptr [ecx + 0x29], 0
// 00516ada  750e                 jne 0x516aea
// 00516adc  8d642400             lea esp, [esp]
// 00516ae0  8bc1                 mov eax, ecx
// 00516ae2  8b08                 mov ecx, dword ptr [eax]
// 00516ae4  80792900             cmp byte ptr [ecx + 0x29], 0
// 00516ae8  74f6                 je 0x516ae0
// 00516aea  c3                   ret 
// standard library set<string> (function ?_Min@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
