// from server: 100% by auto
// roc 2010-06 0058e6c0  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0058e6c0
//
// 0058e6c0  6a20                 push 0x20
// 0058e6c2  e8d9922100           call 0x7a79a0
// 0058e6c7  83c404               add esp, 4
// 0058e6ca  85c0                 test eax, eax
// 0058e6cc  7406                 je 0x58e6d4
// 0058e6ce  c70000000000         mov dword ptr [eax], 0
// 0058e6d4  8d4804               lea ecx, [eax + 4]
// 0058e6d7  85c9                 test ecx, ecx
// 0058e6d9  7406                 je 0x58e6e1
// 0058e6db  c70100000000         mov dword ptr [ecx], 0
// 0058e6e1  8d4808               lea ecx, [eax + 8]
// 0058e6e4  85c9                 test ecx, ecx
// 0058e6e6  7406                 je 0x58e6ee
// 0058e6e8  c70100000000         mov dword ptr [ecx], 0
// 0058e6ee  c6401c01             mov byte ptr [eax + 0x1c], 1
// 0058e6f2  c6401d00             mov byte ptr [eax + 0x1d], 0
// 0058e6f6  c3                   ret 
// standard library set<pod16> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
