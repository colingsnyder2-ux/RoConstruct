// from server: 100% by auto
// roc 2007-08 004ef210  unit: RBX::Render::SceneManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ef210
//
// 004ef210  8b442404             mov eax, dword ptr [esp + 4]
// 004ef214  8b08                 mov ecx, dword ptr [eax]
// 004ef216  80791500             cmp byte ptr [ecx + 0x15], 0
// 004ef21a  750e                 jne 0x4ef22a
// 004ef21c  8d642400             lea esp, [esp]
// 004ef220  8bc1                 mov eax, ecx
// 004ef222  8b08                 mov ecx, dword ptr [eax]
// 004ef224  80791500             cmp byte ptr [ecx + 0x15], 0
// 004ef228  74f6                 je 0x4ef220
// 004ef22a  c3                   ret 
// standard library set<pod8> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
