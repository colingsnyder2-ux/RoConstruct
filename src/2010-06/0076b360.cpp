// from server: 100% by auto
// roc 2010-06 0076b360  unit: RBX::ImageButton  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076b360
//
// 0076b360  6a50                 push 0x50
// 0076b362  e839c60300           call 0x7a79a0
// 0076b367  83c404               add esp, 4
// 0076b36a  85c0                 test eax, eax
// 0076b36c  7406                 je 0x76b374
// 0076b36e  c70000000000         mov dword ptr [eax], 0
// 0076b374  8d4804               lea ecx, [eax + 4]
// 0076b377  85c9                 test ecx, ecx
// 0076b379  7406                 je 0x76b381
// 0076b37b  c70100000000         mov dword ptr [ecx], 0
// 0076b381  8d4808               lea ecx, [eax + 8]
// 0076b384  85c9                 test ecx, ecx
// 0076b386  7406                 je 0x76b38e
// 0076b388  c70100000000         mov dword ptr [ecx], 0
// 0076b38e  c6404c01             mov byte ptr [eax + 0x4c], 1
// 0076b392  c6404d00             mov byte ptr [eax + 0x4d], 0
// 0076b396  c3                   ret 
// standard library set<pod64> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
