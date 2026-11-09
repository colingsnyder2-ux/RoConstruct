// from server: 100% by auto
// roc 2007-08 004d1c00  unit: RBX::View::Texture  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d1c00
//
// 004d1c00  6a2c                 push 0x2c
// 004d1c02  e8efe21500           call 0x62fef6
// 004d1c07  83c404               add esp, 4
// 004d1c0a  85c0                 test eax, eax
// 004d1c0c  7406                 je 0x4d1c14
// 004d1c0e  c70000000000         mov dword ptr [eax], 0
// 004d1c14  8d4804               lea ecx, [eax + 4]
// 004d1c17  85c9                 test ecx, ecx
// 004d1c19  7406                 je 0x4d1c21
// 004d1c1b  c70100000000         mov dword ptr [ecx], 0
// 004d1c21  8d4808               lea ecx, [eax + 8]
// 004d1c24  85c9                 test ecx, ecx
// 004d1c26  7406                 je 0x4d1c2e
// 004d1c28  c70100000000         mov dword ptr [ecx], 0
// 004d1c2e  c6402801             mov byte ptr [eax + 0x28], 1
// 004d1c32  c6402900             mov byte ptr [eax + 0x29], 0
// 004d1c36  c3                   ret 
// standard library set<string> (function ?_Buynode@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@XZ)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
