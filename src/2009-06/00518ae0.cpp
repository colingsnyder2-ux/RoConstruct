// from server: 100% by auto
// roc 2009-06 00518ae0  unit: RBX::PartChunk  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00518ae0
//
// 00518ae0  6a2c                 push 0x2c
// 00518ae2  e851ff1f00           call 0x718a38
// 00518ae7  83c404               add esp, 4
// 00518aea  85c0                 test eax, eax
// 00518aec  7406                 je 0x518af4
// 00518aee  c70000000000         mov dword ptr [eax], 0
// 00518af4  8d4804               lea ecx, [eax + 4]
// 00518af7  85c9                 test ecx, ecx
// 00518af9  7406                 je 0x518b01
// 00518afb  c70100000000         mov dword ptr [ecx], 0
// 00518b01  8d4808               lea ecx, [eax + 8]
// 00518b04  85c9                 test ecx, ecx
// 00518b06  7406                 je 0x518b0e
// 00518b08  c70100000000         mov dword ptr [ecx], 0
// 00518b0e  c6402801             mov byte ptr [eax + 0x28], 1
// 00518b12  c6402900             mov byte ptr [eax + 0x29], 0
// 00518b16  c3                   ret 
// standard library set<string> (function ?_Buynode@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@XZ)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
