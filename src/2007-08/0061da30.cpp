// from server: 100% by auto
// roc 2007-08 0061da30  unit: RBX::ChatOutput  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061da30
//
// 0061da30  8b442404             mov eax, dword ptr [esp + 4]
// 0061da34  8b08                 mov ecx, dword ptr [eax]
// 0061da36  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0061da3a  750e                 jne 0x61da4a
// 0061da3c  8d642400             lea esp, [esp]
// 0061da40  8bc1                 mov eax, ecx
// 0061da42  8b08                 mov ecx, dword ptr [eax]
// 0061da44  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0061da48  74f6                 je 0x61da40
// 0061da4a  c3                   ret 
// standard library set<pod16> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
