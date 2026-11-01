// from server: 100% by auto
// roc 2009-12 005ce5b0  unit: RBX::PartChunk  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005ce5b0
//
// 005ce5b0  6a2c                 push 0x2c
// 005ce5b2  e8a9522200           call 0x7f3860
// 005ce5b7  83c404               add esp, 4
// 005ce5ba  85c0                 test eax, eax
// 005ce5bc  7406                 je 0x5ce5c4
// 005ce5be  c70000000000         mov dword ptr [eax], 0
// 005ce5c4  8d4804               lea ecx, [eax + 4]
// 005ce5c7  85c9                 test ecx, ecx
// 005ce5c9  7406                 je 0x5ce5d1
// 005ce5cb  c70100000000         mov dword ptr [ecx], 0
// 005ce5d1  8d4808               lea ecx, [eax + 8]
// 005ce5d4  85c9                 test ecx, ecx
// 005ce5d6  7406                 je 0x5ce5de
// 005ce5d8  c70100000000         mov dword ptr [ecx], 0
// 005ce5de  c6402801             mov byte ptr [eax + 0x28], 1
// 005ce5e2  c6402900             mov byte ptr [eax + 0x29], 0
// 005ce5e6  c3                   ret 
// standard library set<string> (function ?_Buynode@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@XZ)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
