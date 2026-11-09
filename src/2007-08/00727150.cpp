// from server: 100% by auto
// roc 2007-08 00727150  unit: boost::thread_resource_error  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00727150
//
// 00727150  8b442404             mov eax, dword ptr [esp + 4]
// 00727154  8b08                 mov ecx, dword ptr [eax]
// 00727156  80792500             cmp byte ptr [ecx + 0x25], 0
// 0072715a  750e                 jne 0x72716a
// 0072715c  8d642400             lea esp, [esp]
// 00727160  8bc1                 mov eax, ecx
// 00727162  8b08                 mov ecx, dword ptr [eax]
// 00727164  80792500             cmp byte ptr [ecx + 0x25], 0
// 00727168  74f6                 je 0x727160
// 0072716a  c3                   ret 
// standard library set<pod24> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
