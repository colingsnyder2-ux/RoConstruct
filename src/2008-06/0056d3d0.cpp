// from server: 100% by auto
// roc 2008-06 0056d3d0  unit: G3D::VColor3::?$holder  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056d3d0
//
// 0056d3d0  6a18                 push 0x18
// 0056d3d2  e849351300           call 0x6a0920
// 0056d3d7  83c404               add esp, 4
// 0056d3da  85c0                 test eax, eax
// 0056d3dc  7406                 je 0x56d3e4
// 0056d3de  c70000000000         mov dword ptr [eax], 0
// 0056d3e4  8d4804               lea ecx, [eax + 4]
// 0056d3e7  85c9                 test ecx, ecx
// 0056d3e9  7406                 je 0x56d3f1
// 0056d3eb  c70100000000         mov dword ptr [ecx], 0
// 0056d3f1  8d4808               lea ecx, [eax + 8]
// 0056d3f4  85c9                 test ecx, ecx
// 0056d3f6  7406                 je 0x56d3fe
// 0056d3f8  c70100000000         mov dword ptr [ecx], 0
// 0056d3fe  c6401401             mov byte ptr [eax + 0x14], 1
// 0056d402  c6401500             mov byte ptr [eax + 0x15], 0
// 0056d406  c3                   ret 
// standard library set<pod8> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
