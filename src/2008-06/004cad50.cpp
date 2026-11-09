// from server: 100% by auto
// roc 2008-06 004cad50  unit: RBX::Network::RoundRobinPhysicsSender  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cad50
//
// 004cad50  6a14                 push 0x14
// 004cad52  e8c95b1d00           call 0x6a0920
// 004cad57  83c404               add esp, 4
// 004cad5a  85c0                 test eax, eax
// 004cad5c  7406                 je 0x4cad64
// 004cad5e  c70000000000         mov dword ptr [eax], 0
// 004cad64  8d4804               lea ecx, [eax + 4]
// 004cad67  85c9                 test ecx, ecx
// 004cad69  7406                 je 0x4cad71
// 004cad6b  c70100000000         mov dword ptr [ecx], 0
// 004cad71  8d4808               lea ecx, [eax + 8]
// 004cad74  85c9                 test ecx, ecx
// 004cad76  7406                 je 0x4cad7e
// 004cad78  c70100000000         mov dword ptr [ecx], 0
// 004cad7e  c6401001             mov byte ptr [eax + 0x10], 1
// 004cad82  c6401100             mov byte ptr [eax + 0x11], 0
// 004cad86  c3                   ret 
// standard library set<ptr> (function ?_Buynode@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
