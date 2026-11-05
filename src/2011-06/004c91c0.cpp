// from server: 100% by auto
// roc 2011-06 004c91c0  unit: RBX::Network::Players::W4PlayerChatType::?$holder  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004c91c0
//
// 004c91c0  6a2c                 push 0x2c
// 004c91c2  e8970e3400           call 0x80a05e
// 004c91c7  83c404               add esp, 4
// 004c91ca  85c0                 test eax, eax
// 004c91cc  7406                 je 0x4c91d4
// 004c91ce  c70000000000         mov dword ptr [eax], 0
// 004c91d4  8d4804               lea ecx, [eax + 4]
// 004c91d7  85c9                 test ecx, ecx
// 004c91d9  7406                 je 0x4c91e1
// 004c91db  c70100000000         mov dword ptr [ecx], 0
// 004c91e1  8d4808               lea ecx, [eax + 8]
// 004c91e4  85c9                 test ecx, ecx
// 004c91e6  7406                 je 0x4c91ee
// 004c91e8  c70100000000         mov dword ptr [ecx], 0
// 004c91ee  c6402801             mov byte ptr [eax + 0x28], 1
// 004c91f2  c6402900             mov byte ptr [eax + 0x29], 0
// 004c91f6  c3                   ret 
// standard library set<string> (function ?_Buynode@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@XZ)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
