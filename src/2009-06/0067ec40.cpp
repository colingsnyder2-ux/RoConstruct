// from server: 100% by auto
// roc 2009-06 0067ec40  unit: RBX::Mechanism  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0067ec40
//
// 0067ec40  6a14                 push 0x14
// 0067ec42  e8f19d0900           call 0x718a38
// 0067ec47  83c404               add esp, 4
// 0067ec4a  85c0                 test eax, eax
// 0067ec4c  7406                 je 0x67ec54
// 0067ec4e  c70000000000         mov dword ptr [eax], 0
// 0067ec54  8d4804               lea ecx, [eax + 4]
// 0067ec57  85c9                 test ecx, ecx
// 0067ec59  7406                 je 0x67ec61
// 0067ec5b  c70100000000         mov dword ptr [ecx], 0
// 0067ec61  8d4808               lea ecx, [eax + 8]
// 0067ec64  85c9                 test ecx, ecx
// 0067ec66  7406                 je 0x67ec6e
// 0067ec68  c70100000000         mov dword ptr [ecx], 0
// 0067ec6e  c6401001             mov byte ptr [eax + 0x10], 1
// 0067ec72  c6401100             mov byte ptr [eax + 0x11], 0
// 0067ec76  c3                   ret 
// standard library set<ptr> (function ?_Buynode@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
