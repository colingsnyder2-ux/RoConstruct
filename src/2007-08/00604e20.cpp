// from server: 100% by auto
// roc 2007-08 00604e20  unit: RBX::SleepStage  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00604e20
//
// 00604e20  6a1c                 push 0x1c
// 00604e22  e8cfb00200           call 0x62fef6
// 00604e27  83c404               add esp, 4
// 00604e2a  85c0                 test eax, eax
// 00604e2c  7406                 je 0x604e34
// 00604e2e  c70000000000         mov dword ptr [eax], 0
// 00604e34  8d4804               lea ecx, [eax + 4]
// 00604e37  85c9                 test ecx, ecx
// 00604e39  7406                 je 0x604e41
// 00604e3b  c70100000000         mov dword ptr [ecx], 0
// 00604e41  8d4808               lea ecx, [eax + 8]
// 00604e44  85c9                 test ecx, ecx
// 00604e46  7406                 je 0x604e4e
// 00604e48  c70100000000         mov dword ptr [ecx], 0
// 00604e4e  c6401801             mov byte ptr [eax + 0x18], 1
// 00604e52  c6401900             mov byte ptr [eax + 0x19], 0
// 00604e56  c3                   ret 
// standard library set<pod12> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod12>
struct E { int v[3]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
