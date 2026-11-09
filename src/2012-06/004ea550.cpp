// from server: 100% by auto
// roc 2012-06 004ea550  unit: RBX::RbxTextureProxy  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ea550
//
// 004ea550  6a24                 push 0x24
// 004ea552  e8c37b4900           call 0x98211a
// 004ea557  83c404               add esp, 4
// 004ea55a  85c0                 test eax, eax
// 004ea55c  7406                 je 0x4ea564
// 004ea55e  c70000000000         mov dword ptr [eax], 0
// 004ea564  8d4804               lea ecx, [eax + 4]
// 004ea567  85c9                 test ecx, ecx
// 004ea569  7406                 je 0x4ea571
// 004ea56b  c70100000000         mov dword ptr [ecx], 0
// 004ea571  8d4808               lea ecx, [eax + 8]
// 004ea574  85c9                 test ecx, ecx
// 004ea576  7406                 je 0x4ea57e
// 004ea578  c70100000000         mov dword ptr [ecx], 0
// 004ea57e  c6402001             mov byte ptr [eax + 0x20], 1
// 004ea582  c6402100             mov byte ptr [eax + 0x21], 0
// 004ea586  c3                   ret 
// standard library set<pod20> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
