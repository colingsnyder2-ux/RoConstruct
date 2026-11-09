// from server: 100% by auto
// roc 2007-08 00599750  unit: RBX::VCamera::?$FactoryProduct  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00599750
//
// 00599750  8b442404             mov eax, dword ptr [esp + 4]
// 00599754  8b4808               mov ecx, dword ptr [eax + 8]
// 00599757  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0059975b  750e                 jne 0x59976b
// 0059975d  8d4900               lea ecx, [ecx]
// 00599760  8bc1                 mov eax, ecx
// 00599762  8b4808               mov ecx, dword ptr [eax + 8]
// 00599765  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00599769  74f5                 je 0x599760
// 0059976b  c3                   ret 
// standard library set<pod32> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
