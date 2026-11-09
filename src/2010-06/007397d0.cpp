// from server: 100% by auto
// roc 2010-06 007397d0  unit: seg_00730000  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007397d0
//
// 007397d0  8b542404             mov edx, dword ptr [esp + 4]
// 007397d4  8b4208               mov eax, dword ptr [edx + 8]
// 007397d7  56                   push esi
// 007397d8  8b30                 mov esi, dword ptr [eax]
// 007397da  897208               mov dword ptr [edx + 8], esi
// 007397dd  8b30                 mov esi, dword ptr [eax]
// 007397df  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 007397e3  7503                 jne 0x7397e8
// 007397e5  895604               mov dword ptr [esi + 4], edx
// 007397e8  8b7204               mov esi, dword ptr [edx + 4]
// 007397eb  897004               mov dword ptr [eax + 4], esi
// 007397ee  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 007397f1  5e                   pop esi
// 007397f2  3b5104               cmp edx, dword ptr [ecx + 4]
// 007397f5  750b                 jne 0x739802
// 007397f7  894104               mov dword ptr [ecx + 4], eax
// 007397fa  8910                 mov dword ptr [eax], edx
// 007397fc  894204               mov dword ptr [edx + 4], eax
// 007397ff  c20400               ret 4
// 00739802  8b4a04               mov ecx, dword ptr [edx + 4]
// 00739805  3b11                 cmp edx, dword ptr [ecx]
// 00739807  750a                 jne 0x739813
// 00739809  8901                 mov dword ptr [ecx], eax
// 0073980b  8910                 mov dword ptr [eax], edx
// 0073980d  894204               mov dword ptr [edx + 4], eax
// 00739810  c20400               ret 4
// 00739813  894108               mov dword ptr [ecx + 8], eax
// 00739816  8910                 mov dword ptr [eax], edx
// 00739818  894204               mov dword ptr [edx + 4], eax
// 0073981b  c20400               ret 4
// standard library set<pod32> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
