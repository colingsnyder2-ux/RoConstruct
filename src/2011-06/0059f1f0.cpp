// from server: 100% by auto
// roc 2011-06 0059f1f0  unit: RBX::P8NetworkSettings::?$GetSetImpl  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0059f1f0
//
// 0059f1f0  6a38                 push 0x38
// 0059f1f2  e867ae2600           call 0x80a05e
// 0059f1f7  83c404               add esp, 4
// 0059f1fa  85c0                 test eax, eax
// 0059f1fc  7406                 je 0x59f204
// 0059f1fe  c70000000000         mov dword ptr [eax], 0
// 0059f204  8d4804               lea ecx, [eax + 4]
// 0059f207  85c9                 test ecx, ecx
// 0059f209  7406                 je 0x59f211
// 0059f20b  c70100000000         mov dword ptr [ecx], 0
// 0059f211  8d4808               lea ecx, [eax + 8]
// 0059f214  85c9                 test ecx, ecx
// 0059f216  7406                 je 0x59f21e
// 0059f218  c70100000000         mov dword ptr [ecx], 0
// 0059f21e  c6403401             mov byte ptr [eax + 0x34], 1
// 0059f222  c6403500             mov byte ptr [eax + 0x35], 0
// 0059f226  c3                   ret 
// standard library set<pod40> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
