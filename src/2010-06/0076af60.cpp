// from server: 100% by auto
// roc 2010-06 0076af60  unit: RBX::ImageButton  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076af60
//
// 0076af60  8b442404             mov eax, dword ptr [esp + 4]
// 0076af64  8b08                 mov ecx, dword ptr [eax]
// 0076af66  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 0076af6a  750e                 jne 0x76af7a
// 0076af6c  8d642400             lea esp, [esp]
// 0076af70  8bc1                 mov eax, ecx
// 0076af72  8b08                 mov ecx, dword ptr [eax]
// 0076af74  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 0076af78  74f6                 je 0x76af70
// 0076af7a  c3                   ret 
// standard library set<pod64> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
