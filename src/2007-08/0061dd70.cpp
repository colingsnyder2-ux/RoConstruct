// from server: 100% by auto
// roc 2007-08 0061dd70  unit: RBX::ScoreHud  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061dd70
//
// 0061dd70  6a38                 push 0x38
// 0061dd72  e87f210100           call 0x62fef6
// 0061dd77  83c404               add esp, 4
// 0061dd7a  85c0                 test eax, eax
// 0061dd7c  7406                 je 0x61dd84
// 0061dd7e  c70000000000         mov dword ptr [eax], 0
// 0061dd84  8d4804               lea ecx, [eax + 4]
// 0061dd87  85c9                 test ecx, ecx
// 0061dd89  7406                 je 0x61dd91
// 0061dd8b  c70100000000         mov dword ptr [ecx], 0
// 0061dd91  8d4808               lea ecx, [eax + 8]
// 0061dd94  85c9                 test ecx, ecx
// 0061dd96  7406                 je 0x61dd9e
// 0061dd98  c70100000000         mov dword ptr [ecx], 0
// 0061dd9e  c6403401             mov byte ptr [eax + 0x34], 1
// 0061dda2  c6403500             mov byte ptr [eax + 0x35], 0
// 0061dda6  c3                   ret 
// standard library set<pod40> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
