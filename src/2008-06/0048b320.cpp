// from server: 100% by auto
// roc 2008-06 0048b320  unit: boost::any::placeholder  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048b320
//
// 0048b320  6a10                 push 0x10
// 0048b322  e8f9552100           call 0x6a0920
// 0048b327  83c404               add esp, 4
// 0048b32a  85c0                 test eax, eax
// 0048b32c  7406                 je 0x48b334
// 0048b32e  c70000000000         mov dword ptr [eax], 0
// 0048b334  8d4804               lea ecx, [eax + 4]
// 0048b337  85c9                 test ecx, ecx
// 0048b339  7406                 je 0x48b341
// 0048b33b  c70100000000         mov dword ptr [ecx], 0
// 0048b341  8d4808               lea ecx, [eax + 8]
// 0048b344  85c9                 test ecx, ecx
// 0048b346  7406                 je 0x48b34e
// 0048b348  c70100000000         mov dword ptr [ecx], 0
// 0048b34e  c6400d01             mov byte ptr [eax + 0xd], 1
// 0048b352  c6400e00             mov byte ptr [eax + 0xe], 0
// 0048b356  c3                   ret 
// standard library set<char> (function ?_Buynode@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@XZ)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
