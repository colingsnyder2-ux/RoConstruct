// from server: 100% by auto
// roc 2009-12 006b4560  unit: RBX::VStockSound::?$FactoryProduct  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b4560
//
// 006b4560  6a38                 push 0x38
// 006b4562  e8f9f21300           call 0x7f3860
// 006b4567  83c404               add esp, 4
// 006b456a  85c0                 test eax, eax
// 006b456c  7406                 je 0x6b4574
// 006b456e  c70000000000         mov dword ptr [eax], 0
// 006b4574  8d4804               lea ecx, [eax + 4]
// 006b4577  85c9                 test ecx, ecx
// 006b4579  7406                 je 0x6b4581
// 006b457b  c70100000000         mov dword ptr [ecx], 0
// 006b4581  8d4808               lea ecx, [eax + 8]
// 006b4584  85c9                 test ecx, ecx
// 006b4586  7406                 je 0x6b458e
// 006b4588  c70100000000         mov dword ptr [ecx], 0
// 006b458e  c6403401             mov byte ptr [eax + 0x34], 1
// 006b4592  c6403500             mov byte ptr [eax + 0x35], 0
// 006b4596  c3                   ret 
// standard library set<pod40> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
