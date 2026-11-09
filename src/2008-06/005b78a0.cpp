// from server: 100% by auto
// roc 2008-06 005b78a0  unit: VStockSound::?$FactoryProduct  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b78a0
//
// 005b78a0  6a38                 push 0x38
// 005b78a2  e879900e00           call 0x6a0920
// 005b78a7  83c404               add esp, 4
// 005b78aa  85c0                 test eax, eax
// 005b78ac  7406                 je 0x5b78b4
// 005b78ae  c70000000000         mov dword ptr [eax], 0
// 005b78b4  8d4804               lea ecx, [eax + 4]
// 005b78b7  85c9                 test ecx, ecx
// 005b78b9  7406                 je 0x5b78c1
// 005b78bb  c70100000000         mov dword ptr [ecx], 0
// 005b78c1  8d4808               lea ecx, [eax + 8]
// 005b78c4  85c9                 test ecx, ecx
// 005b78c6  7406                 je 0x5b78ce
// 005b78c8  c70100000000         mov dword ptr [ecx], 0
// 005b78ce  c6403401             mov byte ptr [eax + 0x34], 1
// 005b78d2  c6403500             mov byte ptr [eax + 0x35], 0
// 005b78d6  c3                   ret 
// standard library set<pod40> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
