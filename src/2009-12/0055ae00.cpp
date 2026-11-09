// from server: 100% by auto
// roc 2009-12 0055ae00  unit: RBX::Network::ServerReplicator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0055ae00
//
// 0055ae00  8b442404             mov eax, dword ptr [esp + 4]
// 0055ae04  8b4808               mov ecx, dword ptr [eax + 8]
// 0055ae07  80792500             cmp byte ptr [ecx + 0x25], 0
// 0055ae0b  750e                 jne 0x55ae1b
// 0055ae0d  8d4900               lea ecx, [ecx]
// 0055ae10  8bc1                 mov eax, ecx
// 0055ae12  8b4808               mov ecx, dword ptr [eax + 8]
// 0055ae15  80792500             cmp byte ptr [ecx + 0x25], 0
// 0055ae19  74f5                 je 0x55ae10
// 0055ae1b  c3                   ret 
// standard library set<pod24> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
