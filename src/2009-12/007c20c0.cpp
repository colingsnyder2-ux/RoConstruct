// from server: 100% by auto
// roc 2009-12 007c20c0  unit: RBX::ImageButton  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c20c0
//
// 007c20c0  8b542404             mov edx, dword ptr [esp + 4]
// 007c20c4  8b4208               mov eax, dword ptr [edx + 8]
// 007c20c7  56                   push esi
// 007c20c8  8b30                 mov esi, dword ptr [eax]
// 007c20ca  897208               mov dword ptr [edx + 8], esi
// 007c20cd  8b30                 mov esi, dword ptr [eax]
// 007c20cf  807e4d00             cmp byte ptr [esi + 0x4d], 0
// 007c20d3  7503                 jne 0x7c20d8
// 007c20d5  895604               mov dword ptr [esi + 4], edx
// 007c20d8  8b7204               mov esi, dword ptr [edx + 4]
// 007c20db  897004               mov dword ptr [eax + 4], esi
// 007c20de  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 007c20e1  5e                   pop esi
// 007c20e2  3b5104               cmp edx, dword ptr [ecx + 4]
// 007c20e5  750b                 jne 0x7c20f2
// 007c20e7  894104               mov dword ptr [ecx + 4], eax
// 007c20ea  8910                 mov dword ptr [eax], edx
// 007c20ec  894204               mov dword ptr [edx + 4], eax
// 007c20ef  c20400               ret 4
// 007c20f2  8b4a04               mov ecx, dword ptr [edx + 4]
// 007c20f5  3b11                 cmp edx, dword ptr [ecx]
// 007c20f7  750a                 jne 0x7c2103
// 007c20f9  8901                 mov dword ptr [ecx], eax
// 007c20fb  8910                 mov dword ptr [eax], edx
// 007c20fd  894204               mov dword ptr [edx + 4], eax
// 007c2100  c20400               ret 4
// 007c2103  894108               mov dword ptr [ecx + 8], eax
// 007c2106  8910                 mov dword ptr [eax], edx
// 007c2108  894204               mov dword ptr [edx + 4], eax
// 007c210b  c20400               ret 4
// standard library set<pod64> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
