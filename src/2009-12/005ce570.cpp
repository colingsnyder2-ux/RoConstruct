// from server: 100% by auto
// roc 2009-12 005ce570  unit: RBX::PartChunk  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005ce570
//
// 005ce570  6a24                 push 0x24
// 005ce572  e8e9522200           call 0x7f3860
// 005ce577  83c404               add esp, 4
// 005ce57a  85c0                 test eax, eax
// 005ce57c  7406                 je 0x5ce584
// 005ce57e  c70000000000         mov dword ptr [eax], 0
// 005ce584  8d4804               lea ecx, [eax + 4]
// 005ce587  85c9                 test ecx, ecx
// 005ce589  7406                 je 0x5ce591
// 005ce58b  c70100000000         mov dword ptr [ecx], 0
// 005ce591  8d4808               lea ecx, [eax + 8]
// 005ce594  85c9                 test ecx, ecx
// 005ce596  7406                 je 0x5ce59e
// 005ce598  c70100000000         mov dword ptr [ecx], 0
// 005ce59e  c6402001             mov byte ptr [eax + 0x20], 1
// 005ce5a2  c6402100             mov byte ptr [eax + 0x21], 0
// 005ce5a6  c3                   ret 
// standard library set<pod20> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
