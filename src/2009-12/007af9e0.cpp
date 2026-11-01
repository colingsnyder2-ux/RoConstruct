// from server: 100% by auto
// roc 2009-12 007af9e0  unit: RBX::Block  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007af9e0
//
// 007af9e0  8b542404             mov edx, dword ptr [esp + 4]
// 007af9e4  8b4208               mov eax, dword ptr [edx + 8]
// 007af9e7  56                   push esi
// 007af9e8  8b30                 mov esi, dword ptr [eax]
// 007af9ea  897208               mov dword ptr [edx + 8], esi
// 007af9ed  8b30                 mov esi, dword ptr [eax]
// 007af9ef  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 007af9f3  7503                 jne 0x7af9f8
// 007af9f5  895604               mov dword ptr [esi + 4], edx
// 007af9f8  8b7204               mov esi, dword ptr [edx + 4]
// 007af9fb  897004               mov dword ptr [eax + 4], esi
// 007af9fe  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 007afa01  5e                   pop esi
// 007afa02  3b5104               cmp edx, dword ptr [ecx + 4]
// 007afa05  750b                 jne 0x7afa12
// 007afa07  894104               mov dword ptr [ecx + 4], eax
// 007afa0a  8910                 mov dword ptr [eax], edx
// 007afa0c  894204               mov dword ptr [edx + 4], eax
// 007afa0f  c20400               ret 4
// 007afa12  8b4a04               mov ecx, dword ptr [edx + 4]
// 007afa15  3b11                 cmp edx, dword ptr [ecx]
// 007afa17  750a                 jne 0x7afa23
// 007afa19  8901                 mov dword ptr [ecx], eax
// 007afa1b  8910                 mov dword ptr [eax], edx
// 007afa1d  894204               mov dword ptr [edx + 4], eax
// 007afa20  c20400               ret 4
// 007afa23  894108               mov dword ptr [ecx + 8], eax
// 007afa26  8910                 mov dword ptr [eax], edx
// 007afa28  894204               mov dword ptr [edx + 4], eax
// 007afa2b  c20400               ret 4
// standard library set<pod16> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
