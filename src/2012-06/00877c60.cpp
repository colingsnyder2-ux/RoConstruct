// from server: 100% by auto
// roc 2012-06 00877c60  unit: DummyJob  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00877c60
//
// 00877c60  6a10                 push 0x10
// 00877c62  e8b3a41000           call 0x98211a
// 00877c67  83c404               add esp, 4
// 00877c6a  85c0                 test eax, eax
// 00877c6c  7406                 je 0x877c74
// 00877c6e  c70000000000         mov dword ptr [eax], 0
// 00877c74  8d4804               lea ecx, [eax + 4]
// 00877c77  85c9                 test ecx, ecx
// 00877c79  7406                 je 0x877c81
// 00877c7b  c70100000000         mov dword ptr [ecx], 0
// 00877c81  8d4808               lea ecx, [eax + 8]
// 00877c84  85c9                 test ecx, ecx
// 00877c86  7406                 je 0x877c8e
// 00877c88  c70100000000         mov dword ptr [ecx], 0
// 00877c8e  c6400d01             mov byte ptr [eax + 0xd], 1
// 00877c92  c6400e00             mov byte ptr [eax + 0xe], 0
// 00877c96  c3                   ret 
// standard library set<char> (function ?_Buynode@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@XZ)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
