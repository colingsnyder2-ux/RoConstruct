// from server: 100% by auto
// roc 2010-06 0076af40  unit: RBX::ImageButton  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076af40
//
// 0076af40  8b442404             mov eax, dword ptr [esp + 4]
// 0076af44  8b4808               mov ecx, dword ptr [eax + 8]
// 0076af47  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 0076af4b  750e                 jne 0x76af5b
// 0076af4d  8d4900               lea ecx, [ecx]
// 0076af50  8bc1                 mov eax, ecx
// 0076af52  8b4808               mov ecx, dword ptr [eax + 8]
// 0076af55  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 0076af59  74f5                 je 0x76af50
// 0076af5b  c3                   ret 
// standard library set<pod64> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
