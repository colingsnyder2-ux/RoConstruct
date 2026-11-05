// from server: 100% by auto
// roc 2012-06 00877f70  unit: DummyJob  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00877f70
//
// 00877f70  6a14                 push 0x14
// 00877f72  e8a3a11000           call 0x98211a
// 00877f77  83c404               add esp, 4
// 00877f7a  85c0                 test eax, eax
// 00877f7c  7406                 je 0x877f84
// 00877f7e  c70000000000         mov dword ptr [eax], 0
// 00877f84  8d4804               lea ecx, [eax + 4]
// 00877f87  85c9                 test ecx, ecx
// 00877f89  7406                 je 0x877f91
// 00877f8b  c70100000000         mov dword ptr [ecx], 0
// 00877f91  8d4808               lea ecx, [eax + 8]
// 00877f94  85c9                 test ecx, ecx
// 00877f96  7406                 je 0x877f9e
// 00877f98  c70100000000         mov dword ptr [ecx], 0
// 00877f9e  c6401001             mov byte ptr [eax + 0x10], 1
// 00877fa2  c6401100             mov byte ptr [eax + 0x11], 0
// 00877fa6  c3                   ret 
// standard library set<ptr> (function ?_Buynode@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
