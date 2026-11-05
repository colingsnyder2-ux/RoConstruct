// from server: 100% by auto
// roc 2009-12 00476aa0  unit: VCWorkspace::?$CComObject  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00476aa0
//
// 00476aa0  8b442404             mov eax, dword ptr [esp + 4]
// 00476aa4  8b4808               mov ecx, dword ptr [eax + 8]
// 00476aa7  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00476aab  750e                 jne 0x476abb
// 00476aad  8d4900               lea ecx, [ecx]
// 00476ab0  8bc1                 mov eax, ecx
// 00476ab2  8b4808               mov ecx, dword ptr [eax + 8]
// 00476ab5  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00476ab9  74f5                 je 0x476ab0
// 00476abb  c3                   ret 
// standard library set<pod32> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
