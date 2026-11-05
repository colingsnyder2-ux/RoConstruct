// from server: 100% by auto
// roc 2011-06 00945c30  unit: RBX::RbxTextureProxy  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00945c30
//
// 00945c30  8b442404             mov eax, dword ptr [esp + 4]
// 00945c34  8b4808               mov ecx, dword ptr [eax + 8]
// 00945c37  80792100             cmp byte ptr [ecx + 0x21], 0
// 00945c3b  750e                 jne 0x945c4b
// 00945c3d  8d4900               lea ecx, [ecx]
// 00945c40  8bc1                 mov eax, ecx
// 00945c42  8b4808               mov ecx, dword ptr [eax + 8]
// 00945c45  80792100             cmp byte ptr [ecx + 0x21], 0
// 00945c49  74f5                 je 0x945c40
// 00945c4b  c3                   ret 
// standard library set<pod20> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
