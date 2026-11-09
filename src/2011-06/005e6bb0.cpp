// from server: 100% by auto
// roc 2011-06 005e6bb0  unit: RBX::DataModel  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005e6bb0
//
// 005e6bb0  8b442404             mov eax, dword ptr [esp + 4]
// 005e6bb4  8b4808               mov ecx, dword ptr [eax + 8]
// 005e6bb7  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 005e6bbb  750e                 jne 0x5e6bcb
// 005e6bbd  8d4900               lea ecx, [ecx]
// 005e6bc0  8bc1                 mov eax, ecx
// 005e6bc2  8b4808               mov ecx, dword ptr [eax + 8]
// 005e6bc5  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 005e6bc9  74f5                 je 0x5e6bc0
// 005e6bcb  c3                   ret 
// standard library set<pod32> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
