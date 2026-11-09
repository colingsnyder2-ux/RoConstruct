// from server: 100% by auto
// roc 2008-06 0055c170  unit: RBX::VInstance::?$SignalDesc  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055c170
//
// 0055c170  8b442404             mov eax, dword ptr [esp + 4]
// 0055c174  8b4808               mov ecx, dword ptr [eax + 8]
// 0055c177  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 0055c17b  750e                 jne 0x55c18b
// 0055c17d  8d4900               lea ecx, [ecx]
// 0055c180  8bc1                 mov eax, ecx
// 0055c182  8b4808               mov ecx, dword ptr [eax + 8]
// 0055c185  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 0055c189  74f5                 je 0x55c180
// 0055c18b  c3                   ret 
// standard library set<pod48> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
