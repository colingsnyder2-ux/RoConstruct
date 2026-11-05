// from server: 100% by auto
// roc 2007-08 00587a40  unit: RBX::Reflection::EnumDescriptor  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00587a40
//
// 00587a40  8b442404             mov eax, dword ptr [esp + 4]
// 00587a44  8b08                 mov ecx, dword ptr [eax]
// 00587a46  80793500             cmp byte ptr [ecx + 0x35], 0
// 00587a4a  750e                 jne 0x587a5a
// 00587a4c  8d642400             lea esp, [esp]
// 00587a50  8bc1                 mov eax, ecx
// 00587a52  8b08                 mov ecx, dword ptr [eax]
// 00587a54  80793500             cmp byte ptr [ecx + 0x35], 0
// 00587a58  74f6                 je 0x587a50
// 00587a5a  c3                   ret 
// standard library set<pod40> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
