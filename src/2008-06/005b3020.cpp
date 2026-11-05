// from server: 100% by auto
// roc 2008-06 005b3020  unit: RBX::VHat::?$FactoryProduct  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b3020
//
// 005b3020  6a24                 push 0x24
// 005b3022  e8f9d80e00           call 0x6a0920
// 005b3027  83c404               add esp, 4
// 005b302a  85c0                 test eax, eax
// 005b302c  7406                 je 0x5b3034
// 005b302e  c70000000000         mov dword ptr [eax], 0
// 005b3034  8d4804               lea ecx, [eax + 4]
// 005b3037  85c9                 test ecx, ecx
// 005b3039  7406                 je 0x5b3041
// 005b303b  c70100000000         mov dword ptr [ecx], 0
// 005b3041  8d4808               lea ecx, [eax + 8]
// 005b3044  85c9                 test ecx, ecx
// 005b3046  7406                 je 0x5b304e
// 005b3048  c70100000000         mov dword ptr [ecx], 0
// 005b304e  c6402001             mov byte ptr [eax + 0x20], 1
// 005b3052  c6402100             mov byte ptr [eax + 0x21], 0
// 005b3056  c3                   ret 
// standard library set<pod20> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
