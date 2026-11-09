// from server: 100% by auto
// roc 2010-06 00526aa0  unit: RBX::ViewG3D  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00526aa0
//
// 00526aa0  8b442404             mov eax, dword ptr [esp + 4]
// 00526aa4  8b4808               mov ecx, dword ptr [eax + 8]
// 00526aa7  80792500             cmp byte ptr [ecx + 0x25], 0
// 00526aab  750e                 jne 0x526abb
// 00526aad  8d4900               lea ecx, [ecx]
// 00526ab0  8bc1                 mov eax, ecx
// 00526ab2  8b4808               mov ecx, dword ptr [eax + 8]
// 00526ab5  80792500             cmp byte ptr [ecx + 0x25], 0
// 00526ab9  74f5                 je 0x526ab0
// 00526abb  c3                   ret 
// standard library set<pod24> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
