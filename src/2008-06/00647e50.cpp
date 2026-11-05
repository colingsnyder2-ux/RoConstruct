// from server: 100% by auto
// roc 2008-06 00647e50  unit: RBX::Block  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00647e50
//
// 00647e50  8b442404             mov eax, dword ptr [esp + 4]
// 00647e54  8b4808               mov ecx, dword ptr [eax + 8]
// 00647e57  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 00647e5b  750e                 jne 0x647e6b
// 00647e5d  8d4900               lea ecx, [ecx]
// 00647e60  8bc1                 mov eax, ecx
// 00647e62  8b4808               mov ecx, dword ptr [eax + 8]
// 00647e65  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 00647e69  74f5                 je 0x647e60
// 00647e6b  c3                   ret 
// standard library set<pod16> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
