// from server: 100% by auto
// roc 2010-06 004d68b0  unit: RBX::VNetworkSettings::?$FactoryProduct  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004d68b0
//
// 004d68b0  6a18                 push 0x18
// 004d68b2  e8e9102d00           call 0x7a79a0
// 004d68b7  83c404               add esp, 4
// 004d68ba  85c0                 test eax, eax
// 004d68bc  7406                 je 0x4d68c4
// 004d68be  c70000000000         mov dword ptr [eax], 0
// 004d68c4  8d4804               lea ecx, [eax + 4]
// 004d68c7  85c9                 test ecx, ecx
// 004d68c9  7406                 je 0x4d68d1
// 004d68cb  c70100000000         mov dword ptr [ecx], 0
// 004d68d1  8d4808               lea ecx, [eax + 8]
// 004d68d4  85c9                 test ecx, ecx
// 004d68d6  7406                 je 0x4d68de
// 004d68d8  c70100000000         mov dword ptr [ecx], 0
// 004d68de  c6401401             mov byte ptr [eax + 0x14], 1
// 004d68e2  c6401500             mov byte ptr [eax + 0x15], 0
// 004d68e6  c3                   ret 
// standard library set<pod8> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
