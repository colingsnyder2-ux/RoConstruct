// from server: 100% by auto
// roc 2008-06 004d7220  unit: RBX::ViewNew::ViewRbxGfx  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d7220
//
// 004d7220  8b442404             mov eax, dword ptr [esp + 4]
// 004d7224  8b4808               mov ecx, dword ptr [eax + 8]
// 004d7227  80792100             cmp byte ptr [ecx + 0x21], 0
// 004d722b  750e                 jne 0x4d723b
// 004d722d  8d4900               lea ecx, [ecx]
// 004d7230  8bc1                 mov eax, ecx
// 004d7232  8b4808               mov ecx, dword ptr [eax + 8]
// 004d7235  80792100             cmp byte ptr [ecx + 0x21], 0
// 004d7239  74f5                 je 0x4d7230
// 004d723b  c3                   ret 
// standard library set<pod20> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
