// from server: 100% by auto
// roc 2007-08 00727170  unit: boost::thread_resource_error  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00727170
//
// 00727170  8b442404             mov eax, dword ptr [esp + 4]
// 00727174  8b4808               mov ecx, dword ptr [eax + 8]
// 00727177  80792500             cmp byte ptr [ecx + 0x25], 0
// 0072717b  750e                 jne 0x72718b
// 0072717d  8d4900               lea ecx, [ecx]
// 00727180  8bc1                 mov eax, ecx
// 00727182  8b4808               mov ecx, dword ptr [eax + 8]
// 00727185  80792500             cmp byte ptr [ecx + 0x25], 0
// 00727189  74f5                 je 0x727180
// 0072718b  c3                   ret 
// standard library set<pod24> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
