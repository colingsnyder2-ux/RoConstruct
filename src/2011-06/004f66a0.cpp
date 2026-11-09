// from server: 100% by auto
// roc 2011-06 004f66a0  unit: RBX::VRbxRay::?$holder  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004f66a0
//
// 004f66a0  6a1c                 push 0x1c
// 004f66a2  e8b7393100           call 0x80a05e
// 004f66a7  83c404               add esp, 4
// 004f66aa  85c0                 test eax, eax
// 004f66ac  7406                 je 0x4f66b4
// 004f66ae  c70000000000         mov dword ptr [eax], 0
// 004f66b4  8d4804               lea ecx, [eax + 4]
// 004f66b7  85c9                 test ecx, ecx
// 004f66b9  7406                 je 0x4f66c1
// 004f66bb  c70100000000         mov dword ptr [ecx], 0
// 004f66c1  8d4808               lea ecx, [eax + 8]
// 004f66c4  85c9                 test ecx, ecx
// 004f66c6  7406                 je 0x4f66ce
// 004f66c8  c70100000000         mov dword ptr [ecx], 0
// 004f66ce  c6401801             mov byte ptr [eax + 0x18], 1
// 004f66d2  c6401900             mov byte ptr [eax + 0x19], 0
// 004f66d6  c3                   ret 
// standard library set<pod12> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod12>
struct E { int v[3]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
