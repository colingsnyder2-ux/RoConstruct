// from server: 100% by auto
// roc 2007-08 00569670  unit: RBX::ModelInstance  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00569670
//
// 00569670  8b542404             mov edx, dword ptr [esp + 4]
// 00569674  8b4208               mov eax, dword ptr [edx + 8]
// 00569677  56                   push esi
// 00569678  8b30                 mov esi, dword ptr [eax]
// 0056967a  897208               mov dword ptr [edx + 8], esi
// 0056967d  8b30                 mov esi, dword ptr [eax]
// 0056967f  807e3100             cmp byte ptr [esi + 0x31], 0
// 00569683  7503                 jne 0x569688
// 00569685  895604               mov dword ptr [esi + 4], edx
// 00569688  8b7204               mov esi, dword ptr [edx + 4]
// 0056968b  897004               mov dword ptr [eax + 4], esi
// 0056968e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00569691  3b5104               cmp edx, dword ptr [ecx + 4]
// 00569694  5e                   pop esi
// 00569695  750b                 jne 0x5696a2
// 00569697  894104               mov dword ptr [ecx + 4], eax
// 0056969a  8910                 mov dword ptr [eax], edx
// 0056969c  894204               mov dword ptr [edx + 4], eax
// 0056969f  c20400               ret 4
// 005696a2  8b4a04               mov ecx, dword ptr [edx + 4]
// 005696a5  3b11                 cmp edx, dword ptr [ecx]
// 005696a7  750a                 jne 0x5696b3
// 005696a9  8901                 mov dword ptr [ecx], eax
// 005696ab  8910                 mov dword ptr [eax], edx
// 005696ad  894204               mov dword ptr [edx + 4], eax
// 005696b0  c20400               ret 4
// 005696b3  894108               mov dword ptr [ecx + 8], eax
// 005696b6  8910                 mov dword ptr [eax], edx
// 005696b8  894204               mov dword ptr [edx + 4], eax
// 005696bb  c20400               ret 4
// standard library set<pod36> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
