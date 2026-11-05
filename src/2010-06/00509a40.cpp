// from server: 100% by auto
// roc 2010-06 00509a40  unit: RBX::Network::ServerReplicator  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00509a40
//
// 00509a40  6a2c                 push 0x2c
// 00509a42  e859df2900           call 0x7a79a0
// 00509a47  83c404               add esp, 4
// 00509a4a  85c0                 test eax, eax
// 00509a4c  7406                 je 0x509a54
// 00509a4e  c70000000000         mov dword ptr [eax], 0
// 00509a54  8d4804               lea ecx, [eax + 4]
// 00509a57  85c9                 test ecx, ecx
// 00509a59  7406                 je 0x509a61
// 00509a5b  c70100000000         mov dword ptr [ecx], 0
// 00509a61  8d4808               lea ecx, [eax + 8]
// 00509a64  85c9                 test ecx, ecx
// 00509a66  7406                 je 0x509a6e
// 00509a68  c70100000000         mov dword ptr [ecx], 0
// 00509a6e  c6402801             mov byte ptr [eax + 0x28], 1
// 00509a72  c6402900             mov byte ptr [eax + 0x29], 0
// 00509a76  c3                   ret 
// standard library set<string> (function ?_Buynode@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@XZ)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
