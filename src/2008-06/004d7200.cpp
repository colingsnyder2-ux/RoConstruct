// from server: 100% by auto
// roc 2008-06 004d7200  unit: RBX::ViewNew::ViewRbxGfx  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d7200
//
// 004d7200  8b442404             mov eax, dword ptr [esp + 4]
// 004d7204  8b08                 mov ecx, dword ptr [eax]
// 004d7206  80792100             cmp byte ptr [ecx + 0x21], 0
// 004d720a  750e                 jne 0x4d721a
// 004d720c  8d642400             lea esp, [esp]
// 004d7210  8bc1                 mov eax, ecx
// 004d7212  8b08                 mov ecx, dword ptr [eax]
// 004d7214  80792100             cmp byte ptr [ecx + 0x21], 0
// 004d7218  74f6                 je 0x4d7210
// 004d721a  c3                   ret 
// standard library set<pod20> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
