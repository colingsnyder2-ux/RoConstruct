// from server: 100% by auto
// roc 2010-06 004e7be0  unit: G3D::VRay::?$holder  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e7be0
//
// 004e7be0  6a1c                 push 0x1c
// 004e7be2  e8b9fd2b00           call 0x7a79a0
// 004e7be7  83c404               add esp, 4
// 004e7bea  85c0                 test eax, eax
// 004e7bec  7406                 je 0x4e7bf4
// 004e7bee  c70000000000         mov dword ptr [eax], 0
// 004e7bf4  8d4804               lea ecx, [eax + 4]
// 004e7bf7  85c9                 test ecx, ecx
// 004e7bf9  7406                 je 0x4e7c01
// 004e7bfb  c70100000000         mov dword ptr [ecx], 0
// 004e7c01  8d4808               lea ecx, [eax + 8]
// 004e7c04  85c9                 test ecx, ecx
// 004e7c06  7406                 je 0x4e7c0e
// 004e7c08  c70100000000         mov dword ptr [ecx], 0
// 004e7c0e  c6401801             mov byte ptr [eax + 0x18], 1
// 004e7c12  c6401900             mov byte ptr [eax + 0x19], 0
// 004e7c16  c3                   ret 
// standard library set<pod12> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod12>
struct E { int v[3]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
