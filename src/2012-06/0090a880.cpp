// from server: 100% by auto
// roc 2012-06 0090a880  unit: RBX::PrismPoly  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0090a880
//
// 0090a880  8b442404             mov eax, dword ptr [esp + 4]
// 0090a884  8b08                 mov ecx, dword ptr [eax]
// 0090a886  80792500             cmp byte ptr [ecx + 0x25], 0
// 0090a88a  750e                 jne 0x90a89a
// 0090a88c  8d642400             lea esp, [esp]
// 0090a890  8bc1                 mov eax, ecx
// 0090a892  8b08                 mov ecx, dword ptr [eax]
// 0090a894  80792500             cmp byte ptr [ecx + 0x25], 0
// 0090a898  74f6                 je 0x90a890
// 0090a89a  c3                   ret 
// standard library set<pod24> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
