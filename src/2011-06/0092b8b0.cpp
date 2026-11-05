// from server: 100% by auto
// roc 2011-06 0092b8b0  unit: std::D::DU?$char_traits::V?$basic_string::V?$_Tset_traits::?$_Tree_nod::PAU_Node::?$STLAllocator  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0092b8b0
//
// 0092b8b0  8b442404             mov eax, dword ptr [esp + 4]
// 0092b8b4  8b08                 mov ecx, dword ptr [eax]
// 0092b8b6  80792900             cmp byte ptr [ecx + 0x29], 0
// 0092b8ba  750e                 jne 0x92b8ca
// 0092b8bc  8d642400             lea esp, [esp]
// 0092b8c0  8bc1                 mov eax, ecx
// 0092b8c2  8b08                 mov ecx, dword ptr [eax]
// 0092b8c4  80792900             cmp byte ptr [ecx + 0x29], 0
// 0092b8c8  74f6                 je 0x92b8c0
// 0092b8ca  c3                   ret 
// standard library set<string> (function ?_Min@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
