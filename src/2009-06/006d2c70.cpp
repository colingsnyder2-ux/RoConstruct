// from server: 100% by auto
// roc 2009-06 006d2c70  unit: RBX::Block  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d2c70
//
// 006d2c70  8b442404             mov eax, dword ptr [esp + 4]
// 006d2c74  8b4808               mov ecx, dword ptr [eax + 8]
// 006d2c77  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 006d2c7b  750e                 jne 0x6d2c8b
// 006d2c7d  8d4900               lea ecx, [ecx]
// 006d2c80  8bc1                 mov eax, ecx
// 006d2c82  8b4808               mov ecx, dword ptr [eax + 8]
// 006d2c85  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 006d2c89  74f5                 je 0x6d2c80
// 006d2c8b  c3                   ret 
// standard library set<pod16> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
