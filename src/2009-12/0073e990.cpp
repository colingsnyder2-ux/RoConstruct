// from server: 100% by auto
// roc 2009-12 0073e990  unit: RBX::VCollectionService::?$FactoryProduct  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0073e990
//
// 0073e990  6a34                 push 0x34
// 0073e992  e8c94e0b00           call 0x7f3860
// 0073e997  83c404               add esp, 4
// 0073e99a  85c0                 test eax, eax
// 0073e99c  7406                 je 0x73e9a4
// 0073e99e  c70000000000         mov dword ptr [eax], 0
// 0073e9a4  8d4804               lea ecx, [eax + 4]
// 0073e9a7  85c9                 test ecx, ecx
// 0073e9a9  7406                 je 0x73e9b1
// 0073e9ab  c70100000000         mov dword ptr [ecx], 0
// 0073e9b1  8d4808               lea ecx, [eax + 8]
// 0073e9b4  85c9                 test ecx, ecx
// 0073e9b6  7406                 je 0x73e9be
// 0073e9b8  c70100000000         mov dword ptr [ecx], 0
// 0073e9be  c6403001             mov byte ptr [eax + 0x30], 1
// 0073e9c2  c6403100             mov byte ptr [eax + 0x31], 0
// 0073e9c6  c3                   ret 
// standard library set<pod36> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
