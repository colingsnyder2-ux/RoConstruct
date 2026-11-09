// from server: 100% by auto
// roc 2009-12 00433ad0  unit: CPropGrid::UpdateItemsJob  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00433ad0
//
// 00433ad0  6a1c                 push 0x1c
// 00433ad2  e889fd3b00           call 0x7f3860
// 00433ad7  83c404               add esp, 4
// 00433ada  85c0                 test eax, eax
// 00433adc  7406                 je 0x433ae4
// 00433ade  c70000000000         mov dword ptr [eax], 0
// 00433ae4  8d4804               lea ecx, [eax + 4]
// 00433ae7  85c9                 test ecx, ecx
// 00433ae9  7406                 je 0x433af1
// 00433aeb  c70100000000         mov dword ptr [ecx], 0
// 00433af1  8d4808               lea ecx, [eax + 8]
// 00433af4  85c9                 test ecx, ecx
// 00433af6  7406                 je 0x433afe
// 00433af8  c70100000000         mov dword ptr [ecx], 0
// 00433afe  c6401801             mov byte ptr [eax + 0x18], 1
// 00433b02  c6401900             mov byte ptr [eax + 0x19], 0
// 00433b06  c3                   ret 
// standard library set<pod12> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod12>
struct E { int v[3]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
