// from server: 100% by auto
// roc 2007-08 0040b550  unit: CBrowserView  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040b550
//
// 0040b550  6a24                 push 0x24
// 0040b552  e89f492200           call 0x62fef6
// 0040b557  83c404               add esp, 4
// 0040b55a  85c0                 test eax, eax
// 0040b55c  7402                 je 0x40b560
// 0040b55e  8900                 mov dword ptr [eax], eax
// 0040b560  8d4804               lea ecx, [eax + 4]
// 0040b563  85c9                 test ecx, ecx
// 0040b565  7402                 je 0x40b569
// 0040b567  8901                 mov dword ptr [ecx], eax
// 0040b569  c3                   ret 
// standard library list<string> (function ?_Buynode@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
