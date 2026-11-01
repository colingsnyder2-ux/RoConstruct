// from server: 100% by auto
// roc 2009-12 005cc6a0  unit: RBX::MeshRefPartAdapter  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cc6a0
//
// 005cc6a0  8b442404             mov eax, dword ptr [esp + 4]
// 005cc6a4  8b4808               mov ecx, dword ptr [eax + 8]
// 005cc6a7  80792100             cmp byte ptr [ecx + 0x21], 0
// 005cc6ab  750e                 jne 0x5cc6bb
// 005cc6ad  8d4900               lea ecx, [ecx]
// 005cc6b0  8bc1                 mov eax, ecx
// 005cc6b2  8b4808               mov ecx, dword ptr [eax + 8]
// 005cc6b5  80792100             cmp byte ptr [ecx + 0x21], 0
// 005cc6b9  74f5                 je 0x5cc6b0
// 005cc6bb  c3                   ret 
// standard library set<pod20> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
