// from server: 100% by auto
// roc 2007-08 0061ddb0  unit: RBX::ScoreHud  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061ddb0
//
// 0061ddb0  6a20                 push 0x20
// 0061ddb2  e83f210100           call 0x62fef6
// 0061ddb7  83c404               add esp, 4
// 0061ddba  85c0                 test eax, eax
// 0061ddbc  7406                 je 0x61ddc4
// 0061ddbe  c70000000000         mov dword ptr [eax], 0
// 0061ddc4  8d4804               lea ecx, [eax + 4]
// 0061ddc7  85c9                 test ecx, ecx
// 0061ddc9  7406                 je 0x61ddd1
// 0061ddcb  c70100000000         mov dword ptr [ecx], 0
// 0061ddd1  8d4808               lea ecx, [eax + 8]
// 0061ddd4  85c9                 test ecx, ecx
// 0061ddd6  7406                 je 0x61ddde
// 0061ddd8  c70100000000         mov dword ptr [ecx], 0
// 0061ddde  c6401c01             mov byte ptr [eax + 0x1c], 1
// 0061dde2  c6401d00             mov byte ptr [eax + 0x1d], 0
// 0061dde6  c3                   ret 
// standard library set<pod16> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
