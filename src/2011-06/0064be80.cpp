// from server: 100% by auto
// roc 2011-06 0064be80  unit: RBX::GameBasicSettings  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0064be80
//
// 0064be80  6a24                 push 0x24
// 0064be82  e8d7e11b00           call 0x80a05e
// 0064be87  83c404               add esp, 4
// 0064be8a  85c0                 test eax, eax
// 0064be8c  7406                 je 0x64be94
// 0064be8e  c70000000000         mov dword ptr [eax], 0
// 0064be94  8d4804               lea ecx, [eax + 4]
// 0064be97  85c9                 test ecx, ecx
// 0064be99  7406                 je 0x64bea1
// 0064be9b  c70100000000         mov dword ptr [ecx], 0
// 0064bea1  8d4808               lea ecx, [eax + 8]
// 0064bea4  85c9                 test ecx, ecx
// 0064bea6  7406                 je 0x64beae
// 0064bea8  c70100000000         mov dword ptr [ecx], 0
// 0064beae  c6402001             mov byte ptr [eax + 0x20], 1
// 0064beb2  c6402100             mov byte ptr [eax + 0x21], 0
// 0064beb6  c3                   ret 
// standard library set<pod20> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
