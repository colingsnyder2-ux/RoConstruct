// from server: 100% by auto
// roc 2012-06 005cb190  unit: Ogre::istreamDataStream  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005cb190
//
// 005cb190  6a30                 push 0x30
// 005cb192  e8836f3b00           call 0x98211a
// 005cb197  83c404               add esp, 4
// 005cb19a  85c0                 test eax, eax
// 005cb19c  7406                 je 0x5cb1a4
// 005cb19e  c70000000000         mov dword ptr [eax], 0
// 005cb1a4  8d4804               lea ecx, [eax + 4]
// 005cb1a7  85c9                 test ecx, ecx
// 005cb1a9  7406                 je 0x5cb1b1
// 005cb1ab  c70100000000         mov dword ptr [ecx], 0
// 005cb1b1  8d4808               lea ecx, [eax + 8]
// 005cb1b4  85c9                 test ecx, ecx
// 005cb1b6  7406                 je 0x5cb1be
// 005cb1b8  c70100000000         mov dword ptr [ecx], 0
// 005cb1be  c6402c01             mov byte ptr [eax + 0x2c], 1
// 005cb1c2  c6402d00             mov byte ptr [eax + 0x2d], 0
// 005cb1c6  c3                   ret 
// standard library set<pod32> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
