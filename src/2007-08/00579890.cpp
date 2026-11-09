// from server: 100% by auto
// roc 2007-08 00579890  unit: RBX::P8SpecialShape::?$GetSetImpl  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00579890
//
// 00579890  6a30                 push 0x30
// 00579892  e85f660b00           call 0x62fef6
// 00579897  83c404               add esp, 4
// 0057989a  85c0                 test eax, eax
// 0057989c  7406                 je 0x5798a4
// 0057989e  c70000000000         mov dword ptr [eax], 0
// 005798a4  8d4804               lea ecx, [eax + 4]
// 005798a7  85c9                 test ecx, ecx
// 005798a9  7406                 je 0x5798b1
// 005798ab  c70100000000         mov dword ptr [ecx], 0
// 005798b1  8d4808               lea ecx, [eax + 8]
// 005798b4  85c9                 test ecx, ecx
// 005798b6  7406                 je 0x5798be
// 005798b8  c70100000000         mov dword ptr [ecx], 0
// 005798be  c6402c01             mov byte ptr [eax + 0x2c], 1
// 005798c2  c6402d00             mov byte ptr [eax + 0x2d], 0
// 005798c6  c3                   ret 
// standard library set<pod32> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
