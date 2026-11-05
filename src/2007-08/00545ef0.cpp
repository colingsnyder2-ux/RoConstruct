// from server: 100% by auto
// roc 2007-08 00545ef0  unit: RBX::MD5HasherImpl  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00545ef0
//
// 00545ef0  6a40                 push 0x40
// 00545ef2  e8ff9f0e00           call 0x62fef6
// 00545ef7  83c404               add esp, 4
// 00545efa  85c0                 test eax, eax
// 00545efc  7406                 je 0x545f04
// 00545efe  c70000000000         mov dword ptr [eax], 0
// 00545f04  8d4804               lea ecx, [eax + 4]
// 00545f07  85c9                 test ecx, ecx
// 00545f09  7406                 je 0x545f11
// 00545f0b  c70100000000         mov dword ptr [ecx], 0
// 00545f11  8d4808               lea ecx, [eax + 8]
// 00545f14  85c9                 test ecx, ecx
// 00545f16  7406                 je 0x545f1e
// 00545f18  c70100000000         mov dword ptr [ecx], 0
// 00545f1e  c6403c01             mov byte ptr [eax + 0x3c], 1
// 00545f22  c6403d00             mov byte ptr [eax + 0x3d], 0
// 00545f26  c3                   ret 
// standard library set<pod48> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
