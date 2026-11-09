// from server: 100% by auto
// roc 2012-06 0090e020  unit: RBX::WedgePoly  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0090e020
//
// 0090e020  8b442404             mov eax, dword ptr [esp + 4]
// 0090e024  8b4808               mov ecx, dword ptr [eax + 8]
// 0090e027  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0090e02b  750e                 jne 0x90e03b
// 0090e02d  8d4900               lea ecx, [ecx]
// 0090e030  8bc1                 mov eax, ecx
// 0090e032  8b4808               mov ecx, dword ptr [eax + 8]
// 0090e035  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0090e039  74f5                 je 0x90e030
// 0090e03b  c3                   ret 
// standard library set<pod16> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
