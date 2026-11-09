// from server: 100% by auto
// roc 2010-06 006f4010  unit: RBX::VStudioTool::?$EventDesc  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006f4010
//
// 006f4010  6a10                 push 0x10
// 006f4012  e889390b00           call 0x7a79a0
// 006f4017  83c404               add esp, 4
// 006f401a  85c0                 test eax, eax
// 006f401c  7406                 je 0x6f4024
// 006f401e  c70000000000         mov dword ptr [eax], 0
// 006f4024  8d4804               lea ecx, [eax + 4]
// 006f4027  85c9                 test ecx, ecx
// 006f4029  7406                 je 0x6f4031
// 006f402b  c70100000000         mov dword ptr [ecx], 0
// 006f4031  8d4808               lea ecx, [eax + 8]
// 006f4034  85c9                 test ecx, ecx
// 006f4036  7406                 je 0x6f403e
// 006f4038  c70100000000         mov dword ptr [ecx], 0
// 006f403e  c6400d01             mov byte ptr [eax + 0xd], 1
// 006f4042  c6400e00             mov byte ptr [eax + 0xe], 0
// 006f4046  c3                   ret 
// standard library set<char> (function ?_Buynode@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@XZ)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
