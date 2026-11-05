// from server: 100% by auto
// roc 2010-06 0075aa40  unit: RBX::PrismPoly  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075aa40
//
// 0075aa40  8b442404             mov eax, dword ptr [esp + 4]
// 0075aa44  8b4808               mov ecx, dword ptr [eax + 8]
// 0075aa47  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0075aa4b  750e                 jne 0x75aa5b
// 0075aa4d  8d4900               lea ecx, [ecx]
// 0075aa50  8bc1                 mov eax, ecx
// 0075aa52  8b4808               mov ecx, dword ptr [eax + 8]
// 0075aa55  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0075aa59  74f5                 je 0x75aa50
// 0075aa5b  c3                   ret 
// standard library set<pod16> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
