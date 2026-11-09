// from server: 100% by auto
// roc 2008-06 004d7770  unit: RBX::ViewNew::ViewRbxGfx  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d7770
//
// 004d7770  6a2c                 push 0x2c
// 004d7772  e8a9911c00           call 0x6a0920
// 004d7777  83c404               add esp, 4
// 004d777a  85c0                 test eax, eax
// 004d777c  7406                 je 0x4d7784
// 004d777e  c70000000000         mov dword ptr [eax], 0
// 004d7784  8d4804               lea ecx, [eax + 4]
// 004d7787  85c9                 test ecx, ecx
// 004d7789  7406                 je 0x4d7791
// 004d778b  c70100000000         mov dword ptr [ecx], 0
// 004d7791  8d4808               lea ecx, [eax + 8]
// 004d7794  85c9                 test ecx, ecx
// 004d7796  7406                 je 0x4d779e
// 004d7798  c70100000000         mov dword ptr [ecx], 0
// 004d779e  c6402801             mov byte ptr [eax + 0x28], 1
// 004d77a2  c6402900             mov byte ptr [eax + 0x29], 0
// 004d77a6  c3                   ret 
// standard library set<string> (function ?_Buynode@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@XZ)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
