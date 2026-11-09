// from server: 100% by auto
// roc 2007-08 004cd5e0  unit: G3D::_WeakPtr  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004cd5e0
//
// 004cd5e0  8b442404             mov eax, dword ptr [esp + 4]
// 004cd5e4  8b4808               mov ecx, dword ptr [eax + 8]
// 004cd5e7  80792100             cmp byte ptr [ecx + 0x21], 0
// 004cd5eb  750e                 jne 0x4cd5fb
// 004cd5ed  8d4900               lea ecx, [ecx]
// 004cd5f0  8bc1                 mov eax, ecx
// 004cd5f2  8b4808               mov ecx, dword ptr [eax + 8]
// 004cd5f5  80792100             cmp byte ptr [ecx + 0x21], 0
// 004cd5f9  74f5                 je 0x4cd5f0
// 004cd5fb  c3                   ret 
// standard library set<pod20> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
