// from server: 100% by auto
// roc 2011-06 0078d620  unit: RBX::UniversalTool  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0078d620
//
// 0078d620  6a30                 push 0x30
// 0078d622  e837ca0700           call 0x80a05e
// 0078d627  83c404               add esp, 4
// 0078d62a  85c0                 test eax, eax
// 0078d62c  7406                 je 0x78d634
// 0078d62e  c70000000000         mov dword ptr [eax], 0
// 0078d634  8d4804               lea ecx, [eax + 4]
// 0078d637  85c9                 test ecx, ecx
// 0078d639  7406                 je 0x78d641
// 0078d63b  c70100000000         mov dword ptr [ecx], 0
// 0078d641  8d4808               lea ecx, [eax + 8]
// 0078d644  85c9                 test ecx, ecx
// 0078d646  7406                 je 0x78d64e
// 0078d648  c70100000000         mov dword ptr [ecx], 0
// 0078d64e  c6402c01             mov byte ptr [eax + 0x2c], 1
// 0078d652  c6402d00             mov byte ptr [eax + 0x2d], 0
// 0078d656  c3                   ret 
// standard library set<pod32> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
