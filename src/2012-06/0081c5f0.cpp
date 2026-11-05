// from server: 100% by auto
// roc 2012-06 0081c5f0  unit: RBX::Reflection::UTuple::$$A6A?AV?$shared_ptr::V?$function::?$sp_counted_impl_p  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0081c5f0
//
// 0081c5f0  8b442404             mov eax, dword ptr [esp + 4]
// 0081c5f4  8b08                 mov ecx, dword ptr [eax]
// 0081c5f6  80791100             cmp byte ptr [ecx + 0x11], 0
// 0081c5fa  750e                 jne 0x81c60a
// 0081c5fc  8d642400             lea esp, [esp]
// 0081c600  8bc1                 mov eax, ecx
// 0081c602  8b08                 mov ecx, dword ptr [eax]
// 0081c604  80791100             cmp byte ptr [ecx + 0x11], 0
// 0081c608  74f6                 je 0x81c600
// 0081c60a  c3                   ret 
// standard library set<ptr> (function ?_Min@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
