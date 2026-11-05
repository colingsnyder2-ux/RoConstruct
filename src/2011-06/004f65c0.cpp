// from server: 100% by auto
// roc 2011-06 004f65c0  unit: RBX::VRbxRay::?$holder  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004f65c0
//
// 004f65c0  6a28                 push 0x28
// 004f65c2  e8973a3100           call 0x80a05e
// 004f65c7  83c404               add esp, 4
// 004f65ca  85c0                 test eax, eax
// 004f65cc  7406                 je 0x4f65d4
// 004f65ce  c70000000000         mov dword ptr [eax], 0
// 004f65d4  8d4804               lea ecx, [eax + 4]
// 004f65d7  85c9                 test ecx, ecx
// 004f65d9  7406                 je 0x4f65e1
// 004f65db  c70100000000         mov dword ptr [ecx], 0
// 004f65e1  8d4808               lea ecx, [eax + 8]
// 004f65e4  85c9                 test ecx, ecx
// 004f65e6  7406                 je 0x4f65ee
// 004f65e8  c70100000000         mov dword ptr [ecx], 0
// 004f65ee  c6402401             mov byte ptr [eax + 0x24], 1
// 004f65f2  c6402500             mov byte ptr [eax + 0x25], 0
// 004f65f6  c3                   ret 
// standard library set<pod24> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
