// from server: 100% by auto
// roc 2009-06 006e23b0  unit: RBX::ScoreHud  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e23b0
//
// 006e23b0  6a34                 push 0x34
// 006e23b2  e881660300           call 0x718a38
// 006e23b7  83c404               add esp, 4
// 006e23ba  85c0                 test eax, eax
// 006e23bc  7406                 je 0x6e23c4
// 006e23be  c70000000000         mov dword ptr [eax], 0
// 006e23c4  8d4804               lea ecx, [eax + 4]
// 006e23c7  85c9                 test ecx, ecx
// 006e23c9  7406                 je 0x6e23d1
// 006e23cb  c70100000000         mov dword ptr [ecx], 0
// 006e23d1  8d4808               lea ecx, [eax + 8]
// 006e23d4  85c9                 test ecx, ecx
// 006e23d6  7406                 je 0x6e23de
// 006e23d8  c70100000000         mov dword ptr [ecx], 0
// 006e23de  c6403001             mov byte ptr [eax + 0x30], 1
// 006e23e2  c6403100             mov byte ptr [eax + 0x31], 0
// 006e23e6  c3                   ret 
// standard library set<pod36> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
