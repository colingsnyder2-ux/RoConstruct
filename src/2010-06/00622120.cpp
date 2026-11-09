// from server: 100% by auto
// roc 2010-06 00622120  unit: RBX::VStockSound::?$FactoryProduct  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00622120
//
// 00622120  6a38                 push 0x38
// 00622122  e879581800           call 0x7a79a0
// 00622127  83c404               add esp, 4
// 0062212a  85c0                 test eax, eax
// 0062212c  7406                 je 0x622134
// 0062212e  c70000000000         mov dword ptr [eax], 0
// 00622134  8d4804               lea ecx, [eax + 4]
// 00622137  85c9                 test ecx, ecx
// 00622139  7406                 je 0x622141
// 0062213b  c70100000000         mov dword ptr [ecx], 0
// 00622141  8d4808               lea ecx, [eax + 8]
// 00622144  85c9                 test ecx, ecx
// 00622146  7406                 je 0x62214e
// 00622148  c70100000000         mov dword ptr [ecx], 0
// 0062214e  c6403401             mov byte ptr [eax + 0x34], 1
// 00622152  c6403500             mov byte ptr [eax + 0x35], 0
// 00622156  c3                   ret 
// standard library set<pod40> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
