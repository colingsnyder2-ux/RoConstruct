// from server: 100% by auto
// roc 2012-06 0056bbc0  unit: RBX::RbxRay  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0056bbc0
//
// 0056bbc0  8b442404             mov eax, dword ptr [esp + 4]
// 0056bbc4  8b4808               mov ecx, dword ptr [eax + 8]
// 0056bbc7  80792500             cmp byte ptr [ecx + 0x25], 0
// 0056bbcb  750e                 jne 0x56bbdb
// 0056bbcd  8d4900               lea ecx, [ecx]
// 0056bbd0  8bc1                 mov eax, ecx
// 0056bbd2  8b4808               mov ecx, dword ptr [eax + 8]
// 0056bbd5  80792500             cmp byte ptr [ecx + 0x25], 0
// 0056bbd9  74f5                 je 0x56bbd0
// 0056bbdb  c3                   ret 
// standard library set<pod24> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
