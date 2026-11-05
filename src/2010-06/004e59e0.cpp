// from server: 100% by auto
// roc 2010-06 004e59e0  unit: RBX::Network::Replicator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e59e0
//
// 004e59e0  8b442404             mov eax, dword ptr [esp + 4]
// 004e59e4  8b4808               mov ecx, dword ptr [eax + 8]
// 004e59e7  80793500             cmp byte ptr [ecx + 0x35], 0
// 004e59eb  750e                 jne 0x4e59fb
// 004e59ed  8d4900               lea ecx, [ecx]
// 004e59f0  8bc1                 mov eax, ecx
// 004e59f2  8b4808               mov ecx, dword ptr [eax + 8]
// 004e59f5  80793500             cmp byte ptr [ecx + 0x35], 0
// 004e59f9  74f5                 je 0x4e59f0
// 004e59fb  c3                   ret 
// standard library set<pod40> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
