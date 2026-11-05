// from server: 100% by auto
// roc 2007-08 005835b0  unit: RBX::VHat::?$FactoryProduct  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005835b0
//
// 005835b0  6a18                 push 0x18
// 005835b2  e83fc90a00           call 0x62fef6
// 005835b7  83c404               add esp, 4
// 005835ba  85c0                 test eax, eax
// 005835bc  7406                 je 0x5835c4
// 005835be  c70000000000         mov dword ptr [eax], 0
// 005835c4  8d4804               lea ecx, [eax + 4]
// 005835c7  85c9                 test ecx, ecx
// 005835c9  7406                 je 0x5835d1
// 005835cb  c70100000000         mov dword ptr [ecx], 0
// 005835d1  8d4808               lea ecx, [eax + 8]
// 005835d4  85c9                 test ecx, ecx
// 005835d6  7406                 je 0x5835de
// 005835d8  c70100000000         mov dword ptr [ecx], 0
// 005835de  c6401401             mov byte ptr [eax + 0x14], 1
// 005835e2  c6401500             mov byte ptr [eax + 0x15], 0
// 005835e6  c3                   ret 
// standard library set<pod8> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
