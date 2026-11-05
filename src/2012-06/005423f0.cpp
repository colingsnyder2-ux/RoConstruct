// from server: 100% by auto
// roc 2012-06 005423f0  unit: RBX::VObjectValue::?$FactoryProduct::Creator  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005423f0
//
// 005423f0  6a2c                 push 0x2c
// 005423f2  e823fd4300           call 0x98211a
// 005423f7  83c404               add esp, 4
// 005423fa  85c0                 test eax, eax
// 005423fc  7406                 je 0x542404
// 005423fe  c70000000000         mov dword ptr [eax], 0
// 00542404  8d4804               lea ecx, [eax + 4]
// 00542407  85c9                 test ecx, ecx
// 00542409  7406                 je 0x542411
// 0054240b  c70100000000         mov dword ptr [ecx], 0
// 00542411  8d4808               lea ecx, [eax + 8]
// 00542414  85c9                 test ecx, ecx
// 00542416  7406                 je 0x54241e
// 00542418  c70100000000         mov dword ptr [ecx], 0
// 0054241e  c6402801             mov byte ptr [eax + 0x28], 1
// 00542422  c6402900             mov byte ptr [eax + 0x29], 0
// 00542426  c3                   ret 
// standard library set<string> (function ?_Buynode@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@XZ)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
